#include "stdafx.h"
#include "enemyBoss.h"


enemyBoss::enemyBoss()
{
}


enemyBoss::~enemyBoss()
{
}

HRESULT enemyBoss::init()
{
	tagBoss enemyBoss;
	ZeroMemory(&enemyBoss, sizeof(tagBoss));
	enemyBoss.imageName = IMAGEMANAGER->addFrameImage("enemyBoss", "image/enemyBoss.bmp", 3760, 186, 20, 1, true, false, RGB(255, 0, 255));
	enemyBoss.imageName->setFrameX(0);
	enemyBoss.imageName->setFrameY(0);
	_x = WINSIZEX / 2;
	_y = -200;
	enemyBoss.speed = 3.0f;
	enemyBoss.angle = PI / 4;
	enemyBoss.rc = RectMake(_x, _y, enemyBoss.imageName->getFrameWidth(), enemyBoss.imageName->getFrameHeight());

	_vEnemyBoss.push_back(enemyBoss);

	_count = 0;
	_frameNum = 1;
	_hp = 1000;
	_bossAppear = false;
	return S_OK;
}

void enemyBoss::update()
{
	move();
}

void enemyBoss::release()
{
}

void enemyBoss::render()
{
	for (int i = 0; i < _vEnemyBoss.size(); i++)
	{
		//Rectangle(getMemDC(), _vEnemyBoss[i].rc);
		_vEnemyBoss[i].imageName->frameRender(getMemDC(), _x, _y);
		_count++;
		if (_count % 2 == 0)
		{
			_vEnemyBoss[i].imageName->setFrameX(_vEnemyBoss[i].imageName->getFrameX() + _frameNum);
			if (_vEnemyBoss[i].imageName->getFrameX() >= _vEnemyBoss[i].imageName->getMaxFrameX())
			{
				_frameNum = -_frameNum;
			}
			if (_vEnemyBoss[i].imageName->getFrameX() <= 0)
			{
				_frameNum = -_frameNum;
			}
			//cout << _vEnemyBoss[i].imageName->getFrameX() << endl;
			_count = 0;
		}
	}
}

void enemyBoss::move()
{
	for (int i = 0; i < _vEnemyBoss.size(); i++)
	{
		_x += cos(_vEnemyBoss[i].angle) * _vEnemyBoss[i].speed;
		_y += -sin(_vEnemyBoss[i].angle) * _vEnemyBoss[i].speed;
		_vEnemyBoss[i].rc = RectMake(_x, _y, _vEnemyBoss[i].imageName->getFrameWidth(), _vEnemyBoss[i].imageName->getFrameHeight());

		if ((_x <= 0) ||
			(_x >= WINSIZEX - 170))
		{
			_vEnemyBoss[i].angle = PI - _vEnemyBoss[i].angle;
		}
		if ((_y <= 0) ||
			(_y >= WINSIZEY / 2 - 200))
		{
			_vEnemyBoss[i].angle = PI2 - _vEnemyBoss[i].angle;
		}
	}
}

void enemyBoss::fristMove()
{
	for (int i = 0; i < _vEnemyBoss.size(); i++)
	{
		if (!_bossAppear)
		{
			_y += 1.0f;
			_vEnemyBoss[i].rc = RectMake(_x, _y, _vEnemyBoss[i].imageName->getFrameWidth(), _vEnemyBoss[i].imageName->getFrameHeight());
		}

		if (_y >= 100)
		{
			_bossAppear = true;
		}
	}
}

void enemyBoss::removeBoss(int arrNum)
{
	_vEnemyBoss.erase(_vEnemyBoss.begin() + arrNum);
}
