/*
还是暴力打表，然后规律
递推公式：
a[n]=4*a[n-1]+5（n为奇数）
a[n]=4*a[n-2]+5（n为偶数）
结果：
ans=2*4^n-5*(4^n-1)/3（n为奇数）
ans=2*4^n-4*(4^n-1)/3（n为偶数）
这里由于涉及到除法取余，所以还要把3的逆元求出来
*/
#include<stdio.h>  
#include<stdlib.h>  
#define mod 10007  
 
//非递归方法求p^b
__int64 power(__int64 p,__int64 b)  
{  
    __int64 sq=1;  
    while(b>0)  
    {  
        if(b%2==1)  
            sq=(sq%mod)*(p%mod)%mod;  
        p=(p%mod)*(p%mod)%mod;  
        b=b/2;  
    }  
    return sq%mod;  
}  
  
int main()  
{  
    __int64 n,tmp,a,b,thr,t,T;  
    scanf("%I64d",&T);  
    for(t=1;t<=T;t++)  
    {  
        scanf("%I64d",&n);  
        thr=power(3,mod-2);  
        if(n==1||n==2)  
        {  
            printf("Case #%I64d: 2\n",t);  
            continue;  
        }  
		//2*4^n-5*(4^n-1)/3
        if(n&1)  
        {  
            n=n-2;  
            n=(n+1)/2;  
            tmp=power(4,n);  
            a=2*tmp%mod;  
            b=(5*thr%mod)*(((tmp-1)%mod+mod)%mod)%mod;  
            printf("Case #%I64d: %I64d\n",t,((a-b)%mod+mod)%mod);  
        }  
		//2*4^n-4*(4^n-1)/3
        else  
        {  
            n=n-2;  
            n=n/2;  
            tmp=power(4,n);  
            a=2*tmp%mod;  
            b=(4*thr%mod)*(((tmp-1)%mod+mod)%mod)%mod;  
            printf("Case #%I64d: %I64d\n",t,((a-b)%mod+mod)%mod);  
        }  
    }  
    return 0;  
}
