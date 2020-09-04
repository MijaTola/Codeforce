#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
    cin >> n;
    int o = 0, d = 0;
    for (int i = 0; i < n; ++i) {
        int x,y;
        cin >> x >> y;
        if(x > 0) o++;
        else d++;
    }
    if(o <= 1 or d <= 1) return puts("YES"),0;
    puts("NO");
    return 0;
}

