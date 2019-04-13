#include<iostream>

using namespace std;

#define N 20 //�������

int Best_Multiply_Number[N + 1][N + 1];//������˴���

//***************************����������ֵ������*************************
//  ����˵��:
//     @param *p,ָ��洢����ά�������ָ��
//     @param n,�������
//     @param (&m)[N][N], (��ά������Ϊ�β�����) ָ��洢m[i][j]ֵ�������ָ��
//     @param (&s)[N][N],ָ��洢���ŶϿ�λ��ֵ�������ָ��
//
//*********************************************************************
void MatrixChain(int *p, int n, int (&m)[N + 1][N + 1], int (&s)[N + 1][N + 1])
{
	int r;//�洢i��j����ı���,�� delta(length) = r - 1
	for (int i = 0; i < n; i++)
		m[i][i] = 0;

	for (r = 2; r <= n; r++)//r��ʾ����ĳ���  r=2 A[1,2] A[2,3] A[3,4] A[4,5];  r=3 A[1~3] A[2~4] A[3~5]; r=4 A[1~4] A[2~5]; r=4 A[1~5]
		for (int i = 1; i <= n - r + 1; i++)
		{
			int j = i + r - 1;
			m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];
			s[i][j] = i;
			for (int k = i + 1; k < j; k++) {
				int temp = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (temp < m[i][j])
				{
					m[i][j] = temp;//�洢�������˴���
					s[i][j] = k;//�洢��ѶϿ�λ��
				}
			}
		}
}

void Traceback(int i, int j, int(&s)[N + 1][N + 1])
{
	if (i == j)
		return;
	Traceback(i, s[i][j], s);
	Traceback(s[i][j] + 1, j, s);
	cout << "Multiply A" << i << "��" << s[i][j];
	cout << "and A" << (s[i][j] + 1) << "��" << j << endl;
}


int main()
{
	system("color 2f");

	int MatrixNum;
	int MatixPre[11],MatrixNext[11];
	while (cin >> MatrixNum)
	{
		for (int i = 0; i < MatrixNum; i++)
			cin >> MatixPre[i] >> MatrixNext[i];

		//N�������ά��
		int Matrix_Space_Array[12];
		int i, k = 0;
		for (i = 0; i < MatrixNum; i++)
		{
			Matrix_Space_Array[k] = MatixPre[i];
			k++;
		}
		Matrix_Space_Array[k] = MatrixNext[i - 1];


		int Best_Multiply_Location[N + 1][N + 1];//��ѶϿ�λ��

		//��ά�����ʼ��
		for (int r = 0; r < N + 1; r++)
			for (int c = 0; c < N + 1; c++)
			{
				Best_Multiply_Number[r][c] = 0;
				Best_Multiply_Location[r][c] = 0;
			}

		//��������ֵ
		MatrixChain(Matrix_Space_Array, MatrixNum, Best_Multiply_Number, Best_Multiply_Location);

		//����������˴���
		cout << "\n�������˴���----"<<Best_Multiply_Number[1][MatrixNum] << endl;

		//����Ͽ�λ��
		Traceback(1, MatrixNum, Best_Multiply_Location);
	}
	return 0;
}