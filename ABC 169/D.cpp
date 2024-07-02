#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n;
	cin >> n;
	ll op=0;
	for(ll i=2;i*i<=n;i++){
		ll f = 0;
		while(n%i == 0){
			n/=i;
			f++;
		}
		ll cnt = 0,itr=0;
		while(cnt<=f){
			++itr;
			cnt += itr;
		}
		op += max(0ll,(itr-1));
	}
	op += n>1;
	cout << op;
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

