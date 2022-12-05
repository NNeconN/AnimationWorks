#pragma once
#include "player.h"

class AnimationData
{
public:
	//üŒ`•âŠÔ
	float lerp(float start, float end, float t) {
		return start + t * (end - start);
	}

	void Demo_DragPoints();
private:
	Monster g_Amonster;
};
