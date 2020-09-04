#include <bits/stdc++.h>

using namespace std;

int m[60] = {31,28,31,30,31,30,31,31,30,31,30,31};
int m2[25] = {31,29,31,30,31,30,31,31,30,31,30,31};
int v[25];
int main(){
    
    for (int i = 0; i < 12; ++i) {
        m[i + 12] = m[i];
    }
    
    for (int i = 0; i < 12; ++i) 
        m[i + 24] = m2[i];
    
    for (int i = 0; i < 12; ++i)
        m[i + 36] = m[i];
    
    for (int i = 0; i < 12; ++i)
        m[i + 48] = m[i];
    int n;
    scanf("%d",&n);

    for (int i = 0; i < n; ++i)
        scanf("%d",v + i);
    
    bool ans = 0;

    for (int i = 0; i < 60 - n; ++i) {
        bool f = 1;
        for (int j = i; j < i + n; ++j){
            if(v[j - i] != m[j]) f = 0;
        }

        if(f) {
            ans = 1; break;
        }
    }

    if(ans) puts("Yes");
    else puts("No");
    return 0;
}

