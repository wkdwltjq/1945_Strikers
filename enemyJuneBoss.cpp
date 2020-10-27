#include "stdafx.h"
#include "enemyJuneBoss.h"

HRESULT enemyJuneBoss::init()//준보스 초기화
{
	tagJuneBoss juneboss;
	ZeroMemory(&juneboss, sizeof(tagJuneBoss));

	juneboss.juneBossImage = IMAGEMANAGER->addImage("enemyJuneBoss", "image/enemyJuneBoss.bmp", 162, 173, true, false, RGB(255, 0, 255));
	_x = WINSIZEX / 2 - 80;
	_y = -200;
	juneboss.speed = 1;
	juneboss.rc = RectMake(_x, _y, juneboss.juneBossImage->getWidth(), juneboss.juneBossImage->getHeight());

	_vJuneBoss.push_back(juneboss);

	_juneBossRotation = IMAGEMANAGER->addImage("enemyJuneBossRotation", "image/enemyJuneBossRotation.bmp", 53, 69, true, true, RGB(255, 0, 255));//준보스 회전하는 포신 이미지
	_rotation = 0;//회전각도

	_hp = 1000;//준보스 체력

	return S_OK;
}

void enemyJuneBoss::release()
{
}

void enemyJuneBoss::render()//준보스 그리기
{
	//준보스 포신 돌리기
	_count++;
	if (_count % 2 == 0)
	{
		_rotation++;
		_count = 0;
	}
	if (_rotation >= 360)
	{
		_rotation = 0;
	}

	for (int i = 0; i < _vJuneBoss.size(); i++)
	{
		//Rectangle(getMemDC(), _vJuneBoss[i].rc);//준보스 몸통 렉트 확인용
		_vJuneBoss[i].juneBossImage->render(getMemDC(), _x, _y);//준보스
		_juneBossRotation->RotateRender(getMemDC(), _x + 80, _y + 50, _rotation);//준보스 포신
	}
	
}

void enemyJuneBoss::update()//준보스 업데이트
{
	move();
}

void enemyJuneBoss::move()//준보스 무브
{
	for (int i = 0; i < _vJuneBoss.size(); i++)
	{
		_y += _vJuneBoss[i].speed;
		_vJuneBoss[i].rc = RectMake(_x, _y, _vJuneBoss[i].juneBossImage->getWidth(), _vJuneBoss[i].juneBossImage->getHeight());
	}
}

void enemyJuneBoss::removeJuneBoss(int arrNum)//준보스 벡터에서 삭제
{
	_vJuneBoss.erase(_vJuneBoss.begin() + arrNum);
}
