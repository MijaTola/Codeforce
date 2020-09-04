#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    priority_queue<int> q;
    int power = 1;
    int total = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i){
        int t,d;
        scanf("%d %d",&t,&d);
        power = t;
        total += d;
        q.push(d);
        if(total > power){
            total -= q.top();
            q.pop();
            ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}

