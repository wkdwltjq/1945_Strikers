#include "stdafx.h"
#include "item.h"

HRESULT item::init()//������ �ʱ�ȭ
{
	_bombCount = 2;//��ź�⺻ 2��
	_attackCount = 1;//�⺻ �÷��̾� ���� 1�ܰ�
	_rndItemFire = RND->getFromIntTo(1, 30);//�������� ����Ȯ��
	_rndItemFireCount = 0;//�������� ����Ȯ���� ����� ī��Ʈ
	_bombCountImage = IMAGEMANAGER->addImage("bombCount", "image/playerBombCount.bmp", 32, 30, true, false, RGB(255, 0, 255));//�����ϴܿ� ��ź���� �̹���

	return S_OK;
}

void item::render()//������ �׸���
{
	for (int i = 0; i < _vBombItem.size(); i++)
	{
		//Rectangle(getMemDC(), _vBombItem[i].rc);//��ź������ ��Ʈ

		_vBombItem[i].imageName->frameRender(getMemDC(), _vBombItem[i].x, _vBombItem[i].y, _vBombItem[i].imageName->getFrameX(), _vBombItem[i].imageName->getFrameY());//��ź������ ������ �׸���
		
		_vBombItem[i].count++;
		if (_vBombItem[i].count % 10 == 0)//��ź������ ī��Ʈ�� 5�ʸ���
		{
			_vBombItem[i].imageName->setFrameX(_vBombItem[i].imageName->getFrameX() + 1);//��ź������ ������ 1�� ����
			if (_vBombItem[i].imageName->getFrameX() >= _vBombItem[i].imageName->getMaxFrameX())//��ź�������� �������� ���� �����ϸ� 0���� �ʱ�ȭ
			{
				_vBombItem[i].imageName->setFrameX(0);//��ź������ ������ 0���� �ʱ�ȭ
			}
			_vBombItem[i].count = 0;//��ź������ ī��Ʈ 0���� �ʱ�ȭ
		}
	}

	for (int i = 0; i < _vAttackItem.size(); i++)//���ݷ°�ȭ ������
	{
		//Rectangle(getMemDC(), _vAttackItem[i].rc);//���ݷ°�ȭ ������ ��Ʈ
		_vAttackItem[i].imageName->frameRender(getMemDC(), _vAttackItem[i].x, _vAttackItem[i].y, _vAttackItem[i].imageName->getFrameX(), _vAttackItem[i].imageName->getFrameY());//���ݷ°�ȭ ������ ������

		_vAttackItem[i].count++;//���ݷ� ��ȭ ������ ī��Ʈ ����
		if (_vAttackItem[i].count % 10 == 0)
		{
			_vAttackItem[i].imageName->setFrameX(_vAttackItem[i].imageName->getFrameX() + 1);//���ݷ°�ȭ ������ ������1������
			if (_vAttackItem[i].imageName->getFrameX() >= _vAttackItem[i].imageName->getMaxFrameX())//���ݷ°�ȭ ������ �������� ���� �����ϸ�
			{
				_vAttackItem[i].imageName->setFrameX(0);//���ݷ°�ȭ ������ �������� �ʱ�ȭ
			}
			_vAttackItem[i].count = 0;//���ݷ°�ȭ �������� ī��Ʈ �ʱ�ȭ
		}
	}

	for (int i = 0; i < _vHpItem.size(); i++)//hp ������
	{
		//Rectangle(getMemDC(), _vHpItem[i].rc);//hp ������ ��Ʈ
		_vHpItem[i].imageName->render(getMemDC(), _vHpItem[i].x, _vHpItem[i].y);//hp ������ ������
	}

	if (_bombCount == 1)//��ź������ 1���ϰ��
	{
		_bombCountImage->render(getMemDC(), 10, WINSIZEY - 50);//�����ϴܿ� ��ź���� �̹��� �׸���
	}

	if (_bombCount == 2)//��ź������ 2���ϰ��
	{
		_bombCountImage->render(getMemDC(), 10, WINSIZEY - 50);//�����ϴܿ� ��ź���� �̹��� �׸���
		_bombCountImage->render(getMemDC(), 40, WINSIZEY - 50);//�����ϴܿ� ��ź���� �̹��� �׸���
	}

	if (_bombCount == 3)//��ź������ 3���ϰ��
	{
		_bombCountImage->render(getMemDC(), 10, WINSIZEY - 50);//�����ϴܿ� ��ź���� �̹��� �׸���
		_bombCountImage->render(getMemDC(), 40, WINSIZEY - 50);//�����ϴܿ� ��ź���� �̹��� �׸���
		_bombCountImage->render(getMemDC(), 70, WINSIZEY - 50);//�����ϴܿ� ��ź���� �̹��� �׸���
	}
	
}

void item::update()//������ ������Ʈ
{
	move();//������ ����
}

void item::release()
{
}

void item::move()//������ ����
{
	for (int i = 0; i < _vBombItem.size(); i++)//��ź������
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

	if (_bombCount < 0)//��ź������ 0���� �۾����� �ʰ� �ϱ����� ���ǹ�
	{
		_bombCount++;
	}

	for (int i = 0; i < _vAttackItem.size(); i++)//���ݷ°�ȭ ������
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

	for (int i = 0; i < _vHpItem.size(); i++)//hp ������
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

void item::removeBombItem(int arrNum)//��ź������ ���� ����
{
	_vBombItem.erase(_vBombItem.begin() + arrNum);
}

void item::removeAttackItem(int arrNum)//���ݷ°�ȭ ���� ������ ����
{
	_vAttackItem.erase(_vAttackItem.begin() + arrNum);
}

void item::removeHpItem(int arrNum)
{
	_vHpItem.erase(_vHpItem.begin() + arrNum);
}

void item::bombItemFire(float x, float y)//��ź������ ����
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

void item::attackItemFire(float x, float y)//���ݷ°�ȭ ������ ����
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

void item::hpItemFire(float x, float y)//ȸ�� ������ ����
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

bool item::itemCountFire()//�������� ����Ȯ��
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
