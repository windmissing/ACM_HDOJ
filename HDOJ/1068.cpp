#include <cstdio>
#include <vector>
using namespace std;
#define SUCCESS 1
#define FAIL -1
vector<vector<int> > relation;
int mark[500],flag[500];
int allocatefor(int pos)
{
    int newpos,i;
    if(flag[pos]==0) return FAIL;
    for(i=0;i<relation[pos].size();i++)
        if(mark[relation[pos][i]]==-1)
        {
            mark[relation[pos][i]]=pos;
            return SUCCESS;
        }
    for(i=0;i<relation[pos].size();i++)
    {
        newpos=mark[relation[pos][i]];
        if(newpos==-2) continue;
        mark[relation[pos][i]]=-2;
        if(allocatefor(newpos)==SUCCESS)
        {
            mark[relation[pos][i]]=pos;
            return SUCCESS;
        }
        mark[relation[pos][i]]=newpos;
    }
    flag[pos]=0;
    return FAIL;
}
main()
{
    int n,m,id,i,j,temp,num;
    while(scanf("%d",&n)!=EOF)
    {
        relation.clear();
        relation.resize(n);
        for(j=0;j<n;j++)
        {
            scanf("%d: (%d)",&id,&m);
            for(i=0;i<m;i++)
            {
                scanf("%d",&temp);
                relation[id].push_back(temp);
            }
        }
        for(i=0;i<n;i++) mark[i]=-1;
        num=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++) flag[j]=1;
            if(allocatefor(i)==SUCCESS) num++;
        }
        printf("%d\n",n-num/2);
    }
    return 0;
}