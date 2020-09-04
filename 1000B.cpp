#include <bits/stdc++.h>

using namespace std;

int n,m,x;
vector<int> v,b;
long long a[100010][2];

int main(){
    
    scanf("%d %d", &n, &m);

    v.push_back(0);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        v.emplace_back(x);
    }
    v.push_back(m);

    
    for (int i = 0; i < (int)v.size() - 1; ++i)
        b.push_back(v[i + 1] - v[i]);

    
    for (int i = 0; i < (int)b.size(); ++i) 
        a[i][i & 1] = b[i];
    
    for (int i = b.size() - 1; i >= 0; i--) {
        a[i][0] += a[i + 1][0];
        a[i][1] += a[i + 1][1];
    }

    long long ans = 0, cur = 0;

    for (int i = 0; i < (int)b.size(); ++i) {
        if(!(i & 1)) cur += b[i];
        ans = max(ans, (cur - 1) + a[i][1]);
    }

    printf("%lld\n", max(ans, a[0][0]));


    return 0;
}

