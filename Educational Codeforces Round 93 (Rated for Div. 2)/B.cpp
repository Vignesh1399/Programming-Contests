#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	string s;
	cin >> s;
	s += "0";
	vector<ll> ar;
	ll cnt=0;
	for(ll i=0;s[i];i++){
		if(s[i] == '1')
		cnt++;
		if(s[i] == '0'){
			ar.pb(cnt);
			cnt=0;
		}
	}
	sort(ar.begin(),ar.end(),greater<ll>());
	ll total=0,a=0;
	for(ll i=0;i<sz(ar);i++)
	total += ar[i];
	for(ll i=0;i<sz(ar);i+=2){
		a += ar[i];
	}
	ll ans = max(total-a,a);
	cout << ans << "\n";  
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

