#include <iostream>
using namespace std;
typedef long long int64;  // int64(LL): 64位整型数, 即long long的别称

int64 m,n,k;
int64 cal(int64 x)  // 计算比x小的数的个数 
{
	int64 sum=0;
	for(int i=1;i<=n;i++)
	{
		sum += min(m,x/i);
	}
	return sum;
}

int64 binarySearch(int64 leftVal, int64 rightVal, int64 kth) 
{
    int64 midVal;

    while(leftVal <= rightVal)
    {
	    midVal=(leftVal+rightVal)/2;
		if(cal(midVal) < kth) leftVal=midVal+1; // 要找的数在后面，区间下限继续增大
		else rightVal=midVal-1;                 // 要找的数在前面，区间上限继续减小
	}		
    return leftVal;
}

int main()
{
    while(cin>>m>>n>>k && m>=1 && n>=1 && k>=1 && k<=m*n)
	{
		cout<<binarySearch(1,n*m,k);
		cout<<endl;
	}
    return 0;
}