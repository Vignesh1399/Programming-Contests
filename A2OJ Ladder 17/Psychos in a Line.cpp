#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define sz(a) signed(a.size())
using namespace std;

/*
Consider elements at index j ......... i
i is killed by j if a[j] > a[i]
i.e the first greater  (FGE) to the left 
also because j is the FGE to the left, all elements btw a[j+1] .... a[i-1] are < a[j]
by definition of FGE to the left a[j+1] ... a[i-1] < a[i]
Think of stack always as maching a correct set of paranthesis :: matching element with FGE to left
Golden Rule 
--- Insert into stack only when you find a match on the stack ---
--- Otherwise pop from the stack ----
because a[j+1] > a[j+2] > ... a[i-1], all of them will be on the stack
hence we can update max of ti
*/

void solve(){
	ll n;
	cin >> n;
	stack<ll> s;
	s.push(0);
	vector<ll> id(n+1,1e6),time(n+1,0);
	for(ll i=1;i<=n;i++)
	cin >> id[i];
	for(ll i=1;i<=n;i++){
		while(id[s.top()] < id[i]){
			time[i] = max(time[i],time[s.top()]);
			s.pop();
		}
		time[i]++;
		if(s.top() == 0)
		time[i] = 0;
		s.push(i);
	}
	ll ans = *max_element(time.begin() + 1, time.end());
	cout<<ans;
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}
