#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int>vi;
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)

typedef string str; 

#define FOR(i,a,b) for(int i=a; i<b; i++)
#define ROF(i,a,b) for(int i=b-1; i>=a; i--)


void ckmin(int &x, int y){x=min(x,y);}
//------------------------------------


int main(){
	int N; cin>>N;

	if(N&1){
		cout << -1 << endl;
		return 0;
	}

	map<string,int>mp;
	int cnt=-1;
	vi nxt(N);
	FOR(i,0,N){
		str s,t; cin>>s>>t;
		if(!mp.count(s)) mp[s]=++cnt; 
		if(!mp.count(t)) mp[t]=++cnt; 
	
		int u=mp[s],v=mp[t];
		nxt[u]=v;
	}

	int ans=N;
	FOR(m,0,1<<N){
		int val=1;
		vi taken(N,0);
		FOR(i,0,N) if(!((m>>i)&1)){
			val&=((nxt[nxt[i]]==i && nxt[i]!=i) || (m>>nxt[i])&1 && !taken[nxt[i]]);
			taken[nxt[i]]=1;
		}
		if(val) ckmin(ans,__builtin_popcount(m));
	}
	cout << ans << endl;
}