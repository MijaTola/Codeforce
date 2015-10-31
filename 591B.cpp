#include <iostream>
#include <map>
using namespace std;

int a[30];
int b[30];
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int n,d;
	char brand[200000];
	cin >>  n >> d;
	for (int i = 0; i < n; ++i)	cin >>  brand[i];
	
	for(int i=0;i<26;i++) a[i]=b[i]=i;
	for (int i = 0; i < d; ++i){
		char x,y;
		cin >> x >> y;
        if(x == y)continue;
        swap(a[b[x-'a']],a[b[y-'a']]);
       	swap(b[x-'a'],b[y-'a']);
	}
	string ans = "";
	for(int i=0;i<n;i++)
    {
        int d = (brand[i]-'a');
        ans += a[d]+'a';
    }
    cout << ans;
	return 0;
}
