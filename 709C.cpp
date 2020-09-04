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

string x;
int main(){
    cin >> x;
    int id = -1;
	for (int i = 0; i < x.size(); ++i){
		if(x[i] != 'a'){
			id = i;
			break;
		}
	}
	if(id == -1) x[x.size()-1] = 'z';
	else{
		for (int i = id; i < x.size() and x[i] != 'a'; ++i) x[i]--;
	}
	cout << x << endl;
	return 0;
}

