#include	<memory>
#include	"bullet.h"
#include	"dx11mathutil.h"
#include	"CModel.h"
#include	"CDirectInput.h"
#include	"ModelMgr.h"

constexpr float BULLETSPEED = 5.0f;
constexpr uint32_t BULLETLIFE = 60;

// �e�X�V
void BulletMgr::Update(XMFLOAT4X4 mtx) {

	// �e����
	if (CDirectInput::GetInstance().CheckKeyBufferTrigger(DIK_SPACE)) {

		Fire(mtx);
	}

	// �S�e�X�V
	for (auto& b: m_bullets) {
		b->Update();
	}

	// ����ł�e�폜
	auto it = m_bullets.begin();
	while (it != m_bullets.end()) {

		if ((*it)->isLive() == false) {
			it = m_bullets.erase(it);
		}
		else ++it;
	}
}

// �e�`��
void BulletMgr::Draw() {

	// �S�e�`��
	for (auto& b : m_bullets) {
		b->Draw();
	}
}

// �e����
void BulletMgr::Fire(XMFLOAT4X4 mtx) {

	std::unique_ptr<Bullet> p;

	p = std::make_unique<Bullet>();

	// �e�̏�����
	p->Init();
	p->SetModel(ModelMgr::GetInstance().GetModelPtr("assets/starwars/shot.x"));
	p->SetInitialPos(XMFLOAT3(mtx._41, mtx._42, mtx._43));
	p->SetDirection(mtx);

	// �Ō���ɒe��ǉ�
	m_bullets.emplace_back(std::move(p));
}

bool Bullet::Init() {

	bool sts=true;

	// �s�񏉊���
	DX11MtxIdentity(m_mtx);

	return sts;
}

void Bullet::Draw() {

	// ���f���`��
	if (m_sts == BULLETSTATUS::LIVE) {
		m_pmodel->Draw(m_mtx);
	}
}

void Bullet::Update() {

	m_life--;
	if (m_life > 0) {
		m_pos.x = m_pos.x + m_speed * m_direction.x;
		m_pos.y = m_pos.y + m_speed * m_direction.y;
		m_pos.z = m_pos.z + m_speed * m_direction.z;

		m_mtx._41 = m_pos.x;
		m_mtx._42 = m_pos.y;
		m_mtx._43 = m_pos.z;

	}
	else {
		m_sts = BULLETSTATUS::DEAD;
	}

}

void Bullet::Finalize() {

}