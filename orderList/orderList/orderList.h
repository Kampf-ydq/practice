#pragma once

#define MaxSize 5
#define len1 5
#define len2 7

class SeqList
{
public:
	int arr1[len1], arr2[len2];
	int temp[len1 + len2];
	SeqList() {};//�޲ι���
	~SeqList() {};
	void buildList();//����
	void printList();//��������
	int getElement(int i);//����Ԫ��,���ҳɹ�����1�����򷵻�0
	int IsSymmtri();//�ж��Ƿ�Գƣ��ԳƷ���1�����򷵻�0
	void orderList();//��������������ż��ǰ

	void Sequence(int a[],int length);//����������ǵݼ�
	void BubbleSort(int arr[],int l);//ð������
	void combineSeq();//�ϲ����������
private:
	int array[MaxSize];
};
