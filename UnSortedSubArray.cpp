/*
Find the Minimum length Unsorted SubArray, sorting 
which makes the complete array sorted
*/
#include<iostream>
#include<stdio.h>
using std::cout;
class Array
{
		int* arr,size;
	public:
		Array(int n=0):size(n)
		{
			arr=new int[size];
		}
		void getData()
		{
			printf("\nEnter %i Elements :: ",size);
			for(int i=0;i<size;i++)
				scanf("%d",arr+i);
		}
		void showData(char* msg)
		{
			cout<<msg;
			for(int i=0;i<size;i++)
				printf("%d\t",*(arr+i));
		}
		int findMin(int i,int j)
		{
			int min=arr[i];
			for(;i<=j;i++)
				if(arr[i]<min)
					min=arr[i];
			return min;
		}
		int findMax(int i,int j)
		{
			int max=arr[i];
			for(;i<=j;i++)
				if(arr[i]>max)
					max=arr[i];
			return max;
		}
		int isEqual()
		{
			int x=arr[0];
			int count=0;
			for(int i=0;i<size;i++)
				if(x==arr[i])
					count++;	
			return count==size;
		}
		void getIndex()
		{
			int s=0,e=0,i,j;
			int flag1=0,flag2=0;
			for(i=0,j=size-1;i<size;i++,j--)
			{
				if(arr[i]>arr[i+1] && !flag1)
					s=i,flag1=1;
				if(arr[j-1]>arr[j] && !flag2)
					e=j,flag2=1;
			}
			int min=findMin(s,e);
			int max=findMax(s,e);
			for(i=0,j=e+1;i<size;i++,j++)
			{
				if(arr[i]>min && i<s)
					s=i;
				if(arr[j]<max && j<size)
					e=j;
			}
			if(isEqual())
			{
				printf("\nAll Elements are Equal\n");
				return;
			}
			if(s==e+1)
				printf("\nGiven Array is already Sorted\n");
			else
				printf("\n\nThe UnSorted subarray which makes the given array sorted lies between indices %i and %i\n",s,e);
		}
};
main()
{
	printf("\nHow Many Elements --> ");
	int n;
	scanf("%d",&n);
	Array a(n);
	a.getData();
	a.showData("\nArray is --> ");
	a.getIndex();
}


