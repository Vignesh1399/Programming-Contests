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
	if(n == 1 || n == 2 || n==4)
	cout << -1;
	else{
		if(n%3 == 0)
		cout << n/3 << " " << 0 << " " << 0;
		if(n%3 == 1)
		cout << (n-7)/3 << " " << 0 << " " << 1;
		if(n%3 == 2)
		cout << (n-5)/3 << " " << 1 << " " << 0;
	}
	cout << "\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

