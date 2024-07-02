#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	string s;
	ll m,n;
	cin >> s;
	cin >> m;
	n = sz(s);
	vector<ll> br(m+1,0),v,cnt(26,0);
	for(ll i=0;i<n;i++)
	cnt[s[i]-'a']++;
	for(ll i=1;i<=m;i++)
	cin >> br[i];
	vector<char> news(m+1,'0');
	char c = 'z';
	while(c>='a'){
		ll cc=0;
		v.clear();
		for(ll i=1;i<=m;i++){
			if(br[i] == 0) ++cc;
		}
		if(cnt[c-'a'] < cc){
			c--;
			continue;
		}
		for(ll i=1;i<=m;i++){
			if(br[i] == 0){
				news[i] = c;
				v.pb(i);
			}
		}
		for(ll i=1;i<=m;i++){
			for(ll j=0;j<sz(v);j++)
			if(br[i] > 0)
			br[i] -= abs(v[j] - i);
			else
			br[i] = -1;
		}
		--c;
	}
	for(ll i=1;i<=m;i++)
	cout << news[i];
	cout << "\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

