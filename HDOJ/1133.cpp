#include <iostream>
#include <string.h>
using namespace std;
#define MAX_LENGTH 400                         //最长的数字的长度
typedef struct long_int                         //定义了长数的结构
{
	char num[MAX_LENGTH];                       //具体的每一位上的数字
	int l;                                   //数字的长度
}long_int;
void init_long_int(long_int &a)                 //初始化全部为0
{
	memset(&a,0,sizeof(a));
}
long_int int_to_long_int(int x)                 //返回x对应的长数,错误就打印错误
{
	  long_int a;
	  init_long_int(a);
	  while (x!=0)
	  {
		  a.num[a.l++]=x%10;
		  x/=10;
	  }
	  return a;
}
long_int multiply_int(long_int &a,int b)           //乘法函数,返回a*b
{
	  int jwei,temp,i,j;                     //进位，临时变量
	  long_int c;                           //最终结果存放
	  init_long_int (c);
	  jwei=0;temp=0;i=0;j=0;
	  //以上变量初始化
	  if(b==0) return c;
	  for(i=0;i<a.l;i++)
	  {
			temp=jwei+b*a.num[i];
			c.num[i]=temp%10;
			jwei=temp/10;
	  }
	  c.l=i;
	  while (jwei>0)
	  {
		  c.num[c.l++]=jwei%10;
		  jwei/=10;
	  }
	  return c;
}
void long_int_printf(long_int &x)                 //长数打印函数
{
	  for (int i=x.l-1;i>=0;i--)
		  printf("%c",x.num[i]+48);
	  return ;
}
int main()
{
    void init_long_int(long_int &a);             //初始化函数a=0
    long_int int_to_long_int(int x);           //返回x对应的长数,错误就打印错误
    long_int multiply_int(long_int &a,int b);       //乘法函数,返回a*b(b是一般长度的)
    void long_int_printf(long_int &x);           //长数打印函数
    int a,b,i,t=0;
    long_int x;
    while (cin>>a>>b&&(a||b))
    {
		t++;
		cout<<"Test #"<<t<<':'<<endl;
		if (b>a)
		{
			cout<<0<<endl;//无解输出0
			continue;
		}
		x=int_to_long_int(1);
		for (i=2;i<=(a+b);i++)                     //介乘计算
			if (i!=a+1) x=multiply_int(x,i);             //避免除法，跳过分母
		if (b!=0) x=multiply_int(x,(a-b+1));             //这种情况，分母不该被跳过
		long_int_printf(x);
		cout<<endl;
	}
	return 0;
}