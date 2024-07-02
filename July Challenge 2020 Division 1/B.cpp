#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,ans=0,small = 1e10;
	cin >> n;
	deque<ll> ea,eb;
	map<ll,ll> ma,mt;
	for(ll i=0;i<n;i++){
		ll a;
		cin >> a;
		ma[a]++;
		mt[a]++;
	}
	for(ll i=0;i<n;i++){
		ll a;
		cin >> a;
		mt[a]++;
	}
	for(auto i : mt){
		if(i.second%2){
			cout << -1 << "\n";
			return ;
		}
		ll diff = (ma[i.first] - i.second/2);
		for(ll x=0;x<diff;x++){
			ea.pb(i.first);
		}
		diff = -diff;
		for(ll x=0;x<diff;x++){
			eb.pb(i.first);
		}
		small = min(small,i.first);
	}
	while(sz(ea)){
		//cout << ea.front() << " " << eb.front() << "\n";
		if(ea.front()<eb.front()){
			ans += min(ea.front(),2*small);
			ea.pop_front();
			eb.pop_back();
		}
		else{
			ans += min(eb.front(),2*small);
			eb.pop_front();
			ea.pop_back();
		}
	}
	cout << ans << "\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

