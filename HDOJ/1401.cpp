/*
很显然的BFS，没有悬念，只是实现起来有点麻烦
写完才发现，本题中，起点和终点都很明确，可以用双搜
不过我的单搜也没有超时
*/
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
 
//状态
struct node
{
	char ch[4];//用char类型是为了省空间
	int ceil;
};
//判断两个状态是否为同一状态
int equal(const node& a,const node& b)
{
	int i = 0, j = 0, ans = 0;
	while(i < 4&&j<4)
	{
		if(a.ch[i] == b.ch[j])
		{
			ans++;
			i++;
			j++;
		}
		else if(a.ch[i] < b.ch[j])
			i++;
		else if(a.ch[i] > b.ch[j])
			j++;
	}
	return ans; 
}
queue<node> Q;
map<int, int> M;//避免状态重复
bool m[9][9];
 
int main()
{
	int a1[8], a2[8], i, j, id;
	node start, end, p, q;
	bool flag;
	while(cin>>a1[0])
	{
		flag = 0;id = 0;
		//输入目标状态
		for(i = 1; i < 8; i++)
			cin>>a1[i];
		//输入初始状态
		for(i = 0; i < 8; i++)
			cin>>a2[i];
		//记录初始状态，每个char存储两位数，分别是横坐标与纵坐标
		for(i = 0; i < 4; i++)
		{
			start.ch[i] = (a2[2*i])*10+a2[2*i+1];
			id = id * 100 + start.ch[i];
		}
		//将四个点按顺序存储，有利于后续操作
		sort(start.ch, start.ch+4);
		start.ceil = 0;
		//同样方法处理目标状态
		for(i = 0; i < 4; i++)
			end.ch[i] = (a1[2*i])*10+a1[2*i+1];
		sort(end.ch, end.ch+4);
		
		//典型的BFS
		while(!Q.empty())Q.pop();
		M.clear();
		M[id] = 1;
		Q.push(start);
		while(!Q.empty())
		{
			p = Q.front();
			Q.pop();
			if(p.ceil > 8)break;
			int ans = equal(p, end);
			if(ans == 4)
			{
				flag = 1;
				break;
			}
			//优化：如果还能走2步，却有3个棋子没有在目标位置上，肯定不能成功
			if(ans < p.ceil - 4)
				continue;
			memset(m, 0, sizeof(m));
			//析出状态对应的坐标
			for(i = 0; i < 4; i++)
			{
				int temp = (int)p.ch[i];
				m[temp/10][temp%10] = 1;
			}
			//下一步
			for(i = 0; i < 4; i++)
			{
				int temp = (int)p.ch[i];
				int x = temp/10, y = temp%10;
				//上
				q = p;q.ceil++;
				if(x > 1)
				{
					//下一步是空的，就走下一步
					if(m[x-1][y] == 0)
					{
						q.ch[i] = (x-1)*10+y;
						sort(q.ch, q.ch+4);
						id = 0;
						for(j = 0; j < 4; j++)
							id = id * 100 + q.ch[j];
						if(M[id] == 0)
						{
							Q.push(q);
							M[id] = 1;
						}
					}
					//下一步是棋子，下下步是空的，就跳一步
					else
					{
						if(x > 2 && m[x-2][y] == 0)
						{
							q.ch[i] = (x-2)*10+y;
							sort(q.ch, q.ch+4);
							id = 0;
							for(j = 0; j < 4; j++)
								id = id * 100 + q.ch[j];
							if(M[id] == 0)
							{
								Q.push(q);
								M[id] = 1;
							}
						}
					}
				}
				//下
				q = p;q.ceil++;
				if(x < 8)
				{
					if(m[x+1][y] == 0)
					{
						q.ch[i] = (x+1)*10+y;
						sort(q.ch, q.ch+4);
						id = 0;
						for(j = 0; j < 4; j++)
							id = id * 100 + q.ch[j];
						if(M[id] == 0)
						{
							Q.push(q);
							M[id] = 1;
						}
					}
					else
					{
						if(x < 7 && m[x+2][y] == 0)
						{
							q.ch[i] = (x+2)*10+y;
							sort(q.ch, q.ch+4);
							id = 0;
							for(j = 0; j < 4; j++)
								id = id * 100 + q.ch[j];
							if(M[id] == 0)
							{
								Q.push(q);
								M[id] = 1;
							}
						}
					}
				}
				//左
				q = p;q.ceil++;
				if(y > 1)
				{
					if(m[x][y-1] == 0)
					{
						q.ch[i] = x*10+y-1;
						sort(q.ch, q.ch+4);
						id = 0;
						for(j = 0; j < 4; j++)
							id = id * 100 + q.ch[j];
						if(M[id] == 0)
						{
							Q.push(q);
							M[id] = 1;
						}
					}
					else
					{
						if(y > 2 && m[x][y-2] == 0)
						{
							q.ch[i] = x*10+y-2;
							sort(q.ch, q.ch+4);
							id = 0;
							for(j = 0; j < 4; j++)
								id = id * 100 + q.ch[j];
							if(M[id] == 0)
							{
								Q.push(q);
								M[id] = 1;
							}
						}
					}
				}
				//右
				q = p;q.ceil++;
				if(y < 8)
				{
					if(m[x][y+1] == 0)
					{
						q.ch[i] = x*10+y+1;
						sort(q.ch, q.ch+4);
						id = 0;
						for(j = 0; j < 4; j++)
							id = id * 100 + q.ch[j];
						if(M[id] == 0)
						{
							Q.push(q);
							M[id] = 1;
						}
					}
					else
					{
						if(y < 7 && m[x][y+2] == 0)
						{
							q.ch[i] = x*10+y+2;
							sort(q.ch, q.ch+4);
							id = 0;
							for(j = 0; j < 4; j++)
								id = id * 100 + q.ch[j];
							if(M[id] == 0)
							{
								Q.push(q);
								M[id] = 1;
							}
						}
					}
				}
			}
		}
		if(flag)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}