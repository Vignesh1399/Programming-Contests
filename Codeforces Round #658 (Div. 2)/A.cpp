#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,m,a;
	cin >> n >> m;
	map<ll,ll> m1,m2;
	for(ll i=0;i<n;i++){
		cin >> a;
		m1[a]++;
	}
	for(ll i=0;i<m;i++){
		cin >> a;
		m2[a]++;
	}
	for(auto i : m1){
		if(i.second && m2[i.first]){
			cout << "YES\n";
			cout << 1 << " " << i.first << "\n";
			return ;
		}
	}
	cout << "NO\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

