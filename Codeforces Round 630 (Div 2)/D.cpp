#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define sz(a) signed(a.size())
using namespace std;
/*
Idea:
A constructive algorithm where optimal answer is k ,
Non optimal ans is 0.
This DP approach of bob fails as It takes the best value based on currently
seen elements, not worrying about elements to come after current element
Supposing at a cell i curent optimal value is 1010 (in binary)
Both right and bottom cell have 0101 then final ans is 0.
Taking a non optimal vaue at cell i would give us a bettter answer.
Therefore contruct a matrix where optimal ans is k, but DP ans is 0
*/

void solve(){
	ll k;
	cin >> k;
	
	vector<vector<ll>> ans = {
		{(1<<17) + k,k,0},
		{(1<<17),(1<<17) + k,k}
	};
	cout<<2<<" "<<3<<"\n";
	for(ll i=0;i<2;i++){
		for(ll j=0;j<3;j++)
			cout<<ans[i][j]<<" ";
		cout<<"\n";
	}
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

