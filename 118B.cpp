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

string s[10] ={"0","0 1 0","0 1 2 1 0","0 1 2 3 2 1 0",  "0 1 2 3 4 3 2 1 0",  "0 1 2 3 4 5 4 3 2 1 0",  "0 1 2 3 4 5 6 5 4 3 2 1 0", "0 1 2 3 4 5 6 7 6 5 4 3 2 1 0", "0 1 2 3 4 5 6 7 8 7 6 5 4 3 2 1 0", "0 1 2 3 4 5 6 7 8 9 8 7 6 5 4 3 2 1 0"};
int main(){
    int n; cin >> n;
    
    for (int i = 0; i <= n; ++i){
        for(int j = 0; j < (int)s[n].size()/2 - (int)s[i].size()/2; ++j) cout << " ";
        cout << s[i] << endl;
    }
    for (int i = n -1; i >= 0; --i){
        for (int j = 0; j < (int)s[n].size()/2 - (int)s[i].size()/2; ++j) cout << " ";
        cout << s[i] << endl;
    }
    return 0;
}

