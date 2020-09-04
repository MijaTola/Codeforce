#include <bits/stdc++.h>

using namespace std;

int n;
set<int> s;
int v[100010];
int val[100010];
int c[100010];

int main() {

    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
        scanf("%d", v + i);

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        
        c[val[v[i]]]--;
        if(c[val[v[i]]] == 0) s.erase(val[v[i]]);
        val[v[i]]++;
        c[val[v[i]]]++;
        s.insert(val[v[i]]);

        if(s.size() == 2) {
            int a = *s.begin();
            int b = *s.rbegin();
            if(c[b] > c[a]) swap(a,b);
            else if(c[b] == c[a]) {
                if(b > a) swap(a,b);
            }
            if((b - 1 == 0 or a == b - 1) and c[b] == 1) ans = i + 1;
            if((a - 1 == b or a - 1 == 0) and c[a] == 1) ans = i + 1;
        }

        if(s.size() == 1) {
            if(*s.begin() == 1 or c[*s.begin()] == 1) ans = i + 1;
        }
    }

    printf("%d\n", ans);
    return 0;
}

