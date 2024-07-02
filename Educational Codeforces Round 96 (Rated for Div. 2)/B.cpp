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
	vector<ll> ar(n);
	for(ll i=0;i<n;i++)
	cin >> ar[i];
	sort(ar.begin(),ar.end());
	ll ans = ar[n-1];
	ll cur = 0;
	for(ll i=n-2;i>=0;i--){
		if(cur == k) break;
		ans += ar[i];
		cur++;
	}
	cout << ans << "\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

