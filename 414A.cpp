#include <bits/stdc++.h>

using namespace std;

int n,k;
int main(){
    scanf("%d %d",&n,&k);   
    
    int m = n / 2;

    if((n == 1 and k != 0) or k < m) return puts("-1");
    
    if(n == 1 and k == 0) return puts("1"),0;
    int x = k - (n - 2) / 2;

    printf("%d %d ",x,2*x);
    
    int cur = 0;
    int l = 1;
    while(cur < n - 2){
        if(l == x or l == 2*x){
            l++;
            continue;
        }
        printf("%d ",l);
        cur++;
        l++;
    }
    puts("");
    return 0;
}

