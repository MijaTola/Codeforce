#include <bits/stdc++.h>

using namespace std;

int f(char x){
    if(x == '^') return 0;
    if(x == '>') return 1;
    if(x == 'v') return 2;
    if(x == '<') return 3;
}
int main(){
    char x,y;
    long long u;
    cin >> x >> y >> u;
    u = u % 4;
    int dx = f(x) ,dy = f(y);
    bool xx,yy;
    xx = yy = false;
    if((dx + u)%4 == dy) xx = true;
    if((dx - u + 4) % 4 == dy) yy = true;
    if(xx and !yy) puts("cw");
    else if(!xx and yy) puts("ccw");
    else puts("undefined");
    return 0;
}

