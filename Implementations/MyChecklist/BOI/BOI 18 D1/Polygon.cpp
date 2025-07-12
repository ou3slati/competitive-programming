#include "bits/stdc++.h"
using namespace std; 

typedef long long ll;
typedef vector<int>vi;
#define pb push_back
#define sz(v) (int)v.size()
typedef string str;
#define FOR(i,a,b) for(int i=a; i<b; i++)

void IO(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
}
//------------------------------------------------------//

void ckmin(int &x, int y){x=min(x,y);}


const int MX=2e5;
int N;
vi out(MX),in(MX,0);
map<str,int>mp;

vi vis(MX,0);


int main(){
	IO();

	cin>>N;
	int cnt=0;
	FOR(i,0,N){
		str s,ss; cin>>s>>ss;
		if(!mp.count(s)) mp[s]=cnt++;
		if(!mp.count(ss)) mp[ss]=cnt++;

		out[mp[s]]=mp[ss];
		if(s!=ss) in[mp[ss]]++;
	}
	if(N&1){
		cout << -1 << endl;
		return 0;
	}

	FOR(i,0,N) if(out[i]!=i && out[out[i]]==i) vis[i]=1,vis[out[i]]=1;

	set<int>s;
	FOR(i,0,N) if(in[i]==0) s.insert(i);

	int ans=0;
	while(sz(s)){
		auto it=s.begin();
		int u=*it;
		s.erase(it);

		if(out[u]==u) continue;

		if(!vis[out[u]]){
			if(out[out[u]]!=out[u]){
				in[out[out[u]]]--;
				if(in[out[out[u]]]==0) s.insert(out[out[u]]);	
			}

			vis[u]=1; vis[out[u]]=1;
			out[out[u]]=u;
			ans++;
		}
	}


	FOR(i,0,N){
		int n=0,cur=i;
		while(!vis[cur]){
			vis[cur]=1; n++;
			cur=out[cur];
		}
		if(n!=2) ans+=(n+1)/2;
	}
	cout << ans << endl;
	
	
}
