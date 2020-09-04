#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <climits>
#include <map>
#include <set>
#include <cassert>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;

ll v[100010],a[100010];
int main(){
    int n; cin >> n;

    for (int i = 0; i < n; ++i){cin >> v[i];a[i] = v[i];}
    sort(v,v+n);
    int ans = 0;
    for (int i = 0; i < n; ++i){
        if(v[i] != a[i])ans++;
    }
    if(ans > 2) cout << "NO" << endl;
    else cout << "YES" << endl;
    return 0;
}

