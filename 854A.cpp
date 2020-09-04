#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    int dm,nm;
    dm = nm = 0;
    for (int i = 1; i <= n; ++i){
        int a = i;
        int b = n - a;
        //cout << a << " " << b << endl;
        if(__gcd(a,b) == 1 and a < b){
            if(a > nm or b > dm){
                nm = a;
                dm = b;
            }
        }
    }
    printf("%d %d\n",nm,dm);
    return 0;
}

