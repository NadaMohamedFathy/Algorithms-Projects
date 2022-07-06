#include <iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
struct node
{
    int x,y,w,pos;
}
a[1250000];
int ans[150000];
int n,m;
int cmp(node a,node b)
{
    return a.w<b.w;
}

struct node2
{
    int from,to,w,next;
}e[1500000];
int cont;
int head[150000];
int vis[150000];
int dfn[150000];
int low[150000];
int fa[150000];
int cnt;
void add(int from,int to,int w) //constructor
{
    e[cont].to=to;
    e[cont].w=w;
    e[cont].next=head[from];
    head[from]=cont++;
}
void Dfs(int u,int from) //depth first search 
{
    low[u]=dfn[u]=cnt++;
	vis[u]=1;
    for(int i=head[u];i!=-1;i=e[i].next)
    {
        int v=e[i].to;
        if(vis[v]==1&&e[i].w!=from)low[u]=min(low[u],dfn[v]);
        else if(!vis[v])
        {
            Dfs(v,e[i].w);
            low[u]=min(low[u],low[v]);
            if(low[v]>dfn[u])ans[e[i].w]=1;
        }
    }
}

int f[1250000];
int find(int a)
{
    int r=a;
    while(f[r]!=r)
    r=f[r];
    int i=a;
    int j;
    while(i!=r)
    {
        j=f[i];
        f[i]=r;
        i=j;
    }
    return r;
}
void merge(int a,int b)
{
    int A,B;
    A=find(a);
    B=find(b);
    if(A!=B)
    {
        head[a]=head[b]=head[A]=head[B]=-1;
        vis[a]=vis[b]=vis[A]=vis[B]=0;
        dfn[a]=dfn[b]=dfn[A]=dfn[B]=0;
        low[a]=low[b]=low[A]=low[B]=0;
        f[B]=A;
    }
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        cont=0;
        cnt=1;
        for(int i=0;i<sizeof(dfn);i++)
        {
        	dfn[i]=0;
        }
        for(int i=0;i<sizeof(low);i++)
        {
        	low[i]=0;
        }
        for(int i=0;i<sizeof(vis);i++)
        {
        	vis[i]=0;
        }
        for(int i=0;i<sizeof(head);i++)
        {
        	head[i]=-1;
        }
        for(int i=0;i<sizeof(ans);i++)
        {
        	ans[i]=0;
        }
        //memset(dfn,0,sizeof(dfn));
        //memset(low,0,sizeof(low));
        //memset(vis,0,sizeof(vis));
        //memset(head,-1,sizeof(head));
        //memset(ans,0,sizeof(ans));
        for(int i=1;i<=n;i++)
		{
			f[i]=i;
		}
        for(int i=1;i<=m;i++)
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].w),a[i].pos=i;
        sort(a+1,a+1+m,cmp);
        for(int i=1;i<=m;i++)
        {
            int ss=i;
            int ee=i;
            while(ee+1<=m&&a[ee].w==a[ee+1].w)ee++;
            for(int j=ss;j<=ee;j++)
            {
                int fx=find(a[j].x);
                int fy=find(a[j].y);
                if(fx!=fy)
                {
                    ans[a[j].pos]=2;
                    add(fx,fy,a[j].pos);
                    add(fy,fx,a[j].pos);
                }
            }
            for(int j=ss;j<=ee;j++)
            {
                int fx=find(a[j].x);
                int fy=find(a[j].y);
                if(fx!=fy&&vis[fx]==0)Dfs(fx,-1);
                if(fx!=fy&&vis[fy]==0)Dfs(fy,-1);
            }
            for(int j=ss;j<=ee;j++)
            {
                merge(a[i=j].x,a[j].y);
            }
            i=ee;
        }
        for(int i=1;i<=m;i++)
        {
            if(ans[i]==0)printf("none\n");
            if(ans[i]==1)printf("any\n");
            if(ans[i]==2)printf("at least one\n");
        }
    }
}
/*struct Node // as a data structure storage map
{
	int start;
	int end;
	int length;
};
bool compare(Node a, Node b)
{
	return a.length < b.length;
}
void Kruskal(vector<Node> &arr, vector<bool> &visited)
{
	int M, N;
	M = visited.size();
	N = arr.size();
	int ans[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i].start >> arr[i].end >> arr[i].length;
		ans[i]=0;
	}
	sort(arr.begin(), arr.end(), compare);
	int weight = 0;
	for (int i = 0; i < N; i++)
	{
		if (!visited[arr[i].start] || !visited[arr[i].end])
		{
			weight += arr[i].length;
			visited[arr[i].start] = true;
			visited[arr[i].end] = true;
		}
	}
	 cout << "Minimum spanning tree weight:";
	cout << weight << endl;
}
int main()
{
	int M,N;
	cin>>M>> N;
	vector<Node> arr(N);
	vector<bool> visited(M);
	Kruskal(arr,visited);
}*/
