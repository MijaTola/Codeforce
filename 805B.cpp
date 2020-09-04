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

int main(){
    int n; scanf("%d",&n);
    bool flag = 0;
    for (int i = 0; i < n; ++i){
        if(flag) printf("a");
        else printf("b");
        if(i&1) flag = !flag;
    }
    puts("");
    return 0;
}

