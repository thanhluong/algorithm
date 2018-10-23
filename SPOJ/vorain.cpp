#include <bits/stdc++.h>
 
using namespace std;
 
#define TASK "vorain"
 
#define input_file TASK".inp"
#define output_file TASK".out"
 
#define X first
#define Y second
#define FOR(i,a,b) for (i=(a);i<=(b);i++)
#define FORD(i,a,b) for (i=(a);i>=(b);i--)
#define itr(t) vector<t>::iterator
#define ritr(t) vector<t>::reverse_iterator
#define IT(i,v) for (i=v.begin();i!=v.end();i++)
#define RIT(i,v) for (i=v.rbegin();i!=v.rend();i++)
#define MAX_HEAP(t) priority_queue<t>
#define MIN_HEAP(t) priority_queue<t,vector<t>,greater<t> >
#define abs(x) ((x)>0?(x):-(x))
#define SET_ARR(a,v) memset(a,v,sizeof(a))
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
 
int delta_x[]={-1,0,1,0};
int delta_y[]={0,1,0,-1};
 
inline ll gcd(ll a, ll b){
	return (a?gcd(b%a,a):b);
}
 
#define N 111111
 
const int m=1e6;
 
bool r[N];
 
int n=0;
 
struct Line{
	int x1,y1;
	int x2,y2;
	double a,b;
	Line(int x_1=-1,int y_1=0,int x_2=0,int y_2=0){
		if(x_1!=-1){
			x1=x_1,y1=y_1;
			x2=x_2,y2=y_2;
			double A=y1-y2;
			double B=x2-x1;
			double C=-A*x1-B*y1;
			a=-A/B,b=-C/B;
		}
	}
} line[N];
 
#define VAL(i,x) line[i].a*x+line[i].b
 
struct TNode{
	int i;
	double y;
	TNode(double _y=0,int _i=0){
		y=_y,i=_i;
	}
} rnode;
 
inline bool operator < (const TNode& a,const TNode& b){
	return (a.y>b.y);
}
 
inline void Maximize(TNode& t,TNode c){
	if(t.y>c.y) return;
	t=c;
}
 
struct IntervalTree{
	set<TNode> nodeL[5*m];
	set<TNode> nodeR[5*m];
	void Insert(int,int,int);
	void Remove(int,int,int,int);
	void GetMax(int,int,int,int,int);
} IT;
 
#define LEFT_CHILD i*2,L,(L+R)/2
#define RIGHT_CHILD i*2+1,(L+R)/2+1,R
 
void IntervalTree::Insert(int i,int L,int R){
	if(line[n].x2<L or R<line[n].x1) return;
	if(line[n].x1<=L and R<=line[n].x2){
		nodeL[i].insert(TNode(VAL(n,L),n));
		nodeR[i].insert(TNode(VAL(n,R),n));
		return;
	} 
	Insert(LEFT_CHILD);
	Insert(RIGHT_CHILD);
}
 
void IntervalTree::Remove(int i,int L,int R,int j){
	if(line[j].x2<L or R<line[j].x1) return;
	if(line[j].x1<=L and R<=line[j].x2){
		nodeL[i].erase(TNode(VAL(j,L),j));
		nodeR[i].erase(TNode(VAL(j,R),j));
		return;
	}
	Remove(LEFT_CHILD,j);
	Remove(RIGHT_CHILD,j);
}
 
void IntervalTree::GetMax(int i,int L,int R,int x,int y){
	set<TNode>::iterator itL=nodeL[i].lower_bound(y);
	set<TNode>::iterator itR=nodeR[i].lower_bound(y);
	while (itL!=nodeL[i].end()){
		double z=VAL(itL->i,x);
		if(z<=y){
			Maximize(rnode,TNode(z,itL->i));
			break;
		}
		itL++;
	}
	while (itR!=nodeR[i].end()){
		double z=VAL(itR->i,x);
		if(z<=y){
			Maximize(rnode,TNode(z,itR->i));
			break;
		}
		itR++;
	}
	if(L==R) return;
	if(x<=(L+R)/2){
		GetMax(LEFT_CHILD,x,y);
	}
	else{
		GetMax(RIGHT_CHILD,x,y);
	}
}
 
namespace Solve{
	int Q,i;
	int t;
	int x1,y1;
	int x2,y2;
	void Main(){
		scanf("%d",&Q);
		while(Q--){
			scanf("%d",&t);
			if(t==2){
				scanf("%d",&i);
				if(r[i]) continue;
				r[i]=true;
				IT.Remove(1,1,m,i);
				continue;
			}
			scanf("%d%d",&x1,&y1);
			if(t==3){
				rnode=TNode(-1,0);
				IT.GetMax(1,1,m,x1,y1);
				printf("%d\n",rnode.i);
				continue;
			}
			scanf("%d%d",&x2,&y2);
			if(x1>x2){
				swap(x1,x2);
				swap(y1,y2);
			}
			line[++n]=Line(x1,y1,x2,y2);
			IT.Insert(1,1,m);
			r[n]=false;
		}
	}
}
 
main(){
	#ifndef ONLINE_JUDGE
	freopen(input_file,"r",stdin);
	freopen(output_file,"w",stdout);
	#endif
	Solve::Main();
} 
