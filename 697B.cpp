#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <climits>
#include <map>
#include <set>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <deque>
#include <string> 
#include <sstream>

using namespace std;

typedef long long ll;

int main(){
    string x; cin >> x;
    int pos = 0;
    string A = "";
    int coma = -1;
    while(x[pos] != 'e'){
        if(x[pos] == '.'){ coma = pos;pos++; continue;}
        A += x[pos];
        pos++;
    }
    if(coma == -1) coma = pos-1;
    pos++;
    int number = 0;
    //cout << A << endl;
    while(pos < (int)x.size()){
        number += int(x[pos]-'0');
        if(pos+1 < (int)x.size()) number *= 10;
        pos++;
    }
    coma += number;
    if((int)A.size() <= coma){
        bool flag = true;
        for (int i = 0; i < (int)A.size(); ++i){
            if(A[i] == '0' and flag) continue;
            flag = false;
            cout << A[i];
        }
        for (int i = (int)A.size(); i < coma; ++i)
            cout << 0;
        return 0;
    }
    pos = 0;
    bool flag = true;
    if(A[0] == '0'){ cout << A[0];}
    while(pos < coma){
        if(A[pos] == '0' and flag){
            pos++; continue;
        }
        flag = false;
        cout << A[pos];
        pos++;
    }
   string ans2 = "";
   pos = (int)A.size()-1;
   flag = true;
   while(pos >= coma){
        if(A[pos] == '0' and flag){
            pos--; continue;
        }
        flag = false;
        ans2 = A[pos]+ans2;
        pos--;
    }
    if(ans2.size() != 0) cout << "." << ans2 << endl;
    return 0;
}

