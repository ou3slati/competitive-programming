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

///////////////////////////////////////////////////////////////////////////

struct st{
	int idx,x; 
};

int N,d[MX][MX];
st L,R; 
V<st>tyC,tyD;

void get(int i, int j){
	d[i][j]=d[j][i]=getDistance(i,j);
}

void findLocation(int N, int first, int X[], int ty[]){
	::N=N; 
	if(N==1){
		X[0]=first; 
		ty[0]=1;
		return;
	}


	d[0][0]=0;
	vpi vec;
	FOR(i,1,N){
		get(0,i);
		vec.eb(d[0][i],i);
	}
	sort(all(vec));

	tyC.pb({0,first});
	L=tyC[0];
	X[0]=L.x;
	ty[0]=1;

	tyD.pb({vec[0].se,first+vec[0].fi});
	R=tyD[0];
	X[R.idx]=R.x;
	ty[R.idx]=2;


	int fir=1;
	for(auto it: vec){
		if(fir){
			fir=0;
			continue;
		}

		st k; k.idx=it.se;
		get(k.idx,L.idx);
		get(k.idx,R.idx);

		/*dbg(k.idx)
		dbgs(L.idx,R.idx)*/

		//Case 1
		k.x=L.x+d[k.idx][L.idx];
		int f=0;

		for(st p: tyC){
			if(p.x<k.x){
				f|=(getDistance(k.idx,p.idx)+
					getDistance(R.idx,p.idx)==d[k.idx][R.idx]);
			}
		}
		if(f){
			X[k.idx]=k.x; 
			ty[k.idx]=2;
			tyD.pb(k);
			if(k.x>R.x) R=k; 
			continue;
		}


		//Case 2
		k.x=R.x-d[k.idx][R.idx];
		for(st p: tyD){
			if(p.x>k.x){
				f|=(getDistance(k.idx,p.idx)+
					getDistance(L.idx,p.idx)==d[k.idx][L.idx]);
			}
		}
		//assert(f);

		X[k.idx]=k.x; 
		ty[k.idx]=1;
		tyC.pb(k);
		if(k.x<L.x) L=k; 
	}
	//FOR(i,0,N) cout << ty[i] << ' ' << X[i] << endl;
	
}
/////////////////////////////////////////////////////////////////////////

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
