#include	<random>
#include	"stage.h"
#include	"drawaxis.h"
#include	"ModelMgr.h"


bool Stage::Init() {

	bool sts = true;

	// �s�񏉊���
	DX11MtxIdentity(m_mtx);

	




	return sts;
}

void Stage::Draw() {

	// ���f���`��
	m_pmodel->Draw(m_mtx);

}

void Stage::Update() {

}

void Stage::Finalize() {

}
