#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> grayCode(int n) {
        int size = 1<<n;
        vector<int> grayCodes(size,0);
		int gDecNum=0;
        for(int i = 0; i < size; i++){
            gDecNum = i ^ (i>>1);   // 数学公式digG[i]=i ^ i/2，gDecNum是一个格雷码对应的二进制数，存储时变成int(十进制) 
            grayCodes[i] = gDecNum;
        }
        return grayCodes;
    }
};

// 以下为测试部分
int main()
{
	int n,j;
	vector<int> arr,display;
	cin>>n;
	
	Solution sol;
	display=sol.grayCode(n);
	for(j=0;j<display.size();j++)
	{
		cout<<display[j]<<" ";
	}
	cout<<endl;
	return 0;
}