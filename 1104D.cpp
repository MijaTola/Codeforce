#include <bits/stdc++.h>

using namespace std;

char start[10];
char r1[4];
int main() {
    
    while(1) {
        scanf("%s", start);
        fflush(stdout);
        if(strcmp(start, "end") == 0) break;
        if(strcmp(start, "mistake") == 0) return 0;

        int a = 0;
        int b = 10;
        char a1,a2;
        bool flag = 0;
        while(b - a > 1) {
            int mid = (a + b) / 2;
            printf("? %d %d\n", mid, mid + 1);
            fflush(stdout);
            scanf("%s", r1);
            a1 = r1[0];
            if(a1 == 'e' or a1 == 'e') return 0;
            printf("? %d %d\n", mid - 1, mid);
            fflush(stdout);
            scanf("%s", r1);
            a2 = r1[0];
            if(a1 == 'e' or a1 == 'e') return 0;
            if(a1 == 'x' and a2 == 'x') a = mid;
            else if(a1 == 'y' and a2 == 'y') b = mid;
            else if(a1 == 'y' and a2 == 'x') {
                flag = 1;
                printf("! %d\n", mid);
                fflush(stdout);
                break;
            } else if(a1 == 'x' and a2 == 'y') {
                flag = 1;
                printf("! %d\n", mid);
                fflush(stdout);
                break;
            }
        }
        if(!flag) { 
            printf("! %d\n", b);
            fflush(stdout);
        }
    }
    return 0;
}

