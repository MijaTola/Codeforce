#include <bits/stdc++.h>

using namespace std;

int a[6];

long long tri(long long w) {
    long long cur = (w * (w + 1)) / 2;
    w--;
    long long cur2 = (w * (w + 1)) / 2;
    return cur2 + cur;
}

long long f(long long h, long long w) {
    long long total = tri(w + h);
    long long toDel = tri(w);
    return total - toDel;
}

int main() {
    for (int i = 0; i < 6; ++i) 
        cin >> a[i];

    long long ans = 0;
    for (int i = 0; i < 3; ++i) {
        long long cur = f(min(a[i], a[(i + 2) % 6]), a[(i + 1) % 6]) + f(min(a[(i + 3) % 6], a[(i + 5) % 6]), a[(i + 4) % 6]);
        int dif = abs(a[i] - a[(i + 3) % 6]);
        long long w = a[(i + 1) % 6] + min(a[i], a[(i + 2) % 6]);
        //w = w + dif;
        if(a[i] == a[(i + 2) % 6] and a[(i + 3) % 6] == a[(i + 5) % 6]) w = 0;

        //cout << i << " " << cur << " " << w << " " <<dif << " || " <<min(a[i], a[(i + 2) % 6]) << a[i + 1]<< " test\n";   
        ans = max(ans, cur + 2 * w * dif);
    }
        
    cout << ans << "\n";
    
    return 0;
}

