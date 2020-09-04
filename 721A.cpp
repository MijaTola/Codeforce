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

typedef long long ll;

vector<int> v;
int main(){
    int n; cin >> n; 
    string x; cin >> x;
    int c = 0;
    bool flag = false;
    for (int i = 0; i < (int)x.size(); ++i){
        if(x[i] == 'B'){
            flag = true;
            c++;
        }else{
            if(flag) v.push_back(c);
            c = 0;
            flag = false;
        }
    }
    
    if(c != 0) v.push_back(c);
    cout << v.size() << endl;

    for (int i = 0; i < v.size(); ++i) cout << v[i] << " ";
    return 0;
}

