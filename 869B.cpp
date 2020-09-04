#include <bits/stdc++.h>

using namespace std;



int main(){
    
    long long a,b;
    
    cin >> a >> b;

    long long fa = 1, fb = 1;

    for (int i = 1; i <= a; ++i)
        fa = (fa * i) ;
    for (int i = 1; i <= b; ++i)
        fb = (fb * i) ;
    cout << fb << " " << fa <<  " " << fb / fa << "\n";
    return 0;
}

