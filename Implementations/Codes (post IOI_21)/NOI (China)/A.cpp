#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef string str; 
typedef vector<int>vi; 
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)

#define FOR(i,a,b) for(int i=a; i<b; i++)

void IO(){
#ifdef LOCAL
	freopen("input.txt","r",stdin); 
	freopen("output.txt","w",stdout);
#endif
}

//-------------------------

bool check(char c){
	return (c>='A' && c<='Z') || (c>='a' && c<='z') || (c>='0' && c<='9'); 
}

map<str,bool>vis; 
map<str,str>mp; 

void expand(str s){
	int idx=0; 
	while(idx<sz(s)){
		if(!check(s[idx])){
			cout << s[idx]; 
			idx++; 
			continue;  
		}

		str cur; 
		while(idx<sz(s) && check(s[idx])){
			cur+=s[idx]; 
			idx++; 
		}
		//cerr << cur << endl;
		if(mp.count(cur) && (!vis.count(cur) || !vis[cur])){
			vis[cur]=1; 
			expand(mp[cur]);
			vis[cur]=0;  
		} 
		else cout << cur;
	}
}

int main(){
	IO(); 

	int N; cin>>N;
	cin.ignore();  

	
	FOR(i,0,N){
		str s;  
		getline(cin,s); 

		if(!sz(s)){ cout << endl; continue; } 
		
		if(s[0]=='#'){
			int idx=0; 
			while(s[idx]!=' ') idx++; 
			idx++; 

			if(s[1]=='d'){
				str key, val;
				while(s[idx]!=' '){ key+=s[idx]; idx++; }
				idx++; 
				while(idx<sz(s)){ val+=s[idx]; idx++; } 

				mp[key]=val;  
			}
			else{
				str key;
				while(idx<sz(s)){ key+=s[idx]; idx++; }
				mp.erase(key); 
			}

			cout << endl;
		}
		else{

			expand(s); 

			
			cout << endl;
		}
	}
}