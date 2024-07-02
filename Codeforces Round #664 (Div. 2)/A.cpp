#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll r,g,b,w;
	cin >> r >> g >> b >> w;
	ll m = min({r,g,b});
	ll ans1 = 3,ans2 = 3;
	ll ans  = (r%2 + g%2 + b%2 + w%2); 
	if(m>=1){
		r--;g--;b--;w++;
		ans1  = (r%2 + g%2 + b%2 + w%2);
		r++;g++;b++;w--;
	}
	if(m>=2){
		r-=2;g-=2;b-=2;w+=2;
		ans2  = (r%2 + g%2 + b%2 + w%2);
		r+=2;g+=2;b+=2;w-=2;
	}
	if(ans1>1 && ans2>1 && ans>1)
	cout << "No\n";
	else
	cout << "Yes\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

