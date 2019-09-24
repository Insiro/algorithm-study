#include <stdio.h>
#define MAX 10
int data[] = {3, 6, 17, 11, 7, 15, 5, 19, 30, 14}, data1[5], data2[5];
void printcur();
void devide(int, int);
void merge_dive(int, int);
void merge_inte(int, int);
int main()
{
	merge_dive(0, MAX);
	printcur();
	puts("end");
	return 0;
}
void merge_dive(int start, int size)
{
	int pp = size / 2;
	if (pp == 0)
		return;
	merge_dive(start, pp);
	merge_dive(start + pp, size - pp);
	devide(start, size); //배열 분할
	merge_inte(start, size);
	printcur();
}

void merge_inte(int CurPoint, int size) //배열 정렬, 병합
{
	int inter = size / 2, RSize = size - inter;
	int Ep = size + CurPoint;
	int FrontNum = 0, BackNum = 0; // data1, data2, 현재 위치
	int FroTemp;
	while (CurPoint < Ep)
	{
		FroTemp = FrontNum < inter;
		if (data1[FrontNum] < data2[BackNum] && FroTemp)
		{
			data[CurPoint] = data1[FrontNum];
			FrontNum++;
			CurPoint++;
		}
		else if (BackNum < RSize)
		{
			data[CurPoint] = data2[BackNum];
			CurPoint++;
			BackNum++;
		}
		else if (FroTemp)
		{
			data[CurPoint] = data1[FrontNum];
			FrontNum++;
			CurPoint++;
		}
	}
}

void devide(int dataNum, int size)
{
	int inte = size / 2, j = 0, inte2 = size - inte;
	while (j < inte)
	{
		data1[j] = data[dataNum];
		j++;
		dataNum++;
	}
	j = 0;
	while (j < inte2)
	{
		data2[j] = data[dataNum];
		j++;
		dataNum++;
	}
}
void printcur()
{
	puts("____________");
	for (int a = 0; a < 10; a++)
	{
		printf("%d\n", data[a]);
	}
}