#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,k;
	cin >> n >> k;
	vector<ll> ar(n+1,0),m(n+1,0);
	for(ll i=1;i<=n;i++){
		cin >> ar[i];
		m[i] = k - (ar[i]%k);
	}
	sort(m.begin()+1,m.end());
	ll ans = 0, moves=0,consec=1;
	for(ll i=1;i<=n;i++){
		if(m[i]==k) continue;
		else if(i==1){
			ans = m[i];
			moves = ans+1;
		}
		else{
			if(m[i] == m[i-1]){
				ans = max(ans,m[i] + consec*k);
				consec++;
			}
			else{
				ans = max(ans,m[i]);
				consec = 1;
			}
		}
	}
	if(!ans)
	cout << ans << "\n";
	else
	cout <<  ans + 1 << "\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

