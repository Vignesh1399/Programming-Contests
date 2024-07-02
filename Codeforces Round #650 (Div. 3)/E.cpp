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
	vector<ll> cnt(26,0);
	for(ll i=0;s[i];i++)
	cnt[s[i] - 'a']++;
	ll ans = 0;
	for(ll i=1;i<=k;i++){
		if(k%i != 0 ) continue;
		//cout << i << " ";
		for(ll j=1;j<=n;j++){
			ll curlen=0;
			for(ll c=0;c<26;c++){
				curlen += cnt[c]/(j);
			}
			if(curlen>=i)
			//cout << i << ' ' << j << "\n";
			ans = max(ans,i*j);
		}
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

