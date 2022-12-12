#pragma once
#include "player.h"
#include "CDirectInput.h"

#include <vector>

class AnimationData
{
public:
	AnimationData(); //コンストラクタ

	void AnimeData();

	//線形補間
	float lerp(float start, float end, float t) {
		return start + t * (end - start);
	}

	void Demo_DragPoints();

public:
	std::vector<int> AnimetionKey{}; //アニメーションキー

	Monster g_monster;
private:
	float yy;
	float dd;
};