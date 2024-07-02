#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
	string s,t,ans="";
	cin>>s>>t;
    ll n = s.length(), m = t.length();
    s = s[0] + s;
    t = t[0] + t;
    vector<vector<ll>> dp(n+1,vector<ll>(m+1,0));
    /*
    State
    dp[i][j]: Denotes the length of the longest common subsequence of s[1...i] and t[1...j].
    Recurrence
    dp[i][j]: if s[i]==t[j], s[i],t[j] are the same and hence part of a common subssequence
    so dp[i][j] = dp[i-1][j-1] + 1
    else if s[i]!=t[j], we consider the length of the longest common subsequence obtained till now
    i.e dp[i][j] = max(dp[i-1][j],dp[i][j-1])
    */
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            if(s[i]==t[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    ll i = n, j = m;
    while(i && j){
        if(s[i]==t[j]){
            ans+=s[i];
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }
        else
            j--;
    }
    reverse(ans.begin(),ans.end());
    cout<<ans; 
	return 0;
}
