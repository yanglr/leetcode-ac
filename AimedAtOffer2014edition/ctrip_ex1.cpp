#include<cstdio>
#include<vector>
#include<iostream>
using namespace std;

int maxProfit(vector<int>& prices) {
    int len=prices.size();
    if(len==0||len==1)
        return 0;
    int min=prices[0];
    int sum=0;
    for(int i=1;i<len;i++)
    {
        if(prices[i]<min)
            min=prices[i];
        else if(prices[i]>min)
        {
            int temp=prices[i]-min;
            if(temp>sum)
                sum=temp;
        }
    }
    return sum;
}

int main()
{
	int n;
	vector<int> vec;
	while(scanf("%d", &n))
	{
		vec.push_back(n);
		char ch = getchar();
		if(ch == '\n') break;
	}

	// for(int i: vec)
	//	cout<<i;

	cout<<maxProfit(vec)<<endl;
	vec.clear();
	return 0;
}