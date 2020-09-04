#include <bits/stdc++.h>

using namespace std;

int n;
int x[1010];
int y[1010];
int a[1010];
int b[1010];
set<pair<int,int> > s;
int main() {

    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d %d", x + i, y + i);       
        s.insert(make_pair(x[i],y[i]));
    }
    
    for (int i = 0; i < n; ++i) 
        scanf("%d %d", a + i, b + i);       
    

    for (int i = 0; i < n; ++i) {
        int dx = x[0] + a[i];
        int dy = y[0] + b[i];
        bool flag = 1;
        for (int j = 0; j < n; ++j) 
            flag &= s.count(make_pair(dx - a[j], dy - b[j]));
        
        if(flag) return printf("%d %d\n", dx, dy),0;
        
    }
    return 0;
}

