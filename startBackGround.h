#pragma once
#include "gameNode.h"

class startBackGround : public gameNode
{
private:
	image* _startBackGround;//스타트 게임화면 이미지
	image* _startButton;//스타트버튼 이미지
	int _count;//스타트버튼 이미지

	string _token;
	vector<string>			_vSoundList;
	vector<string>::iterator	_viSoundList;
	//사운드
	bool _oneSoundPlay;//사운드를 한번만 재생시키기 위해 사용할 변수

public:
	startBackGround();
	~startBackGround();

	HRESULT init();
	void release();
	void render();
	void update();
};

