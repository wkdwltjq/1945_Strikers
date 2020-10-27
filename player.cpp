#include "stdafx.h"
#include "player.h"

player::player()
{
}

player::~player()
{
}

HRESULT player::init()
{
	_player = IMAGEMANAGER->addFrameImage("�÷��̾��", "image/playerMove.bmp", 217, 40, 7, 1, true, false, RGB(255, 0, 255));
	_player->setFrameX(3);
	_player->setFrameY(0);
	_speed = 5;
	_x = WINSIZEX / 2;
	_y = WINSIZEY - 100;
	_count = 0;
	_index = 3;

	_rc = RectMake(_x, _y, _player->getFrameWidth(), _player->getFrameHeight());//�÷��̾� ��Ʈ

	_direction = IDLE;//�÷��̾� ������ �⺻����

	_currentHP = _maxHP = 100;//�÷��̾� ü��

	return S_OK;
}

void player::release()
{
}

void player::render()
{
	//Rectangle(getMemDC(), _rc);//��Ʈ��ġ ������
	_player->frameRender(getMemDC(), _x, _y, _player->getFrameX(), _player->getFrameY());//�÷��̾� �׸���

	/*
	sprintf_s(str, "%d", _index);
	TextOut(getMemDC(), 10, 10, str, strlen(str));
	*/
}

void player::update()
{
	move();//�÷��̾� �̵�

	_rc = RectMake(_x, _y, _player->getFrameWidth(), _player->getFrameHeight());//�÷��̾� ��Ʈ�� �ǽð����� ����
}

void player::move()
{
	_count++;

	if (_count % 10 == 0)
	{
		if (_direction == IDLE)
		{
			_player->setFrameX(3);
		}
		if (_direction == LEFT_MOVE)
		{
			if (_index > 0)
			{
				_player->setFrameX(_index);
				_index--;
			}
		}
		if (_direction == RIGHT_MOVE)
		{
			if (_index < 6)
			{
				_player->setFrameX(_index);
				_index++;
			}
		}
		_count = 0;
	}

	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_x -= _speed;
		_direction = LEFT_MOVE;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_x += _speed;
		_direction = RIGHT_MOVE;
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_y -= _speed;
		_direction = IDLE;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_y += _speed;
		_direction = IDLE;
	}
	if ((KEYMANAGER->isOnceKeyUp(VK_LEFT)) ||
		(KEYMANAGER->isOnceKeyUp(VK_RIGHT)) ||
		(KEYMANAGER->isOnceKeyUp(VK_UP)) ||
		(KEYMANAGER->isOnceKeyUp(VK_DOWN)))
	{
		_direction = IDLE;
		_index = 3;
	}
}
