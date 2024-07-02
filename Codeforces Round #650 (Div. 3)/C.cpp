#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,k;
	cin >> n >> k;
	string s;
	cin >> s;
	vector<ll> cnt;
	ll val = 0;
	for(ll i=0;s[i];i++){
		if(s[i] == '0') val++;
		else{
			if(val == i)
			val = max(0ll,val-k);
			else
			val = max(0ll,val-2*k);
			cnt.pb(val);
			val = 0;
		}
	}
	if(val == n)
	cnt.pb(val);
	else if(val!=0)
	cnt.pb(max(val-k,0ll));
	ll ans = 0;
	for(ll i=0;i<sz(cnt);i++){
		//cout << cnt[i] << " ";
		for(ll j=1;j<=cnt[i];j+=k+1)
		ans++;
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

