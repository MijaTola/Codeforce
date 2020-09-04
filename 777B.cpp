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

char a[1010];
char b[1010];
int d[10];
int d1[10];
int da[10];
int main(){
    int n; 
    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> a[i];
        da[a[i]-'0']++;
    }
    for (int i = 0; i < n; ++i){
        cin >> b[i];
        d[b[i]-'0']++;
        d1[b[i]-'0']++;
    }
    
    sort(a,a+n);
    sort(b,b+n);

    int ans = 0;
    int ans2 = 0;
    for (int i = 0; i < n; ++i){
        int cur = 0;
        int pos = i;
        for (int j = 0; j < n; ++j,pos=(pos+1)%n)
            if(a[pos] <= b[j]) cur++;
        
        for (int j = (int)(a[i]-'0')+1; j < 10; ++j){
            if(d1[j]){
                d1[j]--;
                ans2++;
                break;
            }
        }
        ans = max(cur,ans);
    }
    cout << n-ans << "\n";
    cout << ans2 << "\n";
    return 0;
}

