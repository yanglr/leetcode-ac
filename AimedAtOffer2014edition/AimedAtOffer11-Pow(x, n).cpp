#include<cstdio>
using namespace std;
class Solution {
public:
    double Power(double base, int exponent) {
        if(exponent < 0)
        {
            exponent = -exponent;
            base = 1.0/base;
        }
        double res = 1.0;
        for(; exponent > 0; exponent >>= 1)
        {
            if((exponent & 0x1) == 1)  res *= base;
            base *= base;
        }
        return res;
    }
};

// ртобн╙╡Бйт
int main()
{
	Solution sol;
	double num1=sol.Power(20, 2);
	double num2=sol.Power(13, -2);
	double num3=sol.Power(-10, 3);
	int num4=sol.Power(0, 0);	
	printf("%f\n",num1); 
	printf("%f\n",num2);
	printf("%f\n",num3);		
	printf("%d\n",num4);		
	return 0;
}