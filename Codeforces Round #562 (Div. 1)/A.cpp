#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

bool ok(ll mid,vector<ll> &ar, ll m){
	ll prev = 0;
	for(ll i=0;i<sz(ar);i++){
		ar[i] %= m;
		if(prev>ar[i]){
			if(prev - ar[i]>mid)
			return 0;
		}
		else if(prev<ar[i]){
			if((prev - ar[i] + m) % m <=mid){
				
			}
			else
			prev = ar[i];
		}
	}
	return 1;
}
void solve(){
	ll n,m;
	cin >> n >> m;
	vector<ll> ar(n);
	for(auto &i : ar){
		cin >> i;
	}
	ll lb = 0, ub = m;
	while(lb<=ub){
		ll mid = (lb+ub)/2;
		if(ok(mid,ar,m))
		ub = mid - 1;
		else
		lb = mid + 1;
	}
	cout << lb;
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

