#include<iostream>
#include<math.h>
using namespace std;

#define N 5000


//************************【对数组进行划分】***********************
// 描述: 算法的核心，利用下标i、j,分别从左右两端与基准元素a[p]比较
//       满足条件则交换,具体实现参考《算法分析与设计》
//
//***************************************************************
int Partition(int a[], int p, int r)
{
	int i = p, j = r + 1;//i、j初值由下面的++i、--j所决定
	int temp = a[p];
	int t;

	while (true)
	{
		while (a[++i] < temp && i < r);//左边i自增,不满足条件时Stop,得到值i
		while (a[--j] > temp);//右边j自减,不满足条件时Stop,得到值j

		if (i >= j)//退出循环条件
			break;

		//当i,j都停止，此时交换a[i]和a[j]
		t = a[i];
		a[i] = a[j];
		a[j] = t;
	}

	//交换a[j]和temp值
	a[p] = a[j];
	a[j] = temp;

	return j;
}

//***********************【递归求解】*******************************
// 描述: 采用递归方式分别对数组的左右子数组进行排序
//
//*****************************************************************
void Quick_Sort(int array[], int p, int r)
{
	if (p < r)//合法的起始点和终止点下标
	{
		int q = Partition(array, p, r);//寻找分割点

		Quick_Sort(array, p, q);//对左半段排序
		Quick_Sort(array, q + 1, r);//对右半段排序
	}

}

int main()
{
	int Array[N];
	int n;
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
			cin >> Array[i];

		//调用快速排序算法
		Quick_Sort(Array, 0, n - 1);

		for (int i = 0; i < n; i++)
			cout << Array[i] << " ";

		cout << endl;
	}
	return 0;
}


