#include "shoes.h"
#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef vector<int>vi; 
typedef string str;

#define pb push_back
#define sz(v) (int)v.size()

#define FOR(i,a,b) for(int i=a; i<b; i++)
//-------------------------------------------------


const int MX=2e5+10;
vi t(MX,0);	

void upd(int i){ i++;
	for(;i<MX; i+=i&-i) t[i]++;
}

int get(int i){ i++;
	int ans=0;
	for(;i;i-=i&-i) ans+=t[i];
	return ans; 
}

ll count_swaps(vi s) {
	int N=sz(s)/2;
	deque<int> neg[N+1],pos[N+1],p(N*2);
	FOR(i,0,N*2){
		if(s[i]<0){	
			if(sz(pos[-s[i]])){
				p[i]=pos[-s[i]][0];
				p[p[i]]=i;
				pos[-s[i]].pop_front();
			}
			else neg[-s[i]].pb(i);
		}else{
			if(sz(neg[s[i]])){
				p[i]=neg[s[i]][0];
				p[p[i]]=i;
				neg[s[i]].pop_front();
			}
			else pos[s[i]].pb(i);
		}
	}

	vi done(N*2,0);
	ll ans=0;
	FOR(i,0,N*2) if(!done[i]){
		int j=p[i];
		ans+=(j-i-1)-(get(j)-get(i))+(s[i]>0);
		upd(j);

		done[j]=1;
	}
	return ans; 
}
