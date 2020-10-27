#pragma once
#include "gameNode.h"

enum PLAYERDIRECTION
{
	IDLE,
	LEFT_MOVE,
	RIGHT_MOVE
};

class player : public gameNode
{
private:
	PLAYERDIRECTION _direction;//�÷��̾� �̵� ������ ó���� ���� ����
	image* _player;//�÷��̾� �̹���
	RECT _rc;//�÷��̾� �浹�� ��Ʈ
	float _speed;//�÷��̾� ���ǵ�
	float _currentHP, _maxHP;//�÷��̾� HP
	int _x, _y;//�÷��̾� ������ǥ
	int _count, _index;//������ ó���� ���� ī��Ʈ

	char str[127];//������

public:
	player();
	~player();

	HRESULT init();
	void release();
	void render();
	void update();

	void move();
	RECT getPlayerRC() { return _rc; }//�÷��̾��� ��Ʈ�� �÷��� �׶��忡�� ������ �浹ó�� ���������� �������� �Լ�
	int getPlayerX() { return _x; }//�÷��̾� x��ǥ�� �÷��� �׶��忡�� �����ٰ� ������ ������ ��ġ�� �����ϱ� ���� �Լ�
	int getPlayerY() { return _y; }//�÷��̾� y��ǥ�� �÷��� �׶��忡�� �����ٰ� ������ ������ ��ġ�� �����ϱ� ���� �Լ�
	void setPlayerX(int x) { _x = x; }
	void setPlayerY(int y) { _y = y; }

	float getCurrentHP() { return _currentHP; }//�÷��̾� HP�� �÷��� �׶��忡�� �����ϱ� ���� �Լ�
	float getMaxHP() { return _maxHP; }//�÷��̾� maxHP�� �÷��� �׶��忡�� �����ϱ� ���� �Լ�
	void setCurrentHP(float currentHP) { _currentHP -= currentHP; }//�÷��̾� ���� HP�� �÷��� �׶��忡�� �����ϱ� ���� �Լ�
	void setCurrentPlusHP(float currentHP) { _currentHP = currentHP; }//�÷��̾� ���� HP�� �÷��� �׶��忡�� �����ϱ� ���� �Լ�
};

