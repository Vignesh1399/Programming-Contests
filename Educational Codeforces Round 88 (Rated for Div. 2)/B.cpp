#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,m ,x,y,ans=0;
	bool one=0,two=0;
	cin >> n >> m >> x >> y;
	vector<vector<char>> ar(n+1,vector<char>(m+1,'0'));
	if(2*x<=y)
	one = 1;
	else
	two = 1;
	for(ll i=1;i<=n;i++){
		ll c = 0;
		for(ll j=1;j<=m;j++){
			cin >> ar[i][j];
			if(ar[i][j] == '.')
			c++;
			else if(c>0){
				if(one)
				ans += c*x;
				else
				ans += (c/2)*y + (c%2)*x;
				c=0;
			}
		}
		if(c>0){
			if(one)
				ans += c*x;
			else
				ans += (c/2)*y + (c%2)*x;
			c=0;
		}
	}
	cout<<ans;
	cout<<"\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

