#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n;
	cin >> n;
	ll tw=0,th=0;
	while(n%2==0){
		n/=2;
		tw++;
		//cout << 2 << " " << n << " \n";
	}
	while(n%3==0){
		n/=3;
		th++;
		//cout << 3 << " " << n << " \n";
	}
	if(n!=1){
		cout << -1 << "\n";
		return ;
	}
	if(tw==th)
	cout << tw ;
	else if(tw<th){
		ll ans = tw + 2*(((th-tw)));
		cout << ans;
	}
	else
	cout << -1;
	cout << "\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

