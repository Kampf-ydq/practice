#include<iostream>

using namespace std;

#define N 9     //关键字个数
#define p 11

/****
 *@Introduction  创建哈希表
 *     处理冲突采用线性探测法
 *     哈希函数为 H(key) = key % p
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

	void CreatTable(int a[]);//线性探测法建立哈希表
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
		while (hashArray[h] != 0)//该位置已有关键字
		{
			h++;
		} 
		hashArray[h] = a[i];
	}

	//显示出来
	cout << "Hash表为(0表示Hash表中的初始值):" << endl;
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
			cout << "\n查找成功---位置: "<< i + 1<< endl;
			return true;
		}
	}
	cout << "\n查找失败"<< endl;
	return false;
}

int main()
{
	system("color 2f");

	int srcArray[] = { 47,7,29,11,16,92,22,8,3 };
	HashTable hObj;
	int keyNum;
	hObj.CreatTable(srcArray);

	cout << "输入查找关键字: ";
	cin >> keyNum;
	hObj.SearchElemt(keyNum);
	cout << endl;
	return 0;
}