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

using namespace std;

typedef long long ll;
set<string> s;
int main(){
    string s;
    cin >> s;
    int dx[] = {0,0,1,-1};
    int dy[] = {1,-1,0,0};
    
    bool flag = false;
    for (int i = 0; i < 4; ++i){
        for (int i = 0; i < s.size(); ++i){
                int x = int(s[i] - '0')/3;
                int y = int(s[i] - '0')%3;
                int u = x
            }
    }
    return 0;
}

