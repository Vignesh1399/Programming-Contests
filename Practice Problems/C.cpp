#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define F first 
#define S second 
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve() {
	ll n, k;
	cin >> n >> k;
	ll ans = 0;
	vector<ll> ar(n+1, 0);
	vector<ll> cnt(2e5+2,0);
	for(ll i=1; i<=n; i++) {
	    cin >> ar[i];
	    cnt[ar[i]]++;
	}
    ll pos = *max_element(ar.begin() + 1, ar.end());
    ll mn = *min_element(ar.begin() + 1, ar.end());
    ll sum = 0, c = 0;
    while(pos >= mn - 1) {
        if(k < sum - c * pos || (pos == (mn - 1) && cnt[pos+1] != n)) {
            ans++;
            sum = c * (pos + 1);
        }
        c += cnt[pos];
        sum += cnt[pos] * pos;
        pos--;
    }
    cout << ans ;
}

int main() {
    FAST;
    ll t = 1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

