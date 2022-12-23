#include	<random>
#include	"player.h"
#include	"drawaxis.h"
#include	"dx11mathutil.h"
#include	"ModelMgr.h"
#include	"CDirectInput.h"
#include	"StageHit.h"

// �����X�^�[�̐e�q�֌W�y�я����ʒu�E�����p�x���`�����f�[�^
Monster::MonsterInitData	Monster::ObjectInitData[] = {
	// �e					���f���ԍ�				�����ʒu		�����p�x 
	// ���ӁF���Ȃ炸�q�����e����ɂȂ�Ԃ���
	{ MONSTERPARTS::NONE, MONSTERPARTS::HIP, {0.0f, 0.0f, 0.0f}, {0,0,0}, },
	{ MONSTERPARTS::HIP, MONSTERPARTS::BODY, {0.0f, 1.3f, -0.4f}, {0,0,0}, },
	{ MONSTERPARTS::BODY, MONSTERPARTS::HEAD, {0.0f, 1.85f, -0.55f}, {0,0,0}, },
	{ MONSTERPARTS::BODY, MONSTERPARTS::ARMR0, {-1.8f, 1.35f, -0.3f}, {0,0,0}, },
	{ MONSTERPARTS::BODY, MONSTERPARTS::ARML0, {1.8f, 1.35f, -0.3f}, {0,0,0}, },
	{ MONSTERPARTS::HIP, MONSTERPARTS::LEGR0, {-1.0f, -0.6f, 0.45f}, {0,0,0}, },
	{ MONSTERPARTS::HIP, MONSTERPARTS::LEGL0, { 1.0f, -0.6f, 0.45f}, {0,0,0}, },
	{ MONSTERPARTS::ARMR0, MONSTERPARTS::ARMR1, {-1.18f, -1.27f, 0.7f}, {0,0,0}, },
	{ MONSTERPARTS::ARML0, MONSTERPARTS::ARML1, { 1.18f, -1.27f, 0.7f}, {0,0,0}, },
	{ MONSTERPARTS::LEGR0, MONSTERPARTS::LEGR1, {-1.17f, -2.3f, -1.26f}, {0,0,0}, },
	{ MONSTERPARTS::LEGL0, MONSTERPARTS::LEGL1, { 1.17f, -2.3f, -1.26f}, {0,0,0}, },
	{ MONSTERPARTS::BODY, MONSTERPARTS::WINGR0, { 0.1f, 1.17f, 0.0f}, {0,0,0}, },
	{ MONSTERPARTS::BODY, MONSTERPARTS::WINGL0, {-0.1f, 1.17f, 0.0f}, {0,0,0}, },
	{ MONSTERPARTS::WINGR0, MONSTERPARTS::WINGR1, {-2.48f, 4.36f, 1.58f}, {0,0,0}, },
	{ MONSTERPARTS::WINGL0, MONSTERPARTS::WINGL1, { 2.48f, 4.36f, 1.58f}, {0,0,0}, },
	{ MONSTERPARTS::HIP, MONSTERPARTS::TAIL0 , { 0.0f, 0.0f, 0.0f }, {0,0,0}, },
	{ MONSTERPARTS::END, MONSTERPARTS::END, { 0.0f, 0.0f, 0.0f }, { 0,0,0 } } // �I��
};
// ���f���t�@�C�������X�g
Monster::MonsterModelData			Monster::XFileData[] = {
	{MONSTERPARTS::HIP, "assets/model/Char/E2/e2_hip.x"},
	{MONSTERPARTS::BODY, "assets/model/Char/E2/e2_body.x"},
	{MONSTERPARTS::HEAD, "assets/model/Char/E2/e2_head.x"},
	{MONSTERPARTS::ARMR0,"assets/model/Char/E2/e2_armr0.x"},
	{MONSTERPARTS::ARML0,"assets/model/Char/E2/e2_arml0.x"},
	{MONSTERPARTS::LEGR0,"assets/model/Char/E2/e2_legr0.x"},
	{MONSTERPARTS::LEGL0,"assets/model/Char/E2/e2_legl0.x"},
	{MONSTERPARTS::ARMR1,"assets/model/Char/E2/e2_armr1.x"},
	{MONSTERPARTS::ARML1,"assets/model/Char/E2/e2_arml1.x"},
	{MONSTERPARTS::LEGR1,"assets/model/Char/E2/e2_legr1.x"},
	{MONSTERPARTS::LEGL1,"assets/model/Char/E2/e2_legl1.x"},
	{MONSTERPARTS::WINGR0,"assets/model/Char/E2/e2_wingr0.x"},
	{MONSTERPARTS::WINGL0,"assets/model/Char/E2/e2_wingl0.x"},
	{MONSTERPARTS::WINGR1,"assets/model/Char/E2/e2_wingr1.x"},
	{MONSTERPARTS::WINGL1,"assets/model/Char/E2/e2_wingl1.x"},
	{MONSTERPARTS::TAIL0 ,"assets/model/Char/E2/e2_tail0.x"},
	{MONSTERPARTS::END,nullptr }
};

// ���f����ǂݍ��񂾂��ǂ���
bool Monster::m_modelloadflag = false;

bool Monster::Init()
{
	bool sts = true;

	// �s�񏉊���
	DX11MtxIdentity(m_mtx);					// ���f����ǂݍ���

	// �ǂݍ��݂��������Ă��Ȃ���Γǂݍ���
	if (Monster::m_modelloadflag == false) {
		// ���f���ǂݍ��݁i�����X�^�[�p�j
		for (int i = 0; i < static_cast<int>(Monster::PARTSMAX) - 2; i++) {
			sts = ModelMgr::GetInstance().LoadModel(
				Monster::XFileData[i].XfileName,	// �t�@�C���� 
				"shader/vs.hlsl",				// ���_�V�F�[�_�[
				"shader/ps.hlsl",				// �s�N�Z���V�F�[�_�[
				"assets/Char/E2/");				// �e�N�X�`���̊i�[�t�H���_
			if (!sts) {
				char str[128];
				sprintf_s<128>(str, "%s", Monster::XFileData[i].XfileName);
				MessageBox(nullptr, str, "load error", MB_OK);
			}
		}
		Monster::m_modelloadflag = true;
	}

	// ���f���|�C���^�[���Z�b�g
	for (int i = 0; i < static_cast<int>(Monster::PARTSMAX) - 2; i++) {
		SetModel(ModelMgr::GetInstance().GetModelPtr(XFileData[i].XfileName), i);
	}

	// �v���C���s�񏉊���(�����ʒu)�i�����̂��Ƃ������l�����s����쐬�j
	for (int i = 0; i < static_cast<int>(MONSTERPARTS::PARTSMAX) - 2; i++) {
		DX11MakeWorldMatrix(m_mtxlocalpose[i], ObjectInitData[i].FirstAngle, ObjectInitData[i].FirstPosition);
	}

	// �e�q�֌W���l�������s����v�Z����
	CaliculateParentChildMtx();					// �e�̍s����|���Z���ăO���[�o���|�[�Y�����

	return sts;
}

void Monster::Draw()
{
	// ���f���`��
	// drawaxis(m_mtx, 200, m_pos);

	for (int i = 0; i < static_cast<int>(MONSTERPARTS::PARTSMAX) - 2; i++) {
		m_models[i]->Draw(m_mtxParentChild[i]);
	}
}

void Monster::Update()
{

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
		m_angle.y -= 2.0f;
		keyinput = true;
	}

	if (CDirectInput::GetInstance().CheckKeyBuffer(DIK_D)) {
		m_angle.y += 2.0f;
		keyinput = true;
	}

	if (CDirectInput::GetInstance().CheckKeyBuffer(DIK_S)) {
		m_speed = 0.8f;
		keyinput = true;
	}

	if (CDirectInput::GetInstance().CheckKeyBuffer(DIK_W)) {
		m_speed = -0.8f;
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
	m_pos.x += axisZ.x * m_speed;
	m_pos.y += axisZ.y * m_speed;
	m_pos.z += axisZ.z * m_speed;

	m_mtx._41 = m_pos.x;
	m_mtx._42 = m_pos.y;
	m_mtx._43 = m_pos.z;

	// ���[�J���|�[�Y���X�V����
	UpdateLocalpose();

	// �e�q�֌W���l�������s����v�Z����
	CaliculateParentChildMtx();

	keyinput = false;
}

void Monster::Finalize()
{
}

void Monster::UpdateLocalpose()
{

	// �e�p�[�c�̉�]�p�x(�O�t���[������̕ψʗ�)
	XMFLOAT3 partsangle[static_cast<int>(MONSTERPARTS::PARTSMAX)];
	XMFLOAT3 partstrans[static_cast<int>(MONSTERPARTS::PARTSMAX)];

	// �ǂ̃p�[�c�𓮂�����
	int idx = 0;

	// �p�x�ƈړ��ʂ�������
	for (int i = 0; i < static_cast<int>(MONSTERPARTS::PARTSMAX); i++) {
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
	// ���𓮂���
	if (CDirectInput::GetInstance().CheckKeyBuffer(DIK_UP)) {
		idx = HIP;
		partsangle[idx].x += 1.0f;
	}

	// ���𓮂���
	if (CDirectInput::GetInstance().CheckKeyBuffer(DIK_DOWN)) {
		idx = HIP;
		partsangle[idx].x -= 1.0f;
	}

	// ���𓮂���
	if (CDirectInput::GetInstance().CheckKeyBuffer(DIK_RIGHT)) {
		idx = HIP;
		partsangle[idx].y += 1.0f;
	}

	// ���𓮂���
	if (CDirectInput::GetInstance().CheckKeyBuffer(DIK_LEFT)) {
		idx = HIP;
		partsangle[idx].y -= 1.0f;
	}


	// �p�[�c�̊p�x���[�J���|�[�Y��\���s����v�Z
	XMFLOAT4X4 partsmtx;
	DX11MakeWorldMatrix(partsmtx, partsangle[idx], partstrans[idx]);
	DX11MtxMultiply(m_mtxlocalpose[idx], partsmtx, m_mtxlocalpose[idx]);
}

void Monster::CaliculateParentChildMtx()
{
	// ���[�J���|�[�Y��e�����Ɋ|���Ă���


	m_mtxlocalpose[MONSTERPARTS::HIP] = m_mtx;

	// �L���^�s��
	m_mtxParentChild[MONSTERPARTS::HIP] = m_mtxlocalpose[MONSTERPARTS::HIP];

	// �{��
	DX11MtxMultiply(m_mtxParentChild[MONSTERPARTS::BODY], m_mtxlocalpose[MONSTERPARTS::BODY], m_mtxlocalpose[MONSTERPARTS::HIP]);

	// �C��
	DX11MtxMultiply(m_mtxParentChild[MONSTERPARTS::HEAD], m_mtxlocalpose[MONSTERPARTS::HEAD], m_mtxlocalpose[MONSTERPARTS::BODY]);
	DX11MtxMultiply(m_mtxParentChild[MONSTERPARTS::HEAD], m_mtxParentChild[MONSTERPARTS::HEAD], m_mtxlocalpose[MONSTERPARTS::HIP]);

	// �C�g
	DX11MtxMultiply(m_mtxParentChild[MONSTERPARTS::ARMR0], m_mtxlocalpose[MONSTERPARTS::ARMR0], m_mtxlocalpose[MONSTERPARTS::BODY]);
	DX11MtxMultiply(m_mtxParentChild[MONSTERPARTS::ARMR0], m_mtxParentChild[MONSTERPARTS::ARMR0], m_mtxlocalpose[MONSTERPARTS::HIP]);

	DX11MtxMultiply(m_mtxParentChild[MONSTERPARTS::ARML0], m_mtxlocalpose[MONSTERPARTS::ARML0], m_mtxlocalpose[MONSTERPARTS::BODY]);
	DX11MtxMultiply(m_mtxParentChild[MONSTERPARTS::ARML0], m_mtxParentChild[MONSTERPARTS::ARML0], m_mtxlocalpose[MONSTERPARTS::HIP]);

	DX11MtxMultiply(m_mtxParentChild[MONSTERPARTS::LEGR0], m_mtxlocalpose[MONSTERPARTS::LEGR0], m_mtxlocalpose[MONSTERPARTS::HIP]);

	DX11MtxMultiply(m_mtxParentChild[MONSTERPARTS::LEGL0], m_mtxlocalpose[MONSTERPARTS::LEGL0], m_mtxlocalpose[MONSTERPARTS::HIP]);

	DX11MtxMultiply(m_mtxParentChild[MONSTERPARTS::ARMR1], m_mtxlocalpose[MONSTERPARTS::ARMR1], m_mtxlocalpose[MONSTERPARTS::ARMR0]);
	DX11MtxMultiply(m_mtxParentChild[MONSTERPARTS::ARMR1], m_mtxParentChild[MONSTERPARTS::ARMR1], m_mtxlocalpose[MONSTERPARTS::BODY]);
	DX11MtxMultiply(m_mtxParentChild[MONSTERPARTS::ARMR1], m_mtxParentChild[MONSTERPARTS::ARMR1], m_mtxlocalpose[MONSTERPARTS::HIP]);

	DX11MtxMultiply(m_mtxParentChild[MONSTERPARTS::ARML1], m_mtxlocalpose[MONSTERPARTS::ARML1], m_mtxlocalpose[MONSTERPARTS::ARML0]);
	DX11MtxMultiply(m_mtxParentChild[MONSTERPARTS::ARML1], m_mtxParentChild[MONSTERPARTS::ARML1], m_mtxlocalpose[MONSTERPARTS::BODY]);
	DX11MtxMultiply(m_mtxParentChild[MONSTERPARTS::ARML1], m_mtxParentChild[MONSTERPARTS::ARML1], m_mtxlocalpose[MONSTERPARTS::HIP]);

	DX11MtxMultiply(m_mtxParentChild[MONSTERPARTS::LEGR1], m_mtxlocalpose[MONSTERPARTS::LEGR1], m_mtxlocalpose[MONSTERPARTS::LEGR0]);
	DX11MtxMultiply(m_mtxParentChild[MONSTERPARTS::LEGR1], m_mtxParentChild[MONSTERPARTS::LEGR1], m_mtxlocalpose[MONSTERPARTS::HIP]);

	DX11MtxMultiply(m_mtxParentChild[MONSTERPARTS::LEGL1], m_mtxlocalpose[MONSTERPARTS::LEGL1], m_mtxlocalpose[MONSTERPARTS::LEGL0]);
	DX11MtxMultiply(m_mtxParentChild[MONSTERPARTS::LEGL1], m_mtxParentChild[MONSTERPARTS::LEGL1], m_mtxlocalpose[MONSTERPARTS::HIP]);

	DX11MtxMultiply(m_mtxParentChild[MONSTERPARTS::WINGR0], m_mtxlocalpose[MONSTERPARTS::WINGR0], m_mtxlocalpose[MONSTERPARTS::BODY]);
	DX11MtxMultiply(m_mtxParentChild[MONSTERPARTS::WINGR0], m_mtxParentChild[MONSTERPARTS::WINGR0], m_mtxlocalpose[MONSTERPARTS::HIP]);

	DX11MtxMultiply(m_mtxParentChild[MONSTERPARTS::WINGL0], m_mtxlocalpose[MONSTERPARTS::WINGL0], m_mtxlocalpose[MONSTERPARTS::BODY]);
	DX11MtxMultiply(m_mtxParentChild[MONSTERPARTS::WINGL0], m_mtxParentChild[MONSTERPARTS::WINGL0], m_mtxlocalpose[MONSTERPARTS::HIP]);

	DX11MtxMultiply(m_mtxParentChild[MONSTERPARTS::WINGR1], m_mtxlocalpose[MONSTERPARTS::WINGR1], m_mtxlocalpose[MONSTERPARTS::WINGR0]);
	DX11MtxMultiply(m_mtxParentChild[MONSTERPARTS::WINGR1], m_mtxParentChild[MONSTERPARTS::WINGR1], m_mtxlocalpose[MONSTERPARTS::BODY]);
	DX11MtxMultiply(m_mtxParentChild[MONSTERPARTS::WINGR1], m_mtxParentChild[MONSTERPARTS::WINGR1], m_mtxlocalpose[MONSTERPARTS::HIP]);

	DX11MtxMultiply(m_mtxParentChild[MONSTERPARTS::WINGL1], m_mtxlocalpose[MONSTERPARTS::WINGL1], m_mtxlocalpose[MONSTERPARTS::WINGL0]);
	DX11MtxMultiply(m_mtxParentChild[MONSTERPARTS::WINGL1], m_mtxParentChild[MONSTERPARTS::WINGL1], m_mtxlocalpose[MONSTERPARTS::BODY]);
	DX11MtxMultiply(m_mtxParentChild[MONSTERPARTS::WINGL1], m_mtxParentChild[MONSTERPARTS::WINGL1], m_mtxlocalpose[MONSTERPARTS::HIP]);

	DX11MtxMultiply(m_mtxParentChild[MONSTERPARTS::TAIL0], m_mtxlocalpose[MONSTERPARTS::TAIL0], m_mtxlocalpose[MONSTERPARTS::HIP]);
}

