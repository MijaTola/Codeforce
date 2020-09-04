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

int v[100010];
int a[100010];
int b[100010];
int ans[100010];
int main(){
    
    int n; cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> v[i];
    }
    int last = 0;
    for (int i = n-1; i >= 0; --i){
        ans[i]= last+v[i];
        last = v[i];
    }
    for (int i = 0; i < n; ++i)
        cout << ans[i] << " ";
    return 0;
}

