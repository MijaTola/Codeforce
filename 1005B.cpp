#include <bits/stdc++.h>

using namespace std;

int main(){
    
    string x,y;
    cin >> x >> y;
    int dx = x.size() - 1;
    int dy = y.size() - 1;
    while(x[dx] == y[dy] and dx >= 0 and dy >= 0) dx--,dy--;
    
    int xx = x.size() - dx - 1;
    int yy = y.size() - dy - 1;
    int a = x.size() - xx;
    int b = y.size() - yy;
    cout << a + b << "\n";
    return 0;
}

