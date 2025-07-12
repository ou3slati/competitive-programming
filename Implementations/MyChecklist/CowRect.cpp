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

void IO2(){
#ifndef ONLINE_JUDGE 
    freopen("cowrect.in", "r", stdin); 
    freopen("cowrect.out", "w", stdout); 
#endif 
}


int N;
vector <pair<pi,int>> vec;

int32_t main(){
   boost;
   IO();

   cin>>N;
   for(int i=0; i<N; i++){
   	int x,y; char t; cin>>x>>y>>t;
   	int ty=0; if(t=='G') ty=1;
   	vec.pb({{y,ty},x});
   }
   sort(all(vec));

   for(int i=0; i<N; i++){
   		int xx=vec[i].se;
   		vec[i].se=vec[i].fi.se;
   		vec[i].fi.se=xx;
   }

   for(auto x: vec) cout << x.fi.fi  << ' ' << x.fi.se << ' ' << x.se << endl;

   int ans=1,surface=INF;

   int prev=-1;
   for(int i=0; i<N; i++)if(vec[i].se==0 && vec[i].fi.fi!=prev){ //Bottom edge chosen
   		prev=vec[i].fi.fi;
	   	multiset<int> chosen;
	   	int L=-INF,R=INF; // limits
	   	int YB=vec[i].fi.fi,YU=0;

	   	for(int j=0; j<N; j++) if(vec[j].fi.fi>=vec[i].fi.fi){

	   		bool yh=false;
	   		if(j<N-1 && vec[j+1].fi.fi==vec[j].fi.fi) yh=true;


	   		if(vec[j].se==1){

	   			//update range and delete from set those out of range
	   			if(vec[j].fi.fi>vec[i].fi.fi) R=min(R,vec[j].fi.se-1);
	   			else L=max(L,vec[j].fi.se+1); 
	   			
	   			while(!chosen.empty() && *(chosen.begin())<L) 
	   				chosen.erase(chosen.begin());
	   			while(!chosen.empty()){
	   				auto it=chosen.end(); it--;
	   				if(*it<=R) break;
	   				chosen.erase(it);
	   			}
	   		}
	   		else{
	   			//insert if in range
	   			int x=vec[j].fi.se;
	   			if(x>=L && x<=R){
	   				YU=max(YU,vec[j].fi.fi);
	   				chosen.insert(x);
				}
	   		}


		   	if(ans<sz(chosen) && !yh){
		   		ans=sz(chosen);
		   		auto it=chosen.begin();
		   		int XL=*it;
		   		it=chosen.end();it--;
		   		int XR=*it;

		   		surface=(YU-YB)*(XR-XL);
		   		if(ans==2)cout << XL << ' ' << XR << ' ' << YB << ' ' << YU << endl;
	   			
		   	}
		   	else if(ans==sz(chosen) && !yh){
		   		auto it=chosen.begin();
		   		int XL=*it;
		   		it=chosen.end(); it--;
		   		int XR=*it;
		   		surface=min(surface,(YU-YB)*(XR-XL));

		   	}

		   	//cout << YB << ' ' << YU << ' '; cout << endl;// << XB << ' ' << XU<< end
	   	}

   	
   }

   cout << ans << endl;
   cout << surface << endl;

   return 0;
}

