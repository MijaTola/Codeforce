#include <bits/stdc++.h>

using namespace std;

int x[3];
int y[3];
int a[3];
int b[3];
int dx[1000010];
int dy[1000010];

int main() {
    
    for (int i = 0; i < 3; ++i)
        cin >> x[i] >> y[i] >> a[i] >> b[i];
   
    for (int i = 1; i < 3; ++i) {
        for (int j = x[i] ; j <= a[i]; ++j)
            dx[j]++;

        for (int j = y[i] ; j <= b[i]; ++j)
            dy[j]++;
    }
    int mn = 4; 
    for (int i = x[0]; i <= a[0]; ++i) {
        mn = min(dx[i], mn);
    }
    int mn2 = 3;
    for (int i = y[0]; i <= b[0]; ++i) {
        mn2 = min(dy[i], mn2);
    }
    if(!mn or !mn2) return cout << "YES\n",0;
    if(mn == 1 and mn2 == 1) return cout << "YES\n",0;
    cout<< "NO\n";
    return 0;
}

