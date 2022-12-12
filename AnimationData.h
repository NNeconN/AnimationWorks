#pragma once
#include "player.h"
#include "CDirectInput.h"

#include <vector>

class AnimationData
{
public:
	AnimationData(); //�R���X�g���N�^

	void AnimeData();

	//���`���
	float lerp(float start, float end, float t) {
		return start + t * (end - start);
	}

	void Demo_DragPoints();

public:
	std::vector<int> AnimetionKey{}; //�A�j���[�V�����L�[

	Monster g_monster;
private:
	float yy;
	float dd;
};