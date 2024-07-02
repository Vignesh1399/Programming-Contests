
// Problem: C - 1-SAT
// Contest: AtCoder - AtCoder Beginner Contest 187
// URL: https://atcoder.jp/contests/abc187/tasks/abc187_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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
	map<string, ll > m;
	string ans = "satisfiable";
	for(ll i=0;i<n;i++){
		cin >> s[i];
		if(s[i][0] != '!')
		m[s[i]]++;
	}
	for(ll i=0;i<n;i++){
		if(s[i][0] == '!'){
			string x = s[i].substr(1,s[i].length()-1);
			if(m[x]){
				ans = x;
			}
		}
	}
	cout << ans ;
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

