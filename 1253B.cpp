#include <bits/stdc++.h>

using namespace std;

int n;
int v[100010];

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) 
        scanf("%d", v + i);

    vector<int> ans;

    set<int> s, vis;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if(v[i] > 0) {
            if(vis.count(v[i])) return puts("-1"),0;
            cnt++;
            vis.insert(v[i]);
            s.insert(v[i]);
        } else {
            if(!s.count(-v[i])) return puts("-1"),0;
            cnt++;
            s.erase(-v[i]);
        }
    
        if(cnt and s.size() == 0) {
            vis.clear();
            ans.push_back(cnt);
            cnt = 0;
        }
    }
    
    if(s.size()) return puts("-1"), 0;
    printf("%d\n", (int)ans.size());
    
    for (int x: ans)
        printf("%d ", x);
    puts("");
    return 0;
}

