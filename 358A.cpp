#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll x[10000];
int main(){
	int n; cin>>n;
  for (int i=0; i<n; i++) cin>>x[i];

  for (int i=0; i+1<n; i++){
    for (int j=0; j+1<n; j++){
      if (i==j) continue;

      ll a=x[i],b=x[i+1],c=x[j],d=x[j+1];
      if (b<a) swap(a,b);
      if (d<c) swap(c,d);

      if (c<a && a<d and (b<c || d<b)) {cout<<"yes"<<endl;return 0;}
    }
  }

  cout<<"no"<<endl;
	return 0;
}