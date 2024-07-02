#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;
ll tc = 0;
void solve(){
	ll n;
	cin >> n;
	string s;
	cin >> s;
	vector<ll> ar(2,0);
	for(ll i=0;s[i];i++)
		ar[s[i]-'A']++;
	cout << "Case #" << ++tc << ": ";
	if((ar[0] == n/2) || (ar[1] == n/2))
	cout <<"Y\n";
	else
	cout << "N\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

