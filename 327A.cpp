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

int v[110],n;

int main(){
    cin >> n;    
    for (int i = 1; i <= n; ++i) cin >> v[i];
    int sum = 0;
    int ans = 0;
    for (int i = 0; i <= n; ++i){
        int c = 0;
        sum += v[i]; 
        for (int j = i+1; j <= n; ++j){
            int rest = 0;
            c += 1-v[j];
            for (int k = j+1; k <= n; ++k)
                rest += v[k];
            ans = max(ans,sum+c+rest);
            //cout << ans <<" " << sum << " " << c << " " << rest << endl;
        }
    }
    cout << ans << endl;
    return 0;
}

