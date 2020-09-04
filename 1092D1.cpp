#include <bits/stdc++.h>

using namespace std;

int n;
int v[200010];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", v + i);
    
    stack<int> s;

    for (int i = 0; i < n; ++i) {
        if(s.empty()) s.push(v[i]);
        else if(s.top() % 2 == v[i] % 2) s.pop();
        else s.push(v[i]);
    }
    puts(s.size() > 1 ? "NO" : "YES");
    return 0;
}

