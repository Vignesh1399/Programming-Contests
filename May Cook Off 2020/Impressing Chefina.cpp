#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,m;
	cin >> n >> m;
	vector<vector<ll>> ar(n+1,vector<ll>(m+1,0));
	map<ll,ll> freq;
	vector<pair<ll,ll>> odd;
	vector<pair<ll,ll>> even;
	ll eit,oit;
	eit = oit = 0;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			cin >> ar[i][j];
			freq[ar[i][j]]++;
		}
	}
	for(auto i : freq){
		if(i.second%2){
		odd.pb({i.first,1});
		if(i.second - 1 > 0)
		even.pb({i.first,i.second-1});
		}
		else
		even.pb({i.first,i.second});
	}
	if(m%2==0 && sz(odd)>0){
	cout << -1 << "\n";
	return ;
	}
	else if(m%2==1 && sz(odd)> n){
	cout << -1 << "\n";
	return ;
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m/2;j++){
			ar[i][j] = even[eit].first;
			ar[i][m-j+1] = even[eit].first;
			even[eit].second -= 2;
			if(even[eit].second == 0)
			eit++;
		}
	}
	if(m%2 == 0);
	else{
		for(ll i=1;i<=n;i++){
			if(eit != sz(even)){
			ar[i][m/2 + 1] = even[eit].first;
			even[eit].second--;
			if(even[eit].second == 0)
			eit++;
			}
			else{
				ar[i][m/2 + 1] = odd[oit].first;
				odd[oit].second--;
				if(odd[oit].second==0)
				oit++;
			}
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++)
		cout << ar[i][j] <<" ";
		cout << "\n";
	}
	
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

