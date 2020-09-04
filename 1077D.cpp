#include <bits/stdc++.h>

using namespace std;

int n,k;
int v[200010];
vector<int> ans;

bool ver(int x) {
    int c = 0;
    for (int i = 0; i < 200010; ++i) 
        c += v[i] / x;
    return c >= k;
}

int main() {
    
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        v[x]++;
    }
    
    int a = 0, b = n + 1;

    while(b - a > 1) {
        int mid = (a + b) / 2;
        if(ver(mid)) a = mid;
        else b = mid;
    }
    
    for (int i = 0; i < 200010; ++i) 
        for (int j = 0; j < v[i] / a; ++j)ans.push_back(i);
    
    for (int i = 0; i < min((int)ans.size(),k); ++i)
        cout << ans[i] << " ";
    cout << "\n";
    return 0;
}
