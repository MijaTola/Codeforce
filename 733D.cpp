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


const int N = 100010;

int n, a[N][3], p[N];

bool cmp(int i, int j){
    if(a[i][2] == a[j][2] && a[i][1] == a[j][1]) return a[i][0] < a[j][0];
    else if(a[i][2] == a[j][2]) return a[i][1] < a[j][1];
    return a[i][2] < a[j][2];
}

int main(){
    int ans = 0, ans2 = 0, aa, bb, aha;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i][0] >> a[i][1] >> a[i][2];
        sort(a[i], a[i] + 3);
        if(a[i][0] > ans) ans = a[i][0], aha = i;
        p[i] = i;
    }
    
    sort(p+1,p+n+1,cmp);
    for(int i = 1; i <= n; ++i){
        int l = 1, r = n;
        while(l <= r){
            int mid = (l + r) >> 1;
            int k = p[mid];
            if(a[k][2] > a[i][2] || (a[k][2] == a[i][2] && a[k][1] > a[i][1])) r = mid - 1;
            else l = mid + 1;
        }
        int k = p[r];
        if(k != i){
            int cur = min(min(a[i][1], a[i][2]), a[k][0] + a[i][0]);
            if(cur > ans2) aa = i, bb = k, ans2 = cur;
        }
    }
    if(ans2 > ans) cout<<"2"<<endl<<aa<<" "<<bb<<endl;
    else cout<<"1"<<endl<<aha<<endl;
    return 0;
}

