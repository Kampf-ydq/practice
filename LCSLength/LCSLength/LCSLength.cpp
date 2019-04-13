#include<iostream>
#include<string>
using namespace std;

#define len1 1000
#define len2 1000

int c[len1 + 1][len2 + 1], tmp[len1 + 1][len2 + 1];

//根据递归式求解
void LCSLength(int m, int n, string x, string y, int c[][len2 + 1],int tmp[][len2 + 1])
{
	int i, j;
	//二维数组初始化为0
	for (i = 0; i < m + 1; i++) c[i][0];
	for (j = 0; j < n + 1; j++) c[0][j];

	//动态规划计算
	/*【注意】 i,j取值从1开始*/
	for (i = 1; i < m + 1; i++)
		for (j = 1; j < n + 1; j++) {
			if (x[i - 1] == y[j - 1]) {
				c[i][j] = c[i - 1][j - 1] + 1; tmp[i][j] = 1;
			}
			else if (c[i - 1][j] >= c[i][j - 1]) {
				c[i][j] = c[i - 1][j]; tmp[i][j] = 2;
			}
			else
			{
				c[i][j] = c[i][j - 1]; tmp[i][j] = 3;
			}
		}

	cout << c[m][n] << endl;
}

////构造最优解
//void LCS(int i, int j, string x, int tmp[][len2 + 1])
//{
//	
//	if (i == 0 || j == 0) return;//递归终止条件
//	if (tmp[i][j] == 1) {
//		LCS(i - 1, j - 1, x, tmp);
//		LCSlength++;
//	}
//	else if (tmp[i][j] == 2) {
//		LCS(i - 1, j, x, tmp);
//	}
//	else
//	{
//		LCS(i, j - 1, x, tmp);
//	}
//	
//}

int main()
{
	string str1,str2;//两个序列
	while (cin >> str1 >> str2) {

		//调用封装好的算法
		LCSLength(str1.length(), str2.length(), str1, str2, c, tmp);
	}
	
	return 0;
}

/*********
 *   【写在后面】   心得感悟
 *  
 *     存储计算值的数组即c[][]，其第0行0列全为0，第1行第1列才开始对两序列的序列值进行比较，
 *   而计算机内存储字符的数组下标从0开始，所以编程过程中要注意角标的其实和终止位置。
 **************/