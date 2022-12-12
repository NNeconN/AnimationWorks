#include "implot/implot.h"
#include "imgui/imgui.h"
#include "myimplot.h"
#include "CCamera.h"
#include "AnimationData.h"
//#include "player.h"	//���݃C���N���[�h��h���ׂ�cpp�ɂ����B�ق�Ƃ�h�ɏ����̂�����

CDirectInput directinput;

XMFLOAT3 outputpos = { 0,0,0 };

AnimationData::AnimationData()
{
}

void AnimationData::AnimeData()
{
	if (directinput.GetMouseLButtonCheck() == true)
	{

	}
}

void AnimationData::Demo_DragPoints()
{
	ImGui::BulletText("Click and drag each point.");
	static ImPlotDragToolFlags flags = ImPlotDragToolFlags_None;
	ImPlotAxisFlags ax_flags = ImPlotAxisFlags_LockMin | ImPlotAxisFlags_NoTickMarks;

	//����
	static float t = 0;
	t += ImGui::GetIO().DeltaTime;

	// �A�j���[�V�����Đ��ꏊ
	double frametime = t;

	if (ImGui::CollapsingHeader(u8"���x"))
	{
		ImGui::Text("bbbbb");
		//ImGui::CheckboxFlags("Pos", &flags, ImPlotDragToolFlags_NoCursors); ImGui::SameLine();
		//ImGui::CheckboxFlags("Rot", &flags, ImPlotDragToolFlags_NoFit); ImGui::SameLine();
		//ImGui::CheckboxFlags("Scale", &flags, ImPlotDragToolFlags_NoInputs);
		
		//ImGui::CheckboxFlags("saisei", &flags, ImPlotDragToolFlags_Delayed); //�A�j���[�V�����O���t�Đ��{�^��

		if (ImPlot::BeginPlot("##Bezier", ImVec2(-1, -1), ImPlotFlags_CanvasOnly)) {
			ImPlot::SetupAxes(0, 0, frametime, ax_flags);
			ImPlot::SetupAxesLimits(-5, 60, -0.2, 1);
			static ImPlotPoint P[] = { ImPlotPoint(.0f,.0f), ImPlotPoint(5,0.4),  ImPlotPoint(.0f,.0f),  ImPlotPoint(0.2,0.2) };

			//�v���C���[���W�ƃO���t�̍��W�����L////////////////

		/*	outputpos.x = P[1].x;*/  //�������������牺��lerp����������P1�܂ōs�����㏉���l�ɖ߂�
			/*outputpos.y = P[3].y;*/
			///////////////////////////////////////////////

			dd = lerp(P[0].x, P[1].x, t);
			yy = lerp(P[0].y, P[1].y, t);

			if (P[1].x > t)
			{
				outputpos.x = dd;
				outputpos.y = yy;
			}

			g_monster.SetPos(outputpos); //�v���C���[���W����
			
			// �h���b�N���m�������ƃt���[���̎��ԕ\��
			bool isDragFrameTime = ImPlot::DragLineX(0, &frametime, { 1,1,0,1 });

			if (isDragFrameTime == true)
			{
				t = frametime;
			}

			//if (flags & ImPlotDragToolFlags_Delayed) { //�A�j���[�V�����O���t�Đ�
			//	ImPlot::SetupAxisLimits(ImAxis_X1, t - history, t, ImGuiCond_Always);
			//}

			//ImVec4�_��RGBA
			ImPlot::DragPoint(0, &P[0].x, &P[0].y, ImVec4(1, 0.5f, 0.5f, 1), 4, flags);
			ImPlot::DragPoint(1, &P[1].x, &P[1].y, ImVec4(1, 0.5f, 0.5f, 1), 4, flags);
			//ImPlot::DragPoint(2, &P[2].x, &P[2].y, ImVec4(0, 0.5f, 1, 1), 4, flags);
			//ImPlot::DragPoint(3, &P[3].x, &P[3].y, ImVec4(0, 0.5f, 1, 1), 4, flags);

			//ImVec4����RGBA
			ImPlot::SetNextLineStyle(ImVec4(1, 0.5f, 0.5f, 1));
			ImPlot::PlotLine("##h1", &P[0].x, &P[0].y, 2, 0, 0, sizeof(ImPlotPoint));
		/*	ImPlot::SetNextLineStyle(ImVec4(0, 0.5f, 1, 1));
			ImPlot::PlotLine("##h2", &P[2].x, &P[2].y, 2, 0, 0, sizeof(ImPlotPoint));*/
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

			//ImVec4�_��RGBA
			ImPlot::DragPoint(0, &P[0].x, &P[0].y, ImVec4(1, 0.5f, 0.5f, 1), 4, flags);
			ImPlot::DragPoint(1, &P[1].x, &P[1].y, ImVec4(1, 0.5f, 0.5f, 1), 4, flags);
			ImPlot::DragPoint(2, &P[2].x, &P[2].y, ImVec4(0, 0.5f, 1, 1), 4, flags);
			ImPlot::DragPoint(3, &P[3].x, &P[3].y, ImVec4(0, 0.5f, 1, 1), 4, flags);

			//ImVec4����RGBA
			ImPlot::SetNextLineStyle(ImVec4(1, 0.5f, 0.5f, 1));
			ImPlot::PlotLine("##h1", &P[0].x, &P[0].y, 2, 0, 0, sizeof(ImPlotPoint));
			ImPlot::SetNextLineStyle(ImVec4(0, 0.5f, 1, 1));
			ImPlot::PlotLine("##h2", &P[2].x, &P[2].y, 2, 0, 0, sizeof(ImPlotPoint));
			//ImPlot::SetNextLineStyle(ImVec4(0, 0.9f, 0, 1), 2);
			//ImPlot::PlotLine("##bez", &B[0].x, &B[0].y, 100, 0, 0, sizeof(ImPlotPoint));

			ImPlot::EndPlot();
		}
	}

	//�`�F�b�N����ƑI��ł�O���t�̊g��k�����ł���
	if (flags & ImPlotDragToolFlags_NoInputs)
	{
		if (ImPlot::BeginPlot("##Bezier", ImVec2(-1, 0), ImPlotFlags_CanvasOnly)) {
			ImPlot::SetupAxes(0, 0, ax_flags, ax_flags);
			ImPlot::SetupAxesLimits(0, 1, 0, 1);

			ImPlot::EndPlot();
		}
	}
}