#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	string s;
	ll n;
	cin >> n >> s;
	ll p1 = 0;
	vector<ll> gr;
	for(ll i=1;s[i];i++){
		if(s[i] != s[i-1]){
			gr.eb(i-p1);
			p1 = i;
		}
	}
	gr.eb(sz(s)-p1);
	ll p2 = sz(gr);
	for(ll i=0;i<sz(gr);i++){
		if(gr[i]>1){
			p2 = i;
			break;
		}
	}
	ll ans = 0;
	p1 = 0;
	while(p1<sz(gr)){
		++ans;
		if(p2<sz(gr))
		gr[p2]--;
		if(p2<sz(gr))
		++p1;
		else
		p1 += 2;
		p2 = max(p2,p1);
		while(p2<sz(gr) && gr[p2]<=1)
		p2++;
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

