#include <bits/stdc++.h>

using namespace std;

char s[1000010];
vector<int> l;
vector<int> r;
int main(){
    scanf("%s",s);

    int sz = strlen(s);
    
    
    for (int i = 0; i < sz; ++i){
        if(s[i] == 'l') l.push_back(i+1);
        else r.push_back(i+1);
    }
    for (int i = 0; i < (int)r.size(); ++i)
        printf("%d ",r[i]);
    for (int i = l.size() - 1; i >= 0; --i)
        printf("%d ",l[i]);

    puts("");
    return 0;
}

