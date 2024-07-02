#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1000000007
using namespace std;
int main(){
    ll n;
    long double ans = 0.0;
    cin>>n;
    vector<long double> p(n+1,1.0);
    /*
    State
    dp[i][j]: Denotes the probability of getting j heads in i tosses
    Recurrence
    dp[i][j]+=dp[i-1][j-1]*p[i]+dp[i-1][j]*(1-p[i]);
    i.e it is the sum of probabilities of jth head falling in the ith toss
    and jth head falling in the (i-1)th toss, tail falling in the ith toss
    */
    vector<vector<long double>> dp(n+1,vector<long double> (n+1,0.0));
    dp[0][0] = 1.0;
    //probability of getting 0 heads in 0 tosses = 1
    for(ll i=1;i<=n;i++)
        cin>>p[i];
    for(ll i=1;i<=n;i++){
        for(ll j=0;j<=i;j++){ 
            if(j)
                dp[i][j]+=dp[i-1][j-1]*p[i];
            dp[i][j]+=dp[i-1][j]*(1 - p[i]);
        }
    }
    for(ll i=n/2+1;i<=n;i++){
        ans += dp[n][i];
    }
    cout<<fixed<<showpoint;
    cout<<setprecision(15);
    cout<<ans;
	return 0;
}
