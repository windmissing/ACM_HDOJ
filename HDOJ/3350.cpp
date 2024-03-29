//数据结构-栈的应用
#include<iostream>
#include<string>
#include<vector>
using namespace std;
 
struct node
{
	int value;//值
	int add;//+的次数
};
//用容器实现栈的FILO
vector<node> ans;//数值栈
vector<char> sig;//符号栈
int main()
{
	int t, i;
	string str;
	node temp, temp2;
	cin>>t;
	while(t--)
	{
		cin>>str;
		temp.value = 0; temp.add = 0;
		sig.clear(); ans.clear();
		for(i = 0; i < str.length(); i++)
		{
			//逐字打扫，只有'('、'+'、 ','、')'和数字是有用的，"MAX"不用处理
			//优先级：'(' > '+' >  ',' > ')'
			switch (str[i])
			{
			case '(':
				sig.push_back(str[i]);
				temp.value = 0; temp.add = 0;
				break;
			case '+':
				ans.push_back(temp);
				sig.push_back(str[i]);
				temp.value = 0; temp.add = 0;
				break;
			case ',':
				while(!sig.empty() && sig.back() == '+')
				{
					temp2 = ans.back();
					temp.value = temp.value + temp2.value;
					temp.add = temp.add + 1 + temp2.add;
					ans.pop_back();
					sig.pop_back();
				}
				ans.push_back(temp);
				sig.push_back(str[i]);
				temp.value = 0; temp.add = 0;
				break;
			case ')':
				while(!sig.empty() && sig.back() == '+')
				{
					temp2 = ans.back();
					temp.value = temp.value + temp2.value;
					temp.add = temp.add + 1 + temp2.add;
					ans.pop_back();
					sig.pop_back();
				}
				temp2 = ans.back();
				if(temp2.value > temp.value)
				{
					temp.value = temp2.value;
					temp.add = temp2.add * 2 + temp.add;
				}
				else
				{
					temp.add = temp.add * 2 + temp2.add;
				}
				sig.pop_back();sig.pop_back();
				ans.pop_back();
				break;
			case '0':case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9':
				temp.value = temp.value * 10 + str[i] - '0';
				break;
			}
		}
		while(!sig.empty() && sig.back() == '+')
		{
			temp2 = ans.back();
			temp.value = temp.value + temp2.value;
			temp.add = temp.add + 1 + temp2.add;
			ans.pop_back();
			sig.pop_back();
		}
		
		cout<<temp.value<<' '<<temp.add<<endl;
	}
	return 0;
}
