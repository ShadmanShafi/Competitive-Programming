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
#define asi         cout<<"Check"<<endl;
#define bye         return 0
#define ok          cout<<"OK"<<endl;
//lower_bound == Shoman othoba prothom boro element ta return korbe//iterator return kore
//upper bound mane first boro element return korbe
//string s(n,'a');

ll Digits ( ll a )
{
    return ( floor ( log10 ( a ) ) + 1 );
}
ll BMod ( ll B, ll P, ll M )
{
    ll R = 1;
    B = B % M;
    while ( P )
    {
        if ( P & 1 )
            R = ( R * B ) % M;
        P >>= 1;
        B = ( B * B ) % M;
    }
    return R;
}
ll gcd ( ll a, ll b )
{
    if ( b == 0 )
        return a;
    return gcd ( b, a % b );

}
ll lcm ( ll a, ll b )
{
    return a * b / gcd ( a, b );

}

const int N=900005;
vector<int>V[N];
int ara[30];

int main()
{
    //fast
    int n;
    cin>>n;
    string s;
    cin>>s;

    for(int i=0;i<s.size();i++)
        V[s[i]-'a'].push_back(i+1);

    int f;
    cin>>f;
    FOR(i,f)
    {
        string name;
        cin>>name;
        int ans=0,charCount=0;
        memset(ara,0,sizeof(ara));

        for(int j=0;j<name.size();j++)
        {
            ara[name[j]-'a']++;
        }

        for(int x=0;x<26;x++)
        {
            if(ara[x]>0)
            {
                charCount=V[x][ara[x]-1];

            ans=max(charCount,ans);
            }

        }

        cout<<ans<<endl;
    }



}

