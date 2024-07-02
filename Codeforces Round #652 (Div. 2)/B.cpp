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
	ll l1 = n+1,r0=0;
	for(ll i=0;s[i];i++){
		if(s[i] == '1')
		l1 = min(l1,i);
		if(s[i] == '0')
		r0 = max(r0,i);
	}
	string ans = "";
	if(l1>=r0){
		cout << s << "\n";
		return ;
	}
	for(ll i=0;i<l1;i++){
		ans += s[i];
	}
	ans += '0';
	for(ll i=r0+1;i<n;i++){
		ans += s[i];
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

