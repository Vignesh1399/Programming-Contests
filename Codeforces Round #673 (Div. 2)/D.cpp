#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n;
	cin >> n;
	vector<ll> ar(n);
	ll sum = 0;
	for(auto &i : ar)
	{
		cin >> i;	
		sum += i;
	}
	if(sum % n != 0){
		cout << -1 << "\n";
		return ;
	}
	cout << 3*n - 3 << "\n";
	for(ll i=1;i<n;i++){
		ll k = i+1;
		ll x = (k-ar[i]%k)%k;
		cout << 1  << " " << k << " " << x << "\n";
		cout << k << " " << 1 << " " << (ar[i]+x)/k << "\n";
	}
	for(ll i=1;i<n;i++){
		ll k = i+1;
		cout << 1 << " " << k  << " "<< sum/n << "\n";
	}
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

