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


int main()
{
    //fast
    int t;
    cin>>t;
    while(t--)
    {
        int n,flag=0,siz=0,siz2=0,sizPr=0,siz2Pr=0,frontSide=0,backSide=0,zero=0,zero2=0;
        cin>>n;
        si fr,lt,full;//front last


        vi v;

        for(int i=1;i<=n;i++)
        {
            int x;
            cin>>x;

            v.pb(x);

            full.insert(x);

            if(!fr.count(x) and flag==0)
            {
                fr.insert(x);
                siz++;
            }


            else
            {

                if(lt.count(x))zero=1;
                flag=1;
                lt.insert(x);
                sizPr++;
            }
        }
        if(siz==*(fr.rbegin()) and *(fr.begin())==1 and  *(lt.begin())==1 and sizPr==*(lt.rbegin()))
        {
            frontSide=1;
//            cout<<sizPr<<" "<<*lt.rbegin();
//        cout<<"shamne ok"<<endl;
        }

        fr.clear();lt.clear();
        //check back
        int i,j;
        flag=0;

        for( i=1, j=v.size()-1;i<=n,j>=0;j--,i++)
        {
            int x=v[j];
            if(!lt.count(x) and flag==0)
            {
                lt.insert(x);
                siz2++;
            }

            else
            {

         //   cout<<"a"<<x<<"a"<<" ";
                if(lt.count(x))zero2=1;
                flag=1;
                fr.insert(x);
                siz2Pr++;
            }



        }

         if(siz2Pr==*(fr.rbegin()) and *fr.begin()==1 and *lt.begin()==1 and siz2==*(lt.rbegin()))
        {
            backSide=1;
//            cout<<"piche ok"<<endl;
//            cout<<fr.size()<<" "<<*(fr.rbegin())<<endl;
//            cout<<lt.size()<<" "<<*(lt.rbegin())<<endl;
        }

        if(zero2==1 and zero==1)cout<<"0\n";
        else if(frontSide and backSide and siz!=siz2Pr)cout<<"2\n"<<siz<<" "<<sizPr<<"\n"<<siz2Pr<<" "<<siz2<<endl;
        else if(frontSide)cout<<"1\n"<<siz<<" "<<sizPr<<endl;
        else if(backSide)cout<<"1\n"<<siz2Pr<<" "<<siz2<<endl;
        else cout<<"0\n";





    }

}

