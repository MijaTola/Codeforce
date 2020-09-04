#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,p,l,r;

    scanf("%d %d %d %d",&n,&p,&l,&r);


    int ans1 = 0;
    
    int pp = p;
    if(l != 1) {
        ans1 += abs(p - l);
        p = l;
        ans1++;
    }
    if(r != n) {
        ans1 += abs(p - r);
        ans1++;
    }
    
    
    int ans2 = 0;
    p = pp;
    if(r != n) {
        ans2 += abs(p - r);
        ans2++;
        p = r;
    }
    if(l != 1) {
        ans2 += abs(p - l);
        ans2++;
    }

    printf("%d\n", min(ans1,ans2));
    return 0;
}

