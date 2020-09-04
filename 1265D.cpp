#include <bits/stdc++.h>

using namespace std;


int main() {
    
    int a,b,c,d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    
    deque<int> ans;

    print:
    puts("YES");
    for (auto x: ans)
        printf("%d ", x);
    puts("");

    return 0;
    noans:
    puts("NO");
    
    return 0;
}

