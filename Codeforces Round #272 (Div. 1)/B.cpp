#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,k;
	cin >> n >> k;
	vector<ll> add = {1,2,3,5};
	cout << (6*(n-1) + add[3]) * k << "\n";
	for(ll i=0;i<n;i++){
		for(ll j=0;j<4;j++)
		cout << (6*i + add[j]) * k << " ";
		cout << "\n";
	}
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

