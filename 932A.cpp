#include <bits/stdc++.h>

using namespace std;

int main(){
    
    string x; cin >> x;
    string t = x;
    reverse(t.begin(),t.end());
    cout << x + t << "\n";
    return 0;
}

