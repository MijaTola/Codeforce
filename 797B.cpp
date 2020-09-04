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

vector<int> v,b;
int n;

int main(){
    scanf("%d",&n);
    int sum = 0;
    for (int i = 0; i < n; ++i){
        int x; scanf("%d",&x);
        if(x%2==0){ if(x >= 0) sum += x;}
        else v.push_back(x);
    }
    sort(v.rbegin(),v.rend());
    int ans = INT_MIN;
    int c = 0;
    for (int i = 0; i < (int)v.size(); ++i){
        c += v[i];
        if(c%2 != 0) ans = max(ans,c + sum);
    }
    printf("%d",ans);
    return 0;
}

