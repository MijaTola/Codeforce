#include <bits/stdc++.h>

using namespace std;
 
int a[110000];
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n,k;
        string s;
        cin >> n >> k >> s;
        int ans=0;
        int last=-1;
        vector<int>v;
        int sz=0;
        for(int i=0;i<(int)s.size();++i) {
            if(s[i]=='W') {
                if(i and s[i-1]=='W') ans+=2;
                else {
                    if(last!=-1) v.push_back(i-last-1);
                    ans++;
                }
                last=i;
                sz++;
            }
        }
        if(!sz) {
            cout<<max(0,2*(k-1)+1)<<'\n';
            continue;
        }

        sort(v.begin(),v.end());

        for(auto &it:v) {
            if(k>=it) ans+=2*it+1,k-=it;
            else {
                ans+=2*k;
                k=0;
                break;
            }
        }
        int p1=0;
        while(s[p1]=='L') p1++;
        ans+=min(k,p1)*2;
        k=max(0,k-p1);
        int p2=n-1,len=0;;
        while(s[p2]=='L') p2--,len++;
        ans+=min(k,len)*2;
        cout<<min(ans,2*(n-1)+1)<<'\n';
    }
    return 0;
}
