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
#include <unordered_set>
#include <unordered_map>

using namespace std;

int da[1000010];
int db[1000010];

int main(){
    
    string x; cin >> x;
    
    long long a,b; cin >> a >> b;
    da[0] = ( (x[0] - '0') % a);
	for(int i = 1; i < (int)x.size();i++){
		da[i] = (da[i - 1] * 10LL + (x[i] - '0') ) % a;
	}
	db[x.size() - 1] = ( (x[x.size()-1] - '0') % b);
	
    long long p = 10LL % b;
	
    for(int i = x.size() - 2; i >= 0; i--){ db[i] = ( (p * (x[i] - '0' ) % b ) + db[i + 1]) % b;
		p *= 10LL;
		p %= b; 
	}
    
    for (int i = 0; i < (int)x.size()-1; ++i){
        if(!da[i] and !db[i+1] and x[i+1] != '0'){
            cout << "YES\n";
            for (int j = 0; j <= i; ++j) cout << x[j];
            cout << "\n";
            for (int j = i+1; j < (int)x.size(); ++j)
                cout << x[j];
            cout << "\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}

