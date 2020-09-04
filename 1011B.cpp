#include <bits/stdc++.h>

using namespace std;

int v[110];
int c[110];
int n,m; 

bool ver(int days) {
    int p = 0;
    int pos = 1;
    while(p < n and pos <= 100) {
        if(c[pos] >= days) {
            c[pos] -= days;
            p++;
        }else pos++;
    }
    return p == n;
}

int main(){
    
    
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x; cin >> x;
        v[x]++;
    }
        for (int i = 1; i < 110; ++i)
            c[i] = v[i];
    int a = -1;
    int b = 110;
    
    while(b - a > 1) {
        int mid = (a + b) / 2;
        for (int i = 1; i < 110; ++i)
            c[i] = v[i];
        if(ver(mid)) a = mid;
        else b = mid;
    }
    
    cout << a << "\n";
    return 0;
}

