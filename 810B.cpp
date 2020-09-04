#include <bits/stdc++.h>

using namespace std;

vector<int> v;
int n,f;
int main(){
    scanf("%d %d",&n,&f);
    long long ans = 0;
    for (int i = 0; i < n; ++i){
        int k,l;
        scanf("%d %d",&k,&l);
        int cur = min(k,l);
        int dcur = min(2*k,l);
        ans += cur;
        v.push_back(dcur - cur);
    }
    sort(v.rbegin(),v.rend());
    for (int i = 0; i < f and i < (int)v.size(); ++i)
        ans += v[i];
    printf("%lld\n",ans);

    return 0;
}

