#include <bits/stdc++.h>

using namespace std;

int n;
int in[100010];

int main() {
    
    cin >> n;
    
    for (int i = 0; i < n - 1; ++i) {
        int x,y;
        cin >> x >> y;
        in[x]++, in[y]++;
    }
    
    bool flag = 1;
    for (int i = 1; i <= n; ++i) 
        flag &= (in[i] == 1 or in[i] >= 3);

    if(flag) puts("YES");
    else puts("NO");
    return 0;
}

