#include "stdafx.h"
#include "enemy.h"

enemy::enemy()
{
}

enemy::~enemy()
{
}

HRESULT enemy::init()
{
	_CountFire = 0;
	_rndCountFire = RND->getFromIntTo(1, 100);
	//���� �Ѿ��� �߻��� Ȯ��

	for (int x = 1; x <= 3; x++)//�Ϲ���
	{
		tagEnemy enemy;
		ZeroMemory(&enemy, sizeof(tagEnemy));

		enemy.enemyImage = IMAGEMANAGER->addImage("enemy", "image/enemy.bmp", 52, 34, true, false, RGB(255, 0, 255));
		enemy.speed = 3;
		enemy.x = 150 * x;
		enemy.y = -100;
		enemy.rc = RectMakeCenter(enemy.x, enemy.y, enemy.enemyImage->getWidth(), enemy.enemyImage->getHeight());
		enemy.loop = false;//�Ϲ����� ������ ������ �Ϲ����� ȭ���� ����� �ٽ� ������ġ�� �̵���Ű�� ���� ����

		_vEnemy.push_back(enemy);
	}
	
	for (int x = 1; x <= 21; x++)//ufo ���ʿ��� ������
	{
		tagEnemy enemy;
		ZeroMemory(&enemy, sizeof(tagEnemy));

		enemy.enemyImage = IMAGEMANAGER->addFrameImage("ufo", "image/enemyUfo.bmp", 530, 32, 10, 1, true, false, RGB(255, 0, 255));
		enemy.speed = 5;
		enemy.x = -150 * x;

		if (x < 4)
		{
			enemy.y = -500;
		}
		else if (x < 7)
		{
			enemy.y = -500 * 2;
		}
		else if (x < 10)
		{
			enemy.y = -500 * 3;
		}
		else if (x < 13)
		{
			enemy.y = -500 * 4;
		}
		else if (x < 16)
		{
			enemy.y = -500 * 5;
		}
		else if (x < 19)
		{
			enemy.y = -500 * 6;
		}
		else if (x < 22)
		{
			enemy.y = -500 * 7;
		}
		
		enemy.angle = PI2 / 300;//60��
		enemy.rc = RectMakeCenter(enemy.x, enemy.y, enemy.enemyImage->getFrameWidth(), enemy.enemyImage->getFrameHeight());
		enemy.count = 0;//������ī��Ʈ
		enemy.moveCount = 0;//������Ʈ ī��Ʈ

		enemy.enemyImage->setFrameX(0);
		enemy.enemyImage->setFrameY(0);

		_vEnemyUfo.push_back(enemy);
	}
	
	for (int x = 1; x <= 21; x++)//ufo �����ʿ��� ����
	{
		tagEnemy enemy;
		ZeroMemory(&enemy, sizeof(tagEnemy));

		enemy.enemyImage = IMAGEMANAGER->addFrameImage("ufo", "image/enemyUfo.bmp", 530, 32, 10, 1, true, false, RGB(255, 0, 255));
		enemy.speed = 5;
		enemy.x = WINSIZEX + (150 * x);

		if (x < 4)
		{
			enemy.y = -1000;
		}
		else if (x < 7)
		{
			enemy.y = -1000 * 2;
		}
		else if (x < 10)
		{
			enemy.y = -1000 * 3;
		}
		else if (x < 13)
		{
			enemy.y = -1000 * 4;
		}
		else if (x < 16)
		{
			enemy.y = -1000 * 5;
		}
		else if (x < 19)
		{
			enemy.y = -1000 * 6;
		}
		else if (x < 22)
		{
			enemy.y = -1000 * 7;
		}

		enemy.angle = PI2 / 300;//60��
		enemy.rc = RectMakeCenter(enemy.x, enemy.y, enemy.enemyImage->getFrameWidth(), enemy.enemyImage->getFrameHeight());
		enemy.count = 0;//������ ī��Ʈ
		enemy.moveCount = 0;//������Ʈ ī��Ʈ

		enemy.enemyImage->setFrameX(0);
		enemy.enemyImage->setFrameY(0);

		_vEnemyUfo2.push_back(enemy);
	}

	for (int i = 1; i <= 21; i++)//�︮���� ��
	{
		tagEnemy enemy;
		ZeroMemory(&enemy, sizeof(tagEnemy));

		if (i == 1)
		{
			enemy.enemyImage = IMAGEMANAGER->addFrameImage("enemyHelicopter", "image/enemyHelicopter.bmp", 136, 50, 4, 2, true, false, RGB(255, 0, 255));
			enemy.x = 150 * 1;
		}
		if (i == 2)
		{
			enemy.enemyImage = IMAGEMANAGER->addFrameImage("enemyHelicopter2", "image/enemyHelicopter.bmp", 136, 50, 4, 2, true, false, RGB(255, 0, 255));
			enemy.x = 150 * 2;
		}
		if (i == 3)
		{
			enemy.enemyImage = IMAGEMANAGER->addFrameImage("enemyHelicopter3", "image/enemyHelicopter.bmp", 136, 50, 4, 2, true, false, RGB(255, 0, 255));
			enemy.x = 150 * 3;
		}
		if (i == 4)
		{
			enemy.enemyImage = IMAGEMANAGER->addFrameImage("enemyHelicopter4", "image/enemyHelicopter.bmp", 136, 50, 4, 2, true, false, RGB(255, 0, 255));
			enemy.x = 150 * 1;
		}
		if (i == 5)
		{
			enemy.enemyImage = IMAGEMANAGER->addFrameImage("enemyHelicopter5", "image/enemyHelicopter.bmp", 136, 50, 4, 2, true, false, RGB(255, 0, 255));
			enemy.x = 150 * 2;
		}
		if (i == 6)
		{
			enemy.enemyImage = IMAGEMANAGER->addFrameImage("enemyHelicopter6", "image/enemyHelicopter.bmp", 136, 50, 4, 2, true, false, RGB(255, 0, 255));
			enemy.x = 150 * 3;
		}
		if (i == 7)
		{
			enemy.enemyImage = IMAGEMANAGER->addFrameImage("enemyHelicopter7", "image/enemyHelicopter.bmp", 136, 50, 4, 2, true, false, RGB(255, 0, 255));
			enemy.x = 150 * 1;
		}
		if (i == 8)
		{
			enemy.enemyImage = IMAGEMANAGER->addFrameImage("enemyHelicopter8", "image/enemyHelicopter.bmp", 136, 50, 4, 2, true, false, RGB(255, 0, 255));
			enemy.x = 150 * 2;
		}
		if (i == 9)
		{
			enemy.enemyImage = IMAGEMANAGER->addFrameImage("enemyHelicopter9", "image/enemyHelicopter.bmp", 136, 50, 4, 2, true, false, RGB(255, 0, 255));
			enemy.x = 150 * 3;
		}
		if (i == 10)
		{
			enemy.enemyImage = IMAGEMANAGER->addFrameImage("enemyHelicopter10", "image/enemyHelicopter.bmp", 136, 50, 4, 2, true, false, RGB(255, 0, 255));
			enemy.x = 150 * 1;
		}
		if (i == 11)
		{
			enemy.enemyImage = IMAGEMANAGER->addFrameImage("enemyHelicopter11", "image/enemyHelicopter.bmp", 136, 50, 4, 2, true, false, RGB(255, 0, 255));
			enemy.x = 150 * 2;
		}
		if (i == 12)
		{
			enemy.enemyImage = IMAGEMANAGER->addFrameImage("enemyHelicopter12", "image/enemyHelicopter.bmp", 136, 50, 4, 2, true, false, RGB(255, 0, 255));
			enemy.x = 150 * 3;
		}
		if (i == 13)
		{
			enemy.enemyImage = IMAGEMANAGER->addFrameImage("enemyHelicopter13", "image/enemyHelicopter.bmp", 136, 50, 4, 2, true, false, RGB(255, 0, 255));
			enemy.x = 150 * 1;
		}
		if (i == 14)
		{
			enemy.enemyImage = IMAGEMANAGER->addFrameImage("enemyHelicopter14", "image/enemyHelicopter.bmp", 136, 50, 4, 2, true, false, RGB(255, 0, 255));
			enemy.x = 150 * 2;
		}
		if (i == 15)
		{
			enemy.enemyImage = IMAGEMANAGER->addFrameImage("enemyHelicopter15", "image/enemyHelicopter.bmp", 136, 50, 4, 2, true, false, RGB(255, 0, 255));
			enemy.x = 150 * 3;
		}
		if (i == 16)
		{
			enemy.enemyImage = IMAGEMANAGER->addFrameImage("enemyHelicopter16", "image/enemyHelicopter.bmp", 136, 50, 4, 2, true, false, RGB(255, 0, 255));
			enemy.x = 150 * 1;
		}
		if (i == 17)
		{
			enemy.enemyImage = IMAGEMANAGER->addFrameImage("enemyHelicopter17", "image/enemyHelicopter.bmp", 136, 50, 4, 2, true, false, RGB(255, 0, 255));
			enemy.x = 150 * 2;
		}
		if (i == 18)
		{
			enemy.enemyImage = IMAGEMANAGER->addFrameImage("enemyHelicopter18", "image/enemyHelicopter.bmp", 136, 50, 4, 2, true, false, RGB(255, 0, 255));
			enemy.x = 150 * 3;
		}
		if (i == 19)
		{
			enemy.enemyImage = IMAGEMANAGER->addFrameImage("enemyHelicopter19", "image/enemyHelicopter.bmp", 136, 50, 4, 2, true, false, RGB(255, 0, 255));
			enemy.x = 150 * 1;
		}
		if (i == 20)
		{
			enemy.enemyImage = IMAGEMANAGER->addFrameImage("enemyHelicopter20", "image/enemyHelicopter.bmp", 136, 50, 4, 2, true, false, RGB(255, 0, 255));
			enemy.x = 150 * 2;
		}
		if (i == 21)
		{
			enemy.enemyImage = IMAGEMANAGER->addFrameImage("enemyHelicopter21", "image/enemyHelicopter.bmp", 136, 50, 4, 2, true, false, RGB(255, 0, 255));
			enemy.x = 150 * 3;
		}

		if (i < 4)
		{
			enemy.y = -300;
		}
		else if (i < 7)
		{
			enemy.y = -300 * 2;
		}
		else if (i < 10)
		{
			enemy.y = -300 * 3;
		}
		else if (i < 13)
		{
			enemy.y = -300 * 4;
		}
		else if (i < 16)
		{
			enemy.y = -300 * 5;
		}
		else if (i < 19)
		{
			enemy.y = -300 * 6;
		}
		else if (i < 22)
		{
			enemy.y = -300 * 7;
		}

		enemy.speed = 3;
		enemy.rc = RectMake(enemy.x, enemy.y, enemy.enemyImage->getFrameWidth(), enemy.enemyImage->getFrameHeight());
		enemy.enemyImage->setFrameX(0);
		enemy.enemyImage->setFrameY(0);
		enemy.hit = false;

		_vEnemyHelicopter.push_back(enemy);
	}
	
	for (int i = 1; i <= 21; i++)//�︮���� ��
	{
		tagEnemy enemy;
		ZeroMemory(&enemy, sizeof(tagEnemy));

		if (i == 1)
		{
			enemy.enemyImage = IMAGEMANAGER->addFrameImage("enemyHelicopter", "image/enemyHelicopter.bmp", 136, 50, 4, 2, true, false, RGB(255, 0, 255));
			enemy.x = 150 * 1;
		}
		if (i == 2)
		{
			enemy.enemyImage = IMAGEMANAGER->addFrameImage("enemyHelicopter2", "image/enemyHelicopter.bmp", 136, 50, 4, 2, true, false, RGB(255, 0, 255));
			enemy.x = 150 * 2;
		}
		if (i == 3)
		{
			enemy.enemyImage = IMAGEMANAGER->addFrameImage("enemyHelicopter3", "image/enemyHelicopter.bmp", 136, 50, 4, 2, true, false, RGB(255, 0, 255));
			enemy.x = 150 * 3;
		}
		if (i == 4)
		{
			enemy.enemyImage = IMAGEMANAGER->addFrameImage("enemyHelicopter4", "image/enemyHelicopter.bmp", 136, 50, 4, 2, true, false, RGB(255, 0, 255));
			enemy.x = 150 * 1;
		}
		if (i == 5)
		{
			enemy.enemyImage = IMAGEMANAGER->addFrameImage("enemyHelicopter5", "image/enemyHelicopter.bmp", 136, 50, 4, 2, true, false, RGB(255, 0, 255));
			enemy.x = 150 * 2;
		}
		if (i == 6)
		{
			enemy.enemyImage = IMAGEMANAGER->addFrameImage("enemyHelicopter6", "image/enemyHelicopter.bmp", 136, 50, 4, 2, true, false, RGB(255, 0, 255));
			enemy.x = 150 * 3;
		}
		if (i == 7)
		{
			enemy.enemyImage = IMAGEMANAGER->addFrameImage("enemyHelicopter7", "image/enemyHelicopter.bmp", 136, 50, 4, 2, true, false, RGB(255, 0, 255));
			enemy.x = 150 * 1;
		}
		if (i == 8)
		{
			enemy.enemyImage = IMAGEMANAGER->addFrameImage("enemyHelicopter8", "image/enemyHelicopter.bmp", 136, 50, 4, 2, true, false, RGB(255, 0, 255));
			enemy.x = 150 * 2;
		}
		if (i == 9)
		{
			enemy.enemyImage = IMAGEMANAGER->addFrameImage("enemyHelicopter9", "image/enemyHelicopter.bmp", 136, 50, 4, 2, true, false, RGB(255, 0, 255));
			enemy.x = 150 * 3;
		}
		if (i == 10)
		{
			enemy.enemyImage = IMAGEMANAGER->addFrameImage("enemyHelicopter10", "image/enemyHelicopter.bmp", 136, 50, 4, 2, true, false, RGB(255, 0, 255));
			enemy.x = 150 * 1;
		}
		if (i == 11)
		{
			enemy.enemyImage = IMAGEMANAGER->addFrameImage("enemyHelicopter11", "image/enemyHelicopter.bmp", 136, 50, 4, 2, true, false, RGB(255, 0, 255));
			enemy.x = 150 * 2;
		}
		if (i == 12)
		{
			enemy.enemyImage = IMAGEMANAGER->addFrameImage("enemyHelicopter12", "image/enemyHelicopter.bmp", 136, 50, 4, 2, true, false, RGB(255, 0, 255));
			enemy.x = 150 * 3;
		}
		if (i == 13)
		{
			enemy.enemyImage = IMAGEMANAGER->addFrameImage("enemyHelicopter13", "image/enemyHelicopter.bmp", 136, 50, 4, 2, true, false, RGB(255, 0, 255));
			enemy.x = 150 * 1;
		}
		if (i == 14)
		{
			enemy.enemyImage = IMAGEMANAGER->addFrameImage("enemyHelicopter14", "image/enemyHelicopter.bmp", 136, 50, 4, 2, true, false, RGB(255, 0, 255));
			enemy.x = 150 * 2;
		}
		if (i == 15)
		{
			enemy.enemyImage = IMAGEMANAGER->addFrameImage("enemyHelicopter15", "image/enemyHelicopter.bmp", 136, 50, 4, 2, true, false, RGB(255, 0, 255));
			enemy.x = 150 * 3;
		}
		if (i == 16)
		{
			enemy.enemyImage = IMAGEMANAGER->addFrameImage("enemyHelicopter16", "image/enemyHelicopter.bmp", 136, 50, 4, 2, true, false, RGB(255, 0, 255));
			enemy.x = 150 * 1;
		}
		if (i == 17)
		{
			enemy.enemyImage = IMAGEMANAGER->addFrameImage("enemyHelicopter17", "image/enemyHelicopter.bmp", 136, 50, 4, 2, true, false, RGB(255, 0, 255));
			enemy.x = 150 * 2;
		}
		if (i == 18)
		{
			enemy.enemyImage = IMAGEMANAGER->addFrameImage("enemyHelicopter18", "image/enemyHelicopter.bmp", 136, 50, 4, 2, true, false, RGB(255, 0, 255));
			enemy.x = 150 * 3;
		}
		if (i == 19)
		{
			enemy.enemyImage = IMAGEMANAGER->addFrameImage("enemyHelicopter19", "image/enemyHelicopter.bmp", 136, 50, 4, 2, true, false, RGB(255, 0, 255));
			enemy.x = 150 * 1;
		}
		if (i == 20)
		{
			enemy.enemyImage = IMAGEMANAGER->addFrameImage("enemyHelicopter20", "image/enemyHelicopter.bmp", 136, 50, 4, 2, true, false, RGB(255, 0, 255));
			enemy.x = 150 * 2;
		}
		if (i == 21)
		{
			enemy.enemyImage = IMAGEMANAGER->addFrameImage("enemyHelicopter21", "image/enemyHelicopter.bmp", 136, 50, 4, 2, true, false, RGB(255, 0, 255));
			enemy.x = 150 * 3;
		}

		if (i < 4)
		{
			enemy.y = -300;
		}
		else if (i < 7)
		{
			enemy.y = -300 * 2;
		}
		else if (i < 10)
		{
			enemy.y = -300 * 3;
		}
		else if (i < 13)
		{
			enemy.y = -300 * 4;
		}
		else if (i < 16)
		{
			enemy.y = -300 * 5;
		}
		else if (i < 19)
		{
			enemy.y = -300 * 6;
		}
		else if (i < 22)
		{
			enemy.y = -300 * 7;
		}

		enemy.speed = 3;
		enemy.rc = RectMake(enemy.x, enemy.y, enemy.enemyImage->getFrameWidth(), enemy.enemyImage->getFrameHeight());
		enemy.enemyImage->setFrameX(0);
		enemy.enemyImage->setFrameY(0);
		enemy.hit = false;

		_vEnemyHelicopter2.push_back(enemy);
	}

	_count = 0;//�︮���� �����ӿ� ����� ī��Ʈ
	_count2 = 0;
	return S_OK;
}

void enemy::release()
{
}

void enemy::render()
{
	for (_viEnemy = _vEnemy.begin(); _viEnemy != _vEnemy.end(); ++_viEnemy)
	{
		//Rectangle(getMemDC(), _viEnemy->rc);//��Ʈ�浹 Ȯ�ο�
		IMAGEMANAGER->findImage("enemy")->render(getMemDC(), _viEnemy->rc.left, _viEnemy->rc.top);
	}
	
	for (_viEnemyUfo = _vEnemyUfo.begin(); _viEnemyUfo != _vEnemyUfo.end(); ++_viEnemyUfo)//���ʿ��� ���������� ufo
	{
		//Rectangle(getMemDC(), _viEnemyUfo->rc);//��Ʈ�浹 Ȯ�ο�
		_viEnemyUfo->enemyImage->frameRender(getMemDC(), _viEnemyUfo->rc.left, _viEnemyUfo->rc.top, _viEnemyUfo->enemyImage->getFrameX(), _viEnemyUfo->enemyImage->getFrameY());
	}
	
	for (_viEnemyUfo2 = _vEnemyUfo2.begin(); _viEnemyUfo2 != _vEnemyUfo2.end(); ++_viEnemyUfo2)//�����ʿ��� �������� ufo
	{
		//Rectangle(getMemDC(), _viEnemyUfo2->rc);//��Ʈ�浹 Ȯ�ο�
		_viEnemyUfo2->enemyImage->frameRender(getMemDC(), _viEnemyUfo2->rc.left, _viEnemyUfo2->rc.top, _viEnemyUfo2->enemyImage->getFrameX(), _viEnemyUfo2->enemyImage->getFrameY());
	}

	for (int i = 0; i < _vEnemyUfo.size(); i++)//���ʿ��� ������ ufo ������
	{
		_vEnemyUfo[i].count++;
		if (_vEnemyUfo[i].count % 20 == 0)
		{
				_vEnemyUfo[i].enemyImage->setFrameX(_vEnemyUfo[i].enemyImage->getFrameX() + 1);

			if (_vEnemyUfo[i].enemyImage->getFrameX() >= _vEnemyUfo[i].enemyImage->getMaxFrameX())
			{
				_vEnemyUfo[i].enemyImage->setFrameX(0);
			}
			_vEnemyUfo[i].count = 0;
		}
	}

	for (int i = 0; i < _vEnemyUfo2.size(); i++)//�����ʿ��� ���� ufo ������
	{
		_vEnemyUfo2[i].count++;
		if (_vEnemyUfo2[i].count % 20 == 0)
		{
			_vEnemyUfo2[i].enemyImage->setFrameX(_vEnemyUfo2[i].enemyImage->getFrameX() + 1);

			if (_vEnemyUfo2[i].enemyImage->getFrameX() >= _vEnemyUfo2[i].enemyImage->getMaxFrameX())
			{
				_vEnemyUfo2[i].enemyImage->setFrameX(0);
			}
			_vEnemyUfo2[i].count = 0;
		}
	}

	for (int i = 0; i < _vEnemyHelicopter.size(); i++)//�︮���� ��
	{
		//Rectangle(getMemDC(), _vEnemyHelicopter[i].rc);//�︮���� ���� ��ƮȮ�ο�
		_vEnemyHelicopter[i].enemyImage->frameRender(getMemDC(), _vEnemyHelicopter[i].x, _vEnemyHelicopter[i].y, _vEnemyHelicopter[i].enemyImage->getFrameX(), _vEnemyHelicopter[i].enemyImage->getFrameY());//�︮���� �� ������
	}
	
	for (int i = 0; i < _vEnemyHelicopter2.size(); i++)//�︮���� ��
	{
		//Rectangle(getMemDC(), _vEnemyHelicopter[i].rc);//�︮���� ���� ��ƮȮ�ο�
		_vEnemyHelicopter2[i].enemyImage->frameRender(getMemDC(), _vEnemyHelicopter2[i].x, _vEnemyHelicopter2[i].y, _vEnemyHelicopter2[i].enemyImage->getFrameX(), _vEnemyHelicopter2[i].enemyImage->getFrameY());//�︮���� �� ������
	}

	_count++;//�︮���� �����ӿ� ����� ī��Ʈ
	for (int i = 0; i < _vEnemyHelicopter.size(); i++)//�︮���� ��
	{
		if (_count % 5 == 0)
		{
			if (i == 0)
			{
				if (_vEnemyHelicopter[i].y >= 100 && !_vEnemyHelicopter[i].hit)
				{
					_vEnemyHelicopter[i].enemyImage->setFrameY(1);
					if (_vEnemyHelicopter[i].enemyImage->getFrameX() <= _vEnemyHelicopter[i].enemyImage->getMaxFrameX())
					{
						_vEnemyHelicopter[i].enemyImage->setFrameX(_vEnemyHelicopter[i].enemyImage->getFrameX() + 1);
					}
				}
				else if (_vEnemyHelicopter[i].y >= 100 && _vEnemyHelicopter[i].hit)
				{
					_vEnemyHelicopter[i].enemyImage->setFrameY(0);
					if (_vEnemyHelicopter[i].enemyImage->getFrameX() <= _vEnemyHelicopter[i].enemyImage->getMaxFrameX())
					{
						_vEnemyHelicopter[i].enemyImage->setFrameX(_vEnemyHelicopter[i].enemyImage->getFrameX() + 1);
					}
				}
				if (_vEnemyHelicopter[i].x >= WINSIZEX - 30 || _vEnemyHelicopter[i].x <= 0)
				{
					_vEnemyHelicopter[i].enemyImage->setFrameX(0);
				}
			}

			if (i == 1)
			{
				if (_vEnemyHelicopter[i].y >= 100 && !_vEnemyHelicopter[i].hit)
				{
					_vEnemyHelicopter[i].enemyImage->setFrameY(1);
					if (_vEnemyHelicopter[i].enemyImage->getFrameX() <= _vEnemyHelicopter[i].enemyImage->getMaxFrameX())
					{
						_vEnemyHelicopter[i].enemyImage->setFrameX(_vEnemyHelicopter[i].enemyImage->getFrameX() + 1);
					}
				}
				else if (_vEnemyHelicopter[i].y >= 100 && _vEnemyHelicopter[i].hit)
				{
					_vEnemyHelicopter[i].enemyImage->setFrameY(0);
					if (_vEnemyHelicopter[i].enemyImage->getFrameX() <= _vEnemyHelicopter[i].enemyImage->getMaxFrameX())
					{
						_vEnemyHelicopter[i].enemyImage->setFrameX(_vEnemyHelicopter[i].enemyImage->getFrameX() + 1);
					}
				}
				if (_vEnemyHelicopter[i].x >= WINSIZEX - 30 || _vEnemyHelicopter[i].x <= 0)
				{
					_vEnemyHelicopter[i].enemyImage->setFrameX(0);
				}
			}

			if (i == 2)
			{
				if (_vEnemyHelicopter[i].y >= 100 && !_vEnemyHelicopter[i].hit)
				{
					_vEnemyHelicopter[i].enemyImage->setFrameY(1);
					if (_vEnemyHelicopter[i].enemyImage->getFrameX() <= _vEnemyHelicopter[i].enemyImage->getMaxFrameX())
					{
						_vEnemyHelicopter[i].enemyImage->setFrameX(_vEnemyHelicopter[i].enemyImage->getFrameX() + 1);
					}
				}
				else if (_vEnemyHelicopter[i].y >= 100 && _vEnemyHelicopter[i].hit)
				{
					_vEnemyHelicopter[i].enemyImage->setFrameY(0);
					if (_vEnemyHelicopter[i].enemyImage->getFrameX() <= _vEnemyHelicopter[i].enemyImage->getMaxFrameX())
					{
						_vEnemyHelicopter[i].enemyImage->setFrameX(_vEnemyHelicopter[i].enemyImage->getFrameX() + 1);
					}
				}
				if (_vEnemyHelicopter[i].x >= WINSIZEX - 30 || _vEnemyHelicopter[i].x <= 0)
				{
					_vEnemyHelicopter[i].enemyImage->setFrameX(0);
				}
			}
			_count = 0;
		}
	}

	//2������ �︮���� �� ������ ������
	_count2++;
	for (int i = 0; i < _vEnemyHelicopter2.size(); i++)//�︮���� ��
	{
		if (_count2 % 5 == 0)
		{
			if (i == 0)
			{
				if (_vEnemyHelicopter2[i].y >= 100 && !_vEnemyHelicopter2[i].hit)
				{
					_vEnemyHelicopter2[i].enemyImage->setFrameY(1);
					if (_vEnemyHelicopter2[i].enemyImage->getFrameX() <= _vEnemyHelicopter2[i].enemyImage->getMaxFrameX())
					{
						_vEnemyHelicopter2[i].enemyImage->setFrameX(_vEnemyHelicopter2[i].enemyImage->getFrameX() + 1);
					}
				}
				else if (_vEnemyHelicopter2[i].y >= 100 && _vEnemyHelicopter2[i].hit)
				{
					_vEnemyHelicopter2[i].enemyImage->setFrameY(0);
					if (_vEnemyHelicopter2[i].enemyImage->getFrameX() <= _vEnemyHelicopter2[i].enemyImage->getMaxFrameX())
					{
						_vEnemyHelicopter2[i].enemyImage->setFrameX(_vEnemyHelicopter2[i].enemyImage->getFrameX() + 1);
					}
				}
				if (_vEnemyHelicopter2[i].x >= WINSIZEX - 30 || _vEnemyHelicopter2[i].x <= 0)
				{
					_vEnemyHelicopter2[i].enemyImage->setFrameX(0);
				}
			}

			if (i == 1)
			{
				if (_vEnemyHelicopter2[i].y >= 100 && !_vEnemyHelicopter2[i].hit)
				{
					_vEnemyHelicopter2[i].enemyImage->setFrameY(1);
					if (_vEnemyHelicopter2[i].enemyImage->getFrameX() <= _vEnemyHelicopter2[i].enemyImage->getMaxFrameX())
					{
						_vEnemyHelicopter2[i].enemyImage->setFrameX(_vEnemyHelicopter2[i].enemyImage->getFrameX() + 1);
					}
				}
				else if (_vEnemyHelicopter2[i].y >= 100 && _vEnemyHelicopter2[i].hit)
				{
					_vEnemyHelicopter2[i].enemyImage->setFrameY(0);
					if (_vEnemyHelicopter2[i].enemyImage->getFrameX() <= _vEnemyHelicopter2[i].enemyImage->getMaxFrameX())
					{
						_vEnemyHelicopter2[i].enemyImage->setFrameX(_vEnemyHelicopter2[i].enemyImage->getFrameX() + 1);
					}
				}
				if (_vEnemyHelicopter2[i].x >= WINSIZEX - 30 || _vEnemyHelicopter2[i].x <= 0)
				{
					_vEnemyHelicopter2[i].enemyImage->setFrameX(0);
				}
			}

			if (i == 2)
			{
				if (_vEnemyHelicopter2[i].y >= 100 && !_vEnemyHelicopter2[i].hit)
				{
					_vEnemyHelicopter2[i].enemyImage->setFrameY(1);
					if (_vEnemyHelicopter2[i].enemyImage->getFrameX() <= _vEnemyHelicopter2[i].enemyImage->getMaxFrameX())
					{
						_vEnemyHelicopter2[i].enemyImage->setFrameX(_vEnemyHelicopter2[i].enemyImage->getFrameX() + 1);
					}
				}
				else if (_vEnemyHelicopter2[i].y >= 100 && _vEnemyHelicopter2[i].hit)
				{
					_vEnemyHelicopter2[i].enemyImage->setFrameY(0);
					if (_vEnemyHelicopter2[i].enemyImage->getFrameX() <= _vEnemyHelicopter2[i].enemyImage->getMaxFrameX())
					{
						_vEnemyHelicopter2[i].enemyImage->setFrameX(_vEnemyHelicopter2[i].enemyImage->getFrameX() + 1);
					}
				}
				if (_vEnemyHelicopter2[i].x >= WINSIZEX - 30 || _vEnemyHelicopter2[i].x <= 0)
				{
					_vEnemyHelicopter2[i].enemyImage->setFrameX(0);
				}
			}
			_count2 = 0;
		}
	}
	//2������ �︮���� �� ������ ����
		
}

void enemy::update()
{
	move();
}

void enemy::removeEnemy(int arrNum)//�Ϲ��� ���Ϳ��� ����
{
	_vEnemy.erase(_vEnemy.begin() + arrNum);
}

void enemy::removeEnemyUfo(int arrNum)//���ʿ��� ������ ufo ����
{
	_vEnemyUfo.erase(_vEnemyUfo.begin() + arrNum);
}

void enemy::removeEnemyUfo2(int arrNum)//�����ʿ��� ���� ufo ����
{
	_vEnemyUfo2.erase(_vEnemyUfo2.begin() + arrNum);
}

void enemy::removeEnemyHelicopter(int arrNum)//�︮���� �� ����
{
	_vEnemyHelicopter.erase(_vEnemyHelicopter.begin() + arrNum);
}

void enemy::removeEnemyHelicopter2(int arrNum)//2������ ��
{
	_vEnemyHelicopter2.erase(_vEnemyHelicopter2.begin() + arrNum);
}

void enemy::move()
{
	for (_viEnemy = _vEnemy.begin(); _viEnemy != _vEnemy.end(); ++_viEnemy)//�Ϲ���
	{
		if (!_viEnemy->loop)//�Ϲ��� ��ġ�� �ϴ��� �Ѿ�� �ʱ�ȭ
		{
			_viEnemy->y += _viEnemy->speed;
		}
		if (_viEnemy->rc.top > WINSIZEY)
		{
			_viEnemy->y = -100;
			_viEnemy->loop = true;
		}
		if (_viEnemy->rc.bottom < 0)
		{
			_viEnemy->loop = false;
		}
		_viEnemy->rc = RectMakeCenter(_viEnemy->x, _viEnemy->y, _viEnemy->enemyImage->getWidth(), _viEnemy->enemyImage->getHeight());
	}
	
	for (int i = 0; i < _vEnemyUfo.size(); i++)//���ʿ��� ������ ufo
	{
		if (_vEnemyUfo[i].y < 300)//ufo�� y�� ��ǥ�� 300���� �̵�
		{
			_vEnemyUfo[i].y += _vEnemyUfo[i].speed;
			_vEnemyUfo[i].rc = RectMakeCenter(_vEnemyUfo[i].x, _vEnemyUfo[i].y, _vEnemyUfo[i].enemyImage->getFrameWidth(), _vEnemyUfo[i].enemyImage->getFrameHeight());
		}
		else
		{
			if (_vEnemyUfo[i].x < 0)
			{
				_vEnemyUfo[i].x += _vEnemyUfo[i].speed;
				_vEnemyUfo[i].rc = RectMakeCenter(_vEnemyUfo[i].x, _vEnemyUfo[i].y, _vEnemyUfo[i].enemyImage->getFrameWidth(), _vEnemyUfo[i].enemyImage->getFrameHeight());
			}
			else
			{
				_vEnemyUfo[i].y += cos(_vEnemyUfo[i].angle) * _vEnemyUfo[i].speed;
				_vEnemyUfo[i].x += sin(_vEnemyUfo[i].angle) * _vEnemyUfo[i].speed;
				_vEnemyUfo[i].rc = RectMakeCenter(_vEnemyUfo[i].x, _vEnemyUfo[i].y, _vEnemyUfo[i].enemyImage->getFrameWidth(), _vEnemyUfo[i].enemyImage->getFrameHeight());
				for (int j = 359; j >= 300; j--)
				{
					_vEnemyUfo[i].moveCount++;
					if (_vEnemyUfo[i].moveCount % 100 == 0)
					{
						_vEnemyUfo[i].angle += PI2 / j;
						_vEnemyUfo[i].moveCount = 0;
					}
				}
			}
		}
	}

	for (int i = 0; i < _vEnemyUfo2.size(); i++)//�����ʿ��� ���� ufo
	{
		if (_vEnemyUfo2[i].y < 300)//ufo�� y�� ��ǥ�� 300���� �̵�
		{
			_vEnemyUfo2[i].y += _vEnemyUfo2[i].speed;
			_vEnemyUfo2[i].rc = RectMakeCenter(_vEnemyUfo2[i].x, _vEnemyUfo2[i].y, _vEnemyUfo2[i].enemyImage->getFrameWidth(), _vEnemyUfo2[i].enemyImage->getFrameHeight());
		}
		else
		{
			if (_vEnemyUfo2[i].x > WINSIZEX)
			{
				_vEnemyUfo2[i].x -= _vEnemyUfo2[i].speed;
				_vEnemyUfo2[i].rc = RectMakeCenter(_vEnemyUfo2[i].x, _vEnemyUfo2[i].y, _vEnemyUfo2[i].enemyImage->getFrameWidth(), _vEnemyUfo2[i].enemyImage->getFrameHeight());
			}
			else
			{
				_vEnemyUfo2[i].y += cos(_vEnemyUfo2[i].angle) * _vEnemyUfo2[i].speed;
				_vEnemyUfo2[i].x -= sin(_vEnemyUfo2[i].angle) * _vEnemyUfo2[i].speed;
				_vEnemyUfo2[i].rc = RectMakeCenter(_vEnemyUfo2[i].x, _vEnemyUfo2[i].y, _vEnemyUfo2[i].enemyImage->getFrameWidth(), _vEnemyUfo2[i].enemyImage->getFrameHeight());
				for (int j = 359; j >= 300; j--)
				{
					_vEnemyUfo2[i].moveCount++;
					if (_vEnemyUfo2[i].moveCount % 100 == 0)
					{
						_vEnemyUfo2[i].angle += PI2 / j;
						_vEnemyUfo2[i].moveCount = 0;
					}
				}
			}
		}
	}

	for (int i = 0; i < _vEnemyHelicopter.size(); i++)//�︮���� ��
	{
		if (_vEnemyHelicopter[i].y <= 100)
		{
			_vEnemyHelicopter[i].y += _vEnemyHelicopter[i].speed;
		}
		
		if (_vEnemyHelicopter[i].y >= 100 && _vEnemyHelicopter[i].x >= 0 && !_vEnemyHelicopter[i].hit)
		{
			_vEnemyHelicopter[i].x -= _vEnemyHelicopter[i].speed;
		}
		else
		{
			_vEnemyHelicopter[i].hit = true;
		}

		if (_vEnemyHelicopter[i].y >= 100 && _vEnemyHelicopter[i].x <= WINSIZEX && _vEnemyHelicopter[i].hit)
		{
			_vEnemyHelicopter[i].x += _vEnemyHelicopter[i].speed;
		}
		else
		{
			_vEnemyHelicopter[i].hit = false;
		}
		
		_vEnemyHelicopter[i].rc = RectMake(_vEnemyHelicopter[i].x, _vEnemyHelicopter[i].y, _vEnemyHelicopter[i].enemyImage->getFrameWidth(), _vEnemyHelicopter[i].enemyImage->getFrameHeight());
	}
}

void enemy::move2()
{
	for (int i = 0; i < _vEnemyHelicopter2.size(); i++)//�︮���� ��
	{
		if (_vEnemyHelicopter2[i].y <= 100)
		{
			_vEnemyHelicopter2[i].y += _vEnemyHelicopter2[i].speed;
		}

		if (_vEnemyHelicopter2[i].y >= 100 && _vEnemyHelicopter2[i].x >= 0 && !_vEnemyHelicopter2[i].hit)
		{
			_vEnemyHelicopter2[i].x -= _vEnemyHelicopter2[i].speed;
		}
		else
		{
			_vEnemyHelicopter2[i].hit = true;
		}

		if (_vEnemyHelicopter2[i].y >= 100 && _vEnemyHelicopter2[i].x <= WINSIZEX && _vEnemyHelicopter2[i].hit)
		{
			_vEnemyHelicopter2[i].x += _vEnemyHelicopter2[i].speed;
		}
		else
		{
			_vEnemyHelicopter2[i].hit = false;
		}

		_vEnemyHelicopter2[i].rc = RectMake(_vEnemyHelicopter2[i].x, _vEnemyHelicopter2[i].y, _vEnemyHelicopter2[i].enemyImage->getFrameWidth(), _vEnemyHelicopter2[i].enemyImage->getFrameHeight());
	}
}

bool enemy::bulletCountfire()//�Ѿ˹߻� ��ȣ�� �÷��� �׶���� �����ֱ� ���� �Լ�
{
	_CountFire++;

	if (_CountFire % _rndCountFire == 0)
	{
		_rndCountFire = RND->getFromIntTo(1, 100);
		_CountFire = 0;
		return true;
	}

	return false;
}
