#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int myAtoi(string str)
	{
        if(str=="") return 0;  // str.length()==0 等价于 str==""，故条件不必写为if(str=="" || str.length()==0) 
        long long final, res=0;
        int len=str.length();
        int sign=1;
        int sign_count=0;
		for(int i=0; i<len; i++)
        {
        	char ch=str[i];
			if(ch=='-' || ch=='+') sign_count++;
			if(sign_count<=1)			
			{
			if(ch<='9' && ch>='0')
			{
				res = res*10+ch-'0';
				if(res> INT_MAX && sign==1) return INT_MAX;
				if(res< INT_MIN && sign==-1) return INT_MIN;
				if(i+1<len && str[i+1]==' ') break;
			}
			else if(ch=='-' || ch=='+') 
			{
				if(ch=='-') sign=-1;
				if(i+1<len && str[i+1]==' ') break;
			}
				else if(ch==' ') ;  // 开头的空格忽略掉
					else break;  // 输入不合法，退出循环				
			}  	
			else return 0;
		}		
        if(res>= INT_MIN && res <= INT_MAX) final=res*sign;
        else if(sign==1) final = INT_MAX;
        	else if(sign==-1) final = INT_MIN;  // 如果越出整数边界，返回相应的值 
		return final; // -2147483648[(signed int)0x80000000] ~ 2147483647(0x7FFFFFFF)
    }   
};

// 以下为测试
int main()
{
	string str0; //	str0.size() == 0; // 后面的半句：可写可不写，字符串默认初始化为空串 
	string str1="1ab3";  // 应返回1
	string str2="18446744073709551617";	
	string str3="- +899999 ";
	string str4="    010"; // 应返回10
	string str5="   +0 123";
	string str6="13  456"; // 123
	string str7="   - 321";

	Solution sol;
	cout<<sol.myAtoi(str0)<<endl;	
	cout<<sol.myAtoi(str1)<<endl;
	cout<<sol.myAtoi(str2)<<endl;		
	cout<<sol.myAtoi(str3)<<endl;	
	cout<<sol.myAtoi(str4)<<endl;
	cout<<sol.myAtoi(str5)<<endl;
	cout<<sol.myAtoi(str6)<<endl;	
	cout<<sol.myAtoi(str7)<<endl;	
	return 0;
} 