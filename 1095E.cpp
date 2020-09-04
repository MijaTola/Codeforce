#include <bits/stdc++.h>

using namespace std;

int n;
char s[1000010];
int st[1000010],st2[1000010];
bool can[1000010],can1[1000010],vis[1000010];

int main() {


    scanf("%d %s", &n, s);
    
    if(n == 2) {
        if(s[0] == '(' and s[1] == '(') puts("1");
        else if(s[0] == ')' and s[1] == ')') puts("1");
        else puts("0");
        return 0;
    }
    int c = 0;
    
    if(s[0] == '(') can[0] = 1;
    if(s[n - 1] == ')') can1[n - 1] = 1;
    for (int i = 0; i < n; ++i) {
        if(s[i] == '(') c++;
        else c--;
        st[i] = c;
        if(i and can[i - 1] and st[i] >= 0) can[i] = 1;
    }

    c = 0;
    for (int i = n - 1; i >= 0; i--) {
        if(s[i] == '(') c--;
        else c++;
        st2[i] = c;
        if(i < n - 1 and st2[i] >= 0 and can1[i + 1]) can1[i] = 1;
    }


    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if(!can[i] or !can1[i + 1]) continue;
        if(s[i] == ')') {
            int curI = st[i];
            int curR = st2[i + 1];
            curI += 2;
            if(curI == curR and curI >= 0 and curR >= 0) vis[i] = 1;
        } else {
            int curI = st[i];
            int curR = st2[i + 1];
            curI -= 2;
            if(curI == curR and curI >= 0 and curR >= 0) vis[i] = 1;
        }
    }

    for (int i = n - 1; i > 0; i--) {
        if(!can[i - 1] or !can1[i]) continue;
        if(s[i] == ')') {
            int curI = st[i - 1];
            int curR = st2[i];
            curR -= 2;
            if(curI == curR and curI >= 0 and curR >= 0) vis[i] = 1;
        } else {
            int curI = st[i - 1];
            int curR = st2[i];
            curR += 2;
            if(curI == curR and curI >= 0 and curR >= 0) {
                vis[i] = 1;
            }
        }
    }   
    for (int i = 0; i < n; ++i) {
        ans += vis[i];
    }
    printf("%d\n", ans);
    return 0;
}
