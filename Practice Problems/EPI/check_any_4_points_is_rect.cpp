#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define F first 
#define S second 
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

struct Point {
    int x; 
    int y;
};
struct Rectangle {
    Point p1;
    Point p2;
    Point p3;
    Point p4;
};

int dist(const Point& p1, const Point& p2) {
    return (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y);
}

vector<int> getTriangle(const Point& p1, const Point& p2, const Point& p3) {
    int a = dist(p1, p2);
    int b = dist(p2, p3);
    int c = dist(p1, p3);
    vector<int> s = {a,b,c};
    sort(s.begin(), s.end());
    return s;
}

bool check_rect(const Rectangle& r) {
    vector<int> s = getTriangle(r.p1, r.p2, r.p3);
    vector<int> q = getTriangle(r.p2, r.p3, r.p4);
    if((s[2] == (s[0] + s[1])) && (q[2] == (q[1]+q[0])) && (s[2] == q[2]))
        return 1;
    return 0;
    
}
void solve() {
	struct Rectangle r = {{0,0}, {1,1}, {0,1}, {1,0}};
	cout<<check_rect(r);
}

int main() {
    FAST;
    ll t = 1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

