#include <bits/stdc++.h>

using namespace std;

int n,k;

int f(int pos) {
    if(pos >= n) return 0;
    if(pos + k >= n) return 1e9;
    return f(pos + 2 * k + 1) + 1;
}

void r(int pos) {
    if(pos >= n or pos + k >= n) return;
    cout << pos << "\n";
    r(pos + 2 * k + 1);
}

int main(){
    
    scanf("%d %d", &n, &k);
    
    int ans = 1e9;
    int id = -1;
    for (int i = 0; i <= k; ++i) {
        if(f(i + k + 1) < ans) {
            ans = f(i + k + 1) + 1;
            id = i;
        }
    }

    printf("%d\n%d ", ans, id + 1);
    r(id + k + 1);
    puts("");
    return 0;
}

