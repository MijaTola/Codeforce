#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

typedef vector<string> vs;

int main(){

	map<string,vs> data;
	int n;
	cin >> n;
	string email;
	for (int i = 0; i < n; ++i)
	{
		cin >> email;
		string aux = email;
		transform(aux.begin(), aux.end(),aux.begin() , ::tolower);
		string login = "";
		string domain = "";
		bool sw = false;
		bool swd = false;
		for (int j = 0; j < aux.size(); ++j)
		{
				if(aux[j] == '+') sw = true;
				if(aux[j] == '@'){ 
					swd = true;
					sw = true;
					login += aux[j];
				}
				if(!sw){ 
					if(aux[j] == '.') continue; 
					login += aux[j];
				}
				if(swd){	
					if(aux[j] == '@') continue;
					domain += aux[j];
				}
		}
		if(domain == "bmail.com"){
		aux = login + domain;
		data[aux].push_back(email);
		}else{
			data[email].push_back(email);
		}
	}
	cout << data.size() << endl;
	for (map<string,vs>::iterator i = data.begin(); i != data.end(); ++i)
	{
		cout << i->second.size()<<" ";
		for (int j = 0; j < i->second.size(); ++j	)
		{
			cout << i->second[j]<<" ";
		}
		cout << endl;
	}
	return 0;
}
