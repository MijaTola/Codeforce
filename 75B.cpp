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
#include <string>
using namespace std;

typedef long long ll;

string v[10];

int split(string x){
    int pos = 0;
    string word = "";
    for (int i = 0; i < (int)x.size(); ++i){
        if(x[i] == ' '){ v[pos] = word; word = ""; pos++;}
        else word += x[i];
    }
    v[pos] = word; pos++;
    return pos;
}
string build(string x){
    return x.substr(0,x.size()-2);
}
map<string,int> mp;
struct cmp{
    bool operator ()(const pair<string,int> a,pair<string,int> b ){
        if(a.second == b.second) return a.first > b.first;
        return a.second < b.second;
    }
};
int main(){
    
    string you; cin >> you;
    int n; cin >> n;
    cin.ignore();
    for (int i = 0; i < n; ++i){
        string s;
        getline(cin,s);
        split(s); 
        int value;
        string y;
        string x = v[0];
        if(v[1] == "likes"){
            y = build(v[2]);
            value = 5;
        }
        if(v[1] == "commented"){
                y = build(v[3]);
                value = 10;
            }
        if(v[1] == "posted"){
                y = build(v[3]);
                value = 15;
        }
        if(x == you) mp[y] += value;
        else mp[x];
        if(y == you) mp[x] += value;
        else mp[y];
    }
    priority_queue< pair<string,int>, vector< pair<string, int > >,cmp> q;
    for (pair<string,int> u: mp){
        if(u.first == you) continue;
        q.push({u.first,u.second});
    }
    while(!q.empty()){
        cout << q.top().first << endl; q.pop();
    }
    return 0;
}

