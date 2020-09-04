#include <bits/stdc++.h>

using namespace std;

int n,k;
priority_queue<pair<int,int> > q;
int main(){

    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        q.push({x,i});
    }
    
    int ans = 0;
    vector<int> v;
    while(!q.empty() and k) {
        v.push_back(q.top().second);
        ans += q.top().first;
        q.pop();
        k--;
    }
    cout << ans << "\n";
    sort(v.begin(),v.end());
    v.pop_back();
    v.push_back(n - 1);
    int pos = 0;
    for (int i = 0; i < (int)v.size(); ++i) {
        cout << v[i] - pos + 1<< " ";
        pos = v[i] + 1;
    }
    cout << "\n";
    return 0;
}

