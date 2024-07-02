#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll t,n;
	string s;
	//cin >> t;
	cin >> n >> s;
	ll odd = 0, even  =0;
	for(ll i=0;s[i];i++){
		if(i%2 && (s[i]-'0')%2 == 0)
		even++;
		if((i%2 == 0)&& (s[i]-'0')%2)
		odd++;
	}
	if(n%2){
		if(odd>0)
		cout << 1 ;
		else
		cout << 2;	
	}
	else{
		if(even>0)
		cout << 2;
		else
		cout << 1;
	}
	cout << "\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

