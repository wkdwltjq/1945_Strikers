#include "stdafx.h"
#include "playGround.h"


playGround::playGround()
{
}


playGround::~playGround()
{
}

//초기화 함수
HRESULT playGround::init()
{
	gameNode::init(true);

	SCENEMANAGER->addScene("스타트씬", new startBackGround);
	SCENEMANAGER->addScene("메인씬", new mainGameScene);

	SCENEMANAGER->changeScene("스타트씬");


	return S_OK;
}

//메모리 해제
void playGround::release()
{

}

//연산
void playGround::update()
{
	gameNode::update();

	SCENEMANAGER->update();

}

//그리기 전용
void playGround::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//=================================================

	SCENEMANAGER->render();

	//=============================================
	_backBuffer->render(getHDC(), 0, 0);
}

