#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define F first 
#define S second 
#define FAST ios_base::sync_with_stdio(0); cin.tie(0);
#define sz(a) signed(a.size())
using namespace std;

ll add(ll a, ll b) {
    if (b == 0)
        return a;
    return add(a^b, (a&b) << 1);
}
void solve() {
    ll a, b;
	cin >> a >> b;
	ll p = 0;
	ll ans = 0;
	while(b) {
	    if (b & 1)
	     ans = add(ans, a << p);
	    p = add(p, 1);
	    b >>= 1;
	}
	cout << ans;
}

int main() {
    FAST;
    ll t = 1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

