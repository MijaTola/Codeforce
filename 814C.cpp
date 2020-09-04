#include <bits/stdc++.h>

using namespace std;

int n;
char v[1510];
int f[27][1510];
int main(){
    scanf("%d",&n);
    scanf("%s",v);
    for (int i = 0; i < 27; ++i){
        for (int j = 0; j < n; ++j){
            int c = 0;
            for (int k = j; k < n; ++k){
                if(v[k] - 'a' != i) c++;
                f[i][c] = max(f[i][c],k - j + 1);
            }
        }
        for (int j = 0; j < n; ++j)
            f[i][j + 1] = max(f[i][j + 1], f[i][j]);
    }
    int q; 
    scanf("%d",&q);
    while(q--){
        int x; char y;
        scanf("%d %c",&x,&y);
        printf("%d\n",f[y - 'a'][x]);
    }
    return 0;
}

