#include <stdio.h>
#define MAXN 100000
#define ROOT 1

struct node
{
    int left,right,sum;
}t[MAXN];

int val[MAXN];
int n;

void build(int p, int left, int right)
{
    int m;
    t[p].left = left;
    t[p].right = right;
    t[p].sum = 0;
    if (left == right)
        return;
    m = (left + right) / 2;
    build(p*2, left, m);
    build(p*2+1, m+1, right);
}

void update(int p, int goal, int add)
{
    t[p].sum += add;
    if (t[p].left == t[p].right)
        return;
    int m = (t[p].left + t[p].right) / 2;
    if (goal <= m)
        update(p*2, goal, add);
    if (goal > m)
        update(p*2+1, goal, add);
}

int getsum(int p, int left, int right)
{
    if (left > right)
        return 0;
    if (t[p].left == left && t[p].right == right)
        return t[p].sum;
    int m = (t[p].left + t[p].right) / 2;
    if (right <= m)
        return getsum(p*2, left, right);
    else if (left > m)
        return getsum(p*2+1, left, right);
    else return getsum(p*2, left, m) + getsum(p*2+1, m + 1, right);
}


int main()
{
    while (scanf("%d", &n) == 1)
    {
        build(ROOT, 0, n - 1);
        int i,sum = 0,ans;
        for (i = 1; i <= n; i++)
        {
            scanf("%d", &val[i]);
            sum += getsum(ROOT, val[i], n - 1);
            update(ROOT, val[i], 1);
        }
        ans = sum;
        for (i = 1; i <= n; i++)
        {
            sum = sum + (n - val[i] - 1) - val[i];
            ans = sum < ans ? sum : ans;
        }
        printf("%d\n", ans);
    }
    return 0;
}
