#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;
ll  n,m;
map<ll,ll> divs;
vector<ll> ar(16,0);

void lcm_all(ll num, ll index, ll len){
	if(index == m+1 || num > n){
		if(len%2)
		divs[len] += n/num;
		else 
		divs[len] -= n/num;
		//cout<<n<<" "<<len<<" "<<num<<"\n";
		return ;
	}
	lcm_all((num), index+1,len);
	lcm_all((num*ar[index]/(__gcd(num,ar[index]))), index+1,len+1);
}

void solve(){
	while(cin >> n){
		divs.clear();
		cin >> m;
		for(ll i=1;i<=m;i++){
			cin >> ar[i];
		}
		// num, index, length
		lcm_all(1ll,1ll,0);
		ll ans=0;
		for(ll i=1;i<=m;i++)
		ans += divs[i];
		cout<<n - ans<<"\n";
	}
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

