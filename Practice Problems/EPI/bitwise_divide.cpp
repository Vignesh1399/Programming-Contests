#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define F first 
#define S second 
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

int divide(int x, int y) {
    int exp = 32;
    ll power = (1ll << 32);
    int ans = 0;
    while(x >= y) {
        while(power * y > x) {
            power >>= 1;
            exp--;
        }
        x -= power*y;
        ans += power;
    }
    return ans;
}
void solve() {
	cout<<divide(2, 1) << "\n";
	cout<<divide(6, 7) << "\n";
}

int main() {
    FAST;
    ll t = 1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

