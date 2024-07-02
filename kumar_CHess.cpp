#include <bits/stdc++.h>
#define ll int
#define pb push_back
#define eb emplace_back
#define F first 
#define S second 
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;
struct p{
	ll a,b,c;
};
ll n,m;
ll ngr[1000][1000],ngd[1000][1000],ngl[1000][1000],ngup[1000][1000];
bool within(ll i, ll j){
	return (i>=0 && i<n && j>=0 && j<m);
}
bool comp(struct p x, struct p y){
	return x.a>y.a;
}
ll gdfs(ll i, ll j, vector<vector<ll>> &dp, vector<vector<ll>> &ar){
	if(dp[i][j] != -1)
	return dp[i][j];
	ll ans = 0;
	ll nj = ngr[i][j];
	if(within(i,nj))
		ans = max(ans,gdfs(i,nj,dp,ar));
	nj = ngl[i][j];
	if(within(i,nj))
		ans = max(ans,gdfs(i,nj,dp,ar));
	ll ni = ngup[i][j];
	if(within(ni,j))
		ans = max(ans,gdfs(ni,j,dp,ar));
	ni = ngd[i][j];
	if(within(ni,j))
		ans = max(ans,gdfs(ni,j,dp,ar));
	dp[i][j] = 1 + ans;
	return ans;
}
void solve(){
    cin >> n >> m;
    ll ans = 0;
    vector<struct p> order;
    vector<vector<ll>> ar(n,vector<ll>(m,0)),dp(n,vector<ll>(m,-1));
    for(ll i=0;i<n;i++){
    	for(ll j=0;j<m;j++){
    		cin >> ar[i][j];
    		order.pb({ar[i][j],i,j});
    	}
    }
    sort(order.begin(),order.end(),comp);
    stack<ll> s;
    for(ll i=0;i<n;i++){
    	for(ll j=m-1;j>=0;j--){
    		while(!s.empty() && ar[i][s.top()]<=ar[i][j])
    		s.pop();
    		if(s.empty()){
    			ngr[i][j] = 1e4;
    		}
    		else
    			ngr[i][j] = s.top();
    		s.push(j);
    	}
    	while(!s.empty())
    	s.pop();
    	for(ll j=0;j<m;j++){
    		while(!s.empty() && ar[i][s.top()]<=ar[i][j])
    		s.pop();
    		if(s.empty()){
    			ngl[i][j] = 1e4;
    		}
    		else
    			ngl[i][j] = s.top();
    		s.push(j);
    	}
    	while(!s.empty())
    	s.pop();
    }
    for(ll j=0;j<m;j++){
    	for(ll i=0;i<n;i++){
    		while(!s.empty() && ar[s.top()][j]<=ar[i][j])
    		s.pop();
    		if(s.empty()){
    			ngup[i][j] = 1e4;
    		}
    		else
    			ngup[i][j] = s.top();
			s.push(i);
    	}
    	while(!s.empty())
    	s.pop();
    	for(ll i=n-1;i>=0;i--){
    		while(!s.empty() && ar[s.top()][j]<=ar[i][j])
    		s.pop();
    		if(s.empty()){
    			ngd[i][j] = 1e4;
    		}
    		else
    			ngd[i][j] = s.top();
			s.push(i);
    	}
    	while(!s.empty())
    	s.pop();
    }
    for(ll i=0;i<sz(order);i++){
    	if(dp[order[i].b][order[i].c] == -1){
    		gdfs(order[i].b,order[i].c,dp,ar);
    	}
    }
    for(ll i=0;i<n;i++){
    	for(ll j=0;j<m;j++)
    	ans = max(ans,dp[i][j]);
    }
    cout << ans;
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

