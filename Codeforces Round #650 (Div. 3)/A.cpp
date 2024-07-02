#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	string s;
	cin >> s;
	cout << s[0]<<s[1];
	for(ll i=3;i<sz(s);i+=2)
	cout << s[i] ;
	cout << "\n";
	
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

