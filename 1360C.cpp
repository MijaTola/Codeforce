#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);
        vector<int> a,b;
        for (int i = 0; i < n ;++i) {
            int x;
            scanf("%d", &x);
            if(x & 1) b.push_back(x);
            else a.push_back(x);
        }

        if(a.size() % 2 == 0 and  b.size() % 2 == 0) {
            puts("YES");
            continue;
        }
        
        bool flag = 0;
        for (int x: a) 
            for (int y: b) 
                flag |= (abs(x - y) == 1 and a.size() % 2 == b.size() % 2);

        puts(flag ? "YES" : "NO");
    }
        
    return 0;
}

