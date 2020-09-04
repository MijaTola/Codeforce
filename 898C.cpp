#include <bits/stdc++.h>

using namespace std;

struct node{
    map<char,node*> t;
    int key;
    bool end;
    node(int k){key = k;end = false;}
};

vector<string> b;
struct trie{
    node* root;
    int sz;
    trie(){sz = 0; root = new node(sz);}

    void insert(string pattern){
        node* copy = root;
        for (int i = pattern.size() - 1; i >= 0; i--){
            char v = pattern[i];
            if(copy->t[v] == NULL)
                copy->t[v] = new node(++sz);
            copy = copy->t[v];
        }
    }
    void dfs(node* v,string ans){
        if(v == NULL) return;
        bool found = 0;
        for (int i = 0; i < 10; ++i){
            if(v->t[i+'0'] != NULL){
                found = 1;
                dfs(v->t[i+'0'], ans + (char)(i + '0'));
            }
        }
        if(!found) {
            reverse(ans.begin(),ans.end());
            b.push_back(ans);
        }
    }
    void print(){dfs(root, "");}
};

map<string,trie> mp;
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;

    for (int i = 0; i < n; ++i) {
        string x;
        int t;
        cin >> x >> t;
        for (int j = 0; j < t; ++j) {
            string number; cin >> number;
            mp[x].insert(number);
        }
    }

    cout << mp.size() << "\n";
    for (pair<string,trie> tries: mp) {
        cout << tries.first << " ";
        b.clear();
        tries.second.print();
        cout << b.size() << " ";
        for (string x: b) cout << x << " ";
        cout << "\n";
        
    }
    return 0;
}

