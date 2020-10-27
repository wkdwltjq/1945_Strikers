#pragma once
#include "gameNode.h"

struct tagItem
{
	image* imageName;//������ �̹���
	RECT rc;//������ �浹
	float x, y;//������ ������ǥ
	float speed;//������ ���ǵ�
	float angle;//������ �ޱ�
	int count;//������ ī��Ʈ
};

class item : public gameNode
{
private:
	vector<tagItem>				_vBombItem;
	vector<tagItem>::iterator	_viBombItem;//��ź ������ ����

	vector<tagItem>				_vAttackItem;
	vector<tagItem>::iterator	_viAttackItem;//���ݷ� ������ ����

	vector<tagItem>				_vHpItem;
	vector<tagItem>::iterator	_viHpItem;//ȸ�� ������ ����

	image* _bombCountImage;//�����ϴ� ��ź���� �̹���

	int _rndItemFire, _rndItemFireCount;//�������� ����Ȯ���� ����� ����
	int _bombCount;//��ź����
	int _attackCount;//�÷��̾� ���ݷ� �ܰ�

	char _str[127];

public:
	item() {};
	~item() {};

	HRESULT init();
	void render();
	void update();
	void release();

	void move();//������ ����
	void removeBombItem(int arrNum);//��ź �������� �÷��̾�� �浹�� ����
	void removeAttackItem(int arrNum);//���ݷ� ��ȭ �������̶� �÷��̾�� �浹�� ����
	void removeHpItem(int arrNum);//ȸ�� ������ �÷��̾�� �浹�� ����
	void bombItemFire(float x, float y);//��ź �������� ��Ÿ�� ��ġ
	void attackItemFire(float x, float y);//�÷��̾� ���ݷ� �ܰ�� �������� ��Ÿ�� ��ġ
	void hpItemFire(float x, float y);//ȸ�� �������� ��Ÿ�� ��ġ

	int getBobmCount() { return _bombCount; }//���� ������ �ִ� ��ź���� �޾ƿ���
	void setBobmCountPlus(int count) { _bombCount += count; }//���� ������ �ִ� ��ź���� ����
	void setBobmCountMin(int count) { _bombCount -= count; }//���� ������ �ִ� ��ź���� ����

	int getAttackCount() { return _attackCount; }//���� �÷��̾� ���ݷ� �ܰ� �޾ƿ���
	void setAttackCount(int count) { _attackCount += count; }//�÷��̾� ���ݷ� �ܰ��
	bool itemCountFire();//�������� ����Ȯ��

	vector<tagItem> getvBombItem() { return _vBombItem; }
	vector<tagItem>::iterator getviBombItem() { return _viBombItem; }//��ź������ ���� ��������

	vector<tagItem> getvAttackItem() { return _vAttackItem; }
	vector<tagItem>::iterator getviAttackItem() { return _viAttackItem; }//���ݷ� ��ȭ ������ ���� ��������

	vector<tagItem> getvHpItem() { return _vHpItem; }
	vector<tagItem>::iterator getviHpItem() { return _viHpItem; }
};

