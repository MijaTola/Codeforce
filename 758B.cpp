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

int v[4];
char c[4];
map<char,int> mp;
int main(){
    memset(c,'!',sizeof c);
    string x;
    cin >> x;
    int pos = 0;
    for (int i = 0; i < (int)x.size(); ++i){
        if(x[i] != '!') mp[x[i]] = pos;
        if(x[i] == '!') v[pos]++;
        pos = (pos+1)%4;
    }

    cout << v[mp['R']] << " " << v[mp['B']] << " " << v[mp['Y']] << " " << v[mp['G']] << "\n";
    return 0;
}

