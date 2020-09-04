#include <bits/stdc++.h>

using namespace std;

int n,m;
int l[200010];
int s[200010];
map<int,int> mp;
priority_queue<pair<pair<int,int>, int > > q;
int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x; 
        cin >> x;
        mp[x]++;
    }

    cin >> m;
    for (int i = 0; i < m; ++i)
        cin >> l[i];

    for (int i = 0; i < m; ++i)
        cin >> s[i];
    
    for (int i = 0; i < m; ++i) 
        q.push(make_pair(make_pair(mp[l[i]], mp[s[i]]), i));

    cout << q.top().second + 1 << "\n";
    
    return 0;
}

