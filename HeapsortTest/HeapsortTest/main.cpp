#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using std::swap;

#define N 10

int comp(const void*a,const void*b)
{
	return *((int*)a)-*((int*)b);
}

void adjustHeap(int data[],int size,int index)
{
	int left,right,maxIndex;
	left=index*2+1;
	right=index*2+2;
	maxIndex=index;
	if(left<size && data[left]>data[maxIndex])	maxIndex=left;
	if(right<size && data[right]>data[maxIndex])	maxIndex=right;
	if(maxIndex != index)
	{
		swap(data[maxIndex],data[index]);
		adjustHeap(data,size,maxIndex);
	}
}

void heapsort(int data[],int size)
{
	int i;
	for(i=size/2-1;i>=0;i--)
	{
		adjustHeap(data,size,i);
	}
	for(i=size-1;i>0;i--)
	{
		swap(data[0],data[i]);
		adjustHeap(data,i,0);
	}
}

int main()
{
	int data[N],ans[N],i,temp,wrongIndex;
	bool hasWrong;
	srand((unsigned)time(NULL));
	while(1)
	{
		for(i=0;i<N;i++)
		{
			temp=rand()%10000;
			data[i]=temp;
			ans[i]=temp;
		}
		printf("原始数据:\n");
		for(i=0;i<N;i++)
		{
			printf("%d ",data[i]);
		}
		printf("\n");
		heapsort(data,N);
		printf("我的排序后数据:\n");
		for(i=0;i<N;i++)
		{
			printf("%d ",data[i]);
		}
		printf("\n");
		hasWrong=false;
		for(i=0;i<N-1;i++)
		{
			if(data[i]>data[i+1])
			{
				hasWrong=true;
				wrongIndex=i+1;
				break;
			}
		}
		if(hasWrong)
		{
			printf("我的排序数据有误，第一个错误处出现在下标为%d处，标准排序后数据:\n",wrongIndex);
			qsort(ans,N,sizeof(int),comp);
			for(i=0;i<N;i++)
			{
				printf("%d ",ans[i]);
			}
			printf("\n");
		}
		else
		{
			printf("我的排序数据全部正确\n");
		}
		system("pause");
	}
	return 0;
}