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
#include <cmath>
#include <deque>
#include <string> 
#include <sstream>
#include <cstdlib>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int a[200100];
int b[200100];
pair<int,int> c[200100];
int main(){
    int n,k; cin >> n >> k;
    
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    
    for (int i = 0; i < n; ++i){
        c[i].first = a[i]-b[i];
        c[i].second = i;
    }

    sort(c,c+n);
    int ans = 0;
    for (int i = 0; i < k; ++i)
        ans += a[c[i].second];
    
    for (int i = k; i < n; ++i)
        ans += min(a[c[i].second],b[c[i].second]);

    cout << ans << "\n";
    return 0;
}

