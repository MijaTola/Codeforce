#include <bits/stdc++.h>

using namespace std;

bool vis[200010];
int main() {

    int t;
    cin >> t;

    while(t--) {

        int n;
        string s;
        cin >> n >> s;

        for (int i = 0; i < n; ++i)
            vis[i] = 0;
        deque<int> q; 
        char last = s[0];
        int cnt = 0;
        int ini = 0;
        priority_queue<pair<int,int> > pq;

        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if(last == c) cnt++;
            else {
                pq.push({cnt, -ini});
                cnt = 1;
                ini = i;
            }
            last = c;
            q.push_back(c);
        }

        pq.push({cnt, -ini});
        int ans = 0;

        int p = 0;

        vector<int> unos, ceros;

        while(!q.empty() and !pq.empty() and pq.top().first > 1) {
            int cnt = 0;
            char last = '.';
            while(!q.empty()) {
                char x = q.front();
                if(x == last or last == '.') {
                    q.pop_front();
                } else break;
                if(!vis[p]) {
                    cnt++;
                    last = x;
                }
                vis[p] = 1;
                p++;
            }

            if(cnt == 1) {
                while(!pq.empty()) {
                    auto p = pq.top();
                    pq.pop();
                    if(!vis[-p.second]) {
                        vis[-p.second] = 1;
                        p.first--;
                        p.second--;
                        if(p.first) pq.push(p);
                        break;
                    }
                    p.first--;
                    p.second--;
                    if(p.first) pq.push(p);
                }
            }

            if(cnt) ans++;
        }

        cnt = 0;
        while(!pq.empty()) {
            auto pos = pq.top();
            pq.pop();
            if(-pos.second >= p) cnt++;
        }
        cout << ans + (cnt + 1) / 2 << "\n";
    }
    return 0;
}
