#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    scanf("%d", &t);
    while(t--) {
        int d;
        scanf("%d", &d);
        int delta = d * (d - 4);
        if(delta < 0) puts("N");
        else {
            double b = (d - sqrt(delta)) / 2;
            double a = d - b;
            printf("Y %.10f %.10f\n", a, b);
        }
    }
    return 0;
}

