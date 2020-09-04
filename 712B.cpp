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

string x;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int get(char l){
    if(l == 'L') return 1;
    if(l == 'R') return -1;
    if(l == 'U') return 1;
    return -1;
}

int main(){
    cin >> x;
    if(x.size() % 2 == 1) return cout << "-1\n",0;
    
    int t = 0,y = 0;
    for (int i = 0; i < (int)x.size(); ++i){
        if(x[i] == 'L' or x[i] == 'R') t += get(x[i]);
        if(x[i] == 'U' or x[i] == 'D') y += get(x[i]);
    }

    cout << (abs(t)+abs(y))/2 << "\n";
    return 0;
}

