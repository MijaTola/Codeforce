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

vector<int> a; //y
vector<int> b; //n
int v[100];
int letter,n,k;
void yes(int l, int r){
    int p = 0;
    for (int j = l; j < r-1; ++j)
        p = max(p,v[j]);
    v[r-1] = p+1;
}

void no(int l, int r){
    v[r-1] = v[l];
}

void print(){
    for (int i = 0; i < n; ++i){
        if(v[i] < 26) cout << (char)(v[i]+'A') << " ";
        else cout << "A" << (char)((v[i])%26+'a') << " ";       
    }

}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    memset(v,-1,sizeof v);
    cin >> n >> k;
    letter = 0;
    for (int i = 0; i < k; ++i)
        v[i] = i;
    for (int i = 0; i < n-k+1; ++i){
        string x; cin >> x;
        if(x=="YES") yes(i,i+k);
        if(x=="NO") no(i,i+k);
    }
    print();
    return 0;
}

