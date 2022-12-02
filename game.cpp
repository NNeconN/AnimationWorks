#include <cinttypes>

#include "dx11util.h"
#include "CModel.h"
#include "CCamera.h"
#include "DX11Settransform.h"
#include "dx11mathutil.h"
#include "Application.h"
#include "CDirectInput.h"
#include "player.h"
#include "skydome.h"
#include "updatespherecamera.h"
#include "BoundingSphere.h"
#include "myimgui.h"
#include "ModelMgr.h"
#include "stage.h"
#include "StageHit.h"
#include "tank.h"
#include "implot/implot.h"
#include "myimplot.h"
#include "imgui\GraphProcess.h"
#include "player.h"	//相互インクルードを防ぐ為にcppにかく。ほんとはhに書くのがいい

Monster g_monster;

template <typename T>
inline T RandomRange(T min, T max) {
	T scale = rand() / (T)RAND_MAX;
	return min + scale * (max - min);
}

struct ScrollingBuffer {
	int MaxSize;
	int Offset;
	ImVector<ImVec2> Data;
	ScrollingBuffer(int max_size = 2000) {
		MaxSize = max_size;
		Offset = 0;
		Data.reserve(MaxSize);
	}
	void AddPoint(float x, float y) {
		if (Data.size() < MaxSize)
			Data.push_back(ImVec2(x, y));
		else {
			Data[Offset] = ImVec2(x, y);
			Offset = (Offset + 1) % MaxSize;
		}
	}
	void Erase() {
		if (Data.size() > 0) {
			Data.shrink(0);
			Offset = 0;
		}
	}
};

struct RollingBuffer {
	float Span;
	ImVector<ImVec2> Data;
	RollingBuffer() {
		Span = 10.0f;
		Data.reserve(2000);
	}
	void AddPoint(float x, float y) {
		float xmod = fmodf(x, Span);
		if (!Data.empty() && xmod < Data.back().x)
			Data.shrink(0);
		Data.push_back(ImVec2(xmod, y));
	}
};

void GameInit() {
	// DX11初期化
	DX11Init(
		Application::Instance()->GetHWnd(),
		Application::CLIENT_WIDTH,
		Application::CLIENT_HEIGHT,
		false);

	// カメラが必要
	DirectX::XMFLOAT3 eye(0, 10, -170);	// カメラの位置
	DirectX::XMFLOAT3 lookat(0, 0, 0);	// 注視点
	DirectX::XMFLOAT3 up(0, 1, 0);		// カメラの上向きベクトル

	CCamera::GetInstance()->Init(
		10.0f,							// ニアクリップ
		10000.0f,						// ファークリップ
		XM_PI / 5.0f,					// 視野角
		static_cast<float>(Application::CLIENT_WIDTH),		// スクリーン幅
		static_cast<float>(Application::CLIENT_HEIGHT),		// スクリーンの高さ
		eye, lookat, up);				// カメラのデータ

	// 平行光源をセット
	DX11LightInit(
		DirectX::XMFLOAT4(1, 1, -1, 0));

	// アルファブレンド有効化
	TurnOnAlphablend();

	// DirectT INPUT 初期化
	CDirectInput::GetInstance().Init(
		Application::Instance()->GetHInst(),
		Application::Instance()->GetHWnd(),
		Application::CLIENT_WIDTH,
		Application::CLIENT_HEIGHT);
	
	// 戦車初期化
	//g_tank.Init();

	g_monster.Init();

	// IMGUI初期化
	imguiInit();
	implotInit();
}

void GameInput(uint64_t dt) {
	CDirectInput::GetInstance().GetKeyBuffer();
}

void GameUpdate(uint64_t dt) {
	// プレイヤ更新
	/*g_tank.Update();*/
	g_monster.Update();
}

void Demo_DragPoints() {
	ImGui::BulletText("Click and drag each point.");
	static ImPlotDragToolFlags flags = ImPlotDragToolFlags_None;
	ImGui::CheckboxFlags("Pos", &flags, ImPlotDragToolFlags_NoCursors); ImGui::SameLine();
	ImGui::CheckboxFlags("Rot", &flags, ImPlotDragToolFlags_NoFit); ImGui::SameLine();
	ImGui::CheckboxFlags("Scale", &flags, ImPlotDragToolFlags_NoInputs);
	ImPlotAxisFlags ax_flags = ImPlotAxisFlags_LockMax | ImPlotAxisFlags_NoTickMarks;

	static float t = 0;
	t += ImGui::GetIO().DeltaTime;

	static float history = 10.0f;
	ImGui::SliderFloat("History", &history, 1, 30, "%.1f s");

	if (flags & ImPlotDragToolFlags_NoCursors)
	{
		if (ImPlot::BeginPlot("##Bezier", ImVec2(-1, -1), ImPlotFlags_CanvasOnly)) {
			ImPlot::SetupAxes(0, 0, ax_flags, ax_flags);
			ImPlot::SetupAxesLimits(0, 1, 0, 1);
			static ImPlotPoint P[] = { ImPlotPoint(.0f,.0f), ImPlotPoint(g_monster.GetPos().x,0.4),  ImPlotPoint(.0f,.0f),  ImPlotPoint(0.2,0.2) };
			
			ImPlot::SetupAxisLimits(ImAxis_X1, t - history, t, ImGuiCond_Always);

			//ImVec4点のRGBA
			ImPlot::DragPoint(0, &P[0].x, &P[0].y, ImVec4(1, 0.5f, 0.5f, 1), 4, flags);
			ImPlot::DragPoint(1, &P[1].x, &P[1].y, ImVec4(1, 0.5f, 0.5f, 1), 4, flags);
			ImPlot::DragPoint(2, &P[2].x, &P[2].y, ImVec4(0, 0.5f, 1, 1), 4, flags);
			ImPlot::DragPoint(3, &P[3].x, &P[3].y, ImVec4(0, 0.5f, 1, 1), 4, flags);

			XMFLOAT3 outputpos = { 0,0,0 };

			outputpos.x = P[1].x;
			outputpos.y = P[3].y;

			g_monster.SetPos(outputpos);

			//static ImPlotPoint B[100];
			//for (int i = 0; i < 100; ++i) {
			//	double t = i / 99.0;
			//	double u = 1 - t;
			//	double w1 = u * u * u;
			//	double w2 = 3 * u * u * t;
			//	double w3 = 3 * u * t * t;
			//	double w4 = t * t * t;
			//	B[i] = ImPlotPoint(w1 * P[0].x + w2 * P[1].x + w3 * P[2].x + w4 * P[3].x, w1 * P[0].y + w2 * P[1].y + w3 * P[2].y + w4 * P[3].y);
			//}

			//ImVec4線のRGBA
			ImPlot::SetNextLineStyle(ImVec4(1, 0.5f, 0.5f, 1));
			ImPlot::PlotLine("##h1", &P[0].x, &P[0].y, 2, 0, 0, sizeof(ImPlotPoint));
			ImPlot::SetNextLineStyle(ImVec4(0, 0.5f, 1, 1));
			ImPlot::PlotLine("##h2", &P[2].x, &P[2].y, 2, 0, 0, sizeof(ImPlotPoint));
			//ImPlot::SetNextLineStyle(ImVec4(0, 0.9f, 0, 1), 2);
			//ImPlot::PlotLine("##bez", &B[0].x, &B[0].y, 100, 0, 0, sizeof(ImPlotPoint));

			ImPlot::EndPlot();
		}
	}

	if (flags & ImPlotDragToolFlags_NoFit)
	{
		if (ImPlot::BeginPlot("##Bezier", ImVec2(-1, 0), ImPlotFlags_CanvasOnly)) {
			ImPlot::SetupAxes(0, 0, ax_flags, ax_flags);
			ImPlot::SetupAxesLimits(0, 1, 0, 1);
			static ImPlotPoint P[] = { ImPlotPoint(.0f,.0f), ImPlotPoint(0.2,0.4),  ImPlotPoint(.0f,.0f),  ImPlotPoint(0.2,0.2) };

			//ImVec4点のRGBA
			ImPlot::DragPoint(0, &P[0].x, &P[0].y, ImVec4(1, 0.5f, 0.5f, 1), 4, flags);
			ImPlot::DragPoint(1, &P[1].x, &P[1].y, ImVec4(1, 0.5f, 0.5f, 1), 4, flags);
			ImPlot::DragPoint(2, &P[2].x, &P[2].y, ImVec4(0, 0.5f, 1, 1), 4, flags);
			ImPlot::DragPoint(3, &P[3].x, &P[3].y, ImVec4(0, 0.5f, 1, 1), 4, flags);

			//static ImPlotPoint B[100];
			//for (int i = 0; i < 100; ++i) {
			//	double t = i / 99.0;
			//	double u = 1 - t;
			//	double w1 = u * u * u;
			//	double w2 = 3 * u * u * t;
			//	double w3 = 3 * u * t * t;
			//	double w4 = t * t * t;
			//	B[i] = ImPlotPoint(w1 * P[0].x + w2 * P[1].x + w3 * P[2].x + w4 * P[3].x, w1 * P[0].y + w2 * P[1].y + w3 * P[2].y + w4 * P[3].y);
			//}

			//ImVec4線のRGBA
			ImPlot::SetNextLineStyle(ImVec4(1, 0.5f, 0.5f, 1));
			ImPlot::PlotLine("##h1", &P[0].x, &P[0].y, 2, 0, 0, sizeof(ImPlotPoint));
			ImPlot::SetNextLineStyle(ImVec4(0, 0.5f, 1, 1));
			ImPlot::PlotLine("##h2", &P[2].x, &P[2].y, 2, 0, 0, sizeof(ImPlotPoint));
			//ImPlot::SetNextLineStyle(ImVec4(0, 0.9f, 0, 1), 2);
			//ImPlot::PlotLine("##bez", &B[0].x, &B[0].y, 100, 0, 0, sizeof(ImPlotPoint));

			ImPlot::EndPlot();
		}
	}

	//チェックすると選んでるグラフの拡大縮小ができる
	if (flags & ImPlotDragToolFlags_NoInputs)
	{
		if (ImPlot::BeginPlot("##Bezier", ImVec2(-1, 0), ImPlotFlags_CanvasOnly)) {
			ImPlot::SetupAxes(0, 0, ax_flags, ax_flags);
			ImPlot::SetupAxesLimits(0, 1, 0, 1);

			ImPlot::EndPlot();
		}
	}
}

void Demo_RealtimePlots() {
	ImGui::BulletText("Move your mouse to change the data!");
	ImGui::BulletText("This example assumes 60 FPS. Higher FPS requires larger buffer size.");
	static ScrollingBuffer sdata1, sdata2;
	static RollingBuffer   rdata1, rdata2;
	ImVec2 mouse = ImGui::GetMousePos();
	static float t = 0;
	t += ImGui::GetIO().DeltaTime;

	static float history = 10.0f;
	ImGui::SliderFloat("History", &history, 1, 30, "%.1f s");
	rdata1.Span = history;
	rdata2.Span = history;

	static ImPlotAxisFlags flags = ImPlotAxisFlags_NoTickLabels;

	if (ImPlot::BeginPlot("##Scrolling", ImVec2(-1, 150))) {
		ImPlot::SetupAxes(NULL, NULL, flags, flags);
		ImPlot::SetupAxisLimits(ImAxis_X1, t - history, t, ImGuiCond_Always);
		ImPlot::SetupAxisLimits(ImAxis_Y1, 0, 1);
		ImPlot::SetNextFillStyle(IMPLOT_AUTO_COL, 0.5f);
		ImPlot::EndPlot();
	}
	if (ImPlot::BeginPlot("##Rolling", ImVec2(-1, 150))) {
		ImPlot::SetupAxes(NULL, NULL, flags, flags);
		ImPlot::SetupAxisLimits(ImAxis_X1, 0, history, ImGuiCond_Always);
		ImPlot::SetupAxisLimits(ImAxis_Y1, 0, 1);
		ImPlot::EndPlot();
	}
}

// IMGUIウインドウ
void imguidebug() {
	Demo_DragPoints();

	ImGui::Begin(u8"自機");

	std::string str;
	str = "position" + std::to_string(0) + ":" + 
		std::to_string(g_monster.GetMtx()._41) + " " +
		std::to_string(g_monster.GetMtx()._42) + " " +
		std::to_string(g_monster.GetMtx()._43);
		ImGui::Text(str.c_str());

	ImGui::End();

	ImGui::Begin(u8"操作説明");
	ImGui::DragFloat("HP",&g_monster.hp);
	str = u8"自機：ADキー：向きを変える";
	ImGui::Text(str.c_str());

	str = u8"砲身：上矢印：上";
	ImGui::Text(str.c_str());
	str = u8"砲身：下矢印：下";
	ImGui::Text(str.c_str());
	
	str = u8"砲台：左矢印：左回転";
	ImGui::Text(str.c_str());
	str = u8"砲台：右矢印：右回転";
	ImGui::Text(str.c_str());

	ImGui::End();

	//座標のDragGui
	ImGui::Begin(u8"座標");
	static float slider1 =0.0f;
	slider1 = g_monster.GetPos().x;
	static char text1[8] = "";

	ImGui::Text("fps: %.2f", &g_monster.hp);
	ImGui::SliderFloat("slider 1", &slider1, -100, 100);

	XMFLOAT3 outputpos = { 0,0,0 };

	outputpos.x = slider1;

	g_monster.SetPos(outputpos);
	ImGui::InputText("textbox 1", text1, sizeof(text1));
	if (ImGui::Button("button 1")) {
		slider1 = 0.0f;
		strcpy(text1, "button 1");
	}

	ImGui::End();
}

//class gurp

void GameRender(uint64_t dt) {

	float col[4] = { 1,0,0,1 };

	// 描画前処理
	DX11BeforeRender(col);

	XMFLOAT4X4 mtx;

	// プロジェクション変換行列取得
	mtx = CCamera::GetInstance()->GetProjectionMatrix();
	DX11SetTransform::GetInstance()->SetTransform(DX11SetTransform::TYPE::PROJECTION, mtx);

	// ビュー変換行列を取得
	mtx = CCamera::GetInstance()->GetCameraMatrix();
	DX11SetTransform::GetInstance()->SetTransform(DX11SetTransform::TYPE::VIEW, mtx);

	//ライティング
	DirectX::XMFLOAT3 eye = CCamera::GetInstance()->GetEye();
	DX11LightUpdate(DirectX::XMFLOAT4(eye.x, eye.y, eye.z, 0));

	// 戦車描画
	/*g_tank.Draw();*/
	g_monster.Draw();

	// imgui 描画
	imguiDraw(imguidebug);

	//implot描画
	//implotDraw(Demo_LinePlots);

	/*GraphUpdata();*/

	// 描画後処理
	DX11AfterRender();
}

void GameDispose() {

	ModelMgr::GetInstance().Finalize();

	imguiExit();
	DX11Uninit();
}