#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void dfs(ll i, ll j,ll &vcnt, map<pair<ll,ll>,bool> &v, ll limit, vector<vector<char>> &ar, ll n, ll m){
	if(limit == vcnt)
	return ;
	vcnt++;
	v[{i,j}] = 1;
	if(i-1>=1 && (ar[i-1][j] == '.') && !v[{i-1,j}]) dfs(i-1,j,vcnt,v,limit,ar,n,m);
	if(i+1<=n && (ar[i+1][j] == '.') && !v[{i+1,j}]) dfs(i+1,j,vcnt,v,limit,ar,n,m);
	if(j-1>=1 && (ar[i][j-1] == '.') && !v[{i,j-1}]) dfs(i,j-1,vcnt,v,limit,ar,n,m);
	if(j+1<=m && (ar[i][j+1] == '.') && !v[{i,j+1}]) dfs(i,j+1,vcnt,v,limit,ar,n,m);
	
}

void solve(){
	ll n,m,k,s1,s2,s=0,vcnt=0;
	cin >> n >> m >> k;
	vector<vector<char>> ar(n+1,vector<char>(m+1,'0'));
	map<pair<ll,ll>,bool> v;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
		cin >> ar[i][j];
			if(ar[i][j] == '.'){
				s1 = i;
				s2 = j;
				s++;
			}
		}
	}
	dfs(s1,s2,vcnt,v,s-k,ar,n,m);
	
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			if(!v[{i,j}] && ar[i][j] == '.')
			ar[i][j] = 'X';
			cout<<ar[i][j];
		}
		cout<<"\n";
	}
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

