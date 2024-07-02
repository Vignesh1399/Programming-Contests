#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	string s;
	cin >> s;
	ll cnt=0;
	for(ll i=0;s[i];i++){
		if(s[i]=='1')
		cnt++;
	}
	ll val = min(cnt,sz(s) - cnt);
	if(val%2)
	cout << "DA";
	else
	cout << "NET";
	cout << "\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

