#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define F first 
#define S second 
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

ll find_lowest_set(ll x) {
    return (x & ~(x-1));
}

ll find_lowest_unset(ll x) {
    return (x & ~(x+1)) + 1;
}

ll find_same_weight(ll x){
    ll lowest_set = find_lowest_set(x);
    ll lowest_unset = find_lowest_unset(x);
    ll diff;    
    if (lowest_set > lowest_unset){
        diff = lowest_set - lowest_set/2;
    }
    else {
        diff = lowest_unset - lowest_unset/2;
    }
    return x - diff;
}

void solve() {
    ll num;
	cin >> num;
	cout << find_same_weight(num) << "\n";
}

int main() {
    FAST;
    ll t = 1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

