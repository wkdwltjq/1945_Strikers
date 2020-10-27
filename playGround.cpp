#include "stdafx.h"
#include "playGround.h"


playGround::playGround()
{
}


playGround::~playGround()
{
}

//�ʱ�ȭ �Լ�
HRESULT playGround::init()
{
	gameNode::init(true);

	SCENEMANAGER->addScene("��ŸƮ��", new startBackGround);
	SCENEMANAGER->addScene("���ξ�", new mainGameScene);

	SCENEMANAGER->changeScene("��ŸƮ��");


	return S_OK;
}

//�޸� ����
void playGround::release()
{

}

//����
void playGround::update()
{
	gameNode::update();

	SCENEMANAGER->update();

}

//�׸��� ����
void playGround::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//=================================================

	SCENEMANAGER->render();

	//=============================================
	_backBuffer->render(getHDC(), 0, 0);
}

