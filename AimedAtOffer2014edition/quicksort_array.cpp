#include<iostream>
#include<cstdio>
using namespace std;

class Solution{
public:
void quickSort(int arr[], int forward, int backward)
{
	int part_pos;                   // 记录每次调用快排 quickSort()后主元e的位置 
	if(forward>=backward) return;
 
 	// int split(int[], int, int);  // 如果是在C语言中，此处需要声明一下，这里放在了class里面，不能进行声明 
 	part_pos=split(arr, forward, backward);
 	
	cout<<"The postion of the partition elemen is: "<<part_pos<<endl; 
 	for(int idx=0;idx<9;idx++)
	{
	printf("%d ",arr[idx]);		
	}
	printf("\n");	
	
	quickSort(arr, forward, part_pos-1);   // 递归地给主元e左侧元素排序 
	quickSort(arr, part_pos+1, backward);  // 递归地给主元e右侧元素排序 
}

int split(int arr[], int forward, int backward)  // 分割并返回分割主元的位置 
{
	int part_val=arr[forward]; // 用来作分割的元素(也称为partition主元)的值，以第一个数为分割基准 
	
	while(true)
	{
		while(forward<backward && arr[backward]>part_val) backward--;
		if(forward>=backward) break;
		arr[forward++]=arr[backward];
		
		while(forward<backward && arr[forward]<=part_val) forward++;
		if(forward>=backward) break;
		arr[backward--]=arr[forward];		
	}	
	arr[backward]=part_val;
	return backward;		
}
};

int main()
{
	Solution sol;
	int arr[]={12,3,6,18,7,15,10,56,4};
	sol.quickSort(arr,0,8);
	printf("The final result is:\n");	
	for(int idx=0;idx<9;idx++)
	{
	printf("%d ",arr[idx]);		
	}
	printf("\n");
	return 0;
}