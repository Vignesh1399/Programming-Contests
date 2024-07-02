#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n;
	cin >> n;
	vector<ll> ar(n);
	bool flag = 0;
	map<ll,ll> m;
	for(auto &i : ar){
		cin >> i;
	}
	if(n>=62){
		cout << "NO\n";
		return ;
	}
	for(ll i=0;i<n;i++){
		for(ll j=i;j<n;j++){
			ll temp = ar[i];
			for(ll k=i;k<=j;k++)
			temp = temp | ar[k];
			if(!m[temp]) m[temp]++;
			else flag = 1;
		}
	}
	cout << ((flag == 1) ? "NO":"YES") <<"\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

