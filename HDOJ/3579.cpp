#include <iostream>   
#include <cstdio>   
#include <cstdlib>   
#include <cstring>   
using namespace std;  
__int64 x, y, t;  
__int64 egcd(__int64 a, __int64 b)   
{  
    if (b==0)     
    {  
        x=1;        
        y=0;     
        return a;     
    }  
    else   
    {  
        __int64 e=egcd(b,a % b);   
        t=x;   
        x=y;  
        y=t-a/b*y;     
        return e;     
    }  
}  
__int64 gcd(__int64 x, __int64 y)  
{  
    if (!x || !y)  
        return x > y ? x : y;  
    for (__int64 t; t = x % y; x = y, y = t);  
    return y;  
}  
__int64 mm[10],rr[10];  
int main()   
{  
	int T,Case,N;
    __int64 m1,m2,r1,r2,d,c,t;  
    bool flag;     
    scanf ("%d",&T);  
    for(Case = 1; Case <= T; Case++)      
    {  
        scanf ("%d",&N);  
        flag=0;            
        for (__int64 i=0;i<N;i++)  
        {  
            scanf ("%I64d",&mm[i]);  
        }  
        for (__int64 i=0;i<N;i++)  
        {  
            scanf ("%I64d",&rr[i]);  
        }  
        m1=mm[0];  
        r1=rr[0];  
  
        for (__int64 i = 0; i < N - 1; i++)      
        {  
            m2=mm[i+1];  
            r2=rr[i+1];     
            if (flag)   
                continue;     
            d = egcd(m1, m2);     
            c = r2 - r1;   
            if (c % d)        
            {         
                flag = 1;      
                continue;     
            }  
            t=m2/d;      
            x=(c/d*x%t+t)%t;     
            r1=m1*x+r1;      
            m1=m1*m2/d;      
        }  
        if (flag)  
            printf ("Case %d: -1\n",Case);  
        else  
        {  
            if (r1==0&&N>1)  
            {  
                r1=mm[0];  
                __int64 ans=1;  
                for (int i=1;i<N;i++)  
                    r1=gcd(mm[i],r1);  
                for (int i=0;i<N;i++)  
                    ans*=mm[i];  
                r1=ans/r1;  
            }  
            if (r1==0&&N==1)  
                r1=mm[0];  
            printf ("Case %d: %I64d\n",Case,r1);  
        }  
    }  
    return 0;  
}
