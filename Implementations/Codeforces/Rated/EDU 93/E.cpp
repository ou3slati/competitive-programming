//Never stop trying
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
#define int ll
typedef double db;
typedef long double ld;

typedef pair<int,int> pi;
#define fi first
#define se second

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;

#define pb push_back
#define eb emplace_back
#define pf push_front

#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define endl "\n"

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0}; //right left down up

void IO(){
#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
#endif 
}

int32_t main(){
   boost;
   IO();
	
	int Q; cin>>Q;
	set <int> c;
	set <int> nc;
	set <int> ncs;
	set <int> cs;
	
	int waitlist=0;

	int ans=0;

	
	while(Q--){
		int t,x; cin>>t>>x;
		ans+=x;

		if(t==1 && x>0){
			if(!nc.empty()){
				auto it=nc.end();
				it--;
				ans+=*it;
				c.insert(*it);
				if(ncs.count(*it)){
					cs.insert(*it);
					ncs.erase(*it);
				}
				nc.erase(*it);
			}
			else waitlist++; // not used
			nc.insert(x);
		}
		else if(t==0 && x>0){
			nc.insert(x);
			ncs.insert(x);
			if(waitlist>0){
				ans+=x;
				c.insert(x);
				cs.insert(x);
				nc.erase(x);
				ncs.erase(x);
				waitlist--;
			}
		}
		else if(t==0){
			x=abs(x);
			if(c.count(x)){
				ans-=x;
				c.erase(x);
				cs.erase(x);
				
				if(!ncs.empty()){
					auto it=ncs.end();
					it--;
					ans+=*it;
					//for(auto x: ncs) cout << x << ' ';
					c.insert(*it);
					cs.insert(*it);
					nc.erase(*it);
					ncs.erase(*it);
				}
			}
			else{
				nc.erase(x);
				ncs.erase(x);
			}
		}
		else{
			x=abs(x);
			c.erase(x); nc.erase(x);
			if(waitlist){
				waitlist--;
			}
			else{
				if(!c.empty()){
					auto it=c.begin();
					ans-=*it;
					nc.insert(*it);
					if(cs.count(*it)){
						cs.erase(*it);
						ncs.insert(*it);
					}
					c.erase(*it);
				}
			}
			
			
		}
		cout << ans << endl;
		//for(auto x: ncs) cout << x << ' '; cout << endl << endl;
	}

   return 0;
}

