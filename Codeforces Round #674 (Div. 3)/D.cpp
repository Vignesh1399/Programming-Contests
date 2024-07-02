#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n;
	cin >> n;
	vector<ll> ar(n+1);
	for(ll i=1;i<=n;i++){
		cin >> ar[i];
	}
	set<ll> s;
	ll sum = 0,ans = 0;
	for(ll i=1;i<=n;i++){
		sum += ar[i];
		if(s.count(sum) || sum == 0){
			++ans;
			s.clear();
			sum = ar[i];
		}
		s.insert(sum);
	}
	cout << ans << "\n";
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

