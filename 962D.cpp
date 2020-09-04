#include <bits/stdc++.h>

using namespace std;

map<long long,priority_queue<long long> > mp;
int main(){
    
    long long n; cin >> n;
    for (int i = 0; i < n; ++i) {
        long long x; cin >>  x;
        mp[x].push(-i);
    }
    
    vector<pair<long long,long long> > ans;

    for (pair<long long,priority_queue<long long> > pq: mp) {
        long long cur = pq.first;
        long long nw = 2LL * cur;
        while(pq.second.size() >= 2) {
            pq.second.pop();
            mp[nw].push(pq.second.top());
            pq.second.pop();
        }
        while(!pq.second.empty()) {
            ans.push_back({-pq.second.top(),cur});
            pq.second.pop();
        }
    }
    sort(ans.begin(),ans.end());
    cout << ans.size() << "\n";
    for (pair<long long, long long> t: ans)
        cout<<t.second << " ";
    cout << "\n";
    return 0;
}

