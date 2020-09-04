#include <bits/stdc++.h>

using namespace std;

int n,k;
priority_queue<int> q;

int main() {

    scanf("%d %d", &n, &k);
    int p = 1;
    while(n) {
        if(n % 2 != 0) q.push((n % 2) * p);
        n /= 2;
        p *= 2;
    }
    
    while((int)q.size() < k) {
        int cur = q.top();
        q.pop();
        if(cur > 1) {
            q.push(cur / 2);
            q.push(cur / 2);
        } else break;
    }
    if((int)q.size() != k) return puts("NO"),0;

    puts("YES");
    while(!q.empty()) {
        printf("%d ", q.top());
        q.pop();
    }
    puts("");
    return 0;
}

