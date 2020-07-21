#include<bits/stdc++.h>
#include<stdio.h> 
using namespace std;
int v[101][101],d[101][101];
int t[101];
int n,m,x,y,N;
int main()
{
    memset(v,63,sizeof(v));//预处理
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&N);
        for(int j=1;j<=N;j++)
        {
            scanf("%d%d",&x,&y);
            v[i][x]=y;
        }
    }
    for(int k=1;k<=n;k++)
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    {
        if(v[i][k]+v[k][j]<v[i][j])
        v[i][j]=v[i][k]+v[k][j];
    }//搜索最短路径
    int minn=1e9,sum;
    for(int i=1;i<=n;i++)
    {
        int maxx=0;
        for(int k=1;k<=n;k++)
        if(v[i][k]>maxx&&i!=k) 
        maxx=v[i][k];//找出最晚得知消息的权值，若不能到达则maxx自动赋值为最大值
        if(maxx<minn) minn=maxx,sum=i;//与当前最短路径作比较
    }
    if(minn==1e9)
    printf("disjoint");//若搜完后发现不能遍历整个图，则输出"disjoint"    
    else
    printf("%d %d",sum,minn);//否则输出最短路径及开始点
}
