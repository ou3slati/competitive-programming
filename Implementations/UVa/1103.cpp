#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
//#define int ll
typedef double db;
typedef long double ldb;

typedef pair<int,int> pi;
#define mp make_pair
#define fi first
#define se second

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<db> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;

#define pb push_back
#define eb emplace_back
#define pf push_front

#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)

const int MOD = 1e9+7;
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};
//const int nx[8]= {-1,-1,0,1,1,1,0,-1}, ny[8]={0,1,1,1,0,-1,-1,-1};

char g[210][210];
bool vis[210][210];
int R,C;
int mr,mc;
int nb;
int corner;
bool cc;

string convert(char c){
   int x;
   if(c>='0'&&c<='9') x=c-'0';
   else x=c-'a'+10;
   string s=bitset<4>(x).to_string();
   return s;
}

void dfs2(int x, int y){
   vis[x][y]=true;
   if(x==0||y==0||x==R-1||y==C-1) cc=true;
   //cout <<"dfs2" << endl;
   for (int m=0; m<4; m++){
      int nwx=x+nx[m], nwy=y+ny[m];
      if(nwx<0||nwy<0||nwx>mr||nwy>mc||vis[nwx][nwy]) continue;
      if(g[nwx][nwy]=='0') dfs2(nwx,nwy);
   }
   return;
}

void dfs(int x, int y){
   vis[x][y]=true;
   //cout << x << ' ' <<y << endl;
   for (int m=0; m<4; m++){
      int nwx=x+nx[m], nwy=y+ny[m];
      //cout << nwx << ' '<<nwy << endl;
      if(nwx<0||nwy<0||nwx>mr||nwy>mc||vis[nwx][nwy]) continue;
      //cout <<"passed"<<endl;
      if(g[nwx][nwy]=='1'){ dfs(nwx,nwy);}
      else { nb++; cc=false; dfs2(nwx,nwy); if(cc) corner++;  }
   }
   return;
}

int32_t main(){
   boost;
   cin>>R>>C;
   int tc=0;
   while(R||C){
      memset(g,'0',sizeof(g)); memset(vis,false,sizeof(vis));
      mr=0; mc=0;

      for(int r=0; r<R; r++){
         int pos=-1;
         cout << r <<endl;
         for (int j=0; j<C; j++){
            char c; cin>>c;
            string s=convert(c);
            for (int i=0; i<sz(s); i++){pos++; g[r][pos]=s[i]; if(s[i]!='0'){mr=max(mr,r); mc=max(mc,pos); }  }
         }
      }
      if(mr!=R-1) mr++; if(mc!=C-1) mc++;
      //cout << mr << mc << endl;
      //for (int i=0; i<=mr; i++) {for (int j=0; j<=mc; j++) cout << g[i][j]; cout << endl;}

      string res;
      bool ft=false;
      for (int i=0; i<=mr; i++) for (int j=0; j<=mc; j++){
         if(!vis[i][j]&&g[i][j]=='1'){
            nb=0; corner=0;
            dfs(i,j);
            if(!ft&&corner>1) nb-=corner-1;
            else if(ft&&corner) nb-=corner;
            if(!ft){ft=true; nb--;}
            //cout << nb <<endl;
            if(nb==1) res+='A'; else if(nb==3)res+='J'; else if(nb==5) res+='D';else if (nb==4)res+='S';
            else if(nb==0) res+='W'; else if(nb==2) res+='K';
         }
      }
      sort(all(res));
      cout << "Case "<<++tc<<": "<<res<<endl;


      cin>>R>>C;
   }



}


