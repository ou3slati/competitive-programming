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

const int MX=2e5;
int N; 
vi a(MX);

//------------------------------

int f[MX*4][3];
void compute(int pos=1, int tl=0, int tr=N-1){
	FOR(j,0,3) f[pos][j]=1;
	FOR(i,tl,tr+1){
		FOR(j,0,3) if(a[i]!=j) f[pos][j]=0;
	}

	if(tl==tr) return; 
	int tm=(tl+tr)/2;
	compute(pos*2,tl,tm);
	compute(pos*2+1,tm+1,tr);
}


//-----------------------------

struct node{
	int m=1,lazy=-1;
};

vector<node>t(MX*4);

node combine(node a, node b){
	return node{a.m&b.m,-1};
}
void push_down(int pos){
	int v=t[pos].lazy;
	if(v!=-1){
		t[pos*2].lazy=v;
		t[pos*2+1].lazy=v;

		t[pos*2].m=f[pos*2][v];
		t[pos*2+1].m=f[pos*2+1][v];

		t[pos].lazy=-1;
	}
}

void upd(int l, int r, int v, int pos=1, int tl=0, int tr=N-1){
	if(l>r) return; 
	if(l==tl && r==tr){
		t[pos].lazy=v; 
		t[pos].m=f[pos][v];
		return; 
	}

	push_down(pos);

	int tm=(tl+tr)/2;
	upd(l,min(r,tm),v,pos*2,tl,tm);
	upd(max(l,tm+1),r,v,pos*2+1,tm+1,tr);

	t[pos]=combine(t[pos*2],t[pos*2+1]);
}
//-------------------------------------------------

int main() {
    IO();

    map<char,int>mp; 
    mp['J']=0;
    mp['O']=1;
    mp['I']=2;

    cin>>N; 
    string s; cin>>s>>s>>s;
    FOR(i,0,N){
    	a[i]=mp[s[i]];
    }

    compute();

    int Q; 
    cin>>Q;
    FOR(idx,0,Q+1){
    	if(!idx){
    		cin>>s;
    		FOR(i,0,N) upd(i,i,mp[s[i]]);
    	}
    	else{
    		int l,r; char c; cin>>l>>r>>c; l--; r--;
    		upd(l,r,mp[c]);
    	}

    	//answer
    	if(t[1].m) cout << "Yes" << endl;
    	else cout << "No" << endl;
    }
    
    

    return 0;
}
