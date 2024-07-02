#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

ll dp[100000];
ll place(char c, ll cur, vector<ll> &cost, vector<ll> &par){
	if(cur<0)
	return 0;
	if(dp[cur] != -1)
	return dp[cur];
	if(cur == 0){
		par[cur] = c-'a';
		return 1;
	}
	ll ans = 0;
	for(char i=c;i>='a';i--){
		ll x = place(i,cur - cost[i-'a'], cost, par);
		if(x != 0){
			ans = x;
			par[cur] = c-'a';
			break;
		}
		else
		ans = 0;
	}
	return ans;
}
void solve(){
	ll w;
	cin >> w;
	vector<ll> par(w+1,-1);
	memset(dp,-1,sizeof(dp));
	vector<ll> c(26,0);
	for(ll i=0;i<26;i++){
		cin >> c[i];
	}
	char x = 'z';
	ll v = place(x,w,c,par);
	if(v == 0){
		cout << -1 ;
		return ;
	}
	string ans = "";
	ll k=0;
	while(k<w){
		ans += par[k] +'a';
		k += c[par[k]];
	}
	reverse(ans.begin(),ans.end());
	cout << ans;
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

