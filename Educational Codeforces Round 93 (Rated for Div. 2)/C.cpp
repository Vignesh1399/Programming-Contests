#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;



void solve(){
	ll n;
	cin >> n;
	string s;
	cin >> s;
	map<ll,ll> m;
	vector<ll> ar(n+1,0),pr(n+1,0);
	for(ll i=0;s[i];i++){
		ar[i+1] = s[i]-'0';
		pr[i+1] = pr[i] + ar[i+1];
	}
	ll ans = 0;
	for(ll i=0;i<=n;i++){
		ans += m[pr[i]-i];
		m[pr[i]-i]++;
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

