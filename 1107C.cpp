#include <bits/stdc++.h>

using namespace std;

int n,k;
int v[200010];
char s[200010];
vector<pair<long long,int> > a[27];

int main() {
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; ++i)
        scanf("%d", v + i);

    scanf("%s", s);

    for (int i = 0; i < n; ++i) 
        a[s[i] - 'a'].push_back({v[i],i});

    long long ans = 0;
    for (int i = 0; i < 27; ++i) {
        if(a[i].empty()) continue;
        int last = a[i][0].second - 1;
        int c = 0;
        priority_queue<int> q;
        for (int j = 0; j < (int)a[i].size(); ++j) {
            int pos = a[i][j].second;
            if(last + 1 == pos) {
                q.push(a[i][j].first);
                last = pos;
            } else {
                int c = 0;
                while(!q.empty() and c < k) {
                    ans += q.top();
                    q.pop();
                    c++;
                }
                while(!q.empty()) q.pop();
                last = pos;
                q.push(a[i][j].first);
            }
        }
        c = 0;
        while(!q.empty() and c < k) {
            ans += q.top();
            q.pop();
            c++;
        }
    }
    cout << ans << "\n";
    return 0;
}

