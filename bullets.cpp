#include "stdafx.h"
#include "bullets.h"


HRESULT enemyBullet::init(const char * imageName, int bulletMax, float range)//일반적총알 초기화
{
	_imageName = imageName;
	_bulletMax = bulletMax;
	_range = range;

	return S_OK;
}

void enemyBullet::release()
{
}

void enemyBullet::update()//일반적 총알 업데이트
{
	move();
}

void enemyBullet::render()//일반적 총알 그리기
{
	for (_viEnemyBullet = _vEnemyBullet.begin(); _viEnemyBullet != _vEnemyBullet.end(); ++_viEnemyBullet)
	{
		_viEnemyBullet->bulletImage->render(getMemDC(), _viEnemyBullet->rc.left, _viEnemyBullet->rc.top);
	}
}

void enemyBullet::fire(float x, float y, float angle, float speed)//일반적 총알발사
{
	if (_bulletMax < _vEnemyBullet.size()) return;

	tagBullet bullet;
	ZeroMemory(&bullet, sizeof(tagBullet));

	bullet.bulletImage = IMAGEMANAGER->findImage(_imageName);
	bullet.speed = speed;
	bullet.radius = bullet.bulletImage->getWidth() / 2;
	bullet.x = bullet.fireX = x;
	bullet.y = bullet.fireY = y;
	bullet.angle = angle;

	bullet.rc = RectMakeCenter(bullet.x, bullet.y,
		bullet.bulletImage->getWidth(),
		bullet.bulletImage->getHeight());

	_vEnemyBullet.push_back(bullet);


}

void enemyBullet::move()//일반적 총알 무브
{
	for (_viEnemyBullet = _vEnemyBullet.begin(); _viEnemyBullet != _vEnemyBullet.end();)
	{
		_viEnemyBullet->x += cosf(_viEnemyBullet->angle) * _viEnemyBullet->speed;
		_viEnemyBullet->y += -sinf(_viEnemyBullet->angle) * _viEnemyBullet->speed;

		_viEnemyBullet->rc = RectMakeCenter(_viEnemyBullet->x, _viEnemyBullet->y,
			_viEnemyBullet->bulletImage->getWidth(),
			_viEnemyBullet->bulletImage->getHeight());

		if (_range < getDistance(_viEnemyBullet->x, _viEnemyBullet->y,
			_viEnemyBullet->fireX, _viEnemyBullet->fireY))
		{
			_viEnemyBullet = _vEnemyBullet.erase(_viEnemyBullet);
		}
		else ++_viEnemyBullet;
	}

}

void enemyBullet::removeEnemyBullet(int arrNum)//일반적 총알 삭제
{
	_vEnemyBullet.erase(_vEnemyBullet.begin() + arrNum);
}

HRESULT playerBullet::init(int missileMax, float range)//플레이어 총알 초기화
{
	//인자값 대입해준다
	_bulletMax = missileMax;
	_range = range;

	return S_OK;
}

void playerBullet::release()
{
}

void playerBullet::update()//플레이어 업데이트
{
	move();
}

void playerBullet::render()//플레이어 총알 그리기
{
	for (_viPlayerBullet = _vPlayerBullet.begin(); _viPlayerBullet != _vPlayerBullet.end(); ++_viPlayerBullet)
	{
		_viPlayerBullet->bulletImage->frameRender(getMemDC(),
			_viPlayerBullet->rc.left,
			_viPlayerBullet->rc.top,
			_viPlayerBullet->bulletImage->getFrameX(), 0);

		_viPlayerBullet->count++;

		if (_viPlayerBullet->count % 5 == 0)
		{
			_viPlayerBullet->bulletImage->setFrameX(_viPlayerBullet->bulletImage->getFrameX() + 1);

			if (_viPlayerBullet->bulletImage->getFrameX() >= _viPlayerBullet->bulletImage->getMaxFrameX())
			{
				_viPlayerBullet->bulletImage->setFrameX(0);
			}

			_viPlayerBullet->count = 0;
		}

	}

}

void playerBullet::fire(float x, float y)//플레이어 총알 발사
{
	//총알의 최대갯수보다 더 생성되면 실행하지마라
	if (_bulletMax < _vPlayerBullet.size()) return;

	tagBullet bullet;
	ZeroMemory(&bullet, sizeof(bullet));

	bullet.bulletImage = new image;
	bullet.bulletImage->init("image/playerAttack.bmp", 0, 0,
		124, 53, 4, 1, true, false, RGB(255, 0, 255));
	bullet.speed = 6.0f;

	bullet.x = bullet.fireX = x + 15;
	bullet.y = bullet.fireY = y;
	bullet.rc = RectMakeCenter(bullet.x, bullet.y,
		bullet.bulletImage->getFrameWidth(),
		bullet.bulletImage->getFrameHeight());
	
	_vPlayerBullet.push_back(bullet);
}

void playerBullet::move()//플레이어 총알 무브
{
	for (_viPlayerBullet = _vPlayerBullet.begin(); _viPlayerBullet != _vPlayerBullet.end();)
	{
		_viPlayerBullet->y -= _viPlayerBullet->speed;
		_viPlayerBullet->rc = RectMakeCenter(_viPlayerBullet->x, _viPlayerBullet->y,
			_viPlayerBullet->bulletImage->getFrameWidth(),
			_viPlayerBullet->bulletImage->getFrameHeight());

		//사거리밖으로 나갔을때 메모리 해제
		if (_range < getDistance(_viPlayerBullet->x, _viPlayerBullet->y,
			_viPlayerBullet->fireX, _viPlayerBullet->fireY))
		{
			_viPlayerBullet->bulletImage->release();
			SAFE_DELETE(_viPlayerBullet->bulletImage);

			_viPlayerBullet = _vPlayerBullet.erase(_viPlayerBullet);
		}
		else ++_viPlayerBullet;
		
	}
}

void playerBullet::removePlayerBullet(int arrNum)//플레이어 총알삭제
{
	_vPlayerBullet.erase(_vPlayerBullet.begin() + arrNum);
}

HRESULT enemyBullet2::init(const char * imageName, int bulletMax, float range)//헬리콥터적 초기화
{
	_imageName = imageName;
	_bulletMax = bulletMax;
	_range = range;

	return S_OK;
}

void enemyBullet2::render()
{
	for (_viEnemyBullet2 = _vEnemyBullet2.begin(); _viEnemyBullet2 != _vEnemyBullet2.end(); ++_viEnemyBullet2)//헬리콥터적 총알그리기
	{
		//Rectangle(getMemDC(), _viEnemyBullet2->rc);//헬리콥터적 총알 렉트
		_viEnemyBullet2->bulletImage->frameRender(getMemDC(), _viEnemyBullet2->rc.left, _viEnemyBullet2->rc.top, _viEnemyBullet2->bulletImage->getFrameX(), _viEnemyBullet2->bulletImage->getFrameY());

		_viEnemyBullet2->count++;
		if (_viEnemyBullet2->count % 5 == 0)
		{
			_viEnemyBullet2->bulletImage->setFrameX(_viEnemyBullet2->bulletImage->getFrameX() + 1);

			if (_viEnemyBullet2->bulletImage->getFrameX() >= _viEnemyBullet2->bulletImage->getMaxFrameX())
			{
				_viEnemyBullet2->bulletImage->setFrameX(0);
			}

			_viEnemyBullet2->count = 0;
		}
	}
}

void enemyBullet2::release()
{
}

void enemyBullet2::update()//헬리콥터적 총알 업데이트
{
	move();
}

void enemyBullet2::fire(float x, float y, float angle, float speed)//헬리콥터적 총알 발사
{
	if (_bulletMax < _vEnemyBullet2.size()) return;
	tagBullet bullet;
	ZeroMemory(&bullet, sizeof(tagBullet));

	bullet.bulletImage = new image;
	bullet.bulletImage = IMAGEMANAGER->findImage(_imageName);
	bullet.angle = angle;
	bullet.speed = speed;
	bullet.x = bullet.fireX = x;
	bullet.y = bullet.fireY = y;
	bullet.rc = RectMakeCenter(bullet.x, bullet.y, bullet.bulletImage->getFrameWidth(), bullet.bulletImage->getFrameHeight());
	bullet.bulletImage->setFrameX(0);
	bullet.bulletImage->setFrameY(0);

	_vEnemyBullet2.push_back(bullet);
}

void enemyBullet2::move()//헬리콥터적 총알 무브
{
	for (_viEnemyBullet2 = _vEnemyBullet2.begin(); _viEnemyBullet2 != _vEnemyBullet2.end();)
	{
		_viEnemyBullet2->x += cos(_viEnemyBullet2->angle) * _viEnemyBullet2->speed;
		_viEnemyBullet2->y += -sin(_viEnemyBullet2->angle) * _viEnemyBullet2->speed;

		_viEnemyBullet2->rc = RectMakeCenter(_viEnemyBullet2->x, _viEnemyBullet2->y, _viEnemyBullet2->bulletImage->getFrameWidth(), _viEnemyBullet2->bulletImage->getFrameHeight());

		if (_range < getDistance(_viEnemyBullet2->x, _viEnemyBullet2->y, _viEnemyBullet2->fireX, _viEnemyBullet2->fireY))
		{
			_viEnemyBullet2 = _vEnemyBullet2.erase(_viEnemyBullet2);
		}
		else
		{
			_viEnemyBullet2++;
		}
	}
}

void enemyBullet2::removeEnemyBullet2(int arrNum)//헬리콥터적 총알 삭제
{
	_vEnemyBullet2.erase(_vEnemyBullet2.begin() + arrNum);
}

HRESULT bomb::init(const char* imageName, float range, int bombMax)//폭탄초기화
{
	_imageName = imageName;
	_range = range;
	_bombMax = bombMax;

	return S_OK;
}

void bomb::release()
{
}

void bomb::render()//폭탄그리기
{
	for (int i = 0; i < _vBomb.size(); i++)//폭탄 프레임
	{
		//Rectangle(getMemDC(), _vBomb[i].rc);//폭탄 렉트 확인용
		_vBomb[i].bulletImage->frameRender(getMemDC(), _vBomb[i].x, _vBomb[i].y, _vBomb[i].bulletImage->getFrameX(), _vBomb[i].bulletImage->getFrameY());

		_vBomb[i].count++;
		if (_vBomb[i].count % 5 == 0)
		{
			_vBomb[i].bulletImage->setFrameX(_vBomb[i].bulletImage->getFrameX() + 1);
			_vBomb[i].count = 0;
		}
		
		if (_vBomb[i].bulletImage->getFrameX() >= _vBomb[i].bulletImage->getMaxFrameX())
		{
			_vBomb[i].bulletImage->setFrameX(0);
		}
	}

}

void bomb::update()//폭탄업데이트
{
	move();
}

void bomb::move()//폭탄무브
{
	for (_viBomb = _vBomb.begin(); _viBomb != _vBomb.end();)
	{
		_viBomb->y -= _viBomb->speed;
		_viBomb->rc = RectMake(_viBomb->x, _viBomb->y, _viBomb->bulletImage->getFrameWidth(), _viBomb->bulletImage->getFrameHeight());

		if (_range < getDistance(_viBomb->x, _viBomb->y, _viBomb->fireX, _viBomb->fireY))
		{
			_viBomb = _vBomb.erase(_viBomb);
		}
		else
		{
			_viBomb++;
		}
	}
}

void bomb::bombFire(float x, float y, float speed)//폭탄발사
{
	if (_bombMax <= 0) return;//폭탄개수가 0이하면 실행하지말아라
	tagBullet bomb;
	ZeroMemory(&bomb, sizeof(tagBullet));

	bomb.bulletImage = new image;
	bomb.bulletImage = IMAGEMANAGER->findImage(_imageName);
	bomb.x = bomb.fireX = x;
	bomb.y = bomb.fireY = y;
	bomb.count = 0;
	bomb.speed = speed;
	bomb.rc = RectMake(bomb.x, bomb.y, bomb.bulletImage->getFrameWidth(), bomb.bulletImage->getFrameHeight());
	bomb.bulletImage->setFrameX(0);
	bomb.bulletImage->setFrameY(0);

	_vBomb.push_back(bomb);
}

void bomb::removeBomb(int arrNum)
{
	_vBomb.erase(_vBomb.begin() + arrNum);//폭탄삭제
}

HRESULT playerBullet2::init(int bulletMax, float range)//플레이어총알 2단계 초기화
{
	_bulletMax = bulletMax;
	_range = range;

	return S_OK;
}

void playerBullet2::release()
{
}

void playerBullet2::update()//플레이어총알 2단계 업데이트
{
	move();
}

void playerBullet2::render()//플레이어총알 2단계 그리기
{
	for (_viPlayerBullet2 = _vPlayerBullet2.begin(); _viPlayerBullet2 != _vPlayerBullet2.end(); ++_viPlayerBullet2)
	{
		//Rectangle(getMemDC(), _viPlayerBullet2->rc);
		_viPlayerBullet2->bulletImage->frameRender(getMemDC(), _viPlayerBullet2->x, _viPlayerBullet2->y, _viPlayerBullet2->bulletImage->getFrameX(), _viPlayerBullet2->bulletImage->getFrameY());

		_viPlayerBullet2->count++;
		if (_viPlayerBullet2->count % 10 == 0)
		{
			_viPlayerBullet2->bulletImage->setFrameX(_viPlayerBullet2->bulletImage->getFrameX() + 1);
			if (_viPlayerBullet2->bulletImage->getFrameX() >= _viPlayerBullet2->bulletImage->getMaxFrameX())
			{
				_viPlayerBullet2->bulletImage->setFrameX(0);
			}

			_viPlayerBullet2->count = 0;
		}
	}
}

void playerBullet2::fire(float x, float y)//플레이어총알 2단계 발사
{
	if (_bulletMax < _vPlayerBullet2.size()) return;//현재 벡터에 담겨진 플레이어 총알 2단계가 총알의 멕스보다 커지면 실행하지 말아라

	tagBullet bullet;
	ZeroMemory(&bullet, sizeof(tagBullet));

	bullet.bulletImage = new image;
	bullet.bulletImage = IMAGEMANAGER->addFrameImage("playerBullet2", "image/playerAttack2.bmp", 124, 52, 4, 1, true, false, RGB(255,0,255));
	bullet.count = 0;
	bullet.x = bullet.fireX = x;
	bullet.y = bullet.fireY = y - 15;
	bullet.speed = 6.0f;
	bullet.rc = RectMake(bullet.x, bullet.y, bullet.bulletImage->getFrameWidth(), bullet.bulletImage->getFrameHeight());
	bullet.bulletImage->setFrameX(0);
	bullet.bulletImage->setFrameY(0);
	
	_vPlayerBullet2.push_back(bullet);
}

void playerBullet2::move()//플레이어 총알 2단계 무브
{
	for (_viPlayerBullet2 = _vPlayerBullet2.begin(); _viPlayerBullet2 != _vPlayerBullet2.end();)
	{
		_viPlayerBullet2->y -= _viPlayerBullet2->speed;
		_viPlayerBullet2->rc = RectMake(_viPlayerBullet2->x, _viPlayerBullet2->y, _viPlayerBullet2->bulletImage->getFrameWidth(), _viPlayerBullet2->bulletImage->getFrameHeight());

		if (_range < getDistance(_viPlayerBullet2->x, _viPlayerBullet2->y, _viPlayerBullet2->fireX, _viPlayerBullet2->fireY))
		{
			_viPlayerBullet2 = _vPlayerBullet2.erase(_viPlayerBullet2);
		}
		else
		{
			_viPlayerBullet2++;
		}
	}
}

void playerBullet2::removePlayerBullet2(int arrNum)//플레이어 총알 2단계 벡터삭제
{
	_vPlayerBullet2.erase(_vPlayerBullet2.begin() + arrNum);
}

HRESULT playerBullet3::init(int bulletMax, float range)//플레이어 총알 3단계 초기화
{
	_bulletMax = bulletMax;
	_range = range;

	return S_OK;
}

void playerBullet3::update()//플레이어 총알 3단계 업데이트
{
	move();
}

void playerBullet3::render()//플레이어 총알 3단계 그리기
{
	for (_viPlayerBullet3 = _vPlayerBullet3.begin(); _viPlayerBullet3 != _vPlayerBullet3.end(); _viPlayerBullet3++)
	{
		//Rectangle(getMemDC(), _viPlayerBullet3->rc);
		_viPlayerBullet3->bulletImage->frameRender(getMemDC(), _viPlayerBullet3->x, _viPlayerBullet3->y, _viPlayerBullet3->bulletImage->getFrameX(), _viPlayerBullet3->bulletImage->getFrameY());

		_viPlayerBullet3->count++;
		if (_viPlayerBullet3->count % 10 == 0)
		{
			_viPlayerBullet3->bulletImage->setFrameX(_viPlayerBullet3->bulletImage->getFrameX() + 1);
			if (_viPlayerBullet3->bulletImage->getFrameX() >= _viPlayerBullet3->bulletImage->getMaxFrameX())
			{
				_viPlayerBullet3->bulletImage->setFrameX(0);
			}
			_viPlayerBullet3->count = 0;
		}
	}
}

void playerBullet3::release()
{
}

void playerBullet3::move()//플레이어 총알 3단계 무브
{
	for (_viPlayerBullet3 = _vPlayerBullet3.begin(); _viPlayerBullet3 != _vPlayerBullet3.end();)
	{
		_viPlayerBullet3->y -= _viPlayerBullet3->speed;
		_viPlayerBullet3->rc = RectMake(_viPlayerBullet3->x, _viPlayerBullet3->y, _viPlayerBullet3->bulletImage->getFrameWidth(), _viPlayerBullet3->bulletImage->getFrameHeight());

		if (_range < getDistance(_viPlayerBullet3->x, _viPlayerBullet3->y, _viPlayerBullet3->fireX, _viPlayerBullet3->fireY))
		{
			_viPlayerBullet3 = _vPlayerBullet3.erase(_viPlayerBullet3);
		}
		else
		{
			_viPlayerBullet3++;
		}
	}
}

void playerBullet3::fire(float x, float y)//플레이어 총알 3단계 발사
{
	if (_bulletMax < _vPlayerBullet3.size()) return;//현재 플레이어 총알 3단계의 개수가 총알 멕스보다 커지면 실행하지 말아라 

	tagBullet bullet;
	ZeroMemory(&bullet, sizeof(tagBullet));

	bullet.bulletImage = IMAGEMANAGER->addFrameImage("playerBullet3", "image/playerAttack3.bmp", 124, 53, 4, 1, true, false, RGB(255, 0, 255));
	bullet.bulletImage->setFrameX(0);
	bullet.bulletImage->setFrameY(0);
	bullet.count = 0;
	bullet.x = bullet.fireX = x;
	bullet.y = bullet.fireY = y;
	bullet.speed = 6.0f;
	
	_vPlayerBullet3.push_back(bullet);
}

void playerBullet3::removePlayerBullet3(int arrNum)//플레이어 총알 3단계 삭제
{
	_vPlayerBullet3.erase(_vPlayerBullet3.begin() + arrNum);
}

HRESULT enemyBullet3::init(const char* imageName, int bulletMax, float range)//헬리콥터 적 총알 초기화
{
	_imageName = imageName;
	_bulletMax = bulletMax;
	_range = range;

	return S_OK;
}

void enemyBullet3::render()//헬리콥터 적 총알 그리기
{
	for (_viEnemyBullet3 = _vEnemyBullet3.begin(); _viEnemyBullet3 != _vEnemyBullet3.end(); _viEnemyBullet3++)
	{
		//Rectangle(getMemDC(), _viEnemyBullet3->rc);
		_viEnemyBullet3->bulletImage->frameRender(getMemDC(), _viEnemyBullet3->x, _viEnemyBullet3->y, _viEnemyBullet3->bulletImage->getFrameX(), _viEnemyBullet3->bulletImage->getFrameY());
	}

	for (int i = 0; i < _vEnemyBullet3.size(); i++)
	{
		_vEnemyBullet3[i].count++;

		if (_vEnemyBullet3[i].count % 10 == 0)
		{
			_vEnemyBullet3[i].bulletImage->setFrameX(_vEnemyBullet3[i].bulletImage->getFrameX() + 1);

			if (_vEnemyBullet3[i].bulletImage->getFrameX() >= _vEnemyBullet3[i].bulletImage->getMaxFrameX())
			{
				_vEnemyBullet3[i].bulletImage->setFrameX(0);
			}

			_vEnemyBullet3[i].count = 0;
		}
	}
}

void enemyBullet3::release()
{
}

void enemyBullet3::update()//헬리콥터 적 총알 업데이트
{
	move();
}

void enemyBullet3::fire(float x, float y, float speed)//헬리콥터 적 총알 발사
{
	if (_bulletMax < _vEnemyBullet3.size()) return;//현재 총알개수가 총알멕스보다 많아지면 실행하지 말아라
	tagBullet bullet;
	ZeroMemory(&bullet, sizeof(tagBullet));

	bullet.bulletImage = IMAGEMANAGER->findImage(_imageName);
	bullet.bulletImage->setFrameX(0);
	bullet.bulletImage->setFrameY(0);
	bullet.x = bullet.fireX = x;
	bullet.y = bullet.fireY = y;
	bullet.speed = speed;
	bullet.rc = RectMake(bullet.x, bullet.y, bullet.bulletImage->getFrameWidth(), bullet.bulletImage->getFrameHeight());
	
	_vEnemyBullet3.push_back(bullet);
}

void enemyBullet3::move()//헬리콥터 적 총알 무브
{
	for (_viEnemyBullet3 = _vEnemyBullet3.begin(); _viEnemyBullet3 != _vEnemyBullet3.end();)
	{
		_viEnemyBullet3->y += _viEnemyBullet3->speed;
		_viEnemyBullet3->rc = RectMake(_viEnemyBullet3->x, _viEnemyBullet3->y, _viEnemyBullet3->bulletImage->getFrameWidth(), _viEnemyBullet3->bulletImage->getFrameHeight());

		if (_range < getDistance(_viEnemyBullet3->x, _viEnemyBullet3->y, _viEnemyBullet3->fireX, _viEnemyBullet3->fireY))
		{
			_viEnemyBullet3 = _vEnemyBullet3.erase(_viEnemyBullet3);
		}
		else
		{
			_viEnemyBullet3++;
		}
	}
}

void enemyBullet3::removeEnemyBullet3(int arrNum)//헬리콥터 적 총알 벡터 삭제
{
	_vEnemyBullet3.erase(_vEnemyBullet3.begin() + arrNum);
}

HRESULT enemyJuneBullet::init(const char * imageName, int bulletMax, float range)//준보스 총알 초기화
{
	_imageName = imageName;
	_bulletMax = bulletMax;
	_range = range;
	return S_OK;
}

void enemyJuneBullet::render()//준보스 총알 그리기
{
	for (int i = 0; i < _vEnemyJuneBullet.size(); i++)
	{
		//Rectangle(getMemDC(), _vEnemyJuneBullet[i].rc);
		_vEnemyJuneBullet[i].bulletImage->render(getMemDC(), _vEnemyJuneBullet[i].x, _vEnemyJuneBullet[i].y);
	}
}

void enemyJuneBullet::release()
{
}

void enemyJuneBullet::update()//준보스 업데이트
{
	move();
}

void enemyJuneBullet::fire(float x, float y, float angle, float speed)//준보스 총알발사
{
	if (_bulletMax < _vEnemyJuneBullet.size()) return;//준보스의 현재 벡터에 담겨진 총알의 개수가 정해놓은 총알의 멕스개수보다 많아지면 실행하지 말아라

	tagBullet bullet;
	ZeroMemory(&bullet, sizeof(tagBullet));

	bullet.bulletImage = IMAGEMANAGER->findImage(_imageName);
	bullet.angle = angle;
	bullet.x = bullet.fireX = x;
	bullet.y = bullet.fireY = y;
	bullet.speed = speed;
	bullet.rc = RectMake(bullet.x, bullet.y, bullet.bulletImage->getWidth(), bullet.bulletImage->getHeight());

	_vEnemyJuneBullet.push_back(bullet);
}

void enemyJuneBullet::move()//준보스 총알 무브
{
	for (_viEnemyJuneBullet = _vEnemyJuneBullet.begin(); _viEnemyJuneBullet != _vEnemyJuneBullet.end();)
	{
		_viEnemyJuneBullet->x += cos(_viEnemyJuneBullet->angle) * _viEnemyJuneBullet->speed;
		_viEnemyJuneBullet->y += -sin(_viEnemyJuneBullet->angle) * _viEnemyJuneBullet->speed;

		_viEnemyJuneBullet->rc = RectMake(_viEnemyJuneBullet->x, _viEnemyJuneBullet->y, _viEnemyJuneBullet->bulletImage->getWidth(), _viEnemyJuneBullet->bulletImage->getHeight());

		if (_range < getDistance(_viEnemyJuneBullet->x, _viEnemyJuneBullet->y, _viEnemyJuneBullet->fireX, _viEnemyJuneBullet->fireY))//사거리 벗어나면
		{
			_viEnemyJuneBullet = _vEnemyJuneBullet.erase(_viEnemyJuneBullet);//벡터삭제
		}
		else
		{
			_viEnemyJuneBullet++;//다음벡터 확인
		}
	}
}

void enemyJuneBullet::removeEnemyJuneBullet(int arrNum)//준보스 총알삭제
{
	_vEnemyJuneBullet.erase(_vEnemyJuneBullet.begin() + arrNum);
}

HRESULT enemyBossBullet::init(const char * imageName, int bulletMax, float range)//보스 총알 초기화
{
	_imageName = imageName;
	_bulletMax = bulletMax;
	_range = range;

	return S_OK;
}

void enemyBossBullet::render()//보스 총알 그리기
{
	for (int i = 0; i < _vEnemyBossBullet.size(); i++)
	{
		//Rectangle(getMemDC(), _vEnemyBossBullet[i].rc);
		_vEnemyBossBullet[i].bulletImage->render(getMemDC(), _vEnemyBossBullet[i].x, _vEnemyBossBullet[i].y);
	}
}

void enemyBossBullet::release()
{
}

void enemyBossBullet::update()//보스 총알 업데이트
{
	move();
}

void enemyBossBullet::fire(float x, float y, float angle, float speed)//보스 총알 발사
{
	if (_bulletMax < _vEnemyBossBullet.size()) return;//보스의 현재 벡터에 담겨진 총알의 개수가 정해놓은 총알의 멕스개수보다 많아지면 실행하지 말아라

	tagBullet bullet;
	ZeroMemory(&bullet, sizeof(tagBullet));

	bullet.bulletImage = IMAGEMANAGER->findImage(_imageName);
	bullet.angle = angle;
	bullet.x = bullet.fireX = x;
	bullet.y = bullet.fireY = y;
	bullet.speed = speed;
	bullet.rc = RectMake(bullet.x, bullet.y, bullet.bulletImage->getWidth(), bullet.bulletImage->getHeight());

	_vEnemyBossBullet.push_back(bullet);
}

void enemyBossBullet::move()//보스 총알 무브
{
	for (_viEnemyBossBullet = _vEnemyBossBullet.begin(); _viEnemyBossBullet != _vEnemyBossBullet.end();)
	{
		_viEnemyBossBullet->x += cos(_viEnemyBossBullet->angle) * _viEnemyBossBullet->speed;
		_viEnemyBossBullet->y -= -sin(_viEnemyBossBullet->angle) * _viEnemyBossBullet->speed;

		_viEnemyBossBullet->rc = RectMake(_viEnemyBossBullet->x, _viEnemyBossBullet->y, _viEnemyBossBullet->bulletImage->getWidth(), _viEnemyBossBullet->bulletImage->getHeight());

		if (_range < getDistance(_viEnemyBossBullet->x, _viEnemyBossBullet->y, _viEnemyBossBullet->fireX, _viEnemyBossBullet->fireY))//사거리 벗어나면
		{
			_viEnemyBossBullet = _vEnemyBossBullet.erase(_viEnemyBossBullet);//벡터삭제
		}
		else
		{
			_viEnemyBossBullet++;//다음벡터 확인
		}
	}
}

void enemyBossBullet::removeEnemyBossBullet(int arrNum)//보스 총알 삭제
{
	_vEnemyBossBullet.erase(_vEnemyBossBullet.begin() + arrNum);
}

HRESULT enemyBossBullet2::init(const char * imageName, int bulletMax, float range)//보스 총알 2페이즈 초기화
{
	_imageName = imageName;
	_bulletMax = bulletMax;
	_range = range;
	return S_OK;
}

void enemyBossBullet2::render()//보스 총알 2페이즈 그리기
{
	for (int i = 0; i < _vEnemyBossBullet2.size(); i++)
	{
		//Rectangle(getMemDC(), _vEnemyBossBullet2[i].rc);
		_vEnemyBossBullet2[i].bulletImage->render(getMemDC(), _vEnemyBossBullet2[i].x, _vEnemyBossBullet2[i].y);
	}
}

void enemyBossBullet2::release()
{
}

void enemyBossBullet2::update()//보스 총알 2페이즈 업데이트
{
	move();
}

void enemyBossBullet2::fire(float x, float y, float angle, float speed)//보스 총알 2페이즈 발사
{
	if (_bulletMax < _vEnemyBossBullet2.size()) return;//보스의 현재 벡터에 담겨진 총알의 개수가 정해놓은 총알의 멕스개수보다 많아지면 실행하지 말아라

	tagBullet bullet;
	ZeroMemory(&bullet, sizeof(tagBullet));

	bullet.bulletImage = IMAGEMANAGER->findImage(_imageName);
	bullet.angle = angle;
	bullet.x = bullet.fireX = x;
	bullet.y = bullet.fireY = y;
	bullet.speed = speed;
	bullet.rc = RectMake(bullet.x, bullet.y, bullet.bulletImage->getWidth(), bullet.bulletImage->getHeight());

	_vEnemyBossBullet2.push_back(bullet);
}

void enemyBossBullet2::move()//보스 총알 2페이즈 무브
{
	for (_viEnemyBossBullet2 = _vEnemyBossBullet2.begin(); _viEnemyBossBullet2 != _vEnemyBossBullet2.end();)
	{
		_viEnemyBossBullet2->x += cos(_viEnemyBossBullet2->angle) * _viEnemyBossBullet2->speed;
		_viEnemyBossBullet2->y += -sin(_viEnemyBossBullet2->angle) * _viEnemyBossBullet2->speed;

		_viEnemyBossBullet2->rc = RectMake(_viEnemyBossBullet2->x, _viEnemyBossBullet2->y, _viEnemyBossBullet2->bulletImage->getWidth(), _viEnemyBossBullet2->bulletImage->getHeight());

		if (_range < getDistance(_viEnemyBossBullet2->x, _viEnemyBossBullet2->y, _viEnemyBossBullet2->fireX, _viEnemyBossBullet2->fireY))//사거리 벗어나면
		{
			_viEnemyBossBullet2 = _vEnemyBossBullet2.erase(_viEnemyBossBullet2);//벡터삭제
		}
		else
		{
			_viEnemyBossBullet2++;//다음벡터 확인
		}
	}
}

void enemyBossBullet2::removeEnemyBossBullet2(int arrNum)//보스 총알 2페이즈 삭제
{
	_vEnemyBossBullet2.erase(_vEnemyBossBullet2.begin() + arrNum);
}

HRESULT missile::init(int bulletMax, float range)
{
	_range = range;

	for (int i = 0; i < bulletMax; i++)
	{
		tagBullet bullet;
		ZeroMemory(&bullet, sizeof(bullet));
		bullet.bulletImage = new image;
		bullet.bulletImage->init("image/playerAttack.bmp", 0, 0,
			124, 53, 4, 1, true, false, RGB(255, 0, 255));
		bullet.bulletImage->setFrameX(0);
		bullet.bulletImage->setFrameY(0);
		bullet.speed = 6.0f;
		bullet.isFire = false;
		bullet.rc = RectMakeCenter(bullet.x, bullet.y, bullet.bulletImage->getFrameWidth(), bullet.bulletImage->getFrameHeight());

		_vBullet.push_back(bullet);
	}



	return S_OK;
}

void missile::release()
{
	//있? 없? 있? 없?!
	for (_viBullet = _vBullet.begin();
		_viBullet != _vBullet.end();
		++_viBullet)
	{
		_viBullet->bulletImage->release();
		SAFE_DELETE(_viBullet->bulletImage);
	}

	_vBullet.clear();
}

void missile::update()
{
	move();
}

void missile::render()
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		if (!_viBullet->isFire) continue;
		//Rectangle(getMemDC(), _viBullet->rc);
		_viBullet->bulletImage->frameRender(getMemDC(),
			_viBullet->rc.left,
			_viBullet->rc.top,
			_viBullet->bulletImage->getFrameX(), _viBullet->bulletImage->getFrameY());

		_viBullet->count++;

		if (_viBullet->count % 5 == 0)
		{
			_viBullet->bulletImage->setFrameX(_viBullet->bulletImage->getFrameX() + 1);

			if (_viBullet->bulletImage->getFrameX() >= _viBullet->bulletImage->getMaxFrameX())
			{
				_viBullet->bulletImage->setFrameX(0);
			}

			_viBullet->count = 0;
		}
	}
}

void missile::fire(float x, float y)
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		if (_viBullet->isFire) continue;

		_viBullet->isFire = true;

		_viBullet->x = _viBullet->fireX = x + 15;
		_viBullet->y = _viBullet->fireY = y;

		_viBullet->rc = RectMakeCenter(_viBullet->x, _viBullet->y,
			_viBullet->bulletImage->getFrameWidth(),
			_viBullet->bulletImage->getFrameHeight());

		break;
	}

}

void missile::move()
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		if (!_viBullet->isFire) continue;

		_viBullet->y -= _viBullet->speed;
		_viBullet->rc = RectMakeCenter(_viBullet->x, _viBullet->y,
			_viBullet->bulletImage->getFrameWidth(),
			_viBullet->bulletImage->getFrameHeight());

		//사거리 밖으로 나갔다
		if (_range < getDistance(_viBullet->fireX, _viBullet->fireY,
			_viBullet->x, _viBullet->y))
		{
			_viBullet->isFire = false;
		}
	}
}

void missile::removeBullet(int arrNum)
{
	_vBullet[arrNum].isFire = false;
}
