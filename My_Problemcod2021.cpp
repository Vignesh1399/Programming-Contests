#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define F first 
#define S second 
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,m;
	cin >> n >> m;
	if(n>(1<<m)){
		cout << "NO\n";
		return ;
	}
	cout << "YES\n";
	vector<ll> ar[m+1];
	for(ll i=0;i<n;i++){
		for(ll j=0;j<m;j++){
			if(i&(1<<j))
				ar[j].pb(i+1);
		}
	}
	for(ll i=0;i<m;i++){
		cout << sz(ar[i]) << " ";
		for(auto j : ar[i])
		cout << j << " ";
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

