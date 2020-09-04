#include <bits/stdc++.h>

using namespace std;

int n;
int v[200010];
int p[200010];
int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", v + i);
        p[v[i]] = i;
    }
    int pos = 0;

    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        int curp = p[x];
        if(curp < pos) {
            cout << 0 << " ";
        } else {
            cout << curp - pos + 1<< " ";
            pos = curp + 1;
        }
    }
    return 0;
}

