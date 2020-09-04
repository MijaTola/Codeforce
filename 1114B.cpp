#include <bits/stdc++.h>

using namespace std;

int n,k,m;
int v[200010];

int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < n; ++i)
        cin >> v[i];
    
    priority_queue<pair<int,int> > q;
    for (int i = 0; i < n; ++i) 
        q.push({v[i],i});
    
    vector<int> ans;
    long long sum = 0;
    for (int i = 0; i < m * k; ++i) {
        ans.push_back(q.top().second);    
        sum += q.top().first;
        q.pop();
    }
    sort(ans.begin(),ans.end());
    cout << sum << "\n";
    int c = 1;
    for (int i = 0; i < (int)ans.size() - 1; ++i) {
        if(c == m) {
            cout << ans[i] + 1 << " ";
            c = 1;
        } else c++;
    }
    cout << "\n";
    return 0;
}

