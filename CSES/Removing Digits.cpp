#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define F first 
#define S second 
#define FAST ios_base::sync_with_stdio(0); cin.tie(0);
#define sz(a) signed(a.size())
using namespace std;

vector<ll> dp(1e6+1,-1);

ll find_min_steps(ll n) {
  if(n == 0)
    return 0;
  if(n <= 9)
    return 1;
  else if(dp[n] != -1)
    return dp[n];
  string num = to_string(n);
  ll ans = 1e9;
  for(ll i = 0; num[i]; i++) {
    if(num[i] != '0')
      ans = min(ans, find_min_steps(n - (num[i] - '0')) + 1);
  }
  dp[n] = ans;
  return ans;
}

void solve() {
  ll n;
  cin >> n;
  ll ans = find_min_steps(n);
  cout << ans << "\n";
}

int main() {
  FAST;
  ll t = 1;
  // cin >> t;
  while(t--) solve();	
  return 0;
}

