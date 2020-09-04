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

int v[110];
bool ver(char x){
    return x == 'a' or x == 'e' or x == 'i' or x == 'o' or x == 'u' or x == 'y';
}
int main(){
    int n; 
    cin >> n;

    for (int i = 0; i < n; ++i) cin >> v[i];
    
    bool ans = true;
    cin.ignore();
    for (int i = 0; i < n; ++i){
        string x;
        getline(cin,x);
        int c = 0;
        for (int i = 0; i < (int)x.size(); ++i)
            if(ver(x[i])) c++;
        if(c != v[i]) ans = false;
    }

    if(ans) cout <<"YES" << endl;
    else cout << "NO" << endl;
    return  0;
}

