#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n;
	cin >> n;
	string s = "";
	ll len = n,cr=0;
	while(len){
		if(len>=4){
			s += '8';
			len -= 4;
		}
		else{
			s += '8';
			len -= len%4;
		}
		cr++;
	}
	for(ll i=cr;i<n;i++)
	s += '9';
	reverse(s.begin(),s.end());
	cout << s << "\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

