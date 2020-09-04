#include <bits/stdc++.h>

using namespace std;

int v[200010];
int a[200010];
int main(){
    int n;
    scanf("%d",&n);
    int cur = 0;
    double ans = 0;
    while(n--){
        int x; 
        scanf("%d",&x);
        if(x == 1){
            int y,z;
            scanf("%d%d",&y,&z);
            a[y - 1] += z;
            ans += (y * z);
        }
        if(x == 2){
            int y;
            scanf("%d",&y);
            v[++cur] = y;
            ans += y;
        }

        if(x == 3){
            int r = a[cur];
            a[cur - 1] += a[cur];
            r = v[cur] + r;
            ans -= r;
            a[cur] = 0;
            cur--;
        }
        printf("%.6f\n", (double)(ans/(cur + 1)));
    }
    return 0;
}

