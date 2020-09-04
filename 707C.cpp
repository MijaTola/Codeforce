#include <bits/stdc++.h>


using namespace std;

typedef unsigned long long ll;

int main(){
    ll x,y,z; cin >> x;

    if(x&1){
        y = (x*x+1)/2;
        z = (x*x-1)/2;
    }else{
        y = (x/2)*(x/2)-1;
        z = (x/2)*(x/2)+1;
    }
    if((x*x == y*y+z*z or y*y == x*x+z*z or z*z == x*x + y*y) and x and y and z) cout << y << " " << z << endl;
    else cout << -1 << endl;
    return 0;
}

