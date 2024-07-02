#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;


ll search(ll n){
	ll lb = 1,ub = 1e6;
	while(lb <= ub){
		ll mid = (lb+ub)/2;
		ll val = mid*mid*mid;
		if(val == n)
		return mid;
		else if(val>n)
		ub = mid - 1;
		else
		lb = mid + 1;
	}
	return 0;
}
void solve(){
	ll a,b;
	cin >> a >> b;
	ll cr = search(a*b);
	if(cr*cr*cr != a*b)
	cout << "No";
	else if(a%cr + b%cr == 0)
	cout << "Yes";
	else
	cout <<"No";
	cout << "\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

