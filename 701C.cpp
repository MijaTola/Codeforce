#include <bits/stdc++.h>

using namespace std;

int n;
char s[100010];
int a[256];
set<char> st;

bool ver(int k) {
    memset(a, 0, sizeof a);
    for (int i = 0; i < k; ++i)
        a[(int)s[i]]++;
    
    int cur = 0;
    for (int i = 0; i < 256; ++i)
        cur += a[i] != 0;
    if(cur == (int)st.size()) return 1;
    int pos = k;
    for (int i = pos, p = 0; i < n; ++i, ++p) {
        a[(int)s[p]]--;
        if(!a[(int)s[p]]) cur--;
        if(!a[(int)s[i]]) cur++;
        a[(int)s[i]]++;
        if(cur == (int)st.size()) return 1;
    }
    return 0;
}
int main() {

    scanf("%d %s", &n, s);
    for (int i = 0; i < n; ++i) 
        st.insert(s[i]);
    
    int a = -1, b = n;
    while(b - a > 1) {
        int mid = (a + b) / 2;
        if(ver(mid)) b = mid;
        else a = mid;
    }
    cout << b << "\n";
    return 0;
}
