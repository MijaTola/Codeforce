#include <bits/stdc++.h>

using namespace std;

long long n,k,a,b;
vector<int> v;
unordered_set<int> s;
long long f(long long l, long long r) {
    long long mid = (l + r) / 2;
    long long dl = lower_bound(v.begin(), v.end(), l) - v.begin();
    long long dr = upper_bound(v.begin(), v.end(), r) - v.begin();
    dr--;
    long long total = dr - dl + 1;
    long long ans = LLONG_MAX;
    if(!total) ans = a;
    else ans = b * total * (r - l + 1);
    if(!total or l == r) return ans;
    ans = min(ans,f(l, mid) + f(mid + 1, r));
    return ans;
}
int main() {
    scanf("%lld %lld %lld %lld", &n, &k, &a, &b);
    for (int i = 0; i < k; ++i) {
        int x;
        scanf("%d", &x);
        v.push_back(x);
        s.insert(x);
    }
    sort(v.begin(),v.end());
    printf("%lld\n", f(1, 1LL << n));
    return 0;
}
