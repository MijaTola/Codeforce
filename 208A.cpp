#include <iostream>
#include <string>
using namespace std;
string s;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> s;
	for (int i=s.size()-3;i>=0;i--)if (s.substr(i,3)=="WUB"){
		s.erase(s.begin()+i,s.begin()+i+3);
		s.insert(s.begin()+i,' ');
	}
	for (int i=s.size()-1;i>=0;i--)if (s[i]==' '&&(i==s.size()||s[i+1]==' '))s.erase(s.begin()+i);
	while (s.size()&&s[0]==' ')s.erase(s.begin());
	cout << s << endl;
	return 0;
}
