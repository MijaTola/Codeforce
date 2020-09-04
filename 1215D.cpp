#include <bits/stdc++.h>

using namespace std;

int n;
string s;
int main() {
    cin >> n >> s;

    int l = 0, r = 0;
    int left = 0, right = 0;
    for (int i = 0; i < n / 2; ++i) 
        if(s[i] != '?') l += (s[i] - '0');
        else left++;

    for (int i = n / 2; i < n; ++i) 
        if(s[i] != '?') r += (s[i] - '0');
        else right++;

    int curl = (left + 1) / 2;
    int curr = (right + 1) / 2;
    
    if(curl * 9 + l != curr * 9 + r) return cout << "Monocarp\n",0;
    else cout << "Bicarp\n";
    
    return 0;
}

