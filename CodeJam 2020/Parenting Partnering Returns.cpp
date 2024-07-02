#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;
ll c = 1;

struct Test 
{ 
   ll x, y, z; 
}; 

bool comp(struct Test a, struct Test b){
	return a.x<=b.x;
}

void solve(){
	ll n,a,b,np=0;
	cin >> n;
	char ans[n];
	vector<ll> time(1500,0), nact(1500,0);
	vector<Test> act(n+1,{-1,-1,0});
	for(ll i=1;i<=n;i++){
		cin >> a >> b;
		act[i] = {a,b,i};
		time[a]++;
		time[b]--;
	}
	sort(act.begin()+1,act.end(),comp);
	for(ll i=0;i<=1440;i++){
		if(!i)
		nact[i] = time[i];
		else
		nact[i] = nact[i-1] + time[i];
		if(nact[i]>2)
		np = 1; 
	}
	if(np)
	cout<<"Case #"<<c++<<": "<<"IMPOSSIBLE"<<"\n";
	else{
		char ch = 'J';
		for(ll i=1;i<=n;i++){
			if(act[i].x>=act[i-1].y){
				ans[act[i].z - 1] = ch;
			}
			else{
				ch = ((ch == 'J')? 'C':'J');
				ans[act[i].z -1] = ch;
			}
		}
		cout<<"Case #"<<c++<<": ";
		for(ll i=0;i<n;i++)
		cout<<ans[i];
		cout<<"\n";
	}
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

