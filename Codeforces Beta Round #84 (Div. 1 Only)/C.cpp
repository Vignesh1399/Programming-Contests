#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

ll dfs(ll s, vector<ll> g[], vector<bool> &v){
	v[s] = 1;
	ll ans = 1;
	for(auto i : g[s]){
		if(!v[i]){
			ans += dfs(i,g,v);
		}
	}
	return ans;
}
void solve(){
	ll n,a,b,w,ans=0;
	cin >> n;
	vector<ll> g[n+1];
	vector<bool> v(n+1,0);
	for(ll i=0;i<n-1;i++){
		cin >> a >> b >> w;
		bool unlucky = 0;
		while(w){
			if(w%10 !=4 && w%10 != 7){
				unlucky = 1;
				break;
			}
			w /= 10;
		}
		if(unlucky){
			g[a].eb(b);
			g[b].eb(a);
		}
	}
	for(ll i=1;i<=n;i++){
		if(!v[i]){
			ll temp = dfs(i,g,v);
			ans += temp * (n-temp) * (n-temp-1);
		}
	}
	cout << ans ;
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

