#include <bits/stdc++.h>

using namespace std;

map<string,int> mp;
string get(long long u) {
    string x = "";
    while(u > 0) {
        int y = u % 10;
        u /= 10;
        char z = '0';
        if(y & 1) z = '1';
        x += z;
    }
    reverse(x.begin(),x.end());
    while(x.size() <= 18) {
        x = '0' + x;
    }
    return x;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while(t--) {
         char c;
         long long x;
         cin >> c >> x;
         string cur = get(x);
         if(c == '+') mp[cur]++;
         if(c == '-') mp[cur]--;
         if(c == '?') cout << mp[cur] << "\n";
   }
    return 0;
}

