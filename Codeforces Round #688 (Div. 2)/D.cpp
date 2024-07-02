#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define F first 
#define S second 
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;
vector<ll> ar;
void pre(){
	ll sum = 0,pow2 = 2;
	while(sum<=1e18){
		sum += pow2;
		ar.eb(sum);
		pow2 *= 2;
	}
}
void solve(){
	ll k;
	cin >> k;
	vector<ll> ans;
	if(k%2){
		cout << -1 << "\n";
		return ;
	}
	while(k>0){
		auto it = upper_bound(ar.begin(),ar.end(),k);
		ll x = it - ar.begin();
		ans.eb(1);
		for(ll i=1;i<x;i++)
		ans.eb(0);
		k -= ar[x-1];
	}
	cout << sz(ans) << "\n";
	for(auto i : ans)
	cout << i << " ";
	cout << "\n";
}

int main() {
    FAST;
    ll t=1;
    pre();
    cin>>t;
    while(t--) solve();	
    return 0;
}

