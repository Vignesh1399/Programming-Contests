#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll a,b;
	cin >> a >> b;
	ll diff = abs(a-b);
	if(a==b)
	cout <<0;
	else if(a>b){
		cout<<1 + (diff%2);
	}
	else
	cout << 1 + !(diff%2);
	cout << "\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

