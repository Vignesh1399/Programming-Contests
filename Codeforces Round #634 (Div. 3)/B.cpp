#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,a,b;
	string s = "";
	cin >> n >>a >>b;
	for(ll i=1;i<=a-b;i++)
	s+="a";
	ll k=0;
	for(ll i=a-b+1;i<=a;i++)
	s.pb('a' + k++);
	for(ll i=a+1;i<=n;i++)
	s.pb(s[i-a-1]);
	cout<<s;
	cout<<"\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}
 