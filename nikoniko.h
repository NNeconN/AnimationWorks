#pragma once
#include "gameobject.h"
#include "CModel.h"

class Nikoniko :public GameObject {
public:
	// �I�u�W�F�N�g��
	enum Nikonikos {
		NikoModel, // �L�����N�^�[
		Maxobj
	};

	// �\���̌^�^�O(�e�q�֌W�Ə����z�u�f�[�^)
	struct NikonikoInitData {
		Nikoniko::Nikonikos ParentObjectNo; // �e�I�u�W�F�N�g�m��
		Nikoniko::Nikonikos ModelNo; // ���f���ԍ�
		DirectX::XMFLOAT3 FirstPosition; // �ŏ��̈ʒu
		DirectX::XMFLOAT3 FirstAngle; // �ŏ��̊p�x

	};

	// �����X�^�[�̃��f�������X�g
	struct NikonikoModelData {
		Nikoniko::Nikonikos ModelNo; // ���f���ԍ�
		const char* XfileName; // �w�t�@�C����

	};

	// �����z�u�f�[�^
	static NikonikoInitData ObjectInitData[];

	// ���f���t�@�C�������X�g
	static NikonikoModelData XFileData[];

	// ���f���Z�b�g
	void SetModel(CModel* p, int idx) {
		m_models = p;

	}

	void SetPos(DirectX::XMFLOAT3 input)
	{

		m_pos = input;
	}

	bool Init();
	void Draw();
	void Update();
	void Finalize();

private:
	void UpdateLocalpose(); // ���[�J���|�[�Y���X�V����
	void CaliculateParentChildMtx(); // �e�q�֌W���l�������s����쐬
	static bool m_modelloadflag; // ���f����ǂݍ��񂾂��ǂ���
	CModel* m_models;
	DirectX::XMFLOAT4X4 m_mtxlocalpose;
	// �e�q�֌W���l�������s��

	float m_speed = 0.0f; // �X�s�[�h
	DirectX::XMFLOAT3 m_angle; // ��]�p

public:
	float hp = 100;
};