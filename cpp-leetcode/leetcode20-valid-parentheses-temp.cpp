#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    const vector<char> left = { '(', '[', '{' };
    const vector<char> right = { ')', ']', '}'};

    bool isValid(string s) {
        bool isValid;
        bool isSym = true;
        bool isCombineValid;
        int len = s.size();
        if(len % 2 != 0 || find(right.begin(), right.end(), s.front()) != right.end() || find(left.begin(), left.end(), s.back()) != left.end()) return false;

        string curStr;
        int i, lIndex, rIndex;

        // 情形1, 对称        
        for (i = 0; i < len/2; i++)
        {
            char lch = s[i];
            char rch = s[len-i-1];
            if(!isAlwaysNeighbor(s) && (find(right.begin(), right.end(), lch) != right.end() || find(left.begin(), left.end(), rch) != left.end()))
                return false;
            lIndex = distance(left.begin(), find(left.begin(), left.end(), lch));
            rIndex = distance(right.begin(), find(right.begin(), right.end(), rch));
            if(lIndex != rIndex)
                isSym = false;            
        }
        if(isSym == false && i > 0) { 
            curStr = s.substr(lIndex, rIndex-lIndex+1);
            isCombineValid = isAlwaysNeighbor(curStr);
        }
        isValid = isSym || isCombineValid || isAlwaysNeighbor(s);
        
        // 情形2, 自行成对

        // 情形3: 边缘对称，内部相邻   
        return isValid;
    }
    
    bool isAlwaysNeighbor(string s){
        bool isAlwaysNeighbor = true;
        for(int k = 0; k < (s.size()+1)/2; k = k+2)
        {
            char lch = s[k];
            char rch = s[k+1];
            int lIndex = distance(left.begin(), find(left.begin(), left.end(), lch));
            int rIndex = distance(right.begin(), find(right.begin(), right.end(), rch));
            if(lIndex != rIndex)
                isAlwaysNeighbor = false;                        
        }
        return isAlwaysNeighbor;    
    }
};

//Test
int main()
{
    Solution sol;
    string str = "()[]{}";  // "(}{)"; 
    bool res = sol.isValid(str);

    return 0;
}