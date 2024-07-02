#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	string s;
	cin >> s;
	vector<ll> ar(1e5,9);
	for(auto i : ar)
	cout<<to_string(i)<<" ";
	cout<<s<<" ";
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

