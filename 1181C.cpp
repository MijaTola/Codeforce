#include <bits/stdc++.h>

using namespace std;

char c[1010][1010];
int can[1010][1010];
string ver[1010][1010];
int a[27];
int n,m;

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> c[i][j];


    for (int j = 0; j < m; ++j) {
        char last = c[0][j];
        int cur = 1;
        vector<pair<int,char> > v;
        for (int i = 1; i < n; ++i) {
            if(c[i][j] == last) cur++;
            else {
                v.push_back({cur, last});
                cur = 1;
                last = c[i][j];
            }
        }
        v.push_back({cur, last});
        int s = 0;
        for (int i = 0; i < (int)v.size() - 2; ++i) {
            int a = v[i].first;
            int b = v[i + 1].first;
            int cc = v[i + 2].first;
            set<int> st;
            st.insert(v[i].second);
            st.insert(v[i + 1].second);
            st.insert(v[i + 2].second);
            s += a;
            if(a >= b and cc >= b and st.size() == 3) {
                can[s + b + b - 1][j] = b;
                string y = "";
                y += v[i].second;
                y += v[i + 1].second;
                y += v[i + 2].second;
                ver[s + b + b - 1][j] = y;
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        int cur = 0;
        int last = 0;
        string xlast = "";
        for (int j = 0; j < m; ++j) {
            if(can[i][j] == last and xlast == ver[i][j]) cur++;
            else {
                if(last) ans += (cur * (cur - 1)) / 2 + cur;
                cur = 1;
                last = can[i][j];
                xlast = ver[i][j];
            }
        }
        if(last) ans += (cur * (cur - 1)) / 2 + cur;
    }
    cout << ans << "\n";
    return 0;
}

