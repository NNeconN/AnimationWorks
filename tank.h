#pragma once
#include	"gameobject.h"
#include	"CModel.h"

class Tank :public GameObject {
public:
	// �I�u�W�F�N�g��
	enum TANKPARTS {
		TANK_CATERPILLAR,			// �L���^�s��
		TANK_BASE,					// �{��
		TANK_TOP,					// �C��
		TANK_BARREL,				// �C�g
		NONE,						// �Ȃ�
		END,						// �I��
		PARTSMAX					// �p�[�c�̍ő吔
	};

	// �\���̌^�^�O
	struct	TankInitData {
		Tank::TANKPARTS		ParentObjectNo;		// �e�I�u�W�F�N�g�m��
		Tank::TANKPARTS		ModelNo;			// ���f���ԍ�
		DirectX::XMFLOAT3	FirstPosition;		// �ŏ��̈ʒu
		DirectX::XMFLOAT3	FirstAngle;			// �ŏ��̊p�x
	};

	// �^���N�̃��f�������X�g
	struct	TankModelData {
		Tank::TANKPARTS		ModelNo;					// ���f���ԍ�
		const char*			XfileName;					// �w�t�@�C����
	};

	// �����z�u�f�[�^
	static TankInitData	ObjectInitData[];

	// ���f���t�@�C�������X�g
	static TankModelData			XFileData[];

	// ���f���Z�b�g
	void SetModel(CModel* p,int idx) {
		m_models[idx] = p;
	}

	bool Init();
	void Draw();
	void Update();
	void Finalize();

private:
	void UpdateLocalpose();				// ���[�J���|�[�Y���X�V����
	void CaliculateParentChildMtx();	// �e�q�֌W���l�������s����쐬
	static bool m_modelloadflag;		// ���f����ǂݍ��񂾂��ǂ���
	CModel*		m_models[TANKPARTS::PARTSMAX];
	DirectX::XMFLOAT4X4			m_mtxlocalpose[PARTSMAX];	// �����̂��Ƃ������l�����s��
	DirectX::XMFLOAT4X4			m_mtxParentChild[PARTSMAX];	// �e�q�֌W���l�������s��

	float						m_speed = 0.0f;				// �X�s�[�h
	DirectX::XMFLOAT3			m_angle;					// ��]�p
};