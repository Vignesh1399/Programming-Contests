#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,k,m;
    vector<pair<ll,string>> ans,final_ans;
    cin>>n>>m>>k;
    ans.pb({m-1,"R"});
    ans.pb({m-1,"L"});
    for(ll i=2;i<=n;i++){
        ans.pb({1,"D"});
        ans.pb({m-1,"R"});
        ans.pb({m-1,"UDL"});
    }
    ans.pb({n-1,"U"});
    if(k>(4*n*m - 2*n - 2*m))
    cout<<"NO";
    else{
        for(auto x:ans){
            if(k>=sz(x.second)*x.first){
                k-=x.first*sz(x.second);
                if(x.first)final_ans.pb(x);
            }
            else{
                ll len=sz(x.second);
                if(k/len) final_ans.pb({k/len,x.second});
                if(k%len) final_ans.pb({1,x.second.substr(0,k%len)});
                k=0;
            }
        }
        cout<<"YES\n";
        cout<<sz(final_ans)<<"\n";
        for(auto x:final_ans){
            cout<<x.first<<" "<<x.second<<"\n";
        }
    }
}

int main() {
    FAST;
    ll t=1,n,a,b,m;
    //cin>>t;
    while(t--){
    	solve();	
    }
    return 0;
}

