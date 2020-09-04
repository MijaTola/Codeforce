#include <bits/stdc++.h>

using namespace std;

int a[110];
int b[110];
int main(){
    int n,k;
    scanf("%d %d",&n,&k);

    for (int i = 0; i < n; ++i){
        scanf("%d",a + i);
    }
    for (int i = 0; i < k; ++i){
        scanf("%d",b + i);
    }

    sort(b, b + k);
    reverse(b, b + k);
    
    int pos = 0;
    for (int i = 0; i < n; ++i)
        if(!a[i]) a[i] = b[pos++];

    
    for (int i = 1; i < n; ++i){
        if(a[i] < a[i - 1]) return puts("Yes");
    }
    puts("No");
    
    return 0;
}

