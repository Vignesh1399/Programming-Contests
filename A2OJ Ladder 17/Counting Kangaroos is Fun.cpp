#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n;
	cin >> n;
	vector<ll> s(n,0);
	for(ll i=0;i<n;i++)
	cin >> s[i];
	sort(s.begin(),s.end());
	ll p1 = n/2 - (n+1)%2;
	ll p2 = n-1,total=n;
	while(p1>=0 && p2>n/2-((n+1)%2)){
		if(s[p2]>=2*s[p1]){
			p2--;
			p1--;
			total--;
		}
		else p1--;
	}
	cout<<total;
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

