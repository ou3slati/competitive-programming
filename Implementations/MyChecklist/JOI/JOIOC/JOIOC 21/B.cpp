#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int>vi; 
#define pb push_back
#define sz(v) (int)v.size()
#define all(x) begin(x),end(x)

typedef pair<int,int>pi;
#define fi first
#define se second
typedef vector<pi>vpi;
#define eb emplace_back

#define FOR(i,a,b) for(int i=a; i<b; i++)
#define ROF(i,a,b) for(int i=b-1; i>=a; i--)

void IO(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
}
//---------------------------------------------------//

const int MX=3e5;
void ckmax(int &x, int y){x=max(x,y);}

int N,D; 
vi a(MX);


//--------------------------------------
const int INF=1e9;
vi t(MX*4,-INF);

void upd(int i, int v, int pos=1, int tl=0, int tr=N-1){
	if(tl==tr){
		t[pos]=v; 
		return; 
	}

	int tm=(tl+tr)/2;
	if(i<=tm) upd(i,v,pos*2,tl,tm);
	else upd(i,v,pos*2+1,tm+1,tr);

	t[pos]=max(t[pos*2],t[pos*2+1]);
}

int get(int l, int r, int pos=1, int tl=0, int tr=N-1){
	if(l>r) return -INF;
	if(l==tl && r==tr) return t[pos];

	int tm=(tl+tr)/2;
	return max(get(l,min(r,tm),pos*2,tl,tm),
		get(max(l,tm+1),r,pos*2+1,tm+1,tr));
}
//------------------------------

bool cmp2(int i, int j){
	return a[i]<a[j];
}

vi lft(MX);
void precompute(){
	/*FOR(i,0,N){
		lft[i]=i;
		ROF(j,0,i) if(a[j]<a[i]){
			if(lft[i]-j>D) break;
			lft[i]=j; 
		}
	}
	return; */


	vi v(N); iota(all(v),0); sort(all(v),cmp2);

	vi l(N);
	set<int>s,ss; //present , l[i]>D  
	for(int i: v){

		//update l,ss & add to s
		auto it=s.upper_bound(i); 
		if(it==s.begin()){
			l[i]=INF;
			if(it!=s.end()){
				if(ss.count(*it)) ss.erase(*it);
				l[*it]=*it-i;
				if(l[*it]>D) ss.insert(*it);
			}
		}
		else{
			if(it!=s.end()){
				if(ss.count(*it)) ss.erase(*it);
				l[*it]=*it-i;
				if(l[*it]>D) ss.insert(*it);
			}

			it--;
			l[i]=i-*it;
		}

		if(l[i]>D) ss.insert(i);
		s.insert(i);

		//find lft
		lft[i]=i;
		auto itr=ss.upper_bound(i); 
		if(itr!=ss.begin()){
			itr--; 
			lft[i]=*itr; 
		}
	}
}

bool cmp(pi a, pi b){
	if(a.fi!=b.fi) return a.fi<b.fi; 
	return a.se>b.se;
}
int main() {
    IO();
    
    cin>>N>>D;
    FOR(i,0,N) cin>>a[i];

    vpi vec;
    FOR(i,0,N) vec.eb(a[i],i);
    sort(all(vec),cmp);
    int cnt=-1;
    FOR(i,0,N) a[vec[i].se]=++cnt; 


    precompute();

    vi v(N); iota(all(v),0); sort(all(v),cmp2);

    vi dp(N,1);
    for(int i: v){
    	ckmax(dp[i],get(lft[i],i)+1);
    	upd(i,dp[i]);
    }
    
    int ans=0;
    FOR(i,0,N) ckmax(ans,dp[i]);
    cout << ans << endl;

    return 0;
}
//Change your approach 