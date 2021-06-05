//1043双向搜索-八数码
#include <iostream>
#include <string>
#include <queue>
using namespace std;
 
char input[100];
int state[10],s_num,e10[10],fac_n[10];
char hash_T[400000],step[10000],hash_T2[400000];
struct inf
{
    int pos;
    char mode;
};
 
queue<inf> SQ;
queue<inf> SQ2;
 
inline int move(int num,char op);
bool be_solved();
inline int hash(int num);
void BFS2();
 
 
int main()
{
    int i,j;
    for(e10[0]=1,i=1;i<=9;i++)
        e10[i]=e10[i-1]*10;
    for(fac_n[0]=0,fac_n[1]=1,i=2;i<=9;i++)
        fac_n[i]=fac_n[i-1]*i;
    while(gets(input))
    {
        for(i=strlen(input)-1,j=8;i>=0;i--)
        {
            if(input[i]!=' ')
            {
                if(input[i]=='x')
                    state[9]=j+1;
                else state[j--]=input[i]-'0';
            }
        }
        for(s_num=0,i=9,j=1;i>0;i--,j*=10)
            s_num+=state[i]*j;
        if(!be_solved())
            printf("unsolvable\n");
        else 
        {
            BFS2();
            printf("\n");
        }
    }
    return 0;
}
 
bool be_solved()
{
    int i,j,anti=0;
    for(i=1;i<=8;i++)
        for(j=1;j<i;j++)
            if(state[i]<state[j])
                anti++;
    if(anti%2)return 0;
    else return 1;
}
 
void BFS2()
{
    int to_num,to_hash,i;
    char *phash,*phash2;
    char op;
    inf k,t;
    memset(hash_T,0,sizeof(hash_T));
    memset(hash_T2,0,sizeof(hash_T2));
    while(!SQ2.empty())
        SQ2.pop();
    k.pos=s_num;k.mode=1;
    SQ2.push(k);
    k.pos=123456789;k.mode=2;
    SQ2.push(k);
    hash_T[hash(s_num)]='s';
    hash_T2[hash(123456789)]='e';
    while(!SQ2.empty())
    {
        k=SQ2.front();
        SQ2.pop();
        to_hash=hash(k.pos);
        if(k.mode==1)
            if(hash_T2[to_hash]!=0)break;
            else phash=hash_T,phash2=hash_T2;
        if(k.mode==2)
            if(hash_T[to_hash]!=0)break;
            else phash=hash_T2,phash2=hash_T;
        t=k;
        t.pos=move(k.pos,'r');
        to_hash=hash(t.pos);
        if(to_hash>=0&&phash[to_hash]==0)
            phash[to_hash]='r',SQ2.push(t);
        t.pos=move(k.pos,'l');
        to_hash=hash(t.pos);
        if(to_hash>=0&&phash[to_hash]==0)
            phash[to_hash]='l',SQ2.push(t);
        t.pos=move(k.pos,'u');
        to_hash=hash(t.pos);
        if(to_hash>=0&&phash[to_hash]==0)
            phash[to_hash]='u',SQ2.push(t);
        t.pos=move(k.pos,'d');
        to_hash=hash(t.pos);
        if(to_hash>=0&&phash[to_hash]==0)
            phash[to_hash]='d',SQ2.push(t);
    }
    i=0;
    to_hash=hash(k.pos);
    to_num=k.pos;
    while(hash_T[to_hash]!='s')
    {
        switch(step[i++]=hash_T[to_hash])
        {
        case 'r': op='l';break;
        case 'l': op='r';break;
        case 'u': op='d';break;
        case 'd': op='u';break;
        }
        to_num=move(to_num,op);
        to_hash=hash(to_num);
    }
    while(i>0)printf("%c",step[--i]);
    to_hash=hash(k.pos);
    to_num=k.pos;
    while(hash_T2[to_hash]!='e')
    {
        switch(hash_T2[to_hash])
        {
        case 'r': op='l';break;
        case 'l': op='r';break;
        case 'u': op='d';break;
        case 'd': op='u';break;
        }
        printf("%c",op);
        to_num=move(to_num,op);
        to_hash=hash(to_num);
    }
}
 
inline int hash(int num)
{
    int dig[10],i=9,j,sum,anti;
    if(num==0)return -1;
    while(num) dig[i]=num%10,num/=10,i--;
    sum=(9-dig[9])*fac_n[8];
    for(i=1;i<9;i++)
    {
        for(anti=0,j=1;j<i;j++)
            if(dig[i]<dig[j])
                anti++;
        sum+=anti*fac_n[i-1];
    }
    return sum;
}
 
inline int move(int num,char op)
{
    int t0,t1,t2;
    switch(op)
    {
    case 'r':
        if(num%10%3==0)return 0;
        return num+1;
    case 'l':
        if((num-1)%10%3==0)return 0;
        return num-1;
    case 'u':
        if(num%10-3<=0)return 0;
        t0=9-num%10+1;
        t1=num/e10[t0];
        t2=t1%1000;
        t1=t1-t2+(t2%100)*10+t2/100;
        t1*=e10[t0];
        return (t1+((num%e10[t0])-3));
    case 'd':
        if(num%10+3>9)return 0;
        t0=9-num%10+1-3;
        t1=num/e10[t0];
        t2=t1%1000;
        t1=t1-t2+(t2%10)*100+t2/10;
        t1*=e10[t0];
        return (t1+((num%e10[t0])+3));
    }
}