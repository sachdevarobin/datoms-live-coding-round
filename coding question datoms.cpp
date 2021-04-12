#include <bits/stdc++.h>
using namespace std;
int minLength(string a ,string b){
	map<char,int>Char;
	for(int i =0;i<b.length();i++){
		Char[b[i]]++;

	}
	map<char,vector<int>>CharIndex;
	for(int i=0;i<a.length();i++){
		char x = a[i];
		if(Char.find(x)!=Char.end()){
			CharIndex[x].push_back(i);
		}
	}
	int len = INT_MIN;
	int flag;
	while(true){
		flag=1;
		int firstval,lastvar;
		for(int i=0;i<b.length();i++){
			if(i==0){
				if(CharIndex.find(b[i])==CharIndex.end()){
					flag=0;
					break;

				}
				else{
					int x = *(
						CharIndex[b[i]].begin());

					CharIndex[b[i]].erase(CharIndex[b[i]].begin());
					firstval =x;
					lastvar=x;
				}
			}
			else{
				int elementFound=0;
				for(auto e : CharIndex[b[i]]){
					if(e>lastvar){
					elementFound=1;
					lastvar=e;
					break;
					}
				}
				if(elementFound==0)
				{	
					flag=0;
								break;
				}

			}
		}
		if(flag==0)
		{
			break;
		}
		len = min(len,abs(lastvar-firstval)+1);
	}
	return len;
}
int main(){
	string a,b;
	cin>>a>>b;
	int len = minLength(a,b);
	if(len!= INT_MAX)
		cout<<len<<endl;
	else{
		cout<<"does not exist"<<endl;
	}
}