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
    int n,m,x,y;
    long long k;
    cin >> n >> m >> k >> x >> y;

    int est = n*m;

    long long rec = k/est;
    long long mod = k-rec;
    if(mod) rec++;
    long long c = 0;
    if(rec%2==0){
        c = (x-1)*m+y;
        if(mod > c) cout << rec << " " << rec << " " << rec-1 << "\n";
        else cout << rec << " " << rec-1 << " " << rec-1 << "\n";
    }else{
        c = (n-x-1)*m+y;
        if(mod > c) cout << rec << " " << rec << " " << rec-1 << "\n";
        else cout << rec << " " << rec-1 << " " << rec-1 << "\n";
    }
    
    return 0;
}

