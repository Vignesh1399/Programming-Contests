#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

ll dp[20][2520][50];
ll idx[2521];
ll ftlcm = 2520;
string to_String(ll num) {
	string s = "";
	ll dig=19;
	for (int i = 0; i < dig; i++) {
		s += ((num % 10) + '0');
		num /= 10;
	}
	reverse(s.begin(), s.end());
	return s;
}
ll LCM(ll x, ll y){
	return x/__gcd(x,y) * y;
}
void pre(){
	memset(dp,-1,sizeof(dp));
	ll k=0;
	for(ll i=1;i<=ftlcm;i++){
		if(ftlcm%i == 0)
		idx[i] = k++;
	}
}
ll solve(ll pos, ll rem, ll lm, bool flag, string &s){
	if(pos == 19)
	return (lm>0 && rem%lm == 0);
	if(flag && dp[pos][rem][idx[lm]] != -1)
	return dp[pos][rem][idx[lm]];
	ll limit=9;
	if(!flag)
	limit = s[pos] - '0';
	ll res = 0;
	for(ll d=0;d<=limit;d++){
		ll lm1;
		bool f1=0;
		if(d==0)
		lm1 = lm;
		else
		lm1 = LCM(lm,d);
		if(d != limit || flag)
		f1 = 1;
		ll rem1 = ((rem%ftlcm * 10%ftlcm)%ftlcm + d%ftlcm)%ftlcm;
		res += solve(pos+1,rem1,lm1,f1,s);
	}
	if(flag)
	dp[pos][rem][idx[lm]] = res;
	return res;
}
void solve(){
	ll left,right;
	cin >> left >> right;
	string l,r;
	r = to_String(right);
	l = to_String(left-1);
	//cout << r << "\n" <<sz(r) << "\n";
	ll ansr = solve(0,0,1,0,r);
	ll ansl = solve(0,0,1,0,l);
	cout << ansr - ansl<< "\n";
	//O ((19 * 2520 * 50 + 19 ))*10
}

int main() {
    FAST;
    ll t=1;
    pre();
    cin>>t;
    while(t--) solve();	
    return 0;
}

