#include<iostream>

using namespace std;

#define N 9     //�ؼ��ָ���
#define p 11

/****
 *@Introduction  ������ϣ��
 *     �����ͻ��������̽�ⷨ
 *     ��ϣ����Ϊ H(key) = key % p
 *****/
class HashTable
{
public:
	HashTable() 
	{
		for (int i = 0; i < 11; i++)
		{
			hashArray[i] = 0;
		}
	}
	~HashTable() {}

	void CreatTable(int a[]);//����̽�ⷨ������ϣ��
	bool SearchElemt(int key);

private:
	int hashArray[11];
};

void HashTable::CreatTable(int a[])
{
	int h;
	for (int i = 0; i < N; i++)
	{
		h = a[i] % p;
		while (hashArray[h] != 0)//��λ�����йؼ���
		{
			h++;
		} 
		hashArray[h] = a[i];
	}

	//��ʾ����
	cout << "Hash��Ϊ(0��ʾHash���еĳ�ʼֵ):" << endl;
	cout << "	";
	for (int i = 0; i < 11; i++)
	{
		cout << hashArray[i] << " ";
	}
	cout << endl <<endl;
}

bool HashTable::SearchElemt(int key)
{
	for (int i = 0; i < 11; i++)
	{
		if (hashArray[i] == key)
		{
			cout << "\n���ҳɹ�---λ��: "<< i + 1<< endl;
			return true;
		}
	}
	cout << "\n����ʧ��"<< endl;
	return false;
}

int main()
{
	system("color 2f");

	int srcArray[] = { 47,7,29,11,16,92,22,8,3 };
	HashTable hObj;
	int keyNum;
	hObj.CreatTable(srcArray);

	cout << "������ҹؼ���: ";
	cin >> keyNum;
	hObj.SearchElemt(keyNum);
	cout << endl;
	return 0;
}