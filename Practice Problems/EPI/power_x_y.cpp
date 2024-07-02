#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define F first 
#define S second 
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

double power(double x, ll y) {
    double ans = 1.0;
    ll aby = abs(y);
    while(aby > 0){
        if (aby & 1)
            ans *= x;
        aby >>= 1;
        x *= x;
    }
    if (y >= 0)
        return ans;
    else
        return (1.0/ans);
}

void solve() {
	cout << power(5, 2) << "\n";
	cout << power(10, -2) << "\n";
}

int main() {
    FAST;
    ll t = 1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

