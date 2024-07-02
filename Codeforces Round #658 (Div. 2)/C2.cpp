#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n;
	cin >> n;
	string a,b;
	cin >> a >> b;
	vector<ll> f;
	// Convert a to all zeros
	for(ll i=1;i<n;i++){
		if(a[i] != a[i-1])
		f.pb(i);
	}
	if(a[n-1] != '0')
	f.pb(n);
	for(ll i=0;i<n;i++)
	a[i] = '0';
	// Convert b to all zeros
	// Observe that the reverse part does not matter
	// so we can consider the process as flip only
	ll flip = 0;
	for(ll i=n-1;i>=0;i--){
		if(flip%2)
		a[i] = ((a[i] == '0')?'1':'0');
		if(a[i] != b[i]){
			f.pb(i+1);
			flip++;
		}
	}
	cout << sz(f) << "\n";
	for(auto i : f)
	cout << i << " ";
	cout << "\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

