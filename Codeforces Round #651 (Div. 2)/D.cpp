#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

bool ok(ll ans, vector<ll> &ar, ll n, ll k){
	vector<ll> bodd,beven;
	for(ll i=1;i<=n;i++){
		if(sz(beven)%2){
			if(ar[i]<=ans)
			beven.pb(ar[i]);
		}
		else
		beven.pb(ar[i]);
		if(sz(bodd)%2==0){
			if(ar[i]<=ans)
			bodd.pb(ar[i]);
		}
		else
		bodd.pb(ar[i]);
	}
	return ((sz(bodd)>=k || sz(beven)>=k));
}

void solve(){
	ll n,k;
	cin >> n >> k;
	vector<ll> ar(n+1,0);
	for(ll i=1;i<=n;i++){
		cin >> ar[i];
	}
	ll lb = 1, ub = 1e9;
	while(lb <= ub){
		ll mid = (lb+ub)/2;
		bool yes = ok(mid,ar,n,k);
		//cout << mid << " " << yes << '\n';
		if(yes)
		ub = mid-1;
		else
		lb = mid+1;
	}
	cout << lb ;
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

