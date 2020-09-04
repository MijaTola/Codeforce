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
#include <cstdlib>

using namespace std;

typedef long long ll;

int main(){
    string hate = "I hate";
    string love = "I love";
    int n; cin >> n;
    if(n&1){
        bool flag = false;
        while(n--){
            if(!flag){ cout << hate;flag = true;}
            else{ cout << love;flag = false;}
            if(n) cout << " that ";
        }
    }else{
        bool flag = false;
        while(n--){
            if(!flag){cout << hate; flag = true;}
            else {cout << love; flag = false;}
            if(n) cout << " that "; 
        }
    }
    cout << " it"<< endl;
    return 0;
}

