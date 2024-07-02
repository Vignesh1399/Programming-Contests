#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
void find_longest_dist(vector<ll> g[],ll s,vector<ll> &v,vector<ll> &ind,vector<ll> &dp){
    queue<ll> q;
    q.push(s);
    v[s] = 1;
    while(!q.empty()){
        ll vertex = q.front();
        for(ll i=0;i<g[vertex].size();i++){
            ind[g[vertex][i]]--;
            dp[g[vertex][i]] = max(dp[g[vertex][i]],dp[vertex] + 1);
            if(!ind[g[vertex][i]] && !v[g[vertex][i]]){
                v[g[vertex][i]] = 1;
                q.push(g[vertex][i]);
            }
        }
        q.pop();
    }
}
int main() {
    ll n,m,x,y,ans = 0;
    cin>>n>>m;
    vector<ll> g[n+1],dp(n+1,0),v(n+1,0),ind(n+1,0);
    /*
    State: 
    dp[i]: Denotes the longest directed path ending at vertex i
    Recurence:
    dp[i] = max(dp[i],dp[j]+1) for all j, where j is the set of all incoming vertices to i,
    i.e vertices for which head of an edge is in j and tail is in i.
    */
    for(ll i=0;i<m;i++){
        cin>>x>>y;
        g[x].pb(y);
        ind[y]++;    
    }
    for(ll i=1;i<=n;i++){
        if(!v[i] && !ind[i])
            find_longest_dist(g,i,v,ind,dp);
    }
    for(ll i=1;i<=n;i++)
        ans = max(ans,dp[i]);
    cout<<ans;	
	return 0;
}
