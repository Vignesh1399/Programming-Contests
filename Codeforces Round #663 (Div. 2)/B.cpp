#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,m;
	cin >> n >> m;
	vector<vector<char>> ar(n+1,vector<char>(m+1,'0'));
	ll ans = 0;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			cin >> ar[i][j];
			if(i==n && j==m) continue;
			if(j==m && ar[i][j] == 'R') ans++;
			else if(i==n && ar[i][j] == 'D') ans++;
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

