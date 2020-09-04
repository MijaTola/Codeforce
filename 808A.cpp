#include <bits/stdc++.h>

using namespace std;

vector<long long> v;
int main(){
 
    long long cur = 1LL;

    while(cur < 3e9){
        for (int i = 1; i < 10; ++i)
            v.push_back(cur*i);
        cur *= 10;
    }

    int n; scanf("%d",&n);
    int pos = upper_bound(v.begin(),v.end(),n)-v.begin();
    printf("%lld\n", v[pos] - n);
    return 0;
}

