/*每次从未过期的作业中选择分值最大的*/
#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
	int score;
	int deadline;
	bool flag;
	bool operator<(const node& B)const
	{
		if(score > B.score)return 1;
		if(score == B.score && deadline < B.deadline)return 1;
		return 0;
	}
}homework[1001];
int main()
{
    int t,i;
    cin>>t;
    while(t--)
    {
        int day=0;
        int n;
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>homework[i].deadline;
            if(homework[i].deadline>day)day=homework[i].deadline;
			homework[i].flag = 0;
        }
        int s=0;
        for(i=0;i<n;i++)
        {
            cin>>homework[i].score;
            s = s + homework[i].score;
        }
		sort(homework, homework + n);
        int sum=0;
        while(day)
        {
            for(i=0;i<n;i++)
            {
                if(homework[i].deadline>=day && !homework[i].flag)
                {
                    homework[i].flag = 1;
					sum = sum + homework[i].score;
					break;
                }
            }
            day--;
        }
        cout<<s-sum<<endl;
    }
    return 0;
}