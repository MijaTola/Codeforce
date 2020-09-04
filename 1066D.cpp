#include <bits/stdc++.h>

using namespace std;

int n,m,k;
int v[200010];

int f(int pos) {
    int ans = 0;
    int sum = 0;
    for (int i = pos; i < n; ++i) {
        sum += v[i];
        if(sum > k) {
            ans++;
            sum = v[i];
        }
    }
    if(sum) ans++;
    return ans;
}

int main() {
    scanf("%d%d%d", &n, &m, &k);

    for (int i = 0; i < n; ++i)
        scanf("%d", v + i);
    
    int a = -1;
    int b = n;
    while(b - a > 1) {
        int mid = (a + b) / 2;
        if(f(mid) <= m) b = mid;
        else a = mid;
    }
    cout << n - b<< "\n";
    return 0;
}

