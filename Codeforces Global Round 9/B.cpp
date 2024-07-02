#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,m;
	cin >> n >> m;
	bool f = 0;
	vector<vector<ll>> ar(n+1,vector<ll>(m+1,0)),ans(n+1,vector<ll>(m+1,0));
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			if(i==1 && j==1)
			ans[i][j] = 2;
			else if(i==n && j==1)
			ans[i][j] = 2;
			else if(i==1 && j==m)
			ans[i][j] = 2;
			else if(i==n && j==m)
			ans[i][j] = 2;
			else if(i==1 || j==1 || i==n || j==m)
			ans[i][j] = 3;
			else
			ans[i][j] = 4;
			cin >> ar[i][j];
			if(ar[i][j]>ans[i][j])
			f = 1;
		}
	}
	if(f){
		cout << "NO\n";
		return ;
	}
	cout << "YES\n";
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++)
		cout << ans[i][j] << " ";
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

