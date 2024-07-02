#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	string s;
	cin >> s;
	ll ansc = 0;
	ll n = sz(s);
	s = s[0] +s;
	vector<ll> ar(10,0);
	vector<vector<ll>> pr(n+1,vector<ll>(10,0));
	for(ll i=0;i<=9;i++){
		for(ll j=1;s[j];j++){
			pr[j][i] = pr[j-1][i] + (s[j]-'0' == i);
		}
	}
	ll pidx = 0;
	for(ll i=0;i<=9;i++){
		pidx = 0;
		for(ll j=1;s[j];j++){
			if(s[j] -'0' == i){
				for(ll d=0;d<=9;d++){
					if(pr[j][d]-pr[pidx][d]>0)
					ar[d]++;
				}
				pidx = j;
			}
		}
		for(ll j=0;j<=9;j++){
			if(i==j)
			ansc = max(ar[i],ansc);
			else
			ansc = max(2*ar[j],ansc);
			ar[j] = 0;
		}
	}
	cout << n-ansc << "\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

