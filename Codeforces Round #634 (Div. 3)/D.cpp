#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n;
	string temp="1234567891";
	string s[9];
	for(ll i=0;i<9;i++)
	cin >> s[i];
	for(ll i=0,j=0;i<3 && j<9;i++,j+=3){
		for(ll k=0;k<9;k++){
			if(temp[k]!=s[i][j]){
			s[i][j] = temp[k];
			break;
			}
		}
	}
	for(ll i=3,j=1;i<6 && j<9;i++,j+=3){
		for(ll k=0;k<9;k++){
			if(temp[k]!=s[i][j]){
			s[i][j] = temp[k];
			break;
			}
		}
	}
	for(ll i=6,j=2;i<9 && j<9;i++,j+=3){
		for(ll k=0;k<9;k++){
			if(temp[k]!=s[i][j]){
			s[i][j] = temp[k];
			break;
			}
		}
	}
	for(ll i=0;i<9;i++)
	cout<<s[i]<<"\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}
 