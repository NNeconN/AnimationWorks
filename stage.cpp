#include	<random>
#include	"stage.h"
#include	"drawaxis.h"
#include	"ModelMgr.h"


bool Stage::Init() {

	bool sts = true;

	// 行列初期化
	DX11MtxIdentity(m_mtx);

	




	return sts;
}

void Stage::Draw() {

	// モデル描画
	m_pmodel->Draw(m_mtx);

}

void Stage::Update() {

}

void Stage::Finalize() {

}
