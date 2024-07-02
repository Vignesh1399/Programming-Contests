#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

bool ok(string &temp, string s[], ll n, ll m){
	ll diff=0;
	for(ll i=0;i<n;i++){
		diff=0;
		for(ll j=0;j<m;j++){
			if(s[i][j] != temp[j])
			++diff;
		}
		if(diff>1)
		return 0;
	}
	return 1;
}

void solve(){
	ll n,m;
	string ans = "";
	cin >> n >> m;
	string s[11];
	for(ll i=0;i<n;i++)
	cin >> s[i];
	for(ll i=0;i<m;i++){
		for(char ch = 'a';ch<='z';ch++){
			string temp = s[0];
			temp[i] = ch;
			if(ok(temp,s,n,m))
			ans = temp;
		}
	}
	if(!sz(ans))
	cout<<-1;
	else
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

