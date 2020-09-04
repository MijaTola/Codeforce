#include <bits/stdc++.h>

using namespace std;

string s;

char v[] = {'Q','A','Q'};
int f(int pos, int k){

    if(pos == s.size()){
        if(k == 3) return 1;
        return 0;
    }
    if(k == 3) return 1;
    
    int ans = 0;
    if(s[pos] == v[k]) ans += f(pos+1,k + 1);
    ans += f(pos + 1, k);

    return ans;
}
int main(){
    cin >> s;
    cout << f(0,0) << "\n";
    return 0;
}

