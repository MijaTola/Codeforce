#include <bits/stdc++.h>

using namespace std;

long double f(int x,int y,int a, int b){
    return sqrt((x - a)*(x - a)+(y - b)*(y - b));
}
int main(){
    
    int r,d; 
    cin >> r >> d;

    int R = r - d;

    int n; cin >> n;
    
    int ans = 0;
    while(n--){
        int x,y,w;
        cin >> x >> y >> w;
        long double dis = f(x,y,0,0);
        if(dis - w >= R and dis + w <= r){
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}

