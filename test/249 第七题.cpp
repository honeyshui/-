#include<bits/stdc++.h>
#include<stdio.h> 
using namespace std;
int v[101][101],d[101][101];
int t[101];
int n,m,x,y,N;
int main()
{
    memset(v,63,sizeof(v));//Ԥ����
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
    }//�������·��
    int minn=1e9,sum;
    for(int i=1;i<=n;i++)
    {
        int maxx=0;
        for(int k=1;k<=n;k++)
        if(v[i][k]>maxx&&i!=k) 
        maxx=v[i][k];//�ҳ������֪��Ϣ��Ȩֵ�������ܵ�����maxx�Զ���ֵΪ���ֵ
        if(maxx<minn) minn=maxx,sum=i;//�뵱ǰ���·�����Ƚ�
    }
    if(minn==1e9)
    printf("disjoint");//��������ֲ��ܱ�������ͼ�������"disjoint"    
    else
    printf("%d %d",sum,minn);//����������·������ʼ��
}
