#include	"skydome.h"
#include	"dx11mathutil.h"

bool Skydome::Init() {

	bool sts = true;

	// 行列初期化
	DX11MtxIdentity(m_mtx);


	return sts;
}

void Skydome::Draw() {

	// モデル描画
	m_pmodel->Draw(m_mtx);

}

void Skydome::Update() {

}

void Skydome::Finalize() {
}
