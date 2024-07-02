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
	vector<ll> ar(n);
	for(auto &i : ar)
	cin >> i;
	ll ans = 0;
	for(ll i=1;i<n;i++)
	ans += abs(ar[i]-ar[i-1]);
	ll diff = max(abs(ar[1]-ar[0]),abs(ar[n-1]-ar[n-2]));
	for(ll i=1;i<n-1;i++){
		diff = max(diff,abs(ar[i]-ar[i-1])+abs(ar[i+1]-ar[i])-abs(ar[i+1]-ar[i-1]));
	}
	ans -= diff;
	cout << ans << "\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

