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
    string x; 
    cin >> x;
    int ans = 0;
    for (int i = 0; i < (int)x.size(); ++i){
        if(x[i] == 'V') x[i] = 'K';
        else x[i] = 'V';
        int c = 0;
        for (int j = 0; j < (int)x.size()-1; ++j){
            if(x[j] == 'V' and x[j+1] == 'K') c++;
        }
        if(x[i] == 'V') x[i] = 'K';
        else x[i] = 'V';
        ans = max(ans,c);
    }
    for (int i = 0; i < (int)x.size(); ++i){
        int c = 0;
        for (int j = 0; j < (int)x.size()-1; ++j)
            if(x[j] == 'V' and x[j+1] == 'K') c++;
        ans = max(ans,c);
    }
    cout << ans << "\n";
    return 0;
}

