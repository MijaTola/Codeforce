#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int> > p1;
long long b[2010];
int x,y,x2,y2,n;
long long dist(pair<long long, long long> a, pair<long long, long long> b) {
    return ((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}
bool cmp (pair<int,int> a, pair<int,int> b) {
    return dist(a, {x,y}) < dist(b, {x,y});
}

int main(){
    cin >> n >> x >> y >> x2 >> y2;
    
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        int a,b;
        cin >> a >> b;
        p1.push_back({a,b});
        ans = max(ans, dist({a,b}, {x2,y2}));
    }
    
    sort(p1.begin(), p1.end(), cmp);
    long long mx = 0;
    for (int i = n - 1; i >= 0; i--) {
        mx = max(mx, dist(p1[i], {x2,y2}));
        b[i] = mx;
    }
    for (int i = 0; i < n; ++i) 
        ans = min(ans, dist(p1[i],{x,y}) + b[i + 1]);
    
    cout << ans << "\n";
	return 0;
}
