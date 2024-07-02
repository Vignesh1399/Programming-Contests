
// Problem: A - Large Digits
// Contest: AtCoder - AtCoder Beginner Contest 187
// URL: https://atcoder.jp/contests/abc187/tasks/abc187_a
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
	string a,b;
	cin >> a >> b;
	ll sa = 0, sb = 0;
	for(ll i=0;a[i];i++){
		sa += (a[i]-'0');
		sb += (b[i] - '0');
	}
	if(sa>=sb)
	cout << sa ;
	else
	cout << sb;
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

