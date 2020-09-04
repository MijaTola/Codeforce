#include <bits/stdc++.h>

using namespace std;

char s[5050];

int main(){
    
    scanf("%s", s);
    int n = strlen(s);

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int cur = 0, cnt = 0;
        for (int j = i; j < n; ++j) {
            if(s[j] == '(') cur++;
            else if(s[j] == ')') cur--;
            else cnt++;
            if(cur < 0) break;
            if(cnt > cur) cnt--, cur++;
            if(cnt >= cur and (j - i + 1) % 2 == 0) ans++;
        }
    }

    printf("%d\n", ans);
    return 0;
}
