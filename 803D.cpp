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

int n,k;

char s[1010];
int dp[1010][1010];
int f(int pos, int cur){
    if(abs(cur) == k and pos < n) return false;
    if(pos == n){
        if(abs(cur) == k) return true;
        return false;
    }
    if(dp[pos][cur] != -1) return dp[pos][cur];
    bool ans = false;
    if(s[pos] == '?'){
        ans |= f(pos+1,cur-1); // if lose
        ans |= f(pos+1,cur); //if draw
        ans |= f(pos+1,cur+1); //if win
    }else{
        if(s[pos] == 'W') ans |= f(pos+1,cur+1);
        if(s[pos] == 'D') ans |= f(pos+1,cur);
        if(s[pos] == 'L') ans |= f(pos+1,cur-1);
    }
    return dp[pos][cur] = ans;
}

void find(int pos, int cur){
    if(pos == n) return;
    if(s[pos] == '?'){
        if(f(pos+1,cur-1)){
            printf("L");
            find(pos+1,cur-1);
            return;
        }
        if(f(pos+1,cur)){
            printf("D");
            find(pos+1,cur);
            return;
        }
        if(f(pos+1,cur+1)){
            printf("W");
            find(pos+1,cur+1);
            return;
        }
    }else{
        printf("%c",s[pos]);
        if(s[pos] == 'W') find(pos+1,cur+1);
        if(s[pos] == 'D') find(pos+1,cur);
        if(s[pos] == 'L') find(pos+1,cur-1);
    }
}
int main(){
    memset(dp,-1,sizeof dp);
    scanf("%d %d %s",&n,&k,s);
    if(!f(0,0)) return puts("NO"),0;
    find(0,0);
    puts("");
    return 0;
}

