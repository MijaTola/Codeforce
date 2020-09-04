#include <bits/stdc++.h>

using namespace std;

string s;
int a[27];
int main(){
    int n,k;
    cin >> n >> k;
    cin >> s;

    for (int i = 0; i < (int)s.size(); ++i)
        a[s[i] - 'a']++;

    for (int i = 0; i < 27; ++i){
        if(a[i] > k) return puts("NO");
    }
    puts("YES");

    return 0;
}

