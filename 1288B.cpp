#include <bits/stdc++.h>

using namespace std;

long long a,b;

int main() {
 
    int t;
    cin >> t;

    while(t--) {
        cin >> a >> b;
        long long cnt = 1;
        long long p = 9;
        while (p <= b) p = p * 10 + 9, cnt++;;
        p /= 10;
        cnt--;
        cout << a * cnt << "\n";
    }
    return 0;
}

