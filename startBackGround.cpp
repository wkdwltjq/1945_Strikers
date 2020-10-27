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
	_startBackGround = IMAGEMANAGER->addImage("��ŸƮȭ��", "image/inGameStart.bmp", 600, 800, false, false, RGB(255, 0, 255));//��ŸƮ ���ȭ��
	_startButton = IMAGEMANAGER->addImage("��ŸƮ��ư", "image/inGameStartButton.bmp", 305, 57, true, false, RGB(255, 0, 255));//��ŸƮ ��ư

	_count = 0;
	_oneSoundPlay = false;//���带 �ѹ��� �����Ű�� ���� ����� ����

	return S_OK;
}

void startBackGround::release()
{
}

void startBackGround::render()
{
	IMAGEMANAGER->findImage("��ŸƮȭ��")->render(getMemDC(), 0, 0);

	_count++;

	if (_count > 20)
	{
		IMAGEMANAGER->findImage("��ŸƮ��ư")->render(getMemDC(), WINSIZEX / 2 - 150, WINSIZEY - 250);
		if (_count > 100)
		{
			_count = 0;
		}
	}
}

void startBackGround::update()
{
	if (!_oneSoundPlay)//���带 �ѹ��� �����Ű�� ���� �ʿ��� ���ǹ�
	{
		_token = "sound/gameStart.mp3";
		_vSoundList.push_back(_token);

		SOUNDMANAGER->addSound(_vSoundList[_vSoundList.size() - 1], _vSoundList[_vSoundList.size() - 1], true, false);//���������߰�
		SOUNDMANAGER->play(_vSoundList[_vSoundList.size() - 1], 1.0f);//�������
		_oneSoundPlay = true;
	}

	if (_vSoundList.size() > 2)//��ŸƮ���� ���常 �����Ű�� ���� �ʿ��� ���ǹ�
	{
		SOUNDMANAGER->stop(_vSoundList[_vSoundList.size() - 2]);
	}

	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		SOUNDMANAGER->stop(_vSoundList[_vSoundList.size() - 1]);//����Ŭ���� ���� ����

		_token = "sound/main.mp3";
		_vSoundList.push_back(_token);

		SOUNDMANAGER->addSound(_vSoundList[_vSoundList.size() - 1], _vSoundList[_vSoundList.size() - 1], true, false);//���������߰�
		SOUNDMANAGER->play(_vSoundList[_vSoundList.size() - 1], 0.5f);//�������

		SCENEMANAGER->changeScene("���ξ�");
	}

}
