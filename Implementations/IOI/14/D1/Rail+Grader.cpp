//Never stop trying
#include "bits/stdc++.h"
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
typedef string str;
typedef long double ld;
typedef pair<int, int> pi;
#define fi first
#define se second
typedef vector<int> vi;
typedef vector<pi> vpi;
#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define endl "\n"
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)

const int MOD = 1e9 + 7; //998244353
const ll INF = 1e9;
const int MX = 5000 + 10;
const int nx[4] = {0, 0, 1, -1}, ny[4] = {1, -1, 0, 0}; //right left down up

template<class T> using V = vector<T>;
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
ll cdiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); } // divide a by b rounded up
//constexpr int log2(int x) { return 31 - __builtin_clz(x); } // floor(log2(x))

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
ll random(ll a, ll b){
    return a + rng() % (b - a + 1);
}
#ifndef LOCAL  
#define cerr if(false) cerr
#endif
#define dbg(x) cerr << #x << " : " << x << endl; 
#define dbgs(x,y) cerr << #x << " : " << x << " / " << #y << " : " << y << endl;
#define dbgv(v) cerr << #v << " : " << "[ "; for(auto it : v) cerr << it << ' '; cerr << ']' << endl;
#define here() cerr << "here" << endl;

void IO() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#endif
}
/////////////////////////ONLY CLEAN CODES ALLOWED/////////////////////////

typedef struct Station {
  int index;
  int type;
  int location;
  int L,R;
}STATION;
long long cnt;
static int S,SUBTASK;
static STATION stations[10004];

int cmp_fun_1(const void *a,const void *b)
{
	STATION c,d;
	c = *(STATION*)(a);
	d = *(STATION*)(b);
  	return c.location < d.location ? -1 : 1;
}

int cmp_fun_2(const void *a,const void *b)
{
	STATION c,d;
	c = *(STATION*)(a);
	d = *(STATION*)(b);
  	return c.index < d.index ? -1 : 1;
}

void now_I_want_to_getLR(){
  int now = stations[S-1].index,i;
  for(i=S-2;i>=0;i--){
    stations[i].R = now;
    if(stations[i].type==2)	now = stations[i].index;
  }
  now = stations[0].index;
  for(i=1;i<S;i++){
    stations[i].L = now;
    if(stations[i].type==1)	now = stations[i].index;
  }
}

int getDistance(int x,int y)
{
  cnt++;
  if(x==y)	return 0;
  if(x<0 || x>=S || y<0 || y>=S)    return -1;
  if(stations[x].location > stations[y].location){
  	int tmp = x;
	x = y;
	y = tmp;
  }
  int ret = 0;
  if(stations[x].type==1 && stations[y].type==1){
    ret = stations[stations[y].R].location-stations[x].location+stations[stations[y].R].location-stations[y].location;
  }else if(stations[x].type==1 && stations[y].type==2){
    ret = stations[y].location-stations[x].location;
  }else if(stations[x].type==2 && stations[y].type==2){
    ret = stations[x].location-stations[stations[x].L].location+stations[y].location-stations[stations[x].L].location;
  }else if(stations[x].type==2 && stations[y].type==1){
    ret = stations[x].location-stations[stations[x].L].location+stations[stations[y].R].location
      -stations[stations[x].L].location+stations[stations[y].R].location-stations[y].location;
  }
  return ret;
}


void getInput()
{
  int g;
  g = scanf("%d",&SUBTASK);
  g = scanf("%d",&S);
  int s;
  for (s = 0; s < S; s++) {
    int type, location;
    g = scanf(" %d %d",&type,&location);
    stations[s].index = s;
    stations[s].location = location;
    stations[s].type = type;
    stations[s].L = -1;
    stations[s].R = -1;
  }
  qsort(stations, S, sizeof(STATION), cmp_fun_1);
  now_I_want_to_getLR();
  qsort(stations, S, sizeof(STATION), cmp_fun_2);
}

int serverGetStationNumber()
{
  return S;
}

int serverGetSubtaskNumber()
{
  return SUBTASK;
}

int serverGetFirstStationLocation()
{
  return stations[0].location;
}

////////////////////////////////////////////////////////////////////////
int N,x[MX],ty[MX],X,d[MX][MX]; 

int get(int i, int j){
	if(d[i][j]==-1){
		d[i][j]=d[j][i]=getDistance(i,j);
	}
	return d[i][j];
}

void det_X(){
	int mn=INF;
	FOR(i,1,N){
		if(ckmin(mn,get(0,i))) X=i;
	}
	x[X]=x[0]+get(0,X);
	ty[X]=2;
}

vi l,m,r; 
void divide(){
	FOR(Y,1,N) if(Y!=X){
		if(get(0,X)+get(X,Y)==get(0,Y)){
			if(get(X,Y)<get(0,X)) m.pb(Y);
			else l.pb(Y);
		}	
		else{
			r.pb(Y);
		}
	}
}


void solve_mid(){
	for(int Z: m){
		ty[Z]=1;
		x[Z]=x[X]-get(X,Z);
	}
}


bool cmpR(int i, int j){
	return get(0,i)<get(0,j);
}
void solve_right(){
	sort(all(r),cmpR);

	vi tyD={X};
	int Y=X; 
	for(int Z: r){
		int z=(-get(0,Z)+get(0,Y)+get(Y,Z))/2;

		int found=0;
		for(int u: tyD) if(x[Y]-x[u]==z) 
			found=1;

		if(found){
			ty[Z]=1;
			x[Z]=x[Y]-get(Y,Z);
		}
		else{
			ty[Z]=2; tyD.pb(Z);
			x[Z]=x[0]+get(0,Z);

			assert(x[Z]>x[Y]); Y=Z;
		}
	}
}

bool cmpL(int i, int j){
	return get(X,i)<get(X,j);
}
void solve_left(){
	sort(all(l),cmpL);

	vi tyC={0};
	int Y=0;

	for(int Z: l){
		int z=(-get(X,Z)+get(X,Y)+get(Y,Z))/2;

		int found=0;
		for(int u: tyC){
			if(x[u]-x[Y]==z) found=1;
		}

		if(found){
			ty[Z]=2;
			x[Z]=x[Y]+get(Y,Z);
		}
		else{
			ty[Z]=1; tyC.pb(Z);
			x[Z]=x[X]-get(X,Z);
			assert(x[Z]<x[Y]); Y=Z;
		}
	}
}

void findLocation(int N, int fir, int xx[], int tyy[]){
	::N=N; 
	memset(d,-1,sizeof(d));
	FOR(i,0,N) d[i][i]=0;

	x[0]=fir; ty[0]=1;
	if(N==1) return;

	det_X();
	divide();

	solve_mid();
	solve_right();
	solve_left();

	FOR(i,0,N) xx[i]=x[i],tyy[i]=ty[i];
}

/////////////////////////////////////////////////////////////


int main()
{
  
  IO();
  int i;
  getInput();
  cnt = 0;
  
  int location[10005];
  int type[10005];
  int ok = 1;
  findLocation(S, serverGetFirstStationLocation(),location, type);
  if(SUBTASK==3 && cnt>S*(S-1))	ok = 0;
  if(SUBTASK==4 && cnt>3*(S-1))	ok = 0;
  
  
  for (i = 0; i < S; i++)
    if(type[i]!=stations[i].type || location[i]!=stations[i].location)
      ok = 0;
  if(ok==0)	printf("Incorrect");
  else	printf("Correct");
  return 0;
}
