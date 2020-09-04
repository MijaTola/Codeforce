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
    int l,r;
    scanf("%d %d", &l, &r);
    
    int x = l;
    int y = r;
    while(x%2 != 0)x++;
    while(y%2 != 0)y--;
    int ans = (y)-x/2;
    x = l, y = r;
    while(x%3 != 0)x++;
    while(y%3 != 0)y--;
    int ans2 = (y-x)/3;

    printf("%d\n",ans < ans2 ? 3 : 2);
    return 0;
}

