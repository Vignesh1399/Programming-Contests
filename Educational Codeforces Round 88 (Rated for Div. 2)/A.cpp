#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,m,k;
	cin >> n >> m >> k;
	if(m<=n/k)
	cout<<m;
	else{
		m -= n/k;
		ll x = m/(k-1) + (m%(k-1)>0);
		cout<<n/k-x;
	}
	cout<<"\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

