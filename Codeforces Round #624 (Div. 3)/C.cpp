#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,m,p;
	cin >> n >> m;
	map<char,ll> ch;
	string s;
	vector<ll> pr(n+2,0);
	cin >> s;
	for(ll i=1;i<=m;i++){
		cin >> p;
		pr[1]++;
		pr[p+1]--;
	}
	for(ll i=1;i<=n;i++){
		pr[i]+= pr[i-1];
		ch[s[i-1]]+= pr[i]+1;
	}
	for(char c = 'a';c<='z';c++)
	cout << ch[c] << " ";
	cout << "\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

