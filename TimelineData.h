#pragma once

class Timeline
{
public:
	Timeline();
	void TrackData(); //�^�C�����C����̃g���b�N��� �^�C�����C����ł̃t�@�C���f�[�^�ǂݍ��݂Ȃ�

	void Demo_TimelineGraph();
	bool addButton2; //�g���b�N�ǉ��{�^��

private:
	bool addButton; //�g���b�N�ǉ��{�^��

	double frametime;
};