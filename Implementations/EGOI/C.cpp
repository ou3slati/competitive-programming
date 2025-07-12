#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef vector<ll>vi; 
#define pb push_back
#define sz(v) (int)v.size()
#define all(x) begin(x),end(x)


typedef pair<int,int>pi;
#define fi first
#define se second

#define FOR(i,a,b) for(int i=a; i<b; i++)
#define ROF(i,a,b) for(int i=b-1; i>=a; i--)

void IO(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
}

void ckmax(int &x, int y){x=max(x,y);}

//---------


int N;
ll order(vector<ll> vec){
	#ifdef LOCAL
	int i=rand()%sz(vec);
	return vec[i];
	#endif

	cout << "? ";
	for(ll x: vec) cout << x << ' ';
	cout << endl;
	cout.flush();

	ll x; cin>>x;
	return x; 
}
void answer(vector<ll> a, vector<ll>b){
	cout << "! " << sz(a) << ' ' << sz(b) << endl;
	for(ll x: a) cout << x << ' ';
	cout << endl;
	for(ll x: b) cout << x << ' ';
	cout << endl;
	cout.flush();
}

int main(){
	IO();

	cin>>N; 
	if(N==1){
		int x=order(vector<ll>{1});
		x=order(vector<ll>{2});
		x=order(vector<ll>{3});
		answer(vector<ll>{1,2},vector<ll>{3});
	}
	else if(N==2){
		vi vec; 
		for(int i=1; i<=10; i+=2){
			vec.pb(order(vector<ll>{i,i+1}));
		}

		int n=sz(vec);
		FOR(m,1,1<<n){
			FOR(m2,1,1<<n) if(m|m2==m+m2){
				int x=0,y=0;
				vector<ll> a,b; 
				FOR(i,0,n){
					if((m>>i)&1) x+=vec[i],a.pb(vec[i]);
					else if((m2>>i)&1) y+=vec[i],b.pb(vec[i]);
				}
				if(x==y){
					answer(a,b);
					return 0;
				}
			}
		}
	}
	else if(N<=1000){
		vi vec; 
		int n=101;
		for(int i=1; i<=n*N; i+=N){
			vi v; 
			FOR(j,i,i+N) v.pb(j);
			vec.pb(order(v));
		}

		FOR(i,0,n) FOR(j,i+2,n-1){
			if(vec[i]+vec[j+1]==vec[i+1]+vec[j]){
				vi a,b; 
				a.pb(vec[i]);
				a.pb(vec[j+1]);
				b.pb(vec[i+1]);
				b.pb(vec[j]);
				answer(a,b);
				return 0;
			}
		}

		FOR(i,0,n) FOR(j,0,n) if(j!=i) FOR(k,0,n) if(k!=j && k!=i){
			if(vec[j]+vec[k]==vec[i]){
				answer(vi{vec[j],vec[k]},vi{vec[i]});
			}
		}

		map<int,vi>mp;
		FOR(i,0,n) FOR(j,i+1,n){
			mp[vec[i]+vec[j]].pb(i);
			mp[vec[i]+vec[j]].pb(j);
		}
		for(auto it: mp){
			vi vec=it.se; 
			if(sz(vec)>=4){
				answer(vi{vec[0],vec[1]},vi{vec[2],vec[3]});
				return 0;
			}
		}
	}

	return 0;
}
