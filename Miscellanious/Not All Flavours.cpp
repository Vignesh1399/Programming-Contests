#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;
ll MOD = 1e9+7;

void solve(){
	ll n,k;
	cin >> n >> k;
	vector<ll> ar(n+1,0);
	map<ll,ll> m;
	set<ll> s;
	for(ll i=1;i<=n;i++){
		cin >> ar[i];
		if(i<=k-1){
		m[ar[i]]++;
		s.insert(ar[i]);
		}
	}
	ll ans = min(n,k-1);
	ll l = 1,r=k;
	while(l<=r && r<=n){
		if(sz(s) == k){
			m[ar[l]]--;
			if(m[ar[l]]==0)
			s.erase(ar[l]);
			l++;
		}
		else if(sz(s)<k){
			s.insert(ar[r]);
			m[ar[r]]++;
			r++;
		}
		if(sz(s)<k)
		ans = max(ans,r-l);
	}
	
	cout<<ans;
	cout<<"\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

