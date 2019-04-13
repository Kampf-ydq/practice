#include<iostream>
#include<algorithm>

using namespace std;

struct channel
{
	int s;
	int f;
};

void GreedySelector(int n, channel p[], int count)
{
	
	int fir = p[0].f;
	for (int i = 1; i < n; i++)//���μ��i�Ƿ��뵱ǰ�����
	{
		if (p[i].s >= fir) {
			fir = p[i].f;
			count++;
		}
	}
	cout << count << endl;
}

void BubbleSort(int n, channel a[])
{
	channel tmp;
	for (int i = 1; i < n; i++)
		for (int j = 0; j < n - i; j++) {
			if (a[j].f > a[j + 1].f) {
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
}

int main()
{
	int channelNum; //Ƶ������
	int startTime[110], finishTime[110];
	channel chanTable[110];
	int canSee = 1;//��¼�������ۿ��Ľ�Ŀ��

	while (cin >> channelNum)
	{
		for (int i = 0; i < channelNum; i++)
			cin >> chanTable[i].s >> chanTable[i].f;

		//�Խ�Ŀ�Ľ���ʱ����������
		BubbleSort(channelNum, chanTable);
		
		//��ʼ̰��ѡ��
		GreedySelector(channelNum, chanTable, canSee);
	}

	return 0;
}