#include	<random>
#include	"nikoniko.h"
#include	"drawaxis.h"
#include	"dx11mathutil.h"
#include	"ModelMgr.h"
#include	"CDirectInput.h"
#include	"StageHit.h"

// �����X�^�[�̐e�q�֌W�y�я����ʒu�E�����p�x���`�����f�[�^
Nikoniko::NikonikoInitData	Nikoniko::ObjectInitData[] = {
	// �e					���f���ԍ�				�����ʒu		�����p�x 
	// ���ӁF���Ȃ炸�q�����e����ɂȂ�Ԃ���
	{ Nikonikos::NikoModel, Nikonikos::NikoModel, {0.0f, 0.0f, 0.0f}, {0,0,0}, },
};
// ���f���t�@�C�������X�g
Nikoniko::NikonikoModelData			Nikoniko::XFileData[] = {
	{Nikonikos::NikoModel, "assets/paimon/Texture/paimon.pmx"},
};

// ���f����ǂݍ��񂾂��ǂ���
bool Nikoniko::m_modelloadflag = false;

bool Nikoniko::Init()
{
	bool sts = true;

	// �s�񏉊���
	DX11MtxIdentity(m_mtx);					// ���f����ǂݍ���

	// �ǂݍ��݂��������Ă��Ȃ���Γǂݍ���
	if (Nikoniko::m_modelloadflag == false) {
		// ���f���ǂݍ��݁i�����X�^�[�p�j
			sts = ModelMgr::GetInstance().LoadModel(
				Nikoniko::XFileData[0].XfileName,	// �t�@�C���� 
				"shader/vs.hlsl",				// ���_�V�F�[�_�[
				"shader/ps.hlsl",				// �s�N�Z���V�F�[�_�[
				"assets/paimon/Texture");		// �e�N�X�`���̊i�[�t�H���_
			if (!sts) {
				char str[128];
				sprintf_s<128>(str, "%s", Nikoniko::XFileData[0].XfileName);
				MessageBox(nullptr, str, "load error", MB_OK);
			}

		Nikoniko::m_modelloadflag = true;
	}

	// ���f���|�C���^�[���Z�b�g
	SetModel(ModelMgr::GetInstance().GetModelPtr(XFileData[0].XfileName), 1);

	return sts;
}

void Nikoniko::Draw()
{
	// ���f���`��
	drawaxis(m_mtx, 200, m_pos);
	m_models->Draw(m_mtx);
}

void Nikoniko::Update()
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

	keyinput = false;
}

void Nikoniko::Finalize()
{
}