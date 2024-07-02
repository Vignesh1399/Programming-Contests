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
	for(ll i=0;s[i];i++){
		m[s[i]-'a']++;
	}
	bool flag = 0;
	for(ll i=0;i<26;i++){
		if(m[i]%2)
		flag = 1;
	}
	cout << ((flag) ? "NO" : "YES") << "\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

