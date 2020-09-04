#include <bits/stdc++.h>

using namespace std;

int n;
int a[200010];
int b[200010];
int pa[200010];
int pb[200010];

bool ver(int x, int val) {
    int ini = pb[val];
    int cur = x + ini;
    for (int i = val + 1; i <= n; ++i) {
        if(pb[i] != -1 and pb[i] > cur) {
            int dis = abs(cur - pb[i]);
            if(dis > i - 1) return 0;
        }
    }
    return 1;
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pa[a[i]] = i;
    }

    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        pb[b[i]] = i;
    }
    
    int pos2 = n;
    while(b[pos2] == b[pos2 - 1] + 1 and pos2 >= 1 and b[pos2 - 1]) pos2--;
    int pos = 1;
    if(b[pos2] == 1) pos = b[n] + 1;

    while(pa[pos] and pos <= n) pos++;
    if(pos == n + 1) return cout << n - (n - pos2 + 1)<<"\n",0;

    int a = -1, b = n;
    while(b - a > 1) {
        int mid = (a + b) / 2;
        if(ver(mid, pos)) b = mid;
        else a = mid;
    }
    cout << pb[pos] + b + (n - pos + 1) << "\n"; 
    return 0;
}

