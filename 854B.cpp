#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,k;

    scanf("%d %d",&n,&k);
    
    if(n == k or k == 0) return puts("0 0");
    int a1 = (k * 2) + k;
    int c = a1 - n;
    if(c > 0) a1 = k * 2 - c;
    else a1 = k * 2;
    printf("1 %d\n",a1);
    return 0;
}

