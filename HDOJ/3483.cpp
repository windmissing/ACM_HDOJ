/*
看着别人的解题报告写的，推导过程还是不太懂
求sum(x^k*k^x) k=1~N 
x^(k+1)*(k+1)^x=x^k*x*(k+1)^x 然后用二项式定理展开(k+1)^x即可 
例如当x=4时   
| 1x  0  0  0  0  0 | |x^k*k^0| |x^(k+1)*(k+1)^0| 
| 1x 1x  0  0  0  0 | |x^k*k^1| |x^(k+1)*(k+1)^1| 
| 1x 2x 1x  0  0  0 |*|x^k*k^2|=|x^(k+1)*(k+1)^2| 
| 1x 3x 3x 1x  0  0 | |x^k*k^3| |x^(k+1)*(k+1)^3| 
| 1x 4x 6x 4x 1x  0 | |x^k*k^4| |x^(k+1)*(k+1)^4| 
| 1x 4x 6x 4x 1x 1x | | S(k)  | |     S(k+1)    | 
*/
#include "Mat.h"
#include <iostream>
using namespace std;
 
int main(){  
	__int64 n,x, ans;
	int i, j, k;
	Mat A, F;
    while(scanf("%I64d%I64d%I64d",&n,&x,&mod) && n!=-1){  
		A.ReSize(x+2, x+2);
		for(i = 0; i < x+2; i++){  
			for(j = 0; j <= i; j++)
			{
				if(j == 0 || j == i)
						A.s[i][j] = x;
				else{
					if(i != x+1)
						A.s[i][j] = A.s[i-1][j-1]+A.s[i-1][j];
					else
						A.s[i][j]=A.s[i-1][j]; 
				}
				A.s[i][j] = A.s[i][j] % mod;
			} 
		} 
		A.s[x+1][x+1] = 1;
		A.Er_work(n-1);  
		ans = 0;
       for(i = 0; i < x+2; i++)  
	   {
		   ans = ans + A.s[x+1][i] * x;
		   ans = ans % mod;
	   }
	   printf("%I64d\n", ans);
    }  
    return 0;  
}