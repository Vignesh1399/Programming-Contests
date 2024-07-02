#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,m;
	cin >> n >> m;
	ll x1 = n*(m/2) + (m%2)*(n/2 + n%2);
	swap(n,m);
	ll ans = min(n*(m/2) + (m%2)*(n/2 + n%2),x1);
	cout<<ans<<"\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

