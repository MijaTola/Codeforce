#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,a,b;
    scanf("%d %d %d", &n, &a, &b);
    
    int ans = 0;
    for (int i = 1; i < n; ++i){
        int da = i;
        int db = n - i;
        if(a >= da and b >= db) {
            ans = max(ans,min(a / da, b / db));
        }
    }

    printf("%d\n",ans);
    
    return 0;
}

