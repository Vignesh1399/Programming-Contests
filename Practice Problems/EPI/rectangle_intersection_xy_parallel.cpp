#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define F first 
#define S second 
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

struct Rectangle {
    int x;
    int y;
    int width;
    int height;
};

bool isIntersect(const Rectangle& r1, const Rectangle& r2) {
    // dimensions independent
    if ((r1.x >= r2.x+r2.width) || (r1.x + r1.width <= r2.x))
        return 0;
    if ((r1.y >= r2.y+r2.height) || (r1.y + r1.height <= r2.y))
        return 0;
    return 1;
}

Rectangle IntersectRectangle(const Rectangle& r1, const Rectangle& r2) {
    if (!isIntersect(r1, r2))
        return {0, 0, -1, -1};
    return {max(r1.x, r2.x), max(r1.y, r2.y), 
            min(r1.x+r1.width, r2.x+r2.width) - max(r1.x, r2.x),
            min(r1.y+r1.height, r2.y+r2.height) - max(r1.y, r2.y)
            };
    
}

void solve() {
	Rectangle r1 = {0, 0, 3, 4};
	Rectangle r2 = {1, 1, 1, 1};
	cout << isIntersect(r1, r2) << "\n";
	struct Rectangle intrec = IntersectRectangle(r1, r2);
	cout << intrec.x << " " << intrec.y << " " << intrec.width << " " << intrec.height;
	assert((intrec.x == 1) && (intrec.y == 1) && (intrec.height == 1) && (intrec.width == 1));
}

int main() {
    FAST;
    ll t = 1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

