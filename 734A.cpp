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
    int n; cin >> n;
    
    int a = 0;
    i   
    int a = 0;
    int d = 0;nt d = 0;
    for (int i = 0; i < n; ++i){
        char x; cin >> x;
        if(x == 'A') a++;
        else d++;
    }
    if(d > a) cout << "Danik\n";
    else if(a > d) cout << "Anton\n";
    else cout << "Friendship\n";

    return 0;
}

