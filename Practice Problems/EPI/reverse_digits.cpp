#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define F first 
#define S second 
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

ll reverse(ll x) {
    ll rev = 0;
    ll absx = abs(x);
    while(absx){
        rev = (rev * 10) + (absx%10);
        absx/=10;
    }
    if (x >= 0)
        return rev;
    return -rev;
}

void solve() {
	cout << reverse(-567) << "\n";
	cout << reverse(567) << "\n";
}

int main() {
    FAST;
    ll t = 1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

