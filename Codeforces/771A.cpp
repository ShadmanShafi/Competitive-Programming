#include<bits/stdc++.h>
using namespace std;

const int N=200005;
vector<int>V[N];
bool vis[N];
long long vertics=0,edges=0;

void dfs(int s)
{
    vis[s]=true;
    vertics++;

    for(auto x:V[s])
    {
        edges++;
        if(vis[x]==true)continue;
        dfs(x);
    }
}

int main()
{
    int node,m;
    cin>>node>>m;
    for(int j=0;j<m;j++)
    {
        int x,y;
        cin>>x>>y;
        V[x].push_back(y);
        V[y].push_back(x);
    }

    int group=0,unvisited=0;
    for(int i=1;i<=node;i++)
    {
        edges=0;vertics=0;

        if(!vis[i])
        {
            unvisited++;
            dfs(i);
             if((vertics-1)*vertics==edges)group++;
        }


    }

    if(unvisited==group)cout<<"YES";
    else cout<<"NO";



}
