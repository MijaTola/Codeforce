#include <bits/stdc++.h>

using namespace std;

int v[100010];
int main() {

    int n;
    cin >> n;
    set<int> s;
    priority_queue<pair<int,int> > q;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        s.insert(i);
        q.push({-v[i], i});
    }

    while(q.size() > 1) {
        int val = -q.top().first;
        int pos = q.top().second;
        q.pop();
        auto it = s.lower_bound(pos);
        auto l = it, r = it;
        if(it != s.end()) r++;
        if(it != s.begin()) l--;
        
        if(*r < 0) {
            s.erase(r);
        } else if(*l < 0) {
            s.erase(l);
        } else {
            if(*r > *l){
                q.push(-(val + *r));
            } else {
            
            }
        }
    }
    return 0;
}

