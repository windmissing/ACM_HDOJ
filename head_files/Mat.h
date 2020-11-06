/*
Mat.h
矩阵运算：加、乘、二分求幂、二分求和
无返回值，按引用传参，非递归
*/
#include<iostream>
using namespace std;
#define MAX 55
__int64 mod;
 
class Mat
{
public:
	__int64 s[MAX][MAX];
	int sizei,sizej;
public:
	Mat(int a = MAX, int b = MAX, int type = 0);
	void clear(int type = 0);
	void ReSize(int a = MAX, int b = MAX, int type = 0);
	void Add(const Mat& B);
	void Multiply(const Mat &B);
	void Er_work(int n);
	void solve(int p) ;
};
//构造
Mat::Mat(int a, int b, int type)
	:sizei(a),sizej(b){
		int i,j;
		//type = 0, 全零矩阵
		memset(s, 0, sizeof(s));
		//type = 1, 单位矩阵
		if(type == 1)
			for(i = 0; i < min(a, b); i++)
				s[i][i] = 1;
		//type = 2, 全1矩阵
		else if(type == 2)
			for(i = 0; i < a; i++)
				for(j = 0; j < b; j++)
					s[i][j] = 1;
}
//重置
void Mat::clear(int type)
{
	int i,j;
	//type = 0, 全零矩阵
	memset(s, 0, sizeof(s));
	//type = 1, 单位矩阵
	if(type == 1)
		for(i = 0; i < min(sizei, sizej); i++)
			s[i][i] = 1;
	//type = 2, 全1矩阵
	else if(type == 2)
		for(i = 0; i < sizei; i++)
			for(j = 0; j < sizej; j++)
				s[i][j] = 1;
}
//初始化
void Mat::ReSize(int a, int b, int type)
{
	sizei = a; sizej = b;
	int i,j;
	//type = 0, 全零矩阵
	memset(s, 0, sizeof(s));
	//type = 1, 单位矩阵
	if(type == 1)
		for(i = 0; i < min(a, b); i++)
			s[i][i] = 1;
	//type = 2, 全1矩阵
	else if(type == 2)
		for(i = 0; i < a; i++)
			for(j = 0; j < b; j++)
				s[i][j] = 1;
}
//加
void Mat::Add(const Mat& B)
{
    for(int i=0;i<sizei;i++)
	{
		for(int j=0;j<sizej;j++)
		{
			s[i][j] = s[i][j] + B.s[i][j];
			s[i][j]%=mod ;
		}
	}
}
//乘
void Mat::Multiply(const Mat &B)
{
	Mat c(sizei,B.sizej) ;
    for(int i=0;i<sizei;i++)
	{
		for(int j=0;j<B.sizej;j++)
		{
			c.s[i][j]=0 ;
			for(int k=0;k<sizej;k++)
			{
				c.s[i][j]+=s[i][k]*B.s[k][j];
				c.s[i][j]%=mod ;
			}
		}
	}
	*this = c;
}
//二分求幂
void Mat::Er_work(int n)
{
    Mat e(sizei,sizej,1);  
    while (n)  
    {  
        if(n&1)  
            e.Multiply(*this);  
        n>>=1;  
        Multiply(*this);  
    }  
    *this = e;  
}
//二分求和
void Mat::solve(int p)  
{
	Mat temp1 = *this, temp2 = *this;
	Mat e(sizei, sizej, 1);
	if(p == 1)
		return;
	else if(p&1)
	{
		temp1.Er_work(p);
		temp2.solve(p-1);
		temp1.Add(temp2);
	}
	else
	{
		temp1.Er_work(p>>1);
		temp1.Add(e);
		temp2.solve(p>>1);
		temp1.Multiply(temp2);
	}
	*this = temp1;
};
