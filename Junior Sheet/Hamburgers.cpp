#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

map<char,ll> m;
map<ll,char> lvl2;


bool possible(ll cur, vector<ll> &b, vector<ll> &p, ll r){
	for(ll i=1;i<=3;i++){
		r -= max(0ll,cur*m[lvl2[i]]*p[i] - b[i]*p[i]);
	}
	if(r<0)
	return false;
	return true;
}
void solve(){
	string s;
	ll r;
	vector<ll> n(4,0),p(4,0);
	cin >> s;
	for(ll i=0;s[i];i++)
	m[s[i]]++;
	for(ll i=1;i<=3;i++)
	cin >> n[i];
	for(ll i=1;i<=3;i++)
	cin >> p[i];
	cin >> r;
	ll lb = 0, ub = 1e13;
	while(lb <= ub){
		ll mid = (lb + ub)/2;
		if(possible(mid,n,p,r))
		lb = mid + 1;
		else
		ub = mid - 1;
		//cout<<mid<<"\n";
	}
	cout << ub;
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

