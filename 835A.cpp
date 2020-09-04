#include <bits/stdc++.h>

using namespace std;

int main(){
     
    int d,v1,v2,t1,t2;
    cin >> d >> v1 >> v2 >> t1 >> t2;
    
    int f = d*v1 + 2*t1;
    int ss = d*v2 + 2*t2;
    if(f < ss) puts("First");
    else if(ss < f)puts("Second");
    else puts("Friendship");
    return 0;
}

