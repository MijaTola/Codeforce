#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; 
    scanf("%d",&n);
    int sum = 0;
    int odd = 0, even = 0;
    for (int i = 0; i < n; ++i){
        int x;
        scanf("%d",&x);
        sum += x;
        if(x & 1) odd++;
        else even++;
    }

    if(odd) puts("First");
    else puts("Second");
    return 0;
}

