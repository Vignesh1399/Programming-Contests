#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;
ll cs = 0;

void explore(ll i, ll j, vector<vector<char>> &ar, vector<vector<bool>> &vis, multiset<char> &s, ll n, ll m){
	vis[i][j]=1;
	s.insert(ar[i][j]);

	if(j+1<=m && !vis[i][j+1] && ar[i][j+1] == ar[i][j]){
	if(i == n || vis[i+1][j+1])
	explore(i,j+1,ar,vis,s,n,m);
	}
	if(j-1>=1 && !vis[i][j-1] && ar[i][j-1] == ar[i][j]){
	if(i == n || vis[i+1][j-1])
	explore(i,j-1,ar,vis,s,n,m);
	}
	if(i-1>=1 && !vis[i-1][j] && ar[i-1][j] == ar[i][j])
	explore(i-1,j,ar,vis,s,n,m);
}

bool try1(map<char,ll> &m,vector<char> &ans,set<char> &un, vector<vector<char>> &ar, vector<vector<bool>> &vis, multiset<char> &s, ll r, ll c){
	bool flag=0;
	for(ll i = r;i>=1;i--)
	for(ll j=1;j<=c;j++){
		if( (i==r && !vis[i][j]) || (i <r && !vis[i][j] && vis[i+1][j] && un.find(ar[i][j]) == un.end()))
		explore(i,j,ar,vis,s,r,c);
		if(un.find(ar[i][j]) == un.end())
		ans.pb(ar[i][j]);
		un.insert(ar[i][j]);
	}
	for(char c = 'A';c <= 'Z';c++){
		if(s.count(c)!=m[c]){
		flag=1;
		//cout<<c<<" ";
		}
	}
	return flag;
}

bool try2(map<char,ll> &m,vector<char> &ans,set<char> &un, vector<vector<char>> &ar, vector<vector<bool>> &vis, multiset<char> &s, ll r, ll c){
	bool flag=0;
	for(ll i = r;i>=1;i--)
	for(ll j=c;j>=1;j--){
		if( (i==r && !vis[i][j]) || (i <r && !vis[i][j] && vis[i+1][j] && un.find(ar[i][j]) == un.end()))
		explore(i,j,ar,vis,s,r,c);
		if(un.find(ar[i][j]) == un.end())
		ans.pb(ar[i][j]);
		un.insert(ar[i][j]);
	}
	for(char c = 'A';c <= 'Z';c++){
		if(s.count(c)!=m[c]){
		flag=1;
		//cout<<c<<" ";
		}
	}
	return flag;
}

void solve(){
	ll n,r,c;
	cin >> r >> c;
	vector<vector<char>> ar(r+1,vector<char>(c+1,'0'));
	vector<vector<bool>> vis(r+1,vector<bool>(c+1,0));
	set<char> un;
	vector<char> ans;
	multiset<char> s;
	map<char,ll> m;
	for(ll i=1;i<=r;i++){
		for(ll j=1;j<=c;j++){
			cin >> ar[i][j];
			m[ar[i][j]]++;
		}
	}
	bool flag=0;
	/*
	for(ll i = r;i>=1;i--)
	for(ll j=1;j<=c;j++){
		if( (i==r && !vis[i][j]) || (i <r && !vis[i][j] && vis[i+1][j] && un.find(ar[i][j]) == un.end()))
		explore(i,j,ar,vis,s,r,c);
		if(un.find(ar[i][j]) == un.end())
		ans.pb(ar[i][j]);
		un.insert(ar[i][j]);
	}
	for(char c = 'A';c <= 'Z';c++){
		if(s.count(c)!=m[c]){
		flag=1;
		cout<<c<<" ";
		}
	}
	*/
	flag = try1(m,ans,un, ar,vis,s,r,c);
	for(auto &elem : vis) fill(elem.begin(), elem.end(), 0);
	un.clear();
	s.clear();
	if(flag){
	ans.clear();
	flag = try2(m,ans,un, ar,vis,s,r,c);
	}
	if(flag)
	cout<<"Case #"<<++cs<<": "<<-1<<"\n";
	else{
		cout<<"Case #"<<++cs<<": ";
		for(auto i:ans)
		cout<<i;
		cout<<"\n";
	}
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

