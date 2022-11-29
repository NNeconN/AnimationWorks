#pragma once
#include	"gameobject.h"
#include	"CModel.h"

class Skydome : public GameObject {
private:
	CModel*	m_pmodel;	// �R�c���f��
public:
	bool Init();		// ��������

	void Draw();		// �`��

	void Update();		// �X�V

	void SetModel(CModel* p) {
		m_pmodel = p;
	}

	void Finalize();	// �I������	
};