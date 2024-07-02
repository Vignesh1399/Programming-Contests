#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define F first 
#define S second 
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void order_array(vector<ll> &ar) {
    int even = 0, odd = sz(ar)-1;
    while(even < odd) {
        if(ar[even]%2 == 0)
            even++;
        if(ar[odd]%2)
            odd--;
        if((ar[even]%2 == 1) && (ar[odd]%2 == 0))
            swap(ar[even++], ar[odd--]);
    }
}


void solve() {
    vector<ll> ar = {0,1,24,3,1,0,9};
	order_array(ar);
	for(int i=0;i<sz(ar);i++)
	    cout << ar[i] << " ";
}

int main() {
    FAST;
    ll t = 1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

