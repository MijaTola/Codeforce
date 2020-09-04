#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int n,t,k,d;
    scanf("%d %d %d %d",&n,&t,&k,&d);
    if((n-1)/k*t <= d) puts("NO");
    else puts("YES");
    return 0;
}

