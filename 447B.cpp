#include <bits/stdc++.h>

using namespace std;
int k;
string s;
int w[30];
int a[10005];
int t = -1;
int ans;
int main()
{
    cin>>s;
    cin>>k;
    for(int i=0;i<26;i++){
    	cin>>w[i];
    	t=max(t,w[i]);
    }
    for(int i=0;i<s.size();i++)
        a[i+1]=w[s[i]-'a'];
    
    for(int i=1;i<=s.size();i++)
        ans+=i*a[i];
    
    for(int i=s.size()+1;i<=s.size()+k;i++)
    	ans+=t*i;
    cout<<ans<<endl;
    return 0;
}
