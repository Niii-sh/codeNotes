/*
nt评测
我说怎么会没有标准答案 真的坑
*/

#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;

int n;

int convert(int ch){
	if(ch>='A' && ch<='Z')
		return ch-'A'+10;
	else
		return ch-'0';
}

int main(){
	cin>>n;
	
	vector<vector<int> >ans;
	
	while(n--){
		string s;
		cin>>s;
		
		int d=0;
		//先转换成10进制 
		for(int i=0;i<s.size();i++)
			d = d*16 + convert(s[i]);
		
		//转换成8进制 
		vector<int> tmp;
		while(d){
			tmp.push_back(d%8);
			d/=8;
		} 
		
		reverse(tmp.begin(),tmp.end());
		ans.push_back(tmp);
	}


	for(int i=0;i<ans.size()-1;i++){
		for(int j=0;j<ans[i].size();j++)
			cout<<ans[i][j];
		cout<<endl;
	}
	
	for(int j=0;j<ans[ans.size()-1].size();j++)
		cout<<ans[ans.size()-1][j];
		
	return 0;
}