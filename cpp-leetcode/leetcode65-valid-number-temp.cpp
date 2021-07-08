#include<algorithm>
#include<string>
#include<vector>
#include <sstream>
#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        if (s.find("Infinity") != string::npos || s.find("infinity") != string::npos || (s.front() == '.' && s.back() == '.') || (s.front() == '+' && s.back() == '+') || (s.front() == '-' && s.back() == '-'))
        {
            return false;
        }
        if ((s.find("+") != string::npos && s.find("+") != 0) || (s.find("-") != string::npos && s.find("-") != 0)){
            return false;
        }                 
        if (s.find("e") == 0 || s.find("e") == (s.size() - 1) || count(s.begin(), s.end(), '.') == 2){
            return false;
        }
        if (s.find(".e") != string::npos || s.find(".E") != string::npos || s.find("..") != string::npos || s.find("--") != string::npos || s.find("-+") != string::npos){
            return false;
        }           
        bool hasE;
        if (s.find("E") != string::npos || s.find("e") != string::npos)
        {
            hasE = true;
            if(s.back() == 'E' || s.back() == 'e')
            {
                return false;
            }
            if(s.front() == '.' && (s.find('e') > 0 || s.find('E') > 0))
            {
                return true;
            }
        }
        if(!hasE)
        {         
            bool isValid = isDoubleOrInt(s);
            if(isValid)
                return true;           
        }
        else
        {
            vector<string> arr;            
            arr = (s.find('e') != string::npos) ? split(s, 'e') : split(s, 'E');
            string newPart1 = arr[0];
            if (newPart1.find(" ") != string::npos)
            {
                return false;
            }

            string newPart2;
            bool isPart1Valid, isPart2Valid;
            isPart1Valid = isDoubleOrInt(newPart1);

            if (arr.size() == 1)
            {
                if (isPart1Valid)
                    return true;
            }            

            if (arr.size() == 2)
            {
                newPart2 = arr[1];
                if (newPart2 == "") // handle test case like: "0e"
                {
                    return false;
                }

                isPart2Valid = isDoubleOrInt(newPart2);
                if (newPart1.find("E") != string::npos || newPart1.find("e") != string::npos || newPart1.find(".") != string::npos || find_if(newPart1.begin(), newPart1.end(), [](char c) { return std::isalpha(c); }) != newPart1.end()){
                    return false;
                }                
                if (newPart2.find("E") != string::npos || newPart2.find("e") != string::npos || newPart2.find(".") != string::npos || find_if(newPart2.begin(), newPart2.end(), [](char c) { return std::isalpha(c); }) != newPart2.end()){
                    return false;
                }
                                   
                if (isPart1Valid && isPart2Valid)
                {
                    return true;
                }               
            }  
        }        
        return false;
    }
    
    vector<string> split(const string& s, char separator)
    {
        vector<string> tokens;
        string token;
        istringstream tokenStream(s);
        while (getline(tokenStream, token, separator))
        {
            tokens.push_back(token);
        }
        return tokens;
    }

    bool isDoubleOrInt(string str)
    {
        bool isDouble, isInt;
        if (str.find_first_of("abcdfghijklmnopqrstuvwxyzABCDFGHIJKLMNOPQRSTUVWXYZ_") != string::npos)
        {
            return false;
        }        
     
        stringstream sstr1(str);
        double part;
        isDouble = static_cast<bool>(sstr1 >> part);

        stringstream sstr2(str);
        int64_t part2;
        isInt = static_cast<bool>(sstr2 >> part2);

        return (isDouble || isInt);
    }    
};

// Test
int main()
{
    Solution sol;
    string s = "95a5453";
    auto res = sol.isNumber(s);
    cout << res << endl;

    return 0;
}