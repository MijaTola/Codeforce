#include <iostream>
#include <cstring>
using namespace std;

const int mod = 1e9+7;
string s;
int n,m;
int o,c;
int f(int sz, int open){
    if(sz == 0){
        if(open == 0) return 1;
        return 0;
    }
    int ans = 0;
    ans = (ans+f(sz-1,open+1))%mod;
    if(open) ans = (ans + f(sz-1,open-1))%mod;
    return ans;
}
int main(){
	cin >> n >> m;
	cin >> s;
    c = 0;
    for (int i = 0; i < (int)s.size(); ++i){
        if(s[i] == '(') o++;
        else{
            if(o)o--;else c++;
        }
    }
    
    int sz = n-m;
    int ans = 0;
    for (int i = 0; i < sz; ++i){
        int l = f(sz-i,c-i);
        int r = f(sz-i,o);
        ans += (l*r)%mod;
    }
    cout << ans << "\n";
	return 0;
}
