#include<bits/stdc++.h>
using namespace std;
#define ll          long long
#define pb          push_back
#define mp          make_pair
#define ff          first
#define ss          second
#define vi          vector<int>
#define si          set<int>
#define FOR(i,n)    for(int i=0;i<n;i++)
#define fast        ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SP(x)       fixed<<setprecision(x)
#define fWrite      freopen("out.txt", "w", stdout);//to write the output in a txt file
#define fRead       freopen("in.txt", "r", stdin);
#define asi         cout<<"Check"<<endl
#define bye         return 0
#define ok          cout<<"OK"<<endl
//lower_bound == Shoman othoba prothom boro element ta return korbe//iterator return kore
//upper bound mane first boro element return korbe
//string s(n,'a');

ll Digits(ll a)
{
    return(floor(log10(a))+1);
}
ll BMod(ll B,ll P,ll M)
{
    ll R=1;
    B=B%M;
    while(P)
    {
        if(P&1)
            R=(R*B)%M;
        P >>= 1;
        B=(B*B)%M;
    }
    return R;
}
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);

}
ll lcm(ll a,ll b)
{
    return a*b/gcd(a,b);

}

const int N=100005;
vector<int>V[N];
bool vis[N];
vector<int>ans;

void dfs(int s)
{
   // int i,j;
    priority_queue<int,vector<int>,greater<int>>st;
    st.push(s);
    vis[s]=true;
    while(!st.empty())
    {
        int u=st.top();
        st.pop();
        ans.push_back(u);
        for(auto x:V[u])
        {
            if(!vis[x])
            {
                vis[x]=true;
                st.push(x);
            }
        }

    }
    //return c;
}



int main()
{
    fast
    int nodes,edges;
    cin>>nodes>>edges;
    FOR(i,edges)
    {
        int x,y;
        cin>>x>>y;
        V[x].pb(y);
        V[y].pb(x);
    }

    FOR(i,nodes)
    sort(V[i].begin(),V[i].end());

    dfs(1);
    FOR(i,ans.size())
    cout<<ans[i]<<" ";


}

