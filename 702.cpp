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

using namespace std;

typedef long long ll;

ll A[100100];
int main(){
    int n;
    cin >> n;
    for (int i=0;i<n;++i) cin >> A[i];
    
    ll last = -1;
    int ans = 0;
    int count = 0;
    for (int i = 0; i < n; ++i){
        if(A[i] > last) count++;
        else{
            ans = max(ans,count);
            count = 1;
        }
        last = A[i];
    }
    cout << max(ans,count) << endl;
    return 0;
}

