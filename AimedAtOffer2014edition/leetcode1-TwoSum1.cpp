#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>
using namespace std;

typedef struct node{
    int index;
    int value;
    node(){};
    node(int i, int v) : index(i), value(v){}
}Node;

bool compare(const Node& a, const Node& b){
    return a.value < b.value;
}

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        
        int len = nums.size();
        assert(len >= 2);          
        
        vector<int> ret(2, 0);  // 初始化：ret包含2个值为0的元素
        
        vector<Node> nums2(len);
        for(int i = 0; i < len; i++){
            nums2[i] = Node(i+1, nums[i]);
        }
        
        sort(nums2.begin(), nums2.end(), compare);    // 调用快排，T(n)=O(n*log(n))
        
        int l = 0;
        int r = len - 1;
        while(l < r){
            int sum = nums2[l].value + nums2[r].value;
            if(sum == target){
                ret[0] = min(nums2[l].index, nums2[r].index)-1;    // 注意，这里需要减去1
                ret[1] = max(nums2[l].index, nums2[r].index)-1;
                break;
            } else if(sum < target){
                l++;
            } else {
                r--;
            }
        }        
        return ret;  // 用两个指针来扫 
    }
};    

// 下面是测试代码

int main()
{
	Solution sol;
	vector<int> arr;
 
	arr.push_back(3);
	arr.push_back(2);
	arr.push_back(4);		

    vector<int> ret = sol.twoSum(arr, 6);            
    cout<<ret[0]<<" "<<ret[1]<<endl;
    return 0;
}