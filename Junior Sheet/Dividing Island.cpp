#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;


void solve(){
	ll a,b,c,d,n;
	cin >> a >> b >> c >> d >> n;
	vector<ll> x(n);
	vector<char> m(26);
	for(ll i=0;i<26;i++){
		char ch = 'a' + i;
		m[i] = ch;
		//cout << m[i] <<" ";
	}
	for(auto &i : x)
	cin >> i;
	vector<vector<char>> field(max(b,d)+1,vector<char>(a+c+1,'.'));
	for(ll i=1;i<=b;i++){
		for(ll j=1;j<=a;j++)
		field[i][j] = '#';
	}
	for(ll i=1;i<=d;i++){
		for(ll j=a+1;j<=a+c;j++)
		field[i][j] = '#';
	}
	ll idx = 0,dec=0;
	ll leftc = (b>c) ? a : c;
	for(ll i=min(b,d)+1;i<=max(b,d);i++){
		for(ll j=1;j<=leftc;j++){
			if(field[i][a+c-j+1] == '#' && idx<sz(x)){
				field[i][a+c-j+1] = m[idx];
				x[idx]--;
				dec++;
				if(!x[idx]){
					idx++;
					dec=0;
				}
			}
			if(field[i][j] == '#' && idx<sz(x)){
				field[i][j] = m[idx];
				x[idx]--;
				dec++;
				if(!x[idx]){
					dec=0;
					idx++;
				}
			}
		}
	}
	for(ll i=1;i<=min(b,d);i++){
		for(ll j=1;j<=a+c;j++){
			if(i%2 && field[i][j] == '.'){
				if(dec)
				idx++; 
				continue;
			}
			if(i%2 && field[i][j] == '#' && idx<sz(x)){
				field[i][j] = m[idx];
				x[idx]--;
				dec++;
				if(!x[idx]){
					dec=0;
					idx++;
				}
			}
			if(!(i%2) && field[i][a+c-j+1] == '.'){
				if(dec)
				idx++;
				continue;
			}
			if(!(i%2) && field[i][a+c-j+1] == '#' && idx<sz(x)){
				field[i][a+c-j+1] = m[idx];
				x[idx]--;
				dec++;
				if(!x[idx]){
					idx++;
					dec=0;
				}
			}
		}
	}
	
	bool  flag=0;
	for(ll i=0;i<n;i++){
		if(x[i]) flag=1;
	}
	/*
	if(flag){
		cout << "NO";
		return ;
	}
	*/
	for(ll i=1;i<=max(b,d);i++){
		for(ll j=1;j<=a+c;j++)
		cout<<field[i][j];
		cout << "\n";
	}
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

