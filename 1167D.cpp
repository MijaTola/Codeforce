#include <bits/stdc++.h>

using namespace std;

int n;
string s;
stack<pair<int,int> > st;
vector<pair<int,pair<int,int> > > v;
int ans[200010];
int main() {
    cin >> n >> s;
    
    int cur = 1;
    int mx = 1;
    for (int i = 0; i < n; ++i) {
        if(s[i] == '(') st.push({i, cur++});
        else {
            v.push_back({st.top().second, {st.top().first, i}});
            st.pop();
            cur--;
        }
        mx = max(cur, mx);
    }
    
    for (int i = 0; i < (int)v.size(); ++i) {
        int val = v[i].first;
        int x = v[i].second.first;
        int y = v[i].second.second;
        if(val & 1) ans[x] = ans[y] = 1;
    }

    for (int i = 0; i < n; ++i) 
        cout << ans[i];
    cout << "\n";
    return 0;
}

