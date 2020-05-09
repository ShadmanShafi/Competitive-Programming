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
#define NL          "\n"
//lower_bound == Shoman othoba prothom boro element ta return korbe//iterator return kore
//upper bound mane first boro element return korbe
//string s(n,'a');
//ans+=string(r,'R');

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
ll POW(ll  B,ll P)
{
    ll R=1;
    while(P)
    {
        if(P&1)
            R=R*B;
        B=B*B;
        P>>=1;
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

int brute(string s)
{

    int an=0;

    if(s.size()<3)
    {
        cout<<"0";
        return 0;
    }

        for(int i=0; i<s.size()-2; i++)
        {
            if(s[i]=='A' and s[i+1]=='B' and s[i+2]=='C')
            {
                s[i]='B';
                s[i+1]='C';
                s[i+2]='A';
                if(i-2<0)i=0;
                else i=i-2;
                //cout<<s<<NL;
                an++;
            }

        }

    return an;
}

int modern(string s)
{
    int ans=0,a=0;

    if(s.size()<3)
    {
        cout<<"0";
        return 0;
    }

        for(int i=0; i<s.size()-2; i++)
        {
            if(s[i]=='A')a++;
            else a=0;
            int m;

            if(s[i]=='A' and s[i+1]=='B' and s[i+2]=='C')
            {
                s[i]='B';
                s[i+1]='C';
                s[i+2]='A';
                ans++;
                if(a>0)
                {
                ans+=(a-1);
                a=0;
                 m=a;
                 int j=1;
                while(m--)
                {
                    s[i+2-j]='A';
                    j++;
                }
                }


                //cout<<s<<NL;

            }

        }

    return ans;
    }

int main()
{
    fast
    while(true)
    {

    string s;
    //cin>>s;

   string temp[]={"A","B","C"};
   s.clear();
   for(int i=0;i<10;i++)
   {
       int x=rand()%3;
       s=s+temp[x];
   }


    int b=brute(s);
    int m=modern(s);
    if(b!=m)
    {
        cout<<b<<" <=leftbrute "<<m<<NL<<s<<NL;
        break;
    }
    else cout<<"Ok"<<NL;

    }//while
}

