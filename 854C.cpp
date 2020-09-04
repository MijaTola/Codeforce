#include <bits/stdc++.h>

using namespace std;

int v[300010];
int ans[300010];

priority_queue<pair<int,int> > q;
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    
    long long a = 0;

    for (int i = 0; i < n; ++i)
        scanf("%d",v + i);

    for (int i = 0; i < k; ++i)
        q.push(make_pair(v[i],i));
   
    for (int i = k; i < n + k; ++i){
        if(i < n)q.push(make_pair(v[i],i));
        long long depart = q.top().second;
        long long delay = i - depart;
        a += delay * q.top().first;
        q.pop();
        ans[depart] = i;
    }

    printf("%lld\n",a);
    for (int i = 0; i < n; ++i)
        printf("%d ", ans[i] + 1);

    puts("");
    
    return 0;
}

