#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n;
	cin >> n;
	vector<ll> ar(n+1,0),ans(n+1,0);
	map<ll,ll> m;
	bool flag = 0;
	set<ll> s;
	for(ll i=1;i<=1e6;i++){
		s.insert(i);
	}
	for(ll i=1;i<=n;i++){
		cin >> ar[i];
		if(ar[i]>i)
		flag = 1;
	}	
	for(ll i=n;i>=1;i--){
		if(ar[i] == ar[i-1])
		ans[i] = *(s.upper_bound(ar[i]));
		else
		ans[i] = ar[i-1];
		s.erase(ar[i]);
		s.erase(ans[i]);
	}
	if(flag)
	cout << -1;
	else{
		for(ll i=1;i<=n;i++)
		cout << ans[i] << " ";
	}
	
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

