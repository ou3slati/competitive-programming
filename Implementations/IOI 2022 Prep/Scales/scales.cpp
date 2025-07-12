#include "scales.h"

#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=a; i<b; i++)
#define ROF(i,a,b) for(int i=b-1; i>=a; i--)

typedef vector<int>vi; 
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)


//------

void init(int T) {
    
    return;
}

void orderCoins() {
    int a=getLightest(1,2,3), x=getLightest(4,5,6);
    int b; ROF(i,1,4) if(i!=a) b=i; 
    int c; ROF(i,1,4) if(i!=a && i!=b) c=i; 
    int y; ROF(i,4,7) if(i!=x) y=i; 
    int z; ROF(i,4,7) if(i!=x && i!=y) z=i; 


    int k=getNextLightest(b,c,x,a); 

    vi order; 
    if(k==x){
    	int l=getMedian(k,b,c); 
    	int m=b; if(l==b) m=c; 
    	order={a,k,l,m}; 
    }
    else{
    	if(k==c) swap(b,c); 

    	int l=getMedian(b,c,x);
    	if(l==b) order={x,a,b,c}; 
    	else if(l==x) order={a,b,x,c}; 
    	else order={a,b,c,x}; 
    }



    a=order[0], b=order[1], c=order[2]; int d=order[3]; 
    k=getNextLightest(a,b,c,y); 

    if(k==b){
    	order={a,y,b,c,d}; 
    }
    else if(k==c){
    	order={a,b,y,c,d}; 
    }
    else{
    	k=getMedian(a,d,y); 
    	if(k==y) order={a,b,c,y,d}; 
    	else order={a,b,c,d,y}; 
    }




    a=order[0], b=order[1], c=order[2], d=order[3]; int e=order[4]; 
    k=getNextLightest(a,b,c,z); 

    if(k==b){
    	order={a,z,b,c,d,e}; 
    }
    else if(k==c){
    	order={a,b,z,c,d,e}; 
    }
    else{
    	k=getNextLightest(a,d,e,z); 
    	if(k==d) order={a,b,c,z,d,e}; 
    	else if(k==e) order={a,b,c,d,z,e};
    	else order={a,b,c,d,e,z};  
    }


    int W[] = {order[0], order[1], order[2], order[3], order[4], order[5]};
    answer(W);
}