#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

void dfs(int s,vector<int> g[], vector<int> &v, vector<int> &ans){
    v[s]=1;
    ans.pb(s);
    int sz=g[s].size();
    for(int i=0;i<sz;i++){
        if(!v[g[s][i]])
            dfs(g[s][i],g,v,ans);
    }
}
void solve(){
    string s;
    int ar[30][30]={0};
    for(ll i=0;i<30;i++){
        for(ll j=0;j<30;j++)
        ar[i][j]=0;
    }
    vector<int> g[30];
    vector<int> v(40,0),ans;
    cin>>s; 
    
    for(int i=1;s[i];i++){
        int x=s[i]-'a',y=s[i-1]-'a';
        if(!ar[x][y]){
            g[x].pb(y);
        }
        if(!ar[y][x]){
            g[y].pb(x);
        }
        ar[s[i]-'a'][s[i-1]-'a']=1;
        ar[s[i-1]-'a'][s[i]-'a']=1;
    }
    int sr=-1;
    for(int i=0;i<26;i++){
        int gs=g[i].size();
        if(gs==1){
            sr=i;
        }
        if(gs>2){
            sr=-1;
            break;
        }
    }
    
    if(sr==-1)
    cout<<"NO\n";
    
    else{
        dfs(sr,g,v,ans);
        cout<<"YES\n";
        int sz=ans.size();
        for(int i=0;i<sz;i++){
            cout<<(char)(ans[i]+'a');
        }
        for(int i=0;i<26;i++){
            if(!v[i])
            cout<<(char)(i+'a');
        }
        cout<<"\n";
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1,n,a,b,m;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

