#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void dfs(ll i, ll j, ll &cnt, vector<vector<char>> &ar, vector<vector<bool>> &v){
	v[i][j] = 1;
	cnt++;
	if(j-1>=1 && !v[i][j-1] && ar[i][j-1] == '1')
	dfs(i,j-1,cnt,ar,v);
	if(i-1>=1 && !v[i-1][j] && ar[i-1][j] == '1')
	dfs(i-1,j,cnt,ar,v);
}

void solve(){
	ll n;
	ll ones=0;
	cin >> n;
	vector<vector<char>> ar(n+1,vector<char>(n+1,'a'));
	vector<vector<bool>> v(n+1,vector<bool>(n+1,0));
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			cin >> ar[i][j];
			ones += (ar[i][j]=='1');
		}
	}
	ll cnt=0;
	for(ll j=n;j>=1;j--){
		if(ar[n][j] == '1' && !v[n][j])
		dfs(n,j,cnt,ar,v);
	}
	for(ll i=n;i>=1;i--){
		if(ar[i][n] == '1' && !v[i][n])
		dfs(i,n,cnt,ar,v);
	}
	if(cnt==ones)
	cout<<"YES";
	else
	cout<<"NO";
	cout<<"\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

