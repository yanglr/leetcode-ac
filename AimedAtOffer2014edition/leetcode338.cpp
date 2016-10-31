#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res;
		res.push_back(0);
        if(num <= 0 ) return res;
        for(int i=1; i <= num; i++)
        {
			int temp = i;
			int count = 0;
			while(temp != 0)
			{
				temp = temp&(temp-1);
				count++;
			}
            res.push_back(count);
        }
        return res;
    }
};

int main()
{
	Solution sol;
	vector<int> res;
	int n;
	cin>>n;
	res=sol.countBits(n);

	for(auto i:res)
		cout<<i<<' ';

	return 0;
}

