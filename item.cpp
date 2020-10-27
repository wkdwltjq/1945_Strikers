#include "stdafx.h"
#include "item.h"

HRESULT item::init()//아이템 초기화
{
	_bombCount = 2;//폭탄기본 2개
	_attackCount = 1;//기본 플레이어 공격 1단계
	_rndItemFire = RND->getFromIntTo(1, 30);//아이템이 나올확률
	_rndItemFireCount = 0;//아이템이 나올확률에 사용할 카운트
	_bombCountImage = IMAGEMANAGER->addImage("bombCount", "image/playerBombCount.bmp", 32, 30, true, false, RGB(255, 0, 255));//왼쪽하단에 폭탄개수 이미지

	return S_OK;
}

void item::render()//아이템 그리기
{
	for (int i = 0; i < _vBombItem.size(); i++)
	{
		//Rectangle(getMemDC(), _vBombItem[i].rc);//폭탄아이템 렉트

		_vBombItem[i].imageName->frameRender(getMemDC(), _vBombItem[i].x, _vBombItem[i].y, _vBombItem[i].imageName->getFrameX(), _vBombItem[i].imageName->getFrameY());//폭탄아이템 프레임 그리기
		
		_vBombItem[i].count++;
		if (_vBombItem[i].count % 10 == 0)//폭탄아이템 카운트가 5초마다
		{
			_vBombItem[i].imageName->setFrameX(_vBombItem[i].imageName->getFrameX() + 1);//폭탄아이템 프레임 1씩 증가
			if (_vBombItem[i].imageName->getFrameX() >= _vBombItem[i].imageName->getMaxFrameX())//폭탄아이템의 프레임이 끝에 도달하면 0으로 초기화
			{
				_vBombItem[i].imageName->setFrameX(0);//폭탄아이템 프레임 0으로 초기화
			}
			_vBombItem[i].count = 0;//폭탄아이템 카운트 0으로 초기화
		}
	}

	for (int i = 0; i < _vAttackItem.size(); i++)//공격력강화 아이템
	{
		//Rectangle(getMemDC(), _vAttackItem[i].rc);//공격력강화 아이템 렉트
		_vAttackItem[i].imageName->frameRender(getMemDC(), _vAttackItem[i].x, _vAttackItem[i].y, _vAttackItem[i].imageName->getFrameX(), _vAttackItem[i].imageName->getFrameY());//공격력강화 아이템 프레임

		_vAttackItem[i].count++;//공격력 강화 아이템 카운트 증가
		if (_vAttackItem[i].count % 10 == 0)
		{
			_vAttackItem[i].imageName->setFrameX(_vAttackItem[i].imageName->getFrameX() + 1);//공격력강화 아이템 프레임1씩증가
			if (_vAttackItem[i].imageName->getFrameX() >= _vAttackItem[i].imageName->getMaxFrameX())//공격력강화 아이템 프레임이 끝에 도달하면
			{
				_vAttackItem[i].imageName->setFrameX(0);//공격력강화 아이템 프레임을 초기화
			}
			_vAttackItem[i].count = 0;//공격력강화 아이템의 카운트 초기화
		}
	}

	for (int i = 0; i < _vHpItem.size(); i++)//hp 아이템
	{
		//Rectangle(getMemDC(), _vHpItem[i].rc);//hp 아이템 렉트
		_vHpItem[i].imageName->render(getMemDC(), _vHpItem[i].x, _vHpItem[i].y);//hp 아이템 프레임
	}

	if (_bombCount == 1)//폭탄개수가 1개일경우
	{
		_bombCountImage->render(getMemDC(), 10, WINSIZEY - 50);//왼쪽하단에 폭탄개수 이미지 그리기
	}

	if (_bombCount == 2)//폭탄개수가 2개일경우
	{
		_bombCountImage->render(getMemDC(), 10, WINSIZEY - 50);//왼쪽하단에 폭탄개수 이미지 그리기
		_bombCountImage->render(getMemDC(), 40, WINSIZEY - 50);//왼쪽하단에 폭탄개수 이미지 그리기
	}

	if (_bombCount == 3)//폭탄개수가 3개일경우
	{
		_bombCountImage->render(getMemDC(), 10, WINSIZEY - 50);//왼쪽하단에 폭탄개수 이미지 그리기
		_bombCountImage->render(getMemDC(), 40, WINSIZEY - 50);//왼쪽하단에 폭탄개수 이미지 그리기
		_bombCountImage->render(getMemDC(), 70, WINSIZEY - 50);//왼쪽하단에 폭탄개수 이미지 그리기
	}
	
}

void item::update()//아이템 업데이트
{
	move();//아이템 무브
}

void item::release()
{
}

void item::move()//아이템 무브
{
	for (int i = 0; i < _vBombItem.size(); i++)//폭탄아이템
	{
		_vBombItem[i].x += cos(_vBombItem[i].angle) * _vBombItem[i].speed;
		_vBombItem[i].y += -sin(_vBombItem[i].angle) * _vBombItem[i].speed;

		if ((_vBombItem[i].x >= WINSIZEX - (_vBombItem[i].rc.right - _vBombItem[i].rc.left)) ||
			(_vBombItem[i].x <= 0))
		{
			_vBombItem[i].angle = PI - _vBombItem[i].angle;
		}

		if ((_vBombItem[i].y >= WINSIZEY - (_vBombItem[i].rc.bottom - _vBombItem[i].rc.top)) ||
			(_vBombItem[i].y <= 100))
		{
			_vBombItem[i].angle = PI2 - _vBombItem[i].angle;
		}

		_vBombItem[i].rc = RectMake(_vBombItem[i].x, _vBombItem[i].y, _vBombItem[i].imageName->getFrameWidth(), _vBombItem[i].imageName->getFrameHeight());
	}

	if (_bombCount < 0)//폭탄개수가 0보다 작아지지 않게 하기위한 조건문
	{
		_bombCount++;
	}

	for (int i = 0; i < _vAttackItem.size(); i++)//공격력강화 아이템
	{
		_vAttackItem[i].x += cos(_vAttackItem[i].angle) * _vAttackItem[i].speed;
		_vAttackItem[i].y += -sin(_vAttackItem[i].angle) * _vAttackItem[i].speed;

		if ((_vAttackItem[i].x >= WINSIZEX - (_vAttackItem[i].rc.right - _vAttackItem[i].rc.left)) ||
			(_vAttackItem[i].x <= 0))
		{
			_vAttackItem[i].angle = PI - _vAttackItem[i].angle;
		}

		if ((_vAttackItem[i].y >= WINSIZEY - (_vAttackItem[i].rc.bottom - _vAttackItem[i].rc.top)) ||
			(_vAttackItem[i].y <= 100))
		{
			_vAttackItem[i].angle = PI2 - _vAttackItem[i].angle;
		}

		_vAttackItem[i].rc = RectMake(_vAttackItem[i].x, _vAttackItem[i].y, _vAttackItem[i].imageName->getFrameWidth(), _vAttackItem[i].imageName->getFrameHeight());
	}

	for (int i = 0; i < _vHpItem.size(); i++)//hp 아이템
	{
		_vHpItem[i].x += cos(_vHpItem[i].angle) * _vHpItem[i].speed;
		_vHpItem[i].y += -sin(_vHpItem[i].angle) * _vHpItem[i].speed;

		if ((_vHpItem[i].x >= WINSIZEX - (_vHpItem[i].rc.right - _vHpItem[i].rc.left)) ||
			(_vHpItem[i].x <= 0))
		{
			_vHpItem[i].angle = PI - _vHpItem[i].angle;
		}

		if ((_vHpItem[i].y >= WINSIZEY - (_vHpItem[i].rc.bottom - _vHpItem[i].rc.top)) ||
			(_vHpItem[i].y <= 100))
		{
			_vHpItem[i].angle = PI2 - _vHpItem[i].angle;
		}

		_vHpItem[i].rc = RectMake(_vHpItem[i].x, _vHpItem[i].y, _vHpItem[i].imageName->getWidth(), _vHpItem[i].imageName->getHeight());
	}
}

void item::removeBombItem(int arrNum)//폭탄아이템 벡터 삭제
{
	_vBombItem.erase(_vBombItem.begin() + arrNum);
}

void item::removeAttackItem(int arrNum)//공격력강화 벡터 아이템 삭제
{
	_vAttackItem.erase(_vAttackItem.begin() + arrNum);
}

void item::removeHpItem(int arrNum)
{
	_vHpItem.erase(_vHpItem.begin() + arrNum);
}

void item::bombItemFire(float x, float y)//폭탄아이템 생성
{
	tagItem item;
	ZeroMemory(&item, sizeof(tagItem));

 	item.imageName = IMAGEMANAGER->addFrameImage("bombItem", "image/playerItemBomb.bmp", 550, 30, 11, 1, true, false, RGB(255,0,255));
	item.count = 0;
	item.x = x;
	item.y = y;
	item.angle = PI2 / RND->getFromIntTo(1, 360);
  	item.rc = RectMake(item.x, item.y, item.imageName->getFrameWidth(), item.imageName->getFrameHeight());
	item.speed = 5;
	item.imageName->setFrameX(0);
	item.imageName->setFrameY(0);
	
	_vBombItem.push_back(item);
}

void item::attackItemFire(float x, float y)//공격력강화 아이템 생성
{
	tagItem item;
	ZeroMemory(&item, sizeof(tagItem));

	item.imageName = IMAGEMANAGER->addFrameImage("attack", "image/attackItem.bmp", 260, 30, 6, 1, true, false, RGB(255, 0, 255));
	item.count = 0;
	item.x = x;
	item.y = y;
	item.angle = PI2 / RND->getFromIntTo(1, 360);
	item.speed = 5;
	item.rc = RectMake(item.x, item.y, item.imageName->getFrameWidth(), item.imageName->getFrameHeight());
	item.imageName->setFrameX(0);
	item.imageName->setFrameY(0);

	_vAttackItem.push_back(item);
}

void item::hpItemFire(float x, float y)//회복 아이템 생성
{
	tagItem item;
	ZeroMemory(&item, sizeof(tagItem));

	item.imageName = IMAGEMANAGER->addImage("hp", "image/hpItem.bmp", 43, 30, true, false, RGB(255, 0, 255));
	item.x = x;
	item.y = y;
	item.angle = PI2 / RND->getFromIntTo(1, 360);
	item.speed = 5;
	item.rc = RectMake(item.x, item.y, item.imageName->getWidth(), item.imageName->getHeight());
	item.imageName->setFrameX(0);
	item.imageName->setFrameY(0);

	_vHpItem.push_back(item);
}

bool item::itemCountFire()//아이템이 나올확률
{
	_rndItemFireCount++;

	if (_rndItemFireCount % _rndItemFire == 0)
	{
		_rndItemFireCount = 0;
		_rndItemFire = RND->getFromIntTo(1, 30);

		return true;
	}

	return false;
}
