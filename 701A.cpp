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

using namespace std;

typedef long long ll;

int v[110];
int main(){
    int n; cin >> n;
    int total = 0;

    for (int i = 0;  i < n; ++i){
        cin >> v[i];
        total += v[i];
    }

    int eq = total/(n/2);

    for (int i = 0; i < n; ++i){
        for (int j = i +1; j < n; ++j){
            if(v[i] + v[j] == eq){
                cout << i+1 << " " << j+1 << endl;
                v[i] = v[j] = -1;
            }
        }
    }
    return 0;
}

