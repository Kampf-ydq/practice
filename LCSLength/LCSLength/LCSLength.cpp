#include<iostream>
#include<string>
using namespace std;

#define len1 1000
#define len2 1000

int c[len1 + 1][len2 + 1], tmp[len1 + 1][len2 + 1];

//���ݵݹ�ʽ���
void LCSLength(int m, int n, string x, string y, int c[][len2 + 1],int tmp[][len2 + 1])
{
	int i, j;
	//��ά�����ʼ��Ϊ0
	for (i = 0; i < m + 1; i++) c[i][0];
	for (j = 0; j < n + 1; j++) c[0][j];

	//��̬�滮����
	/*��ע�⡿ i,jȡֵ��1��ʼ*/
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

////�������Ž�
//void LCS(int i, int j, string x, int tmp[][len2 + 1])
//{
//	
//	if (i == 0 || j == 0) return;//�ݹ���ֹ����
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
	string str1,str2;//��������
	while (cin >> str1 >> str2) {

		//���÷�װ�õ��㷨
		LCSLength(str1.length(), str2.length(), str1, str2, c, tmp);
	}
	
	return 0;
}

/*********
 *   ��д�ں��桿   �ĵø���
 *  
 *     �洢����ֵ�����鼴c[][]�����0��0��ȫΪ0����1�е�1�вſ�ʼ�������е�����ֵ���бȽϣ�
 *   ��������ڴ洢�ַ��������±��0��ʼ�����Ա�̹�����Ҫע��Ǳ����ʵ����ֹλ�á�
 **************/