#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char ch : s)
        {
            if(ch == '(' || ch == '[' || ch == '{')
                st.push(ch);
            else {
                if(st.empty())
                    return false;
                if(ch == ')' && st.top() != '(')
                    return false;
                if(ch == ']' && st.top() != '[')
                    return false;
                if(ch == '}' && st.top() != '{')
                    return false;

                st.pop();                                   
            }
        }
        return st.empty();
    }
};

//Test
int main()
{
    Solution sol;
    string str = "()[]{}";  // "(}{)"; 
    bool res = sol.isValid(str);
    cout << (res == true ? "true" : "false") << endl;

    return 0;
}