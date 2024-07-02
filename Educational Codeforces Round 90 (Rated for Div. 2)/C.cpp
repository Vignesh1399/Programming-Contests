#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	string s;
	cin >> s;
	map<ll,ll> m;
	ll val = 0,ans=0;
	for(ll i=0;s[i];i++){
		if(s[i] == '-')
		val--;
		else
		val++;
		if(val<0 && !m[val])
		m[val] = i+1;
	}
	for(auto i:m){
		ans += i.second;
	}
	ans += sz(s);
	cout << ans << "\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

