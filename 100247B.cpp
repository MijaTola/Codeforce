#include <bits/stdc++.h>

using namespace std;

vector<string> v;

long long p = 67280421310721LL;
long long x = 31;
int a[27];

long long h(string &s){
    long long hsh = 0;
    for (int i = s.size() - 1; i >= 0; --i)
        hsh = ((((hsh*x+a[s[i] - 'a'])%p)+p)%p);
    return hsh;
}

map<long long,long long> mp;

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i){
        string x;
        cin >> x;
        int cur = 1;
        for (int j = 0; j < 27; ++j) a[j] = 0;
        for (int j = 0; j < (int)x.size(); ++j)
            if(!a[x[j] - 'a']) a[x[j] - 'a'] = cur++;
        
        long long p = h(x);
        mp[p]++;
    }

    long long ans = 0;

    for (pair<long long, int> p: mp)
        ans = ans + (((long long)p.second * (p.second - 1)) / 2);

    printf("%lld\n",ans);
    return 0;
}

