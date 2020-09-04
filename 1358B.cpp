#include <bits/stdc++.h>

using namespace std;

int v[100010];

int main() {

    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d", v + i);

        sort(v, v + n);

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if(i + 1 >= v[i]) ans = i + 1;
        }
        printf("%d\n", ans + 1);
    }
    return 0;
}

