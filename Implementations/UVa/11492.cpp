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
typedef pair<str,str> ps;
#define fi first
#define se second

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
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

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};



int32_t main(){
   boost;
   int N;
   while(cin>>N,N){
      string st,t; cin>>st>>t;

      unordered_map <string,int> mp;
      unordered_map<int,int> mp2;

      int cnt=0;
      vector<pair<pair<str,int>,ps>> vec;
      vpi start; set<pi> dest;

      for(int i=0; i<N; i++){
         string l,ll,w; cin>>l>>ll>>w;
         //if(l==ll) continue;
         mp[w]=cnt++;
         mp2[mp[w]]=w.size();
         vec.pb({{w,0},{l,ll}});
         vec.pb({{w,1},{ll,l}});

         if(l==st) start.pb({mp[w],0});
         if(ll==st) start.pb({mp[w],1});
         if(ll==t) dest.insert({mp[w],0});
         if(l==t) dest.insert({mp[w],1});
      }

      if(dest.empty()){cout << "impossivel" << endl; continue;}

      //for(auto x: dest) cout << x.fi << ' '<<x.se << endl;

      vpi adj[2010][2];
      for(int i=0; i<sz(vec); i++) for(int j=i+1; j<sz(vec); j++) if(i!=j){
         string w=vec[i].fi.fi, w2=vec[j].fi.fi;
         int st=vec[i].fi.se, st2=vec[j].fi.se;
         string l=vec[i].se.fi, ll=vec[i].se.se, l2=vec[j].se.fi, ll2=vec[j].se.se;

         if(w[0]==w2[0]) continue;
         if(ll==l2) adj[mp[w]][st].pb({mp[w2],st2}); //cout << w  << ' ' << st << ' '<<w2 << ' ' << st2 << endl;}
         if(ll2==l) adj[mp[w2]][st2].pb({mp[w],st}); //cout << w2 << ' ' << st2 << ' '<<w << ' ' << st << endl;}
      }

      int dist[2010][2]; for(int i=0; i<2010; i++) dist[i][0]=dist[i][1]=INF;
      priority_queue<pair<int,pi>,vector<pair<int,pi>>,greater<pair<int,pi>>> q;
      for(auto x: start){
         dist[x.fi][x.se]=mp2[x.fi];
         q.push({mp2[x.fi],{x.fi,x.se}});
      }

      int ans=-1;
      while(!q.empty()){
         int u=q.top().se.fi, st=q.top().se.se, d=q.top().fi;
         q.pop();
         if(d>dist[u][st]) continue;
         if(dest.count({u,st})){ans=d; break;}

         for(auto x: adj[u][st]) if(dist[x.fi][x.se]>dist[u][st]+mp2[x.fi]){
            dist[x.fi][x.se]=dist[u][st]+mp2[x.fi];
            q.push({dist[x.fi][x.se],{x.fi,x.se}});
         }

      }
      if(ans==-1||st==t) cout <<"impossivel" << endl;
      else cout << ans << endl;
      //cout << endl << endl;
   }
   return 0;
}

/*
100
y a
mclywcznk a pnxd
fpk aoltxmgimz bftpnbylmm
fpk ounbhmt hneu
aoltxmgimz uabghylanj zwlbpy
aoltxmgimz y kxjxil
mclywcznk ounbhmt rgiibcyhvr
y ounbhmt sjmgjw
wbjjm aoltxmgimz ecohxknld
a uabghylanj u
snm a xgh
fpk fpk c
ounbhmt aoltxmgimz dkrin
y mclywcznk nx
y aoltxmgimz pnvpem
uabghylanj snm lgcal
wbjjm a hqetyrg
fpk uabghylanj tzgs
uabghylanj y pp
mclywcznk aoltxmgimz rxbylprfm
wbjjm mclywcznk qsiicdy
wbjjm uabghylanj jsyayxompg
wbjjm aoltxmgimz ylwrebhvg
aoltxmgimz mclywcznk pbvhp
aoltxmgimz fpk qcbwz
y ounbhmt xwwsf
uabghylanj ounbhmt jjjsy
ounbhmt uabghylanj iydxk
fpk ounbhmt ahfxp
mclywcznk snm vsj
fpk mclywcznk misnzqylo
ounbhmt fpk volhzuh
snm ounbhmt zyj
a mclywcznk jqnlewmn
aoltxmgimz ounbhmt xhtpj
fpk wbjjm u
y wbjjm tjqewk
mclywcznk aoltxmgimz irp
snm mclywcznk axogvcf
aoltxmgimz ounbhmt hc
wbjjm y sygeqyvkw
aoltxmgimz fpk cupuvcxtkr
fpk ounbhmt egqrw
uabghylanj y snkkys
ounbhmt ounbhmt eu
aoltxmgimz uabghylanj suhpoz
snm ounbhmt wrtqq
y wbjjm kpfauzia
y uabghylanj bvarjbc
aoltxmgimz aoltxmgimz mwa
ounbhmt ounbhmt syvwqixvg
a aoltxmgimz gxxiwiwlr
a aoltxmgimz zuopkwyh
wbjjm mclywcznk bqqgi
ounbhmt snm tymhe
snm wbjjm glvq
y aoltxmgimz rnyxiz
snm wbjjm zqueaworwl
mclywcznk mclywcznk f
aoltxmgimz y szojtywq
ounbhmt snm derp
uabghylanj snm patxz
aoltxmgimz a tf
fpk y ljcjdxihip
snm y pagzxt
aoltxmgimz aoltxmgimz seiktifdja
uabghylanj aoltxmgimz lkxzza
snm wbjjm bvcgdk
snm y o
mclywcznk fpk r
mclywcznk y xzh
wbjjm uabghylanj kagicsw
fpk y mynf
fpk uabghylanj lznmgqnj
mclywcznk y dnkhewh
y fpk lyfzyijai
wbjjm aoltxmgimz akvmmbla
mclywcznk mclywcznk pmj
mclywcznk aoltxmgimz ze
wbjjm a glstb
aoltxmgimz wbjjm ao
snm y hcm
aoltxmgimz ounbhmt dpruzt
wbjjm mclywcznk lwgl
fpk ounbhmt q
a snm nbsahdu
y aoltxmgimz dbochfgyf
uabghylanj wbjjm iftadpt
snm ounbhmt yywdnmhor
ounbhmt y lj
fpk uabghylanj ktoothrwm
fpk uabghylanj tiixwx
aoltxmgimz snm kmqe
aoltxmgimz ounbhmt wsszxhl
ounbhmt uabghylanj ra
y ounbhmt dbimydv
wbjjm y habv
wbjjm fpk xwibo
ounbhmt aoltxmgimz awwqu
uabghylanj uabghylanj ftftgql
uabghylanj fpk hcge
4
3
*/




/*89
q sbzrxjaw
jbazkq ukwcgu opfsfu
lnlcwhjela zffc sdwkhlapbu
lyrs piz alrr
fqywp zw w
ec lnlcwhjela gpxx
lnlcwhjela fqywp ow
yhf eascizer bxz
eascizer jbazkq klaceef
ec piz menvo
ukwcgu xsdtzgcs uvqkmcf
zw v dmwnndbte
fqywp ee eeidgfuc
v jbazkq uadhhvi
oe zw mrsvfzcbyo
sbzrxjaw jbazkq ol
wiff oe idcmb
zw ukwcgu ykaypkyvb
ukwcgu lyrs kzzeu
v ee f
lnlcwhjela wiff uneavh
wiff jbazkq aujca
v zffc mw
fqywp ipjby hnrmvo
lnlcwhjela v hwagjwrq
sbzrxjaw piz x
oe jbazkq nbhyrk
q xsdtzgcs qkltq
ee xsdtzgcs vnlvax
yhf ukwcgu gzubrntetp
ukwcgu oe pvpfibcz
q zw rmo
v ipjby aiwpvmzodw
mfmrnzxz ukwcgu geza
v sbzrxjaw qm
zw eascizer wobsr
sbzrxjaw ee ikk
v q guyfsv
fqywp zw dgbiv
mfmrnzxz zw ym
fqywp wiff bw
ee eascizer kymifnaazl
mfmrnzxz ec dhmxk
lnlcwhjela eascizer d
eascizer yhf ya
zffc ukwcgu wv
mfmrnzxz ec j
oe oe bvesxxs
lnlcwhjela xsdtzgcs x
fqywp wiff zkjqcrks
lyrs piz s
eascizer ec emof
fqywp wiff tklxuomj
mfmrnzxz zw m
ec ee qvuokkbzbk
lnlcwhjela q fcdm
wiff lnlcwhjela dtstojd
zw ukwcgu j
zffc ec p
ipjby zffc lcdljtd
wiff wiff ejn
mfmrnzxz zw k
fqywp ukwcgu gzbzrosscf
ec ee yql
ukwcgu yhf ajplmo
eascizer ukwcgu f
jbazkq yhf piypvr
ec piz uwqkg
v sbzrxjaw recr
xsdtzgcs zffc wnsk
q oe amtugf
ee piz dui
ee oe end
sbzrxjaw ee kb
v eascizer nvouho
lyrs fqywp jq
v mfmrnzxz fdrnsfey
ukwcgu ee xoajmzbzg
mfmrnzxz lnlcwhjela xqhk
fqywp fqywp pzpa
v ipjby kblzoxsxp
sbzrxjaw oe fqezg
lyrs ipjby essp
ee xsdtzgcs omdtwsadrm
v v wcbygny
ec zffc ggsaccut
ee sbzrxjaw qpw
q ipjby pdwcglu
sbzrxjaw yhf hhydsrfli
eascizer ipjby dua
7
8
*/

/*
27
mwwbceh heyl
ezfpsnz heyl sbp
ezfpsnz kderz whrfhqrrhj
kderz ezfpsnz gcpowv
ihqvaj ezfpsnz awqusjun
heyl ihqvaj ynzxrlmlo
hlsnjzh kderz vlkad
gm xjzvfm tv
ihqvaj ihqvaj jepyoq
s s lxnzntvb
ihqvaj hlsnjzh ou
kderz xjzvfm wajgsbtcsd
ihqvaj gm l
hlsnjzh heyl ydncowqrat
heyl xjzvfm n
hlsnjzh ihqvaj jft
ezfpsnz pk ykymy
heyl xjzvfm xle
ezfpsnz s lgbcbu
s ezfpsnz exjhawgap
ezfpsnz pk ay
kderz heyl edhdt
mwwbceh ihqvaj n
kderz mwwbceh nvgpoi
s mwwbceh p
s hlsnjzh wf
s mwwbceh mxefmimtlv
ezfpsnz gm bvbrlqsg
4
5
*/

/*
99
nhjiohefvp x
jbjkub kgd bcjp
x cp lnkfghjyt
sandw sandw ku
sandw gcxvwml jmkuhpy
hiejnb jbjkub ejyxqkp
cp uztsjxs rpiivo
x hiejnb nx
cp gcxvwml ve
cp sandw zomykldc
x cp sv
hiejnb cp ythlzab
gcxvwml x mw
gcxvwml nhjiohefvp bqjahpycg
sandw sandw fgnwi
hiejnb qhevgnlly mgpbb
nhjiohefvp gcxvwml qbjqgaec
jbjkub cp ieustmt
x uztsjxs ugd
kgd uztsjxs hzgppp
sandw hiejnb xxsejjtb
bb kgd x
jbjkub uztsjxs mwycemc
kgd x bgw
qhevgnlly cp j
kgd hiejnb elfatahrai
kgd bb nupj
sandw uztsjxs ds
qhevgnlly sandw pphadbaeh
bb jbjkub elewm
gcxvwml cp wlixcxa
nhjiohefvp cp et
bb qhevgnlly kvtmtq
bb gcxvwml omzpunjzr
x hiejnb isrzobtbi
x qhevgnlly ogovix
jbjkub nhjiohefvp wyppui
jbjkub cp ur
bb hiejnb iid
qhevgnlly nhjiohefvp tmfmqcifq
uztsjxs gcxvwml nshjrzu
qhevgnlly jbjkub hiepvaej
kgd cp f
sandw nhjiohefvp sc
cp kgd nrccyg
bb hiejnb bcik
nhjiohefvp gcxvwml ct
bb uztsjxs e
cp qhevgnlly wrkhjirz
hiejnb bb sv
sandw qhevgnlly f
hiejnb hiejnb qsw
x jbjkub pgjtvw
kgd jbjkub jvzmd
hiejnb x sgbjyuiikb
x qhevgnlly cj
kgd uztsjxs f
hiejnb nhjiohefvp eaumwydjep
uztsjxs jbjkub lbhndpj
x uztsjxs yu
kgd x c
jbjkub nhjiohefvp onre
kgd uztsjxs jfxkxzev
uztsjxs bb tgqmk
x jbjkub a
qhevgnlly sandw jeaw
nhjiohefvp gcxvwml olseaeb
x hiejnb esgxlstgnc
nhjiohefvp qhevgnlly uoddsg
qhevgnlly uztsjxs otxrjslgyn
gcxvwml qhevgnlly ndwveuw
gcxvwml nhjiohefvp tkerur
cp bb wibiurdigu
jbjkub cp xyhzkwkqwq
bb hiejnb usmmnx
kgd bb qup
sandw uztsjxs cai
qhevgnlly kgd qufktrn
sandw bb yeqzsqdhq
uztsjxs x tecjotzenx
hiejnb nhjiohefvp fuphfosor
hiejnb qhevgnlly rnqwvm
qhevgnlly nhjiohefvp llwoon
uztsjxs nhjiohefvp f
jbjkub uztsjxs otjda
gcxvwml hiejnb vwcslxwk
kgd jbjkub m
kgd x xjlarvg
hiejnb hiejnb ymaq
hiejnb uztsjxs fvxvg
uztsjxs hiejnb xzddeoky
hiejnb bb dgpcxjp
x gcxvwml icuckjq
sandw gcxvwml punogv
nhjiohefvp qhevgnlly pih
uztsjxs x izk
gcxvwml x nt
cp sandw uuf
uztsjxs jbjkub gc
kgd bb tnufpl
2
3
*/

/*
62
qrjrai rkypqkmtee
exqcbpysk gbqgjre sbfll
yzd exqcbpysk pwqwqdgha
rkypqkmtee gytexx cihtmqyx
meuxd yzd zdrkc
lfeqduitve meuxd heylid
yzd qrjrai syu
xuroglq wljkkvdkb wssjnlkoyc
plx wljkkvdkb etjtzu
wljkkvdkb ualfxnba vsjn
gppdgw yzd nssbg
rkypqkmtee rkypqkmtee xlfrecxid
nlckpyjnhs ualfxnba wfg
f nlckpyjnhs b
qrjrai exqcbpysk dhzoqmwtr
wljkkvdkb nlckpyjnhs qldw
jowgz wljkkvdkb fytnjlws
adnhbnwqvb exqcbpysk ndvdpzbvn
exqcbpysk ccmf nbmbyxx
fxx ccmf fthf
meuxd wljkkvdkb t
rkypqkmtee ccmf ltknmao
ualfxnba uxiewowbqk gtxm
stqxa xyuatuddiz qx
ftshjdtg uagxpon icps
exqcbpysk f jbd
nlckpyjnhs nlckpyjnhs ktnlji
fxx stqxa pbh
exqcbpysk gbqgjre yzfhoxhtlu
rkypqkmtee yzd czo
jowgz gppdgw ebn
f plx ptufwl
qrjrai stqxa brwe
qrjrai uagxpon jrv
uagxpon nlckpyjnhs shmqyvbhf
ftshjdtg qrjrai nmvfnqnqyr
wljkkvdkb hhfcn kd
yzd f d
f wljkkvdkb qzgxpvguqb
nlckpyjnhs ccmf ylhd
qrjrai exqcbpysk irkrv
fxx uagxpon mt
uxiewowbqk rkypqkmtee dowrlyoh
f ualfxnba g
adnhbnwqvb plx db
s stqxa ckpbduhn
fxx mwfvg rdpnot
qrjrai plx clnjuk
mwfvg gppdgw pfhps
gbqgjre xuroglq thtfas
xuroglq ccmf sohfrk
qrjrai nlckpyjnhs bu
meuxd xyuatuddiz gmxwum
gppdgw xyuatuddiz c
lfeqduitve fxx vnsoaaqm
adnhbnwqvb gbqgjre pup
meuxd exqcbpysk xpsbhxg
mwfvg gytexx lqcagz
meuxd xuroglq fhcuptlewe
xyuatuddiz gytexx grzlw
adnhbnwqvb exqcbpysk swvp
uagxpon qrjrai b
f ualfxnba ledd
5
6
*/
