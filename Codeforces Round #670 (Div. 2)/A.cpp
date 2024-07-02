#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n;
	cin >> n;
	vector<ll> ar(n);
	map<ll,ll> m;
	for(auto &i : ar){
		cin >> i;
		m[i]++;
	}
	ll x = *max_element(ar.begin(),ar.end());
	ll val = 0;
	for(ll i=0;i<=100;i++){
		if(m[i] == 0){
			if(val != 0)
			cout << i + val << "\n";
			else
			cout << 2*(i) << "\n";
			return ;
		}
		else if(m[i] == 1){
			val = i+1;
		}
	}
	cout << 2ll*(x+1) << "\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

