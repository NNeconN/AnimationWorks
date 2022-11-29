#include "GraphProcess.h"
#include "player.h" 
#include "ModelMgr.h"
#include "\Users\wajir\Downloads\５９－戦車（平面上の移動）\ソース\38-01-モデル表示 戦車表示 （ループを使わない）\imgui\imgui_internal.h"
#include "ImGuizmo.h"

Monster g_monster;

void Process::GraphInit()
{
	
}

void Process::GraphUpdata()
{

}

void Process::GraphDrow()
{
	g_monster.SetGraph()
}

//XMFlOAT4X4 Process::GraphEditor(XMFLOAT4X4 mtx)
//{
//
//}

//void Demo_DragPoints() {
//	ImGui::BulletText("Click and drag each point.");
//	static ImPlotDragToolFlags flags = ImPlotDragToolFlags_None;
//	ImGui::CheckboxFlags("Pos", &flags, ImPlotDragToolFlags_NoCursors); ImGui::SameLine();
//	ImGui::CheckboxFlags("Rot", &flags, ImPlotDragToolFlags_NoFit); ImGui::SameLine();
//	ImGui::CheckboxFlags("Scale", &flags, ImPlotDragToolFlags_NoInputs);
//	ImPlotAxisFlags ax_flags = ImPlotAxisFlags_LockMax | ImPlotAxisFlags_NoTickMarks;
//	if (flags & ImPlotDragToolFlags_NoCursors)
//	{
//		if (ImPlot::BeginPlot("##Bezier", ImVec2(-1, -1), ImPlotFlags_CanvasOnly)) {
//			ImPlot::SetupAxes(0, 0, ax_flags, ax_flags);
//			ImPlot::SetupAxesLimits(0, 1, 0, 1);
//			static ImPlotPoint p[] = {ImPlotPoint(.0f,.0f), ImPlotPoint(0.2,0.4),  ImPlotPoint(.0f,.0f),  ImPlotPoint(0.2,0.2)}; //頂点座標初期化
//			
//			//static ImPlotPoint B[100];
//			//for (int i = 0; i < 100; ++i) {
//			//	double t = i / 99.0;
//			//	double u = 1 - t;
//			//	double w1 = u * u * u;
//			//	double w2 = 3 * u * u * t;
//			//	double w3 = 3 * u * t * t;
//			//	double w4 = t * t * t;
//			//	B[i] = ImPlotPoint(w1 * P[0].x + w2 * P[1].x + w3 * P[2].x + w4 * P[3].x, w1 * P[0].y + w2 * P[1].y + w3 * P[2].y + w4 * P[3].y);
//			//}
//
//			//ImVec4点のRGBA
//			ImPlot::DragPoint(0, &P[0].x, &P[0].y, ImVec4(1, 0.5f, 0.5f, 1), 4, flags);
//			ImPlot::DragPoint(1, &P[1].x, &P[1].y, ImVec4(1, 0.5f, 0.5f, 1), 4, flags);
//			ImPlot::DragPoint(2, &P[2].x, &P[2].y, ImVec4(0, 0.5f, 1, 1), 4, flags);
//			ImPlot::DragPoint(3, &P[3].x, &P[3].y, ImVec4(0, 0.5f, 1, 1), 4, flags);
//
//			//ImVec4線のRGBA
//			ImPlot::SetNextLineStyle(ImVec4(1, 0.5f, 0.5f, 1));
//			ImPlot::PlotLine("##h1", &P[0].x, &P[0].y, 2, 0, 0, sizeof(ImPlotPoint));
//			ImPlot::SetNextLineStyle(ImVec4(0, 0.5f, 1, 1));
//			ImPlot::PlotLine("##h2", &P[2].x, &P[2].y, 2, 0, 0, sizeof(ImPlotPoint));
//			//ImPlot::SetNextLineStyle(ImVec4(0, 0.9f, 0, 1), 2);
//			//ImPlot::PlotLine("##bez", &B[0].x, &B[0].y, 100, 0, 0, sizeof(ImPlotPoint));
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
//			//ImVec4点のRGBA
//			ImPlot::DragPoint(0, &P[0].x, &P[0].y, ImVec4(1, 0.5f, 0.5f, 1), 4, flags);
//			ImPlot::DragPoint(1, &P[1].x, &P[1].y, ImVec4(1, 0.5f, 0.5f, 1), 4, flags);
//			ImPlot::DragPoint(2, &P[2].x, &P[2].y, ImVec4(0, 0.5f, 1, 1), 4, flags);
//			ImPlot::DragPoint(3, &P[3].x, &P[3].y, ImVec4(0, 0.5f, 1, 1), 4, flags);
//
//			//static ImPlotPoint B[100];
//			//for (int i = 0; i < 100; ++i) {
//			//	double t = i / 99.0;
//			//	double u = 1 - t;
//			//	double w1 = u * u * u;
//			//	double w2 = 3 * u * u * t;
//			//	double w3 = 3 * u * t * t;
//			//	double w4 = t * t * t;
//			//	B[i] = ImPlotPoint(w1 * P[0].x + w2 * P[1].x + w3 * P[2].x + w4 * P[3].x, w1 * P[0].y + w2 * P[1].y + w3 * P[2].y + w4 * P[3].y);
//			//}
//
//			//ImVec4線のRGBA
//			ImPlot::SetNextLineStyle(ImVec4(1, 0.5f, 0.5f, 1));
//			ImPlot::PlotLine("##h1", &P[0].x, &P[0].y, 2, 0, 0, sizeof(ImPlotPoint));
//			ImPlot::SetNextLineStyle(ImVec4(0, 0.5f, 1, 1));
//			ImPlot::PlotLine("##h2", &P[2].x, &P[2].y, 2, 0, 0, sizeof(ImPlotPoint));
//			//ImPlot::SetNextLineStyle(ImVec4(0, 0.9f, 0, 1), 2);
//			//ImPlot::PlotLine("##bez", &B[0].x, &B[0].y, 100, 0, 0, sizeof(ImPlotPoint));
//
//			ImPlot::EndPlot();
//		}
//	}
//
//	if (flags & ImPlotDragToolFlags_NoInputs)
//	{
//		if (ImPlot::BeginPlot("##Bezier", ImVec2(-1, 0), ImPlotFlags_CanvasOnly)) {
//			ImPlot::SetupAxes(0, 0, ax_flags, ax_flags);
//			ImPlot::SetupAxesLimits(0, 1, 0, 1);
//			static ImPlotPoint P[] = { ImPlotPoint(.0f,.0f), ImPlotPoint(0.2,0.4),  ImPlotPoint(.0f,.0f),  ImPlotPoint(0.2,0.2) };
//
//			//ImVec4点のRGBA
//			ImPlot::DragPoint(0, &P[0].x, &P[0].y, ImVec4(1, 0.5f, 0.5f, 1), 4, flags);
//			ImPlot::DragPoint(1, &P[1].x, &P[1].y, ImVec4(1, 0.5f, 0.5f, 1), 4, flags);
//			ImPlot::DragPoint(2, &P[2].x, &P[2].y, ImVec4(0, 0.5f, 1, 1), 4, flags);
//			ImPlot::DragPoint(3, &P[3].x, &P[3].y, ImVec4(0, 0.5f, 1, 1), 4, flags);
//
//			//static ImPlotPoint B[100];
//			//for (int i = 0; i < 100; ++i) {
//			//	double t = i / 99.0;
//			//	double u = 1 - t;
//			//	double w1 = u * u * u;
//			//	double w2 = 3 * u * u * t;
//			//	double w3 = 3 * u * t * t;
//			//	double w4 = t * t * t;
//			//	B[i] = ImPlotPoint(w1 * P[0].x + w2 * P[1].x + w3 * P[2].x + w4 * P[3].x, w1 * P[0].y + w2 * P[1].y + w3 * P[2].y + w4 * P[3].y);
//			//}
//
//			//ImVec4線のRGBA
//			ImPlot::SetNextLineStyle(ImVec4(1, 0.5f, 0.5f, 1));
//			ImPlot::PlotLine("##h1", &P[0].x, &P[0].y, 2, 0, 0, sizeof(ImPlotPoint));
//			ImPlot::SetNextLineStyle(ImVec4(0, 0.5f, 1, 1));
//			ImPlot::PlotLine("##h2", &P[2].x, &P[2].y, 2, 0, 0, sizeof(ImPlotPoint));
//			//ImPlot::SetNextLineStyle(ImVec4(0, 0.9f, 0, 1), 2);
//			//ImPlot::PlotLine("##bez", &B[0].x, &B[0].y, 100, 0, 0, sizeof(ImPlotPoint));
//
//			ImPlot::EndPlot();
//		}
//	}
//}