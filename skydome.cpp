#include	"skydome.h"
#include	"dx11mathutil.h"

bool Skydome::Init() {

	bool sts = true;

	// �s�񏉊���
	DX11MtxIdentity(m_mtx);


	return sts;
}

void Skydome::Draw() {

	// ���f���`��
	m_pmodel->Draw(m_mtx);

}

void Skydome::Update() {

}

void Skydome::Finalize() {
}
