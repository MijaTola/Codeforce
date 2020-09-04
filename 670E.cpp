#include <bits/stdc++.h>

using namespace std;

int Next[500010];
int Back[500010];
int ini[500010];
int fin[500010];
char s[500010];
stack<int> st;
int n,m,p;

int main() {
    scanf("%d %d %d %s", &n, &m, &p, s + 1);
    Next[0] = 1;
    Back[n] = n - 1;
    for (int i = 1; i <= n; ++i) {
        Next[i] = i + 1;
        Back[i] = i - 1;
        if(s[i] == '(') st.push(i);
        else {
            int pos = st.top();
            st.pop();
            ini[pos] = ini[i] = pos;
            fin[pos] = fin[i] = i;
        }
    }

    while(m--) {
        char c;
        cin >> c;
        if(c == 'R') p = Next[p];
        if(c == 'L') p = Back[p];
        if(c == 'D') {
            int l = Back[ini[p]];
            int r = Next[fin[p]];
            Next[l] = r;
            Back[r] = l;
            if(Next[l] <= n) p = Next[l];
            else p = Back[r];
        }

    }

    p = Next[0];

    while (p <= n) {
        printf("%c", s[p]);
        p = Next[p];
    }
    puts("");
    return 0;
}

//((())()())
//RRDDRDD 

