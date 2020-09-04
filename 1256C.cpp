#include <bits/stdc++.h>

using namespace std;

int n,m,d;
vector<int> v,b;
int ans[1010];

int main() {
    scanf("%d %d %d", &n, &m, &d);
    
    v.push_back(1);
    b.push_back(1);
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        v.push_back(x);
        b.push_back(x);
    }

    v.push_back(1);
    b.push_back(1);
    for (int i = v.size() - 2; i >= 0; --i) 
        v[i] += v[i + 1];
    
    auto build = [] (int a, int b, int id) {
        for (int i = a; i <= b; ++i) {
            ans[i] = id;
        }
    };

    int pos = 0;
    for (int i = 0; i < (int)v.size() - 1; ++i) {
        bool flag = 0;
        int dis = v[i + 1];
        for (int j = pos + 1; j <= pos + d; ++j) {
            if(j + dis - 1 == n + 1) {
                pos = j + b[i + 1] - 1;
                build(j, j + b[i + 1] - 1, i + 1);
                flag = 1;
                break;
            }
        }

        if(!flag) {
            build(pos + d, pos + d + b[i + 1] - 1, i + 1);
            pos = (pos + d) + b[i + 1] - 1;
        }
    }

    if(pos != n + 1) return puts("NO"), 0;

    puts("YES");
    for (int i = 1; i <= n; ++i) 
        printf("%d ", ans[i]);
    puts("");
    return 0;
}

