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

struct edge
{
    int u,v,w;
    bool operator<(const edge& p)const
    {
        return w < p.w;
    }
};

int pr[100005];
vector<edge>e;

int Find(int r)
{
    return pr[r]= (pr[r]==r) ? r: Find(pr[r]);
}

int mst(int n)
{
    sort(e.begin(),e.end());
    for(int i=0;i<=e.size();i++)
        pr[i]=i;

        int kount=0,minn=9999999;

        for(int i=0;i<e.size();i++)
        {
            int u=Find(e[i].u);
            int v=Find(e[i].v);

            if(u!=v)
            {
                pr[u]=v;
                minn=min(minn,e[i].w);
                kount++;
                if(kount==n-1)break;
            }
        }
        return minn;
}

int main()
{
    fast
    int node,edges;
    while(cin>>node>>edges)
    {
        if(!node and !edges )break;
        map<string,int>mp;
        int a=0;
        edge get;

        for(int j=0;j<edges;j++)
        {
            string f,s;
            int cost;
            cin>>f>>s>>cost;
            if(mp.find(f)==mp.end())
            {
                mp[f]=a++;
            }

            if(mp.find(s)==mp.end())
            {
                mp[s]=a++;
            }

            get.u=mp[f];
            get.v=mp[s];
            get.w=cost;
            e.pb(get);
        }

        cout<<mst(node);
    }
}









