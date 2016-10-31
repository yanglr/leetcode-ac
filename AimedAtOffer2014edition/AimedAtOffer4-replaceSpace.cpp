#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

class Solution{
public:
void replaceSpace(char *str, int length)  // 出题作者指出:length为字符数组str的总容量
{
	if(str==NULL || length<=0) return;
	
	int newlen=0;
    int spaceCount = 0;
    int idx;
    for(idx = 0; str[idx] != '\0'; idx++)
	{
        if (str[idx] == ' ')
		{
            spaceCount++;
        }
    }
    newlen = idx + 2*spaceCount;
    if(newlen > length) return;
    str[newlen]='\0';  //此行很关键 
    int frontCur = idx - 1, backCur = newlen-1;
    for(; frontCur >= 0 && backCur > frontCur; frontCur--)
	{
        if (str[frontCur] == ' ')
			{
            str[backCur--] = '0';
            str[backCur--] = '2';
            str[backCur--] = '%';
        	}
		else str[backCur--] = str[frontCur];
    }
}
};

// 以下为测试部分

int main()
{
	Solution sol;
	char str[]="Hello World, haha";
	sol.replaceSpace(str, 20);
	// printf("%s\n",str);
	cout<<str<<endl;	
	return 0;
}
