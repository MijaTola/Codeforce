#include <bits/stdc++.h>

using namespace std;

char s[110];
int main(){
    int n,m;

    scanf("%d %d %s",&n,&m,s);
    
    while(m--){
        int l,r;
        char c,x;
        scanf("%d %d %c %c", &l, &r, &c, &x);
        l--,r--;
        for (int i = l; i <= r; ++i)
            if(s[i] == c)s[i] = x;
        printf("%s",s);
    }
    return 0;
}

