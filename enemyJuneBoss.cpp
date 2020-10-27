#include "stdafx.h"
#include "enemyJuneBoss.h"

HRESULT enemyJuneBoss::init()//�غ��� �ʱ�ȭ
{
	tagJuneBoss juneboss;
	ZeroMemory(&juneboss, sizeof(tagJuneBoss));

	juneboss.juneBossImage = IMAGEMANAGER->addImage("enemyJuneBoss", "image/enemyJuneBoss.bmp", 162, 173, true, false, RGB(255, 0, 255));
	_x = WINSIZEX / 2 - 80;
	_y = -200;
	juneboss.speed = 1;
	juneboss.rc = RectMake(_x, _y, juneboss.juneBossImage->getWidth(), juneboss.juneBossImage->getHeight());

	_vJuneBoss.push_back(juneboss);

	_juneBossRotation = IMAGEMANAGER->addImage("enemyJuneBossRotation", "image/enemyJuneBossRotation.bmp", 53, 69, true, true, RGB(255, 0, 255));//�غ��� ȸ���ϴ� ���� �̹���
	_rotation = 0;//ȸ������

	_hp = 1000;//�غ��� ü��

	return S_OK;
}

void enemyJuneBoss::release()
{
}

void enemyJuneBoss::render()//�غ��� �׸���
{
	//�غ��� ���� ������
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
		//Rectangle(getMemDC(), _vJuneBoss[i].rc);//�غ��� ���� ��Ʈ Ȯ�ο�
		_vJuneBoss[i].juneBossImage->render(getMemDC(), _x, _y);//�غ���
		_juneBossRotation->RotateRender(getMemDC(), _x + 80, _y + 50, _rotation);//�غ��� ����
	}
	
}

void enemyJuneBoss::update()//�غ��� ������Ʈ
{
	move();
}

void enemyJuneBoss::move()//�غ��� ����
{
	for (int i = 0; i < _vJuneBoss.size(); i++)
	{
		_y += _vJuneBoss[i].speed;
		_vJuneBoss[i].rc = RectMake(_x, _y, _vJuneBoss[i].juneBossImage->getWidth(), _vJuneBoss[i].juneBossImage->getHeight());
	}
}

void enemyJuneBoss::removeJuneBoss(int arrNum)//�غ��� ���Ϳ��� ����
{
	_vJuneBoss.erase(_vJuneBoss.begin() + arrNum);
}
