#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define F first 
#define S second 
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

// Tabs

void solve() {
	ll n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	vector<ll> stars;
	ll ans = 0, last = n + 2 * k;
	for(ll i = 0; i < n; i++) {
	    if(s[i] == '*'){
	        ans++;
	        s[i] = 'x';
	        stars.pb(i);
	        break;
	    }
	}
	for(ll i = n - 1; i >= 0; i--) {
	    if(s[i] == '*') {
	        ans++;
	        s[i] = 'x';
	        last = i;
	        break;
	    }
	}
	for(ll i = 0; i < n; i++) {
	    if(s[i] == '*')
	        stars.pb(i);
	}
	auto it = stars.begin();
	while(it != stars.end()) {
	    auto nit = upper_bound(it, stars.end(), *it + k);
	    nit--;
	    if(nit == it) break;
	    else if(last - *it <= k) {
	        break;
	    }
	    else {
	        ans++;
	        it = nit;
	    }
	}
	cout << ans << "\n";
}

int main() {
    FAST;
    ll t = 1;
    cin >> t;
    while(t--) solve();	
    return 0;
}

