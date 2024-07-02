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
	vector<pair<ll,ll>> com;
	ll cnt = 1;
	for(ll i=1;s[i];i++){
		if(s[i] == s[i-1])
			cnt++;
		else{
			com.pb({s[i-1] - '0',cnt});
			cnt = 1;
		}
	}
	com.pb({s[sz(s)-1]-'0',cnt});
	ll b = 0,a = 0;
	for(ll i=0;i<sz(com);i++){
		if(com[i].second == 2)
		a++;
		else if(com[i].second>2)
		b++;
	}
	if(b>0 || a>1)
	cout << sz(com) + 2 ;
	else
	cout << sz(com) + a ;
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

