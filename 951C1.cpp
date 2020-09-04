#include <bits/stdc++.h>
using namespace std;
string a, b;
map<char,int>mp;
long long solve( int idx, bool ok ){
    if( idx == (int)a.size() ){
        return 0;
    }
    if( ok ){
        for( char j = '9' ; j >= '0' ; j-- ){
            if( mp[j] ){
                mp[j]--;
                long long aux = solve(idx+1, true);
                if( aux != -1 ) return aux*10LL +(long long)(j-'0');
            }
        }
        return -1;
    }else{
        long long mn = LLONG_MAX;
        for( char j = b[idx] ; j >= '0' ; j-- ){
            if( mp[j] ){
                mp[j]--;
                if( j != b[idx] ) ok = true;
                long long aux = solve(idx+1, ok);
                if( aux != -1 ) return aux*10LL + (long long)(j-'0');
                ok = false;
                mp[j]++;
            }
        }
        return -1;
    }
}
int main(){
    cin >> a >> b;

    if( b.size() > a.size() ){
        sort( a.rbegin(), a.rend() );
        cout << a << '\n';
        return 0;
    }

    for( auto it: a ){
        ++mp[it];
    }
    int idx = 0;
    long long anx = solve(0, false);
    while( idx < (int)a.size() ){
        cout << anx%10LL;
        anx/=10LL;
        idx++;
    }
}
