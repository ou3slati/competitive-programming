#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int>vi;
#define pb push_back
#define sz(v) (int)v.size()
#define all(x) begin(x),end(x)

#define dbgv(v) for(auto x: v) cerr << x << ' '; cerr << endl;

#define FOR(i,a,b) for(int i=a; i<b; i++)
#define ROF(i,a,b) for(int i=b-1; i>=a; i--)

const int nx[4]={-1,0,1,0},ny[4]={0,1,0,-1};

void IO(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
}

//-----------------------------------------------//

void ckmax(int &x, int y){
	x=max(x,y);
}

const int MX=2e5+10;

int N;
vi a(MX);

bool cmp(int i, int j){
	return a[i]>a[j];
}

vi t(MX*4);
void build(int pos=1, int l=0, int r=N-1){
	if(l==r){
		t[pos]=a[l];
		return; 
	}

	int m=(l+r)/2;
	build(pos*2,l,m);
	build(pos*2+1,m+1,r);
	t[pos]=max(t[pos*2],t[pos*2+1]);
}

int get(int l, int r, int pos=1, int tl=0, int tr=N-1){
	if(l>r) return -1e9;
	if(l==tl && r==tr) return t[pos];

	int tm=(tl+tr)/2;
	return max(get(l,min(r,tm),pos*2,tl,tm),
		get(max(l,tm+1),r,pos*2+1,tm+1,tr));
}

int main(){
	IO();

	cin>>N;
	FOR(i,0,N) cin>>a[i];

	build();

	vi vec(N); iota(all(vec),0);
	sort(all(vec),cmp);

	int Q; cin>>Q>>Q>>Q;

	const int B=20;
	int ans=0;
	FOR(idx,0,min(sz(vec),B)){
		int i=vec[idx];

		//left
		FOR(j,i+1,N){
			ckmax(ans,a[i]+a[j]+get(2*j-i,N-1));
		}

		//mid

		FOR(j,0,i){
			ckmax(ans,a[i]+a[j]+get(2*i-j,N-1));
		}

		//right

		FOR(j,0,i){
			ckmax(ans,a[i]+a[j]+get(max(0,2*j-i),j-1));
		}
	}

	cout << ans << endl;
}