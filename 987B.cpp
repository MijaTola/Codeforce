#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int x, y; cin >> x >> y;
    
    
    double dx = y * log(x);
    double dy = x * log(y);

    if(abs(dx - dy) < 0.001) cout << "=\n";
    if(dx > dy) cout << ">\n";
    if(dx < dy) cout << "<\n";

    return 0;
}

