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

char M[30][30];
int sum[30][30];
int n,m;
int main(){

    int n,m;
    
    cin >> n >> m;
    
    for(int i = 0;i < n;++i)
        cin >> M[i];
   
    for(int i = 0;i < n;++i)
        for(int j = 0;j < m;++j)
            sum[i + 1][j + 1] = M[i][j] - '0' + sum[i + 1][j] + sum[i][j + 1] - sum[i][j];
    
    int ans = 0;
    
    for(int r = 1;r <= n;++r)
        for(int c = 1;c <= m;++c){
            for(int i = 0;i + r <= n;++i)
                for(int j = 0;j + c <= m;++j){
                    int aux = sum[i + r][j + c] - sum[i + r][j] - sum[i][j + c] + sum[i][j];
                    if(aux == 0) ans = max(ans,2 * (r + c));
                }
        }
    
    cout << ans << endl;
    return 0;
}

