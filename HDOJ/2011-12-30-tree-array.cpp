#include<iostream>    
using namespace std;   
      
#define MAX 1002  
      
class TreeArray  
{  
public:  
    int **s;  
    int type;  
public:  
    TreeArray(int t);  
    ~TreeArray();  
    void clear();  
    int lowbit(int x){return x&(-x);};  
    void modify(int x, int value);  
    void modify(int x, int y, int value);  
    int sum(int x);  
    int sum(int x, int y);  
};  
TreeArray::TreeArray(int t):type(t)  
{  
    int i;  
    s = new int*[MAX+1];  
    //一维  
    if(type == 1)  
    {  
        for(i = 0; i <= MAX; i++)  
            s[i] = new int;  
    }  
    //二维  
    else if(type == 2)  
    {  
        for(i = 0; i <= MAX; i++)  
            s[i] = new int[MAX+1];  
    }  
}  
TreeArray::~TreeArray()  
{  
    int i;  
    for(i = 0; i <= MAX; i++)  
        delete []s[i];  
    delete []s;  
}  
void TreeArray::clear()  
{  
    int i, j;  
    for(i = 0; i <= MAX; i++)  
    {  
        if(type == 1)  
            s[i][0] = 0;  
        else  
        {  
            for(j = 0; j <= MAX; j++)  
                s[i][j] = 0;  
        }  
    }  
}  
void TreeArray::modify(int x, int value)  
{  
    while(x <= MAX)  
    {  
        s[x][0] += value;  
        x += lowbit(x);  
    }  
}  
void TreeArray::modify(int x,int y,int value)  
{    
    int temp = y;  
    while(x <= MAX)  
    {  
        y = temp;  
        while(y <= MAX)  
        {  
            s[x][y] += value;  
            y = y + lowbit(y);  
        }  
        x = x + lowbit(x);  
    }       
}    
int TreeArray::sum(int x)  
{  
    int ans=0;  
    while(x > 0)  
    {  
        ans += s[x][0];  
        x -= lowbit(x);  
    }  
    return ans;  
}  
int TreeArray::sum(int x,int y)  
{    
    int ans=0, temp = y;    
    while(x > 0)  
    {  
        y = temp;  
        while(y > 0)  
        {  
            ans += s[x][y];  
            y = y - lowbit(y);  
        }  
        x = x - lowbit(x);  
    }  
    return ans;    
}