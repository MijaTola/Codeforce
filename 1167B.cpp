#include <bits/stdc++.h>

using namespace std;

int ans[8];
int a1,a2,x,y,a,b;
int v[] = {4,8,15,16,23,42};
bool is[1100];
int main() {

    printf("? 1 2\n");
    fflush(stdout);
    scanf("%d", &a1);

    printf("? 2 3\n");
    fflush(stdout);
    scanf("%d", &a2);
    
    for (int i = 0; i < 6; ++i)
        is[v[i]] = 1;

    for (int i = 0; i < 6; ++i) {
        if(a1 % v[i] == 0 and is[v[i]] and is[a1/v[i]]) {
            x = v[i];
            y = a1 / v[i];
            break;
        }
    }    

    for (int i = 0; i < 6; ++i) {
        if(a2 % v[i] == 0 and is[v[i]] and is[a2/v[i]]) {
            a = v[i];
            b = a2 / v[i];
            break;
        }
    }  
    if(x == a) {
        ans[1] = x;
        ans[0] = y;
        ans[2] = b;
    }
    if(x == b) {
        ans[1] = x;
        ans[0] = y;
        ans[2] = a;
    }
    if(y == a) {
        ans[1] = y;
        ans[0] = x;
        ans[2] = b;
    }
    if(y == b) {
        ans[1] = y;
        ans[0] = x;
        ans[2] = a;
    }
    printf("? 3 4\n");
    fflush(stdout);
    scanf("%d", &a1);
    ans[3] = a1 / ans[2];
    printf("? 4 5\n");
    fflush(stdout);
    scanf("%d", &a1);
    ans[4] = a1 / ans[3];
    memset(is, 0, sizeof is);
    for (int i = 0; i < 6; ++i)
        is[ans[i]] = 1;

    for (int i = 0; i < 6; ++i) 
        if(!is[v[i]]) ans[5] = v[i];
    
    printf("! ");
    for (int i = 0; i < 6; ++i)
        printf("%d ", ans[i]);
    puts("");
    fflush(stdout);
    return 0;
}

