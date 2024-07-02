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
	ll n;
	cin >> n;
	ll fac = 2;
	while(n%fac != 0){
		fac++;
	}
	vector<vector<ll>> ar(n+1,vector<ll>(n+1,0));
	for(ll sti=1,stj=1;sti<=n && stj<=n;sti+=fac,stj+=fac){
		for(ll i=0;i<fac;i++){
			for(ll j=0;j<fac;j++){
				ll pi = sti+i;
				ll pj = stj+j;
				ar[pi][pj] = 1;
			}
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++)
		cout << ar[i][j] << " ";
		cout << "\n";
	}
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

