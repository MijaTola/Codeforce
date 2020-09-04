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

vector<int> prime;
bool s[100100];
int main(){
    int n;
    cin >> n;

    int d = n/2;
    int mod = n%2;
    bool last = false;
    if(mod != 0) last = true;
    cout << d << "\n";
    if(last) d--;
    for (int i = 0; i < d; ++i) cout << 2 << " ";
    if(last) cout << 3;
    return 0;

}

