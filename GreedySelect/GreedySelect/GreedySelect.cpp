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
	for (int i = 1; i < n; i++)//依次检查活动i是否与当前活动相容
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
	int channelNum; //频道数量
	int startTime[110], finishTime[110];
	channel chanTable[110];
	int canSee = 1;//记录可完整观看的节目数

	while (cin >> channelNum)
	{
		for (int i = 0; i < channelNum; i++)
			cin >> chanTable[i].s >> chanTable[i].f;

		//对节目的结束时间升序排列
		BubbleSort(channelNum, chanTable);
		
		//开始贪心选择
		GreedySelector(channelNum, chanTable, canSee);
	}

	return 0;
}