#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define F first 
#define S second 
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n;
	cin >> n;
	string s[n];
	for(ll i=0;i<n;i++)
	cin >> s[i];
	vector<ll> maxrow(10,-1),minrow(10,n+1),maxcol(10,-1),mincol(10,n+1);
	for(ll i=0;i<n;i++){
		for(ll j=0;j<n;j++){
			maxrow[s[i][j]-'0'] = max(maxrow[s[i][j]-'0'],i);
			minrow[s[i][j]-'0'] = min(minrow[s[i][j]-'0'],i);
			maxcol[s[i][j]-'0'] = max(maxcol[s[i][j]-'0'],j);
			mincol[s[i][j]-'0'] = min(mincol[s[i][j]-'0'],j);
		}
	}
	vector<ll> ans(10,0);
	for(ll i=0;i<n;i++){
		for(ll j=0;j<n;j++){
			ll b = max(j,n-j-1);
			ll h1 = maxrow[s[i][j] - '0'];
			ll h2 = minrow[s[i][j] - '0'];
			if(h1 != -1)
			ans[s[i][j] - '0'] = max(ans[s[i][j]-'0'],b*abs(i-h1));
			if(h2 != n+1)
			ans[s[i][j] - '0'] = max(ans[s[i][j]-'0'],b*abs(i-h2));
			b = max(i,n-i-1);
			h1 = maxcol[s[i][j]-'0'];
			h2 = mincol[s[i][j]-'0'];
			if(h1 != -1)
			ans[s[i][j] - '0'] = max(ans[s[i][j]-'0'],b*abs(j-h1));
			if(h2 != n+1)
			ans[s[i][j] - '0'] = max(ans[s[i][j]-'0'],b*abs(j-h2));
		}
	}
	for(auto i : ans)
	cout << i << " ";
	cout << "\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

