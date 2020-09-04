#include <bits/stdc++.h>

using namespace std;

int n,d;
int main() {
    
    auto check = [] (auto x) -> bool {
        if(x == -1) return 0;
        int ne = d / (x + 1) + (d % (x + 1) != 0);
        return n - (x + ne) >= 0;
    };

    int t;
    cin >> t;
    while(t--) {
        cin >> n >> d;
        int a = -1, b = n;

        while(b - a > 1) {
            int mid = (a + b) / 2;
            if(check(mid)) a = mid;
            else b = mid;
        }

        if(check(a)) puts("YES");
        else puts("NO");
    }
    return 0;
}

