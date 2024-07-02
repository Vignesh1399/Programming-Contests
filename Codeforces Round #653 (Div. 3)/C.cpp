#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,ans=0;
	string s;
	cin >> n >> s;
	stack<ll> m;
	for(ll i=0;s[i];i++){
		if(s[i]=='(')
		m.push(s[i]);
		else if(!m.empty() && s[i]==')')
		m.pop();
		else
		ans++;
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

