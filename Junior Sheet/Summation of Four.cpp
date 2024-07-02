#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;
vector<bool> primes(1e7+1,1);

/*
Goldbach's Conjecture: 
Every even Number >2 can be expressed as a sum of two primes
*/

void preprocess(){
	primes[0] = primes[1] = 0;
	for(ll i=2;i*i<=1e7;i++){
		for(ll j=i*i;j<=1e7;j+=i)
		primes[j] = 0;
	}
}
void solve(){
	preprocess();
	ll n;
	while(cin >> n){
		if(n<8)
		cout<<"Impossible.\n";
		else{
			if(n%2)
			cout<<"2 3 ";
			else
			cout<<"2 2 ";
			n -= 4 + n%2;
			for(ll i=1;i<=n;i++){
				if(primes[i] && primes[n-i]){
					cout<<i<<" "<<n-i<<"\n";
					break;
				}
			}
		}
	}
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

