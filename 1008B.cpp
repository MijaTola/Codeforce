#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int,int> > v;
int dp[100010][2];
bool f(int pos, bool flag) {
    if(pos == n) return 1;
    if(dp[pos][flag] != -1) return dp[pos][flag];
    bool ans = 0;
    if(!flag) {
        int cur = v[pos].first;
        int c1 = v[pos + 1].first;
        int c2 = v[pos + 1].second;
        if(cur >= c1) ans |= f(pos + 1, 0);
        if(cur >= c2) ans |= f(pos + 1, 1);
    }else {
        int cur = v[pos].second;
        int c1 = v[pos + 1].first;
        int c2 = v[pos + 1].second;
        if(cur >= c1) ans |= f(pos + 1, 0);
        if(cur >= c2) ans |= f(pos + 1, 1);
    }
    return dp[pos][flag] = ans;
}
int main(){

    memset(dp,-1,sizeof dp);
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int x,y; cin >> x >> y;
        v.push_back(make_pair(x,y));
    }

    if(f(0,0) or f(0,1))  cout << "YES";
    else cout << "NO";
    return 0;
}

