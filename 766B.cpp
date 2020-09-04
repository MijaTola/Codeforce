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

int v[100010];

bool ver(int a, int b,int c){
    return a+b > c and b+c > a and c+a > b;
}
int main(){
    int n; cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> v[i];

    sort(v,v+n);

    for (int i = 0; i < n-2; ++i)
        if(ver(v[i],v[i+1],v[i+2])) return cout << "YES\n",0;
    cout << "NO\n";
    return 0;
}

