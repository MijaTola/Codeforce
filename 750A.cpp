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
    
    int n,k;
    cin >> n >> k;
    int time = 0;
    int i = 1;
    int ans = 0;
    while(time <= 240-k and i <= n){
        time += i*5;
        i++;
        if(time <= 240-k)ans++;
    }
    cout << ans << "\n";
    return 0;
}

