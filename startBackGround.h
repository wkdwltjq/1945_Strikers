#pragma once
#include "gameNode.h"

class startBackGround : public gameNode
{
private:
	image* _startBackGround;//��ŸƮ ����ȭ�� �̹���
	image* _startButton;//��ŸƮ��ư �̹���
	int _count;//��ŸƮ��ư �̹���

	string _token;
	vector<string>			_vSoundList;
	vector<string>::iterator	_viSoundList;
	//����
	bool _oneSoundPlay;//���带 �ѹ��� �����Ű�� ���� ����� ����

public:
	startBackGround();
	~startBackGround();

	HRESULT init();
	void release();
	void render();
	void update();
};

