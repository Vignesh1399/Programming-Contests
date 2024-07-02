#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;
typedef pair<ll, ll> pi; 

void solve(){
	ll n,x,days=0;
	cin >> n >> x;
	vector<ll> ar(n);
	for (ll i=0;i<n;i++){
		cin >> ar[i];
	}
	sort(ar.begin(),ar.end());
	ll idx = upper_bound(ar.begin(),ar.end(),x/2) - ar.begin();
	for(ll i=idx;i<n;i++){
		//cout << ar[i] << " " << x << "\n";
		if(x>=ar[i]){
			x  = ar[i];
		}
		else
			--i;
	 	x *= 2;
	 	++days;
	}
	days += idx;
	cout << days << "\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

