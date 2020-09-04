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

vector<unsigned long long> v;
int main(){
    
    unsigned long long a = 2;
    unsigned long long b = 3;
    v.push_back(a);
    v.push_back(b);
    while(v.size() < 100){
        unsigned long long c = a+b;
        v.push_back(c);
        a = b;
        b = c;
    }
    //for (int i = 0; i < (int)v.size(); ++i) cout << v[i] << endl;
    unsigned long long n; cin >> n;
    cout << upper_bound(v.begin(),v.end(),n)-v.begin();
    return 0;
}

