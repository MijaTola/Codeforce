#include <bits/stdc++.h>

using namespace std;

int v[200010];
int n,a,b;

int main() {
    scanf("%d %d %d", &n, &b, &a);

    for (int i = 0; i < n; ++i)
        scanf("%d", v + i);
    
    int pos = 0;
    int da = a, db = b;
    while((da or db) and pos < n) {
        if(v[pos]) {
            if(da < a) {
                if(db) da++, db--;
                else if(da) da--;
                else break;
            }
            else if (da)da--;
            else if (db)db--;
            else break;
        } else {
            if (da)da--;
            else if (db)db--;
            else break;
        }
        pos++;
    }
    printf("%d\n", pos);
    return 0;
}

