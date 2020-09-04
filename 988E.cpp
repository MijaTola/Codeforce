#include <bits/stdc++.h>

using namespace std;

int v[10];
int main(){
    
    string s;
    cin >> s;

    for (char x: s) 
        v[x - '0']++;
    
    return 0;
}



