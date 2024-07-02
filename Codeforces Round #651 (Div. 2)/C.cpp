#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	string ff = "FastestFinger";
	string a = "Ashishgup";
	ll n;
	cin >> n;
	if(n==1){
		cout << ff << "\n";
		return ;
	}
	if(n==2){
		cout << a << "\n";
		return ;
	}
	if(n%2){
		cout << a << "\n";
		return ;
	}
	ll odd=0,eve=0;
	for(ll i=2;i*i<=n;i++){
		while(n%i == 0){
			if(i%2)
			odd++;
			else
			eve++;
			n/=i;
		}
	}
	odd += n>1;
	if(odd == 0){
		cout << ff << "\n";
		return ;
	}
	if(eve==1 && odd==1){
		cout <<ff << "\n";
		return ;
	}
	else
	cout << a << "\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

