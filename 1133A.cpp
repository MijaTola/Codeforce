#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int h1,h2,m1,m2;
    scanf("%d:%d",&h1,&m1);
    scanf("%d:%d",&h2,&m2);
    
    int total1 = h1 * 3600 + m1 * 60;
    int total2 = h2 * 3600 + m2 * 60;
    int mid = (total2 - total1) / 2;
    
    int ans = total1 + mid;
    int h = ans / 3600;
    int m = (ans % 3600) / 60;
    if(h < 10) cout << "0"<< h << ":";
    else cout << h << ":";
    if(m < 10) cout << "0"<< m << "\n";
    else cout << m << "\n";
    return 0;
}

