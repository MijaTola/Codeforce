#include <bits/stdc++.h>

using namespace std;

pair<int,pair<int,int> > v[100010];

long long a[100010];
int main(){
    int n,k; cin >> n >> k;

    for (int i = 0; i < n; ++i) 
        cin >> v[i].first;


    for (int i = 0; i < n; ++i) {
        int x; cin >> x ;
        v[i].second.first = x;
        v[i].second.second = i;
    }
    sort(v, v + n);
    int c = 0;
    long long ans = 0;
    int cur = INT_MAX;
    priority_queue<int> q;
    for (int i = 0; i < n; ++i) {
        int coins = v[i].second.first;
        int val = v[i].first;
        a[v[i].second.second] = ans + v[i].second.first ;
        if((int)q.size() < k) {
            ans += coins;
            q.push(-coins);
        } else {
            if(q.empty()) continue;
            int cur = -q.top();
            q.pop();
            if(coins > cur) {
                ans -= cur;
                ans += coins;
                cur = coins;
            }
            q.push(-cur);
        }
    }

    for (int i = 0; i < n; ++i) 
        cout << a[i] << " ";
    cout << "\n";
    return 0;
}

