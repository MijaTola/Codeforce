#include <iostream>
#include <algorithm>

using namespace std;

int n,b;
int v[2010];

int f(int pos,int win, int dollar){
    if(pos == n) return win;
    int ans = -1;
    if(win >= v[pos]){
        ans = max(ans,f(pos+1,win-v[pos],dollar+1));
        ans = max(ans,f(pos,win-v[pos],dollar+1));
    }
    if(dollar > 0) {
        ans = max(ans,f(pos+1,win+v[pos],dollar-1));
        ans = max(ans,f(pos+1,win+(v[pos]*dollar),0));
        ans = max(ans,f(pos,win+(v[pos*dollar]),0));
    }
    ans = max(ans,f(pos+1,win,dollar));
    return ans;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> b;
    for (int i = 0; i < n; ++i) cin >> v[i];
    
    int ans = -1;
    for (int i = 0; i < n; ++i){
        for (int j = i; j < n; ++j){
            int buy = b/v[i];
            int rest = b%v[i];
            int sell = buy*v[j]+rest;
            ans = max(sell,ans);
        }
    }
    cout << ans << endl;
   return 0;
}
