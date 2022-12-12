#include <cinttypes>

#include "dx11util.h"
#include "CModel.h"
#include "CCamera.h"
#include "DX11Settransform.h"
#include "dx11mathutil.h"
#include "Application.h"
#include "CDirectInput.h"
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
#include "player.h"	//相互インクルードを防ぐ為にcppにかく。ほんとはhに書くのがいい
#include "AnimationData.h"
#include "nikoniko.h"

Monster g_monster;
AnimationData g_anime;
Nikoniko g_nikoniko;

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

ImVec4 RandomColor() {
	ImVec4 col;
	col.x = RandomRange(0.0f, 1.0f);
	col.y = RandomRange(0.0f, 1.0f);
	col.z = RandomRange(0.0f, 1.0f);
	col.w = 1.0f;
	return col;
}

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
	//g_nikoniko.Init();

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
	/*g_nikoniko.Update();*/
}

//void Demo_DragPoints() {
//	// マウス座標の取得
//	POINT po;
//	GetCursorPos(&po);
//
//	ImGui::BulletText("Click and drag each point.");
//	static ImPlotDragToolFlags flags = ImPlotDragToolFlags_None;
//	ImGui::CheckboxFlags("Pos", &flags, ImPlotDragToolFlags_NoCursors); ImGui::SameLine();
//	ImGui::CheckboxFlags("Rot", &flags, ImPlotDragToolFlags_NoFit); ImGui::SameLine();
//	ImGui::CheckboxFlags("Scale", &flags, ImPlotDragToolFlags_NoInputs);
//	ImPlotAxisFlags ax_flags = ImPlotAxisFlags_LockMin | ImPlotAxisFlags_NoTickMarks;
//
//	static float t = 0;
//	t += ImGui::GetIO().DeltaTime;
//
//	static float history = 10.0f;
//	ImGui::SliderFloat(u8"速度", &history, 1, 30, "%.1f s");
//
//	if (flags & ImPlotDragToolFlags_NoCursors)
//	{
//		ImGui::CheckboxFlags("saisei", &flags, ImPlotDragToolFlags_Delayed); //アニメーショングラフ再生ボタン
//
//		if (ImPlot::BeginPlot("##Bezier", ImVec2(-1, -1), ImPlotFlags_CanvasOnly)) {
//			ImPlot::SetupAxes(0, 0, ax_flags, ax_flags);
//			ImPlot::SetupAxesLimits(-5, 60, 0, 1);
//			static ImPlotPoint P[] = { ImPlotPoint(.0f,.0f), ImPlotPoint(g_monster.GetPos().x,0.4),  ImPlotPoint(.0f,.0f),  ImPlotPoint(0.2,0.2) };
//			 アニメーション再生場所
//			double frametime = t;
//
//			 ドラック検知初期化とフレームの時間表示
//			bool isDragFrameTime = ImPlot::DragLineX(0, &frametime, { 1,1,0,1 });
//
//			if (isDragFrameTime == true)
//			{
//				t = frametime;
//			}
//
//			if (flags & ImPlotDragToolFlags_Delayed) { //アニメーショングラフ再生
//				ImPlot::SetupAxisLimits(ImAxis_X1, t - history, t, ImGuiCond_Always);
//			}
//
//			ImVec4点のRGBA
//			ImPlot::DragPoint(0, &P[0].x, &P[0].y, ImVec4(1, 0.5f, 0.5f, 1), 4, flags);
//			ImPlot::DragPoint(1, &P[1].x, &P[1].y, ImVec4(1, 0.5f, 0.5f, 1), 4, flags);
//			ImPlot::DragPoint(2, &P[2].x, &P[2].y, ImVec4(0, 0.5f, 1, 1), 4, flags);
//			ImPlot::DragPoint(3, &P[3].x, &P[3].y, ImVec4(0, 0.5f, 1, 1), 4, flags);
//
//			プレイヤー座標とグラフの座標を共有////////////////
//			XMFLOAT3 outputpos = { 0,0,0 };
//
//			outputpos.x = P[1].x;
//			outputpos.y = P[3].y;
//
//			g_monster.SetPos(outputpos);
//			/////////////////////////////////////////////
//
//			static ImPlotPoint B[100];
//			for (int i = 0; i < 100; ++i) {
//				double t = i / 99.0;
//				double u = 1 - t;
//				double w1 = u * u * u;
//				double w2 = 3 * u * u * t;
//				double w3 = 3 * u * t * t;
//				double w4 = t * t * t;
//				B[i] = ImPlotPoint(w1 * P[0].x + w2 * P[1].x + w3 * P[2].x + w4 * P[3].x, w1 * P[0].y + w2 * P[1].y + w3 * P[2].y + w4 * P[3].y);
//			}
//
//			ImVec4線のRGBA
//			ImPlot::SetNextLineStyle(ImVec4(1, 0.5f, 0.5f, 1));
//			ImPlot::PlotLine("##h1", &P[0].x, &P[0].y, 2, 0, 0, sizeof(ImPlotPoint));
//			ImPlot::SetNextLineStyle(ImVec4(0, 0.5f, 1, 1));
//			ImPlot::PlotLine("##h2", &P[2].x, &P[2].y, 2, 0, 0, sizeof(ImPlotPoint));
//			ImPlot::SetNextLineStyle(ImVec4(0, 0.9f, 0, 1), 2);
//			ImPlot::PlotLine("##bez", &B[0].x, &B[0].y, 100, 0, 0, sizeof(ImPlotPoint));
//
//			ImPlot::EndPlot();
//		}
//	}
//
//	if (flags & ImPlotDragToolFlags_NoFit)
//	{
//		if (ImPlot::BeginPlot("##Bezier", ImVec2(-1, 0), ImPlotFlags_CanvasOnly)) {
//			ImPlot::SetupAxes(0, 0, ax_flags, ax_flags);
//			ImPlot::SetupAxesLimits(0, 1, 0, 1);
//			static ImPlotPoint P[] = { ImPlotPoint(.0f,.0f), ImPlotPoint(0.2,0.4),  ImPlotPoint(.0f,.0f),  ImPlotPoint(0.2,0.2) };
//
//			ImVec4点のRGBA
//			ImPlot::DragPoint(0, &P[0].x, &P[0].y, ImVec4(1, 0.5f, 0.5f, 1), 4, flags);
//			ImPlot::DragPoint(1, &P[1].x, &P[1].y, ImVec4(1, 0.5f, 0.5f, 1), 4, flags);
//			ImPlot::DragPoint(2, &P[2].x, &P[2].y, ImVec4(0, 0.5f, 1, 1), 4, flags);
//			ImPlot::DragPoint(3, &P[3].x, &P[3].y, ImVec4(0, 0.5f, 1, 1), 4, flags);
//
//			static ImPlotPoint B[100];
//			for (int i = 0; i < 100; ++i) {
//				double t = i / 99.0;
//				double u = 1 - t;
//				double w1 = u * u * u;
//				double w2 = 3 * u * u * t;
//				double w3 = 3 * u * t * t;
//				double w4 = t * t * t;
//				B[i] = ImPlotPoint(w1 * P[0].x + w2 * P[1].x + w3 * P[2].x + w4 * P[3].x, w1 * P[0].y + w2 * P[1].y + w3 * P[2].y + w4 * P[3].y);
//			}
//
//			ImVec4線のRGBA
//			ImPlot::SetNextLineStyle(ImVec4(1, 0.5f, 0.5f, 1));
//			ImPlot::PlotLine("##h1", &P[0].x, &P[0].y, 2, 0, 0, sizeof(ImPlotPoint));
//			ImPlot::SetNextLineStyle(ImVec4(0, 0.5f, 1, 1));
//			ImPlot::PlotLine("##h2", &P[2].x, &P[2].y, 2, 0, 0, sizeof(ImPlotPoint));
//			ImPlot::SetNextLineStyle(ImVec4(0, 0.9f, 0, 1), 2);
//			ImPlot::PlotLine("##bez", &B[0].x, &B[0].y, 100, 0, 0, sizeof(ImPlotPoint));
//
//			ImPlot::EndPlot();
//		}
//	}
//
//	チェックすると選んでるグラフの拡大縮小ができる
//	if (flags & ImPlotDragToolFlags_NoInputs)
//	{
//		if (ImPlot::BeginPlot("##Bezier", ImVec2(-1, 0), ImPlotFlags_CanvasOnly)) {
//			ImPlot::SetupAxes(0, 0, ax_flags, ax_flags);
//			ImPlot::SetupAxesLimits(0, 1, 0, 1);
//
//			ImPlot::EndPlot();
//		}
//	}
//}

//void Demo_RealtimePlots() {
//	ImGui::BulletText("Move your mouse to change the data!");
//	ImGui::BulletText("This example assumes 60 FPS. Higher FPS requires larger buffer size.");
//	static ScrollingBuffer sdata1, sdata2;
//	static RollingBuffer   rdata1, rdata2;
//	ImVec2 mouse = ImGui::GetMousePos();
//	static float t = 0;
//	t += ImGui::GetIO().DeltaTime;
//
//	static float history = 10.0f;
//	ImGui::SliderFloat("History", &history, 1, 30, "%.1f s");
//	rdata1.Span = history;
//	rdata2.Span = history;
//
//	static ImPlotAxisFlags flags = ImPlotAxisFlags_NoTickLabels;
//
//	if (ImPlot::BeginPlot("##Scrolling", ImVec2(-1, 150))) {
//		ImPlot::SetupAxes(NULL, NULL, flags, flags);
//		ImPlot::SetupAxisLimits(ImAxis_X1, t - history, t, ImGuiCond_Always);
//		ImPlot::SetupAxisLimits(ImAxis_Y1, 0, 1);
//		ImPlot::SetNextFillStyle(IMPLOT_AUTO_COL, 0.5f);
//		ImPlot::EndPlot();
//	}
//	if (ImPlot::BeginPlot("##Rolling", ImVec2(-1, 150))) {
//		ImPlot::SetupAxes(NULL, NULL, flags, flags);
//		ImPlot::SetupAxisLimits(ImAxis_X1, 0, history, ImGuiCond_Always);
//		ImPlot::SetupAxisLimits(ImAxis_Y1, 0, 1);
//		ImPlot::EndPlot();
//	}
//}

//void ShowDemo_DragAndDrop() {
//	/*ImGui::BulletText("Drag/drop items from the left column.");
//	ImGui::BulletText("Drag/drop items between plots.");
//	ImGui::Indent();
//	ImGui::BulletText("Plot 1 Targets: Plot, Y-Axes, Legend");
//	ImGui::BulletText("Plot 1 Sources: Legend Item Labels");
//	ImGui::BulletText("Plot 2 Targets: Plot, X-Axis, Y-Axis");
//	ImGui::BulletText("Plot 2 Sources: Plot, X-Axis, Y-Axis (hold Ctrl)");
//	ImGui::Unindent();*/
//
//	// convenience struct to manage DND items; do this however you like
//	struct MyDndItem {
//		int              Idx;
//		int              Plt;
//		ImAxis           Yax;
//		char             Label[16];
//		ImVector<ImVec2> Data;
//		ImVec4           Color;
//		MyDndItem() {
//			static int i = 0;
//			Idx = i++;
//			Plt = 0;
//			Yax = ImAxis_Y1;
//			sprintf(Label, "%02d Hz", Idx + 1);
//			Color = RandomColor();
//			Data.reserve(1001);
//			for (int k = 0; k < 1001; ++k) {
//				float t = k * 1.0f / 999;
//				Data.push_back(ImVec2(t, 0.5f + 0.5f * sinf(2 * 3.14f * t * (Idx + 1))));
//			}
//		}
//		void Reset() { Plt = 0; Yax = ImAxis_Y1; }
//	};
//
//	const int         k_dnd = 20;
//	static MyDndItem  dnd[k_dnd];
//	static MyDndItem* dndx = NULL; // for plot 2
//	static MyDndItem* dndy = NULL; // for plot 2
//
//	// child window to serve as initial source for our DND items
//	//ImGui::BeginChild("DND_LEFT", ImVec2(100, 400));
//	//if (ImGui::Button("Reset Data")) {
//	//	for (int k = 0; k < k_dnd; ++k)
//	//		dnd[k].Reset();
//	//	dndx = dndy = NULL;
//	//}
//	//for (int k = 0; k < k_dnd; ++k) {
//	//	if (dnd[k].Plt > 0)
//	//		continue;
//	//	ImPlot::ItemIcon(dnd[k].Color); ImGui::SameLine();
//	//	ImGui::Selectable(dnd[k].Label, false, 0, ImVec2(100, 0));
//	//	if (ImGui::BeginDragDropSource(ImGuiDragDropFlags_None)) {
//	//		ImGui::SetDragDropPayload("MY_DND", &k, sizeof(int));
//	//		ImPlot::ItemIcon(dnd[k].Color); ImGui::SameLine();
//	//		ImGui::TextUnformatted(dnd[k].Label);
//	//		ImGui::EndDragDropSource();
//	//	}
//	//}
//	//ImGui::EndChild();
//	//if (ImGui::BeginDragDropTarget()) {
//	//	if (const ImGuiPayload* payload = ImGui::AcceptDragDropPayload("MY_DND")) {
//	//		int i = *(int*)payload->Data; dnd[i].Reset();
//	//	}
//	//	ImGui::EndDragDropTarget();
//	//}
//
//	ImGui::SameLine();
//	ImGui::BeginChild("DND_RIGHT", ImVec2(-1, 400));
//	// plot 1 (time series)
//	ImPlotAxisFlags flags = ImPlotAxisFlags_NoTickLabels | ImPlotAxisFlags_NoGridLines;
//	if (ImPlot::BeginPlot("##DND1", ImVec2(-1, 195))) {
//		ImPlot::SetupAxis(ImAxis_X1, NULL, flags | ImPlotAxisFlags_Lock);
//		//ImPlot::SetupAxis(ImAxis_Y1, "[drop here]", flags);
//		//ImPlot::SetupAxis(ImAxis_Y2, "[drop here]", flags | ImPlotAxisFlags_Opposite);
//		//ImPlot::SetupAxis(ImAxis_Y3, "[drop here]", flags | ImPlotAxisFlags_Opposite);
//
//		for (int k = 0; k < k_dnd; ++k) {
//			if (dnd[k].Plt == 1 && dnd[k].Data.size() > 0) {
//				ImPlot::SetAxis(dnd[k].Yax);
//				ImPlot::SetNextLineStyle(dnd[k].Color);
//				ImPlot::PlotLine(dnd[k].Label, &dnd[k].Data[0].x, &dnd[k].Data[0].y, dnd[k].Data.size(), 0, 2 * sizeof(float));
//				// allow legend item labels to be DND sources
//				if (ImPlot::BeginDragDropSourceItem(dnd[k].Label)) {
//					ImGui::SetDragDropPayload("MY_DND", &k, sizeof(int));
//					ImPlot::ItemIcon(dnd[k].Color); ImGui::SameLine();
//					ImGui::TextUnformatted(dnd[k].Label);
//					ImPlot::EndDragDropSource();
//				}
//			}
//		}
//		// allow the main plot area to be a DND target
//		if (ImPlot::BeginDragDropTargetPlot()) {
//			if (const ImGuiPayload* payload = ImGui::AcceptDragDropPayload("MY_DND")) {
//				int i = *(int*)payload->Data; dnd[i].Plt = 1; dnd[i].Yax = ImAxis_Y1;
//			}
//			ImPlot::EndDragDropTarget();
//		}
//		// allow each y-axis to be a DND target
//		for (int y = ImAxis_Y1; y <= ImAxis_Y3; ++y) {
//			if (ImPlot::BeginDragDropTargetAxis(y)) {
//				if (const ImGuiPayload* payload = ImGui::AcceptDragDropPayload("MY_DND")) {
//					int i = *(int*)payload->Data; dnd[i].Plt = 1; dnd[i].Yax = y;
//				}
//				ImPlot::EndDragDropTarget();
//			}
//		}
//		// allow the legend to be a DND target
//		if (ImPlot::BeginDragDropTargetLegend()) {
//			if (const ImGuiPayload* payload = ImGui::AcceptDragDropPayload("MY_DND")) {
//				int i = *(int*)payload->Data; dnd[i].Plt = 1; dnd[i].Yax = ImAxis_Y1;
//			}
//			ImPlot::EndDragDropTarget();
//		}
//		ImPlot::EndPlot();
//	}
//	// plot 2 (Lissajous)
//	if (ImPlot::BeginPlot("##DND2", ImVec2(-1, 195))) {
//		ImPlot::PushStyleColor(ImPlotCol_AxisBg, dndx != NULL ? dndx->Color : ImPlot::GetStyle().Colors[ImPlotCol_AxisBg]);
//		ImPlot::SetupAxis(ImAxis_X1, dndx == NULL ? "[drop here]" : dndx->Label, flags);
//		ImPlot::PushStyleColor(ImPlotCol_AxisBg, dndy != NULL ? dndy->Color : ImPlot::GetStyle().Colors[ImPlotCol_AxisBg]);
//		ImPlot::SetupAxis(ImAxis_Y1, dndy == NULL ? "[drop here]" : dndy->Label, flags);
//		ImPlot::PopStyleColor(2);
//		if (dndx != NULL && dndy != NULL) {
//			ImVec4 mixed((dndx->Color.x + dndy->Color.x) / 2, (dndx->Color.y + dndy->Color.y) / 2, (dndx->Color.z + dndy->Color.z) / 2, (dndx->Color.w + dndy->Color.w) / 2);
//			ImPlot::SetNextLineStyle(mixed);
//			ImPlot::PlotLine("##dndxy", &dndx->Data[0].y, &dndy->Data[0].y, dndx->Data.size(), 0, 2 * sizeof(float));
//		}
//		// allow the x-axis to be a DND target
//		if (ImPlot::BeginDragDropTargetAxis(ImAxis_X1)) {
//			if (const ImGuiPayload* payload = ImGui::AcceptDragDropPayload("MY_DND")) {
//				int i = *(int*)payload->Data; dndx = &dnd[i];
//			}
//			ImPlot::EndDragDropTarget();
//		}
//		// allow the x-axis to be a DND source
//		if (dndx != NULL && ImPlot::BeginDragDropSourceAxis(ImAxis_X1)) {
//			ImGui::SetDragDropPayload("MY_DND", &dndx->Idx, sizeof(int));
//			ImPlot::ItemIcon(dndx->Color); ImGui::SameLine();
//			ImGui::TextUnformatted(dndx->Label);
//			ImPlot::EndDragDropSource();
//		}
//		// allow the y-axis to be a DND target
//		if (ImPlot::BeginDragDropTargetAxis(ImAxis_Y1)) {
//			if (const ImGuiPayload* payload = ImGui::AcceptDragDropPayload("MY_DND")) {
//				int i = *(int*)payload->Data; dndy = &dnd[i];
//			}
//			ImPlot::EndDragDropTarget();
//		}
//		// allow the y-axis to be a DND source
//		if (dndy != NULL && ImPlot::BeginDragDropSourceAxis(ImAxis_Y1)) {
//			ImGui::SetDragDropPayload("MY_DND", &dndy->Idx, sizeof(int));
//			ImPlot::ItemIcon(dndy->Color); ImGui::SameLine();
//			ImGui::TextUnformatted(dndy->Label);
//			ImPlot::EndDragDropSource();
//		}
//		// allow the plot area to be a DND target
//		if (ImPlot::BeginDragDropTargetPlot()) {
//			if (const ImGuiPayload* payload = ImGui::AcceptDragDropPayload("MY_DND")) {
//				int i = *(int*)payload->Data; dndx = dndy = &dnd[i];
//			}
//		}
//		// allow the plot area to be a DND source
//		if (ImPlot::BeginDragDropSourcePlot()) {
//			ImGui::TextUnformatted("Yes, you can\ndrag this!");
//			ImPlot::EndDragDropSource();
//		}
//		ImPlot::EndPlot();
//	}
//	ImGui::EndChild();
//}

// IMGUIウインドウ
void imguidebug() {
	//Demo_DragPoints();
	g_anime.Demo_DragPoints();
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
	static float slider1 = 0.0f;
	static float slider2 = 0.0f;
	slider1 = g_anime.g_monster.GetPos().x;
	slider2 = g_anime.g_monster.GetPos().y;
	static char text1[8] = "";

	//if (CDirectInput::GetInstance().)
	//{

	//}
	ImGui::Text("fps: %.2f", &g_monster.hp);
	ImGui::SliderFloat("slider 1", &slider1, -100, 100);

	DirectX::XMFLOAT3 outputpos = { 0,0,0 };

	outputpos.x = slider1;
	outputpos.y = slider2;

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
	/*g_nikoniko.Draw();*/

	// imgui 描画
	imguiDraw(imguidebug);

	// 描画後処理
	DX11AfterRender();
}

void GameDispose() {

	ModelMgr::GetInstance().Finalize();

	imguiExit();
	DX11Uninit();
}