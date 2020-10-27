#include "stdafx.h"
#include "startBackGround.h"

startBackGround::startBackGround()
{
}

startBackGround::~startBackGround()
{
}

HRESULT startBackGround::init()
{
	_startBackGround = IMAGEMANAGER->addImage("스타트화면", "image/inGameStart.bmp", 600, 800, false, false, RGB(255, 0, 255));//스타트 배경화면
	_startButton = IMAGEMANAGER->addImage("스타트버튼", "image/inGameStartButton.bmp", 305, 57, true, false, RGB(255, 0, 255));//스타트 버튼

	_count = 0;
	_oneSoundPlay = false;//사운드를 한번만 재생시키기 위해 사용할 변수

	return S_OK;
}

void startBackGround::release()
{
}

void startBackGround::render()
{
	IMAGEMANAGER->findImage("스타트화면")->render(getMemDC(), 0, 0);

	_count++;

	if (_count > 20)
	{
		IMAGEMANAGER->findImage("스타트버튼")->render(getMemDC(), WINSIZEX / 2 - 150, WINSIZEY - 250);
		if (_count > 100)
		{
			_count = 0;
		}
	}
}

void startBackGround::update()
{
	if (!_oneSoundPlay)//사운드를 한번만 재생시키기 위해 필요한 조건문
	{
		_token = "sound/gameStart.mp3";
		_vSoundList.push_back(_token);

		SOUNDMANAGER->addSound(_vSoundList[_vSoundList.size() - 1], _vSoundList[_vSoundList.size() - 1], true, false);//음악파일추가
		SOUNDMANAGER->play(_vSoundList[_vSoundList.size() - 1], 1.0f);//음악재생
		_oneSoundPlay = true;
	}

	if (_vSoundList.size() > 2)//스타트씬의 사운드만 재생시키기 위해 필요한 조건문
	{
		SOUNDMANAGER->stop(_vSoundList[_vSoundList.size() - 2]);
	}

	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		SOUNDMANAGER->stop(_vSoundList[_vSoundList.size() - 1]);//게임클리어 사운드 정지

		_token = "sound/main.mp3";
		_vSoundList.push_back(_token);

		SOUNDMANAGER->addSound(_vSoundList[_vSoundList.size() - 1], _vSoundList[_vSoundList.size() - 1], true, false);//음악파일추가
		SOUNDMANAGER->play(_vSoundList[_vSoundList.size() - 1], 0.5f);//음악재생

		SCENEMANAGER->changeScene("메인씬");
	}

}
