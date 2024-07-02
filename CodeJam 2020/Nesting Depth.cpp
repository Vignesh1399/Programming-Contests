#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;
ll c = 1;

void solve(){
	ll n, prev = 0, bal = 0;
	string s,ans = "";
	cin >> s;
	for(ll i=0;s[i];i++){
		ll cur = s[i] - '0';
		bal += cur - prev;
		if(cur == prev)
		ans += s[i];
		else{
			if(cur>prev){
				for(ll j=1;j<=cur-prev;j++)
				ans += "(";
			}
			else{
				for(ll j=1;j<=prev-cur;j++)
				ans += ")";
			}
			ans += s[i];
			prev = cur;
		}
	}
	while(bal>0){
		ans += ")";
		bal--;
	}
	cout<<"Case #"<<c++<<": "<<ans<<"\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

