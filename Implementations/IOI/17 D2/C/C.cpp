#include "books.h"
#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef vector<int>vi; 
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)


typedef pair<int,int>pi;
#define fi first
#define se second
typedef vector<pi>vpi;
#define eb emplace_back

#define FOR(i,a,b) for(int i=a; i<b; i++)
#define ROF(i,a,b) for(int i=b-1; i>=a; i--)

//--------------------------------

bool ckmin(int &x, int y){
	if(x<=y) return 0;
	x=y; return 1;
}

const int MX=1e6+5;
int N; 
vi a;

ll minimum_walk(vi p, int s){
	N=sz(p);
	a.resize(N);
	FOR(i,0,N) a[i]=i+1;

	//for(auto x: a) cout << x << ' ';
	//cout << endl;
	
	vi ans(N);
	FOR(i,0,N) ans[p[i]]=i+1;

	//for(auto x: ans) cout << x << ' ';
	//cout << endl;
	
	priority_queue<pair<int,pair<vi,int>>,vector<pair<int,pair<vi,int>>>,greater<pair<int,pair<vi,int>>>>q;
	q.push({0,{a,s}});
	
	map<pair<vi,int>,int>dist;
	dist[{a,s}]=0;

	while(!q.empty()){
		int d=q.top().fi,pos=q.top().se.se;
		vi v=q.top().se.fi; 
		q.pop();

		//if(v==ans && pos==s) cout << "here" << endl;

		if(!dist.count({v,pos})) dist[{v,pos}]=1e8;
		if(d>dist[{v,pos}]) continue;

		if(pos+1<N && (!dist.count({v,pos+1}) || ckmin(dist[{v,pos+1}],d+1))){
			dist[{v,pos+1}]=d+1;
			q.push({dist[{v,pos+1}],{v,pos+1}});
		}
		if(pos-1>=0 && (!dist.count({v,pos-1}) || ckmin(dist[{v,pos-1}],d+1))){
			dist[{v,pos-1}]=d+1;
			q.push({dist[{v,pos-1}],{v,pos-1}});
		}

		vi vis(N+1,0);
		for(auto x: v) vis[x]=1;
		int cur;
		FOR(i,0,N+1) if(!vis[i]) cur=i;

		swap(v[pos],cur);

		/*for(auto x: v) cout << x << ' ';
			cout << endl;*/

		if(!dist.count({v,pos}) || ckmin(dist[{v,pos}],d)){
			dist[{v,pos}]=d;
			q.push({dist[{v,pos}],{v,pos}});
		}
	}

	return dist[{ans,s}];
}

/*

4 0
0 2 3 1

*/