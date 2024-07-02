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
	set<ll> s;
	for(ll i=1;i<=n;i++){
		cin >> ar[i];
		if(i<=k-1)
		s.insert(ar[i]);
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

