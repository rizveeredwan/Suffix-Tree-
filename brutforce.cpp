#include <bits/stdc++.h>
using namespace std;
#define MAX 500
#define MAX_SKIP 3

map<string,int>M;
map<int,string>M_rev; 
int cnt;
vector<int>occurence_vector[MAX+1];

void generate(string s,int idx, int start, int end,int skip_cnt,int max_skip,vector<char>V){
	if(idx>end) {
		if(skip_cnt != 0) {
			string temp="";
			for(int i=0;i<(int)V.size();i++){
				temp=temp+V[i];
			}
			if(M[temp] ==0) {
				cnt++;
				M[temp] = cnt;
				M_rev[cnt]=temp;
			}
			occurence_vector[M[temp]].push_back(start);
		}
		return;
	}
	//without skip
	V.push_back(s[idx]);
	string temp="";
	for(int i=0;i<(int)V.size();i++){
		temp=temp+V[i];
	}
	if(M[temp] == 0) {
		cnt++;
		M[temp]=cnt; 
		M_rev[cnt]=temp; 
	}
	occurence_vector[M[temp]].push_back(start);
	generate(s,idx+1,start,end,0,max_skip,V);
	V.pop_back();
	
	//with skip 
	if((skip_cnt+1)<=max_skip){
		V.push_back('*');
		temp="";
		for(int i=0;i<(int)V.size();i++){
			temp=temp+V[i];
		}
		/*if(M[temp] == 0) {
			cnt++;
			M[temp]=cnt; 
			M_rev[cnt]=temp; 
		}*/
		//occurence_vector[M[temp]].push_back(start);
		generate(s,idx+1,start,end,skip_cnt+1,max_skip,V);
		V.pop_back();
	}
	return;
	
}

void func(string s){
	cnt=0; 
	for(int i=0;i<(int)s.size();i++){
		vector<char>V;
		V.push_back(s[i]);
		string temp="";
		temp = temp + s[i];
		if(M[temp] == 0) {
			cnt++;
			M[temp] = cnt;
			M_rev[cnt]=temp;
		}
		occurence_vector[M[temp]].push_back(i);
		generate(s,i+1,i,s.size()-1,0,MAX_SKIP,V);
	}
	cout<<cnt<<endl;
	for(int i=1;i<=cnt;i++){
		cout<<M_rev[i]<<endl;
	}
}


int main(void){
	string s;
	cin>>s;
	func(s);
}
