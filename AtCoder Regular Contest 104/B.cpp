#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n;
	string s;
	cin >> n >> s;
	vector<ll> a(n+1,0),t(n+1,0),c(n+1,0),g(n+1,0);
	vector<char> ar = {'A','T','C','G'};
	for(ll i=0;i<n;i++){
		if(i==0){
			a[i] += (s[i] == ar[0]);
			t[i] += (s[i] == ar[1]);
			c[i] += (s[i] == ar[2]);
			g[i] += (s[i] == ar[3]);
		}
		else{
			a[i] = a[i-1] + (s[i] == ar[0]);
			t[i] += t[i-1] + (s[i] == ar[1]);
			c[i] += c[i-1] + (s[i] == ar[2]);
			g[i] += g[i-1] + (s[i] == ar[3]);
		}
	}
	ll ans = 0;
	for(ll len=2;len<=n;len++){
		for(ll i=0;i<n;i++){
			if(len%2) continue;
			if(i+len-1>=n) continue;
			ll av = a[i+len-1];
			ll gv = g[i+len-1];
			ll cv = c[i+len-1];
			ll tv = t[i+len-1];
			if(i-1>=0){
				av -= a[i-1];
				tv -= t[i-1];
				cv -= c[i-1];
				gv -= g[i-1];
			}
			if((av == tv) && (cv == gv))
			ans++;
		}
	}
	cout << ans;
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

