#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

bool equal(ll a, ll b, ll c, ll d){
	ll lcd = (b*d)/__gcd(b,d);
	ll n1 = lcd/b, n2 = lcd/d;
	a *= n1;
	c *= n2;
	return a==c;
}
bool compare(ll a, ll b, ll c, ll d){
	ll lcd = (b*d)/__gcd(b,d);
	ll n1 = lcd/b, n2 = lcd/d;
	a *= n1;
	c *= n2;
	return a<c;
}

void solve(){
	ll h,c,t,ans=1e10;
	cin >> h >> c >> t;
	ll lb = 0, ub = 1e7;
	ll num = 1e10;
	ll den = 1;
	ll x;
	while(lb <= ub){
		ll mid = (lb+ub)/2;
		ll cn = (mid+1)*h + mid*c, dn = 2*mid + 1;
		bool pos = (cn-dn*t)>0;
		cn = abs(cn - dn*t);
		x = __gcd(cn,dn);
		cn/=x;
		dn/=x;
		bool val = compare(cn,dn,num,den);
		if(val && pos){
			num = cn;
			den = dn;
			lb = mid + 1;
		}
		else if(pos)
			lb = mid + 1;
		else 
			ub = mid - 1;
	}
	ans = 2*ub + 1;
	//cout << ans << " ";
	if(compare(abs(h+c-2*t),2,num,den)){
		ans = 2ll;
		num = abs(h+c-2*t);
		den = 2;
		x = __gcd(num,den);
		num /= x;
		den /= x;
	}
	else if(equal(abs(h+c-2*t),2,num,den))
	ans = min(ans,2ll);
	ll mid = ub+1;
	ll cn = (mid+1)*h + mid*c, dn = 2*mid + 1;
	cn = abs(cn - dn*t);
	x = __gcd(cn,dn);
	cn/=x;
	dn/=x;
	if(compare(cn,dn,num,den))
	ans  = 2*mid + 1;
	cout << ans;
	cout << "\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

