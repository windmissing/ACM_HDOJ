// 1.用树状数组求逆序数
// 缺点：只能对整数求逆序数

#include "TreeArray.h"
/*
算法：
由树状数组求逆序对。加入元素i即把以元素i为下标的a[i]值+1，从队尾到队首入队，
每次入队时逆序对数 += getsum(i - 1),即下标比它大的但是值比它小的元素个数。
因为树状数组不能处理下标为0的元素，每个元素进入时+1，相应的其他程序也要相应调整。
求出原始的序列的逆序对个数后每次把最前面的元素移到队尾，逆序对数即为
原逆序对数+比i大的元素个数-比i小的元素个数，因为是0..n,容易直接算出
*/
int NiXuShu(int Array[], int n)
{
	TreeArray ta(1);
	ta.clear();
	int i, sum = 0;
	for (i = n-1; i >= 0; i --)
	{
		ta.modify(Array[i]+1, 1);
		sum = sum + ta.sum(Array[i]);
	}
	return sum;
}

// 2.用归并排序求逆序数

// 缺点：会改变数组中的值

#include <iostream>
using namespace std;
#define MAX 50005
 
int rs, tar[MAX];
void merge(int Array[], int l,int m,int r){  
    int l1=l,l2=m+1,pp=0;  
    while(l1<=m&&l2<=r){  
        if(Array[l1]<=Array[l2]){  
            tar[pp++]=Array[l1++];   
        }else{  
            tar[pp++]=Array[l2++];  
            rs+=m-l1+1;  
        }  
    }  
    while(l1<=m)tar[pp++]=Array[l1++];  
    while(l2<=r)tar[pp++]=Array[l2++];  
    for(int i=l,j=0;i<=r;i++,j++){  
        Array[i]=tar[j];     
    }  
}  
void mergesort(int Array[], int l,int r){  
    if(l>=r)return;  
    int m=(l+r)/2;  
    mergesort(Array, l, m);  
    mergesort(Array, m+1, r);  
    merge(Array, l, m, r);  
} 
int NiXuShu(int Array[], int n)
{
	rs = 0;
	mergesort(Array, 0, n-1);
	return rs;
}
