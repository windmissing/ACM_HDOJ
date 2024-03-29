/*
Line都是直线，不是线段，没有端点，输入的点只是用于确定这条直线的位置
对每条直线与x=L,和x=r的交点分别为xl,xr，两直线在(L,R)相交，必然有
xl1>xl2&&xr1<xr2 或者 xl1<xl2&&xr1>xr2
所以对xl排序，求xr的逆序对,处理一下与x=L平行的那些直线即可
数据是double型，要用归并排序求逆序数
*/
#include <iostream>
#include <algorithm>
using namespace std;
#include "NiXuShu.h"
 
struct point
{  
    double l,r;   
    bool operator<(const point& p)const
	{  
        return l<p.l || (l==p.l&&r<p.r);    
	}  
}p[MAX]; 
 
int main(){  
	int n,ps,sz; 
	double ll,rr,x1,y1,x2,y2,ar[50005];
	while(scanf("%d",&n)!=EOF){  
        scanf("%lf%lf",&ll,&rr);   
        sz=0,ps=0;  
        for(int i=0;i<n;i++){  
            scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);  
            if(x2==x1){  
                if(ll<x1&&x1<rr)sz++;   
            }else{  
                p[ps].l=y1+(y2-y1)*(ll-x1)/(x2-x1);  
                p[ps].r=y1+(y2-y1)*(rr-x1)/(x2-x1);  
                ps++;  
            }  
        }  
        sort(p,p+ps);  
        for(int i=0;i<ps;i++)ar[i]=p[i].r;  
          
        int ans = NiXuShu(ar, ps);  
        ans += sz*ps;  
        printf("%d\n",ans);  
    }  
    return 0;     
}
