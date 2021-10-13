#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        if (arr[0]*10 + arr[1] > 23) return "";

        vector<vector<int>> hhs; // hour, i, j
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (i != j && (arr[i]*10 + arr[j] < 24))
                    hhs.push_back({arr[i]*10 + arr[j], i, j});
            }
        } 
        sort(hhs.begin(), hhs.end(), greater<>());
        vector<int> validHhs;
        vector<int> last2num;
        bool ok = getValidLast2num(hhs, arr, last2num, validHhs);
        if (!ok) return "";
        int hour = validHhs.at(0);
        int digitB = hour % 10;
        int digitA = hour / 10;

        if (last2num[0] >= 6 && last2num[1] >= 6) return "";
        string res = to_string(digitA) + to_string(digitB) + ":";        
        string minu;
        if (last2num[0] < 6 && last2num[1] < 6)
        {
            sort(last2num.begin(), last2num.end(), greater<>());
            minu.push_back(last2num[0] + '0');
            minu.push_back(last2num[1] + '0');
            res += minu;
        }     
        else if (last2num[0] >= 6 || last2num[1] >= 6)
        {
            sort(last2num.begin(), last2num.end());
            minu.push_back(last2num[0] + '0');
            minu.push_back(last2num[1] + '0');
            res += minu;
        }              
        return res;
    }
    bool getValidLast2num(vector<vector<int>> hhs, vector<int> arr, vector<int>& last2num, vector<int>& validHhs)
    {
        bool canGetValidLast2num = false;
        for (int k = 0; k < hhs.size(); k++)
        {
            vector<int> hh = hhs[k];
            last2num.clear();       // 这个地方很关键 
            for (int i = 0; i < 4; i++)
            {
                if (i != hh.at(1) && i != hh.at(2))
                    last2num.push_back(arr[i]);
            }
            if ((last2num[0]*10 + last2num[1] <= 60) || (last2num[1]*10 + last2num[0] <= 60)) 
            {
                canGetValidLast2num = true;
                validHhs = hh;
                break;
            }               
        }
        return canGetValidLast2num;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {2, 0, 6, 6};
    auto res = sol.largestTimeFromDigits(nums);
    cout << res << endl;

    return 0;
}