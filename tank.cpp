#include	<random>
#include	"tank.h"
#include	"drawaxis.h"
#include	"dx11mathutil.h"
#include	"ModelMgr.h"
#include	"CDirectInput.h"
#include	"StageHit.h"

// ��Ԃ̐e�q�֌W�y�я����ʒu�E�����p�x���`�����f�[�^
Tank::TankInitData	Tank::ObjectInitData[] = {
	//   �e							���f���ԍ�						�����ʒu				�����p�x	// ���ӁF���Ȃ炸�q�����e����ɂȂ�Ԃ���
	{ Tank::NONE,				Tank::TANK_CATERPILLAR,			{ 0, 0, 0 },				{ 0, 0, 0 } },	// ��� �L���^�s���[
	{ Tank::TANK_CATERPILLAR,	Tank::TANK_BASE,				{ 0, 0, 0 },				{ 0, 0, 0 } },	// ��� �x�[�X
	{ Tank::TANK_BASE,			Tank::TANK_TOP,					{ 0, 3.82394f, -1.15362f }, { 0, 0, 0 } },	// ��� �C��
	{ Tank::TANK_TOP,			Tank::TANK_BARREL,				{ 0, 0.684f, -3.53283f },	{ 0, 0, 0 } },	// ��� �C�g
	{ Tank::END,				Tank::END,						{ 0, 0, 0 },				{ 0, 0, 0 } },	// �I�[�R�[�h
};

// ���f���t�@�C�������X�g
Tank::TankModelData			Tank::XFileData[] = {
	{ Tank::TANK_CATERPILLAR,	"assets/tank/tank10_cat.x" },				// ��Ԃ̃L���^�s���[
	{ Tank::TANK_BASE,			"assets/tank/tank10_base.x" },				// ��Ԃ̓y��
	{ Tank::TANK_TOP,			"assets/tank/tank10_top.x" },				// ��Ԃ̖C��
	{ Tank::TANK_BARREL,		"assets/tank/tank10_pipe.x" },				// ��Ԃ̖C�g
	{ Tank::END, nullptr }													// �I�[�R�[�h
};

// ���f����ǂݍ��񂾂��ǂ���
bool Tank::m_modelloadflag = false;

bool Tank::Init() {

	bool sts = true;

	// �s�񏉊���
	DX11MtxIdentity(m_mtx);					// ���f����ǂݍ���

	// �ǂݍ��݂��������Ă��Ȃ���Γǂݍ���
	if (Tank::m_modelloadflag == false) {
		// ���f���ǂݍ��݁i��ԗp�j
		for (int i = 0; i < static_cast<int>(Tank::PARTSMAX) - 2; i++) {
			sts = ModelMgr::GetInstance().LoadModel(
				Tank::XFileData[i].XfileName,	// �t�@�C���� 
				"shader/vs.hlsl",				// ���_�V�F�[�_�[
				"shader/ps.hlsl",				// �s�N�Z���V�F�[�_�[
				"assets/tank/");				// �e�N�X�`���̊i�[�t�H���_
			if (!sts) {
				char str[128];
				sprintf_s<128>(str, "%s", Tank::XFileData[i].XfileName);
				MessageBox(nullptr, str, "load error", MB_OK);
			}
		}
		Tank::m_modelloadflag = true;
	}

	// ���f���|�C���^�[���Z�b�g
	for (int i = 0; i < static_cast<int>(Tank::PARTSMAX) - 2; i++) {
		SetModel(ModelMgr::GetInstance().GetModelPtr(XFileData[i].XfileName), i);
	}

	// �v���C���s�񏉊���(�����ʒu)�i�����̂��Ƃ������l�����s����쐬�j
	for (int i = 0; i < static_cast<int>(TANKPARTS::PARTSMAX) - 2; i++) {
		DX11MakeWorldMatrix(m_mtxlocalpose[i], ObjectInitData[i].FirstAngle, ObjectInitData[i].FirstPosition);
	}

	// �e�q�֌W���l�������s����v�Z����
	CaliculateParentChildMtx();					// �e�̍s����|���Z���ăO���[�o���|�[�Y�����

	return sts;
}

void Tank::Draw() {

	// ���f���`��
//	drawaxis(m_mtx, 200, m_pos);

	for (int i = 0; i < static_cast<int>(TANKPARTS::PARTSMAX) - 2; i++) {
		m_models[i]->Draw(m_mtxParentChild[i]);
	}
}

void Tank::UpdateLocalpose() {

	// �e�p�[�c�̉�]�p�x(�O�t���[������̕ψʗ�)
	XMFLOAT3			partsangle[static_cast<int>(TANKPARTS::PARTSMAX)];
	XMFLOAT3			partstrans[static_cast<int>(TANKPARTS::PARTSMAX)];

	// �ǂ̃p�[�c�𓮂�����
	int idx = 0;

	// �p�x�ƈړ��ʂ�������
	for (int i = 0; i < static_cast<int>(TANKPARTS::PARTSMAX); i++) {
		partsangle[i].x = 0.0f;
		partsangle[i].y = 0.0f;
		partsangle[i].z = 0.0f;
		partstrans[i].x = 0.0f;
		partstrans[i].y = 0.0f;
		partstrans[i].z = 0.0f;
	}


	// �L���^�s���𓮂���
//	if (CDirectInput::GetInstance().CheckKeyBuffer(DIK_A)) {
//		idx = TANK_CATERPILLAR;
//		partsangle[idx].y += 1.0f;
//	}

	// �L���^�s���𓮂���
//	if (CDirectInput::GetInstance().CheckKeyBuffer(DIK_D)) {
//		idx = TANK_CATERPILLAR;
//		partsangle[idx].y -= 1.0f;
//	}


	// �p�[�c�̃��[�J���|�[�Y�����߂�ׂ̃L�[����
	// �C�g�𓮂���
	if (CDirectInput::GetInstance().CheckKeyBuffer(DIK_UP)) {
		idx = TANK_BARREL;
		partsangle[idx].x += 1.0f;
	}

	// �C�g�𓮂���
	if (CDirectInput::GetInstance().CheckKeyBuffer(DIK_DOWN)) {
		idx = TANK_BARREL;
		partsangle[idx].x -= 1.0f;
	}

	// �C��𓮂���
	if (CDirectInput::GetInstance().CheckKeyBuffer(DIK_LEFT)) {
		idx = TANK_TOP;
		partsangle[idx].y += 1.0f;
	}

	// �C��𓮂���
	if (CDirectInput::GetInstance().CheckKeyBuffer(DIK_RIGHT)) {
		idx = TANK_TOP;
		partsangle[idx].y -= 1.0f;
	}

	// �p�[�c�̊p�x���[�J���|�[�Y��\���s����v�Z
	XMFLOAT4X4 partsmtx;
	DX11MakeWorldMatrix(partsmtx, partsangle[idx], partstrans[idx]);
	DX11MtxMultiply(m_mtxlocalpose[idx], partsmtx, m_mtxlocalpose[idx]);
}

// �X�V
void Tank::Update() {

	XMFLOAT4 axisX;
	XMFLOAT4 axisY;
	XMFLOAT4 axisZ;

	static bool keyinput = true;

	//�@�{�̂̈ړ�����
	//  X�������o��
	axisX.x = m_mtx._11;
	axisX.y = m_mtx._12;
	axisX.z = m_mtx._13;
	axisX.w = 0.0f;

	// Y�������o��
	axisY.x = m_mtx._21;
	axisY.y = m_mtx._22;
	axisY.z = m_mtx._23;
	axisY.w = 0.0f;

	// Z�������o��
	axisZ.x = m_mtx._31;
	axisZ.y = m_mtx._32;
	axisZ.z = m_mtx._33;
	axisZ.w = 0.0f;

	// �ړ��ʋy�ъp�x���O�ɂ���
	m_speed = 0.0f;
	m_angle.x = m_angle.y = m_angle.z = 0.0f;

	if (CDirectInput::GetInstance().CheckKeyBuffer(DIK_A)) {
		m_angle.y -= 1.0f;
		keyinput = true;
	}

	if (CDirectInput::GetInstance().CheckKeyBuffer(DIK_D)) {
		m_angle.y += 1.0f;
		keyinput = true;
	}

	if (CDirectInput::GetInstance().CheckKeyBuffer(DIK_W)) {
		m_speed = 1.0f;
		keyinput = true;
	}

	if (CDirectInput::GetInstance().CheckKeyBuffer(DIK_S)) {
		m_speed = -1.0f;
		keyinput = true;
	}

	// �L�[���͂��������ꍇ
	if (keyinput) {
		XMFLOAT4 qt;	// �N�I�[�^�j�I��

		// �s�񂩂�N�I�[�^�j�I���𐶐�
		DX11GetQtfromMatrix(m_mtx, qt);

		XMFLOAT4 qtx, qty, qtz;		// �N�I�[�^�j�I��

		// �w�莲��]�̃N�I�[�^�j�I���𐶐�
		DX11QtRotationAxis(qtx, axisX, m_angle.x);
		DX11QtRotationAxis(qty, axisY, m_angle.y);
		DX11QtRotationAxis(qtz, axisZ, m_angle.z);

		// �N�I�[�^�j�I��������
		XMFLOAT4 tempqt1;
		DX11QtMul(tempqt1, qt, qtx);

		XMFLOAT4 tempqt2;
		DX11QtMul(tempqt2, qty, qtz);

		XMFLOAT4 tempqt3;
		DX11QtMul(tempqt3, tempqt1, tempqt2);

		// �N�I�[�^�j�I�����m�[�}���C�Y
		DX11QtNormalize(tempqt3, tempqt3);

		// �N�I�[�^�j�I������s����쐬
		DX11MtxFromQt(m_mtx, tempqt3);
	}

	// Z�������o��
	axisZ.x = m_mtx._31;
	axisZ.y = m_mtx._32;
	axisZ.z = m_mtx._33;
	axisZ.w = 0.0f;

	// �ʒu���X�V
	m_pos.x += axisZ.x*m_speed;
	m_pos.y += axisZ.y*m_speed;
	m_pos.z += axisZ.z*m_speed;

	m_mtx._41 = m_pos.x;
	m_mtx._42 = m_pos.y;					
	m_mtx._43 = m_pos.z;

	// ���[�J���|�[�Y���X�V����
	UpdateLocalpose();

	// �e�q�֌W���l�������s����v�Z����
	CaliculateParentChildMtx();

	keyinput = false;
}

void Tank::Finalize() {

}

void Tank::CaliculateParentChildMtx() {

	// ��Ԃ̐e�̃L���^�s���ɍs����Z�b�g
//	m_mtxlocalpose[TANK_CATERPILLAR] = m_mtx;

/*
	// �e�q�֌W���l�������s������
	for (int i = 0; i < static_cast<int>(TANKPARTS::PARTSMAX) - 2; i++) {
		m_mtxParentChild[i] = m_mtxlocalpose[i];
		for (int j = static_cast<int>(ObjectInitData[i].ParentObjectNo);
			j != static_cast<int>(TANKPARTS::NONE);
			j = static_cast<int>(ObjectInitData[j].ParentObjectNo)) {

			DX11MtxMultiply(m_mtxParentChild[i], m_mtxParentChild[i], m_mtxlocalpose[j]);
		}
	}
*/

	// ���[�J���|�[�Y��e�����Ɋ|���Ă���


	m_mtxlocalpose[Tank::TANK_CATERPILLAR] = m_mtx;

	// �L���^�s��
	m_mtxParentChild[Tank::TANK_CATERPILLAR] = m_mtxlocalpose[Tank::TANK_CATERPILLAR];

	// �{��
	DX11MtxMultiply(m_mtxParentChild[Tank::TANK_BASE], m_mtxlocalpose[Tank::TANK_BASE], m_mtxlocalpose[Tank::TANK_CATERPILLAR]);

	// �C��
	DX11MtxMultiply(m_mtxParentChild[Tank::TANK_TOP], m_mtxlocalpose[Tank::TANK_TOP], m_mtxlocalpose[Tank::TANK_BASE]);
	DX11MtxMultiply(m_mtxParentChild[Tank::TANK_TOP], m_mtxParentChild[Tank::TANK_TOP], m_mtxlocalpose[Tank::TANK_CATERPILLAR]);

	// �C�g
	DX11MtxMultiply(m_mtxParentChild[Tank::TANK_BARREL], m_mtxlocalpose[Tank::TANK_BARREL], m_mtxlocalpose[Tank::TANK_TOP]);
	DX11MtxMultiply(m_mtxParentChild[Tank::TANK_BARREL], m_mtxParentChild[Tank::TANK_BARREL], m_mtxlocalpose[Tank::TANK_BASE]);
	DX11MtxMultiply(m_mtxParentChild[Tank::TANK_BARREL], m_mtxParentChild[Tank::TANK_BARREL], m_mtxlocalpose[Tank::TANK_CATERPILLAR]);

}