#include <iostream>
#include <queue>
using namespace std;

//有向图的邻接表
typedef struct v
{
   int vex;//终点的序号
   v *next;//与这条有向边具有相同起点的其它有向边
}V;//边结点
typedef struct h
{
   int indegree;//入度
   v *next;//指向（（从该节点出发的有向边的）边结点所组成的单链表）
}H;//头结点
H team[10010];
V *p;

int main()
{
   int i,n,m,a,b,count;
   priority_queue<int,vector<int>,greater<int> > q;
   while(cin>>n>>m)
   {
       memset(team,0,sizeof(team));
       while(m--)
       {
           //加入一条a->b的有向边
           cin>>a>>b;
           team[b].indegree++;
           p=new V;
           p->vex=b;
           p->next=team[a].next;
           team[a].next=p;
       }
       //输出拓扑排序
       for(i=1;i<=n;i++)
           if(team[i].indegree==0)
               q.push(i);
       count=0;
       while(!q.empty())
       {
           a=q.top(); q.pop();
           if(count)
               cout<<' ';
           cout<<a;
           count++;
           for(p=team[a].next;p!=0;p=p->next)
           {
               b=p->vex;
               if(--team[b].indegree==0)
                   q.push(b);
           }
       }
       cout<<endl;
   }
   return 0;
}