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

int mod = 1000000000+7;
char s[1000010];
int sz;
int main(){
    scanf("%s",s);
    sz = strlen(s);
    int ans = 0;
    int cur = 0;
    for (int i = sz - 1; i >= 0; --i){
        if(s[i] == 'b') cur++;
        else{ ans = (ans+cur)%mod; cur = (2*cur)%mod;}
    }
    printf("%d\n",ans);
    return 0;
}

