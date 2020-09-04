#include <bits/stdc++.h>

using namespace std;

int out[100010];
int main() {
    int n,s;
    scanf("%d %d", &n, &s);

    for (int i = 0; i < n - 1; ++i) {
        int x,y;
        scanf("%d %d", &x, &y);
        x--,y--;
        out[y]++;
        out[x]++;
    }
    
    double c = 0;
    for (int i = 0; i < n; ++i) 
        c += out[i] == 1;
    
    printf("%.10lf\n", s / c * 2);
    
    
    return 0;
}

