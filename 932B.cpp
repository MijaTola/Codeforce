#include <bits/stdc++.h>

using namespace std;

vector<int> v[10];

int f(int u) {
    int ans = 1;
    while(u > 0) {
        if(u % 10) ans *= (u % 10);
        u /= 10;
    }
    return ans;
}

int g(int u) {
    if(u < 10) return u;
    return g(f(u));
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    for (int i = 1; i <= 1000100; ++i){
        int cur = g(i);
        if(cur <= 9)v[cur].push_back(i);
    }
    
    int q; cin >> q;
    while(q--) {
        int l,r,cur;
        cin >> l >> r >> cur;
       int left = lower_bound(v[cur].begin(),v[cur].end(),l) - v[cur].begin();
       int right = lower_bound(v[cur].begin(),v[cur].end(),r) - v[cur].begin();
       if(v[cur][right] > r) right--;

       cout << right - (left - 1)<< "\n";

    }
    return 0;
}

