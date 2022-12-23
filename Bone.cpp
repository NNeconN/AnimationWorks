//#define NOMINMAX
//
//#include	<windows.h>
//#include	<vector>
//
//#include	<assimp\Importer.hpp>
//#include	<assimp\scene.h>
//#include	<assimp\postprocess.h>
//#include	<assimp/cimport.h>
//#include	<map>
//#include	<DirectXMath.h>
//#include	<stdio.h>
//
//#include	"utftosjisconv.h"
//
//#pragma comment (lib,"assimp-vc141-mtd.lib")
//
//// ���_�f�[�^
//struct Vertex {
//	DirectX::XMFLOAT3 m_Pos;			//	�ʒu
//	DirectX::XMFLOAT3 m_Normal;			//	�@��
//	DirectX::XMFLOAT2 m_Tex;			//	UV���W
//	int				m_BoneIndex[4];		//	�{���̓{�[���C���f�b�N�X�ŊǗ�����ׂ�
//	float			m_BoneWeight[4];	//	�E�F�C�g�l
//	int				m_BoneNum;			//	�{�[����
//	std::string		m_BoneName[4];		//	�{���̓{�[���C���f�b�N�X�ŊǗ�����ׂ�
//};
//
//// �{�[���f�[�^
//struct BONE
//{
//	unsigned int idx = -1;				// �{�[���z��̃C���f�b�N�X�ԍ�
//	//std::string Name;
//	aiMatrix4x4 Matrix;					// �����z�u�s��
//	aiMatrix4x4 AnimationMatrix;		// �{�[���s��
//	aiMatrix4x4 OffsetMatrix;			// �{�[���I�t�Z�b�g�s��
//};
//
//// �{�[������
//std::map<std::string, BONE> g_Bone;		//�{�[���f�[�^�i���O�ŎQ�Ɓj
//
//// �{�[������
//std::map < std::string, std::vector<Vertex>> g_MeshVertex;		//���b�V�����_�i���O�ŎQ�Ɓj
//
//// ���b�V���̉��
//void processMesh(aiMesh* mesh, const aiScene* scene, int meshidx)
//{
//	std::vector<Vertex> vertices;			// ���_
//
//	// ���_�����擾
//	for (unsigned int i = 0; i < mesh->mNumVertices; i++)
//	{
//		Vertex vertex;
//
//		vertex.m_Pos.x = mesh->mVertices[i].x;
//		vertex.m_Pos.y = mesh->mVertices[i].y;
//		vertex.m_Pos.z = mesh->mVertices[i].z;
//
//		// �@���x�N�g�������݂��邩�H
//		if (mesh->HasNormals()) {
//			vertex.m_Normal.x = mesh->mNormals[i].x;
//			vertex.m_Normal.y = mesh->mNormals[i].y;
//			vertex.m_Normal.z = mesh->mNormals[i].z;
//		}
//		else {
//			vertex.m_Normal.x = 0.0f;
//			vertex.m_Normal.y = 0.0f;
//			vertex.m_Normal.z = 0.0f;
//		}
//
//		// �e�N�X�`�����W�i�O�Ԗځj�����݂��邩�H
//		if (mesh->HasTextureCoords(0)) {
//			vertex.m_Tex.x = mesh->mTextureCoords[0][i].x;
//			vertex.m_Tex.y = mesh->mTextureCoords[0][i].y;
//		}
//
//		vertex.m_BoneNum = 0;
//
//		for (unsigned int b = 0; b < 4; b++)
//		{
//			vertex.m_BoneIndex[b] = -1;
//			vertex.m_BoneName[b] = "";
//			vertex.m_BoneWeight[b] = 0.0f;
//		}
//
//		vertices.push_back(vertex);
//	}
//
//	//�{�[���f�[�^�������i���b�V���̒��ɉ��̃{�[�������݂��邩�j
//	for (unsigned int b = 0; b < mesh->mNumBones; b++)
//	{
//		// ���b�V���Ɋ֘A�Â��Ă�{�[�������擾
//		aiBone* bone = mesh->mBones[b];
//
//		// �{�[���I�t�Z�b�g�s����擾
//		g_Bone[bone->mName.C_Str()].OffsetMatrix = bone->mOffsetMatrix;
//
//		// �{�[���Ɋ֘A�Â��Ă��钸�_��I�Ѥ�E�F�C�g�l���Z�b�g����
//		for (unsigned int widx = 0; widx < bone->mNumWeights; widx++)
//		{
//			aiVertexWeight weight = bone->mWeights[widx];
//
//			unsigned int vidx = weight.mVertexId;	// ���̃E�G�C�g�Ɋ֘A�Â��Ă钸�_idx
//
//			// ���b�V���̒��̉��Ԗڂ�
//			vertices[vidx].m_BoneWeight[vertices[vidx].m_BoneNum] = weight.mWeight;
//			vertices[vidx].m_BoneName[vertices[vidx].m_BoneNum] = bone->mName.C_Str();
//			// �Y������{�[�����̃C���f�b�N�X�l���Z�b�g
//			vertices[vidx].m_BoneIndex[vertices[vidx].m_BoneNum] = g_Bone[bone->mName.C_Str()].idx;
//
//			vertices[vidx].m_BoneNum++;
//
//			assert(vertices[vidx].m_BoneNum <= 4);
//		}
//	}
//
//	g_MeshVertex[mesh->mName.C_Str()] = vertices;
//
//	return;
//}
//
//void processNode(aiNode* node, const aiScene* scene, int depth)
//{
//	// �C���f���g
//	for (int i = 0; i < depth; i++) {
//		printf(" ");
//	}
//
//	// utf8���V�t�g�i�h�r�ɕϊ�
//	std::string nodename = utf8_to_multi_winapi(std::string(node->mName.C_Str()));
//	printf("%s \n", nodename.c_str());
//
//	// �m�[�h���̃��b�V���̐������[�v����
//	for (unsigned int i = 0; i < node->mNumMeshes; i++)
//	{
//		int meshindex = node->mMeshes[i];			// �m�[�h��i�Ԗڃ��b�V���̃C���f�b�N�X���擾
//		aiMesh* mesh = scene->mMeshes[meshindex];	// �V�[�����烁�b�V���{�̂����o��
//
//		processMesh(mesh, scene, meshindex);
//	}
//
//	for (unsigned int i = 0; i < node->mNumChildren; i++)
//	{
//		processNode(node->mChildren[i], scene, depth + 1);
//	}
//}
//
//
//void CreateBone(aiNode* node)
//{
//	BONE bone;
//
//	// �m�[�h�����L�[�ɂ��ă{�[������ۑ�
//	g_Bone[node->mName.C_Str()] = bone;
//
//	for (unsigned int n = 0; n < node->mNumChildren; n++)
//	{
//		CreateBone(node->mChildren[n]);
//	}
//}
//
//int eee() {
//
//	Assimp::Importer importer;
//	std::string filename("HAL/halchan2.pmx");
//
//	const aiScene* pScene = importer.ReadFile(filename,
//		aiProcess_ConvertToLeftHanded |
//		aiProcessPreset_TargetRealtime_MaxQuality);
//
//	if (pScene == nullptr) {
//		printf("load halchan2.pmx error \n");
//		return false;
//	}
//
//	printf("load halchan2.pmx success \n");
//
//	// ��̃{�[���𐶐�����
//	CreateBone(pScene->mRootNode);
//
//	// �{�[���̔z��ʒu���i�[����
//	unsigned int num = 0;
//	for (auto& data : g_Bone) {
//		data.second.idx = num;
//		num++;
//	}
//
//
//	// ai�m�[�h���ċA�I�ɉ��
//	processNode(pScene->mRootNode, pScene, 0);
//
//	// �{�[�����\��
//	printf("\n������������������������������\n");
//	printf("��         �{�[�����         ��\n");
//	printf("������������������������������\n");
//
//	for (auto& b : g_Bone) {
//		// utf8���V�t�g�i�h�r�ɕϊ�
//		std::string nodename = utf8_to_multi_winapi(std::string(b.first.c_str()));
//		printf("\n�{�[����: %s\n", nodename.c_str());
//		printf("  �I�t�Z�b�g�s��F%f %f %f\n",
//			b.second.OffsetMatrix.a4,
//			b.second.OffsetMatrix.b4,
//			b.second.OffsetMatrix.c4);
//	}
//
//
//	// ���_���\��
//	printf("\n������������������������������\n");
//	printf("��         ���_���         ��\n");
//	printf("������������������������������\n");
//
//	for (auto& mv : g_MeshVertex) {
//		// utf8���V�t�g�i�h�r�ɕϊ�
//		std::string meshname = utf8_to_multi_winapi(std::string(mv.first.c_str()));
//		printf("\n���b�V����: %s\n", meshname.c_str());
//
//		for (auto& v : mv.second) {
//			// utf8���V�t�g�i�h�r�ɕϊ�
//			std::string bid = utf8_to_multi_winapi(std::string(v.m_BoneName[0].c_str()));
//			printf("  �{�[��ID(0)�F%s %s %f\n",
//				meshname.c_str(),
//				bid.c_str(), v.m_BoneWeight[0]);
//
//			bid = utf8_to_multi_winapi(std::string(v.m_BoneName[0].c_str()));
//			printf("  �{�[��ID(1)�F%s %s %f\n",
//				meshname.c_str(),
//				bid.c_str(), v.m_BoneWeight[1]);
//
//			bid = utf8_to_multi_winapi(std::string(v.m_BoneName[0].c_str()));
//			printf("  �{�[��ID(2)�F%s %s %f\n",
//				meshname.c_str(),
//				bid.c_str(), v.m_BoneWeight[2]);
//
//			bid = utf8_to_multi_winapi(std::string(v.m_BoneName[0].c_str()));
//			printf("  �{�[��ID(3)�F%s %s %f\n\n",
//				meshname.c_str(),
//				bid.c_str(), v.m_BoneWeight[3]);
//
//		}
//	}
//
//	// �������
//	aiReleaseImport(pScene);
//
//	int s = getchar();
//
//	return true;
//}