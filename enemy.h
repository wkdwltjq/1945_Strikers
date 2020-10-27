#pragma once
#include "gameNode.h"
//#define COUNT 3

struct tagEnemy
{
	image* enemyImage;//���̹���
	RECT rc;//�浹������ ���� ����Ʈ
	float speed;//�����ǵ�
	float angle;//ufo �� ������
	int x, y;//��������ǥ
	int count;//������ ī��Ʈ
	int moveCount;//����ī��Ʈ
	bool loop;//�Ϲ����� ȭ����� ����� ��ġ�� �ʱ�ȭ ��Ű�� ���� ����
	bool hit;//���� �ε����� �ݴ�������� �̵���Ű�� ���� �ʿ��� ����
};

class enemy : public gameNode
{
private:
	vector<tagEnemy>			_vEnemy;
	vector<tagEnemy>::iterator	_viEnemy;//�Ϲ���

	vector<tagEnemy>			_vEnemyUfo;
	vector<tagEnemy>::iterator	_viEnemyUfo;//���ʿ��� ���������� ������ ufo

	vector<tagEnemy>			_vEnemyUfo2;
	vector<tagEnemy>::iterator	_viEnemyUfo2;//�����ʿ��� �������� ������ ufo

	vector<tagEnemy>			_vEnemyHelicopter;
	vector<tagEnemy>::iterator  _viEnemyHelicopter;//�︮���� ��

	vector<tagEnemy>			_vEnemyHelicopter2;
	vector<tagEnemy>::iterator  _viEnemyHelicopter2;//�︮���� ��

	//int _count[COUNT];//���� �ٸ� ������ ����� ���� ī��Ʈ
	int _count;//�︮���� �����ӿ� ����� ī��Ʈ
	int _count2;//�︮���� �����ӿ� ����� ī��Ʈ
	int _CountFire;//�߻� ī��Ʈ��
	int _rndCountFire;//���� �������� ������ Ȯ��

	char str[127];

public:
	enemy();
	~enemy();

	HRESULT init();
	void release();
	void render();
	void update();

	void removeEnemy(int arrNum);//�Ϲ�������
	void removeEnemyUfo(int arrNum);//ufo������
	void removeEnemyUfo2(int arrNum);//ufo������
	void removeEnemyHelicopter(int arrNum);//�︮���� �� ����
	void removeEnemyHelicopter2(int arrNum);//2������ �︮���� �� ����
	void move();
	void move2();

	bool bulletCountfire();//���� ����Ȯ���� �÷��̾ �����ϰ� ����� ���� �Լ�

	vector<tagEnemy> getvEnemy() { return _vEnemy; }//�Ϲ���
	vector<tagEnemy>::iterator getviEnemy() { return _viEnemy; }//�Ϲ���

	vector<tagEnemy> getvEnemyUfo() { return _vEnemyUfo; }//ufo
	vector<tagEnemy>::iterator getviEnemyUfo() { return _viEnemyUfo; }//ufo

	vector<tagEnemy> getvEnemyUfo2() { return _vEnemyUfo2; }//ufo
	vector<tagEnemy>::iterator getviEnemyUfo2() { return _viEnemyUfo2; }//ufo

	vector<tagEnemy> getvEnemyHelicopter() { return _vEnemyHelicopter; }//�︮������
	vector<tagEnemy>::iterator getviEnemyHelicopter() { return _viEnemyHelicopter; }//�︮������

	vector<tagEnemy> getvEnemyHelicopter2() { return _vEnemyHelicopter2; }//�︮������
	vector<tagEnemy>::iterator getviEnemyHelicopter2() { return _viEnemyHelicopter2; }//�︮������
};

