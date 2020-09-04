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

pair<int,int> v[1010];
pair<int,int> vc[1010];
int main(){
    int n;
    scanf("%d",&n);
    
    bool flag = false;
    bool sorted = true;
    for (int i = 0; i < n; ++i){
        int x,y;
        scanf("%d %d" ,&x,&y);
        v[i].first = x; v[i].second = y;
        vc[i].first = x; vc[i].second = y;
        if(x != y) flag = true;
    }
    if(flag) return puts("rated"),0;
    
    sort(vc,vc+n);
    reverse(vc,vc+n);
    for (int i = 0; i < n; ++i)
        if(vc[i] != v[i]) sorted = false;

    if(sorted) puts("maybe");
    else puts("unrated");
    return 0;
}

