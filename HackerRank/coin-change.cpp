#include<bits/stdc++.h>
using namespace std;

vector<int>coins;
int dp[500];
#define ll long long

int coinChange( int amount)
{
    int coinSize= coins.size();
    int dp[amount+1];
    dp[0]=0;

    for(int i=1; i<=amount; i++)
        dp[i]=INT_MAX;

    for(int i=1; i<=amount; i++)
    {
        int ans=INT_MAX;
        for(int j=0; j<coinSize; j++)
            if(coins[j]<=i)
                ans=min(ans,dp[i-coins[j]]);

        if(ans==INT_MAX)
            dp[i]=INT_MAX;
        else
            dp[i]=ans+1;

    }

    if(dp[amount]==INT_MAX)
        return -1;
    else
        return dp[amount];

}

int main()
{
    ll n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        ll x;
        cin>>x;
        coins.push_back(x);
    }
    cout<<coinChange(n);
}