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
const ll INF = 1e18;
const int MX = 2e5 + 10;
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

static const int MAX_INSTRUCTIONS = 10000;
static const int MAX_INPUTS = 1000000;

static const int _AND = 0;
static const int _OR = 1;
static const int _XOR = 2;
static const int _NOT = 3;

static inline bool increasing(int a, int b, int c) {
	return a <= b && b <= c;
}

[[noreturn]] static inline void error(string message) {
	printf("%s\n", message.c_str());
	exit(0);
}

class InstructionNetwork {

	struct Instruction {
		int type;
		vector<int> input_indexes;

		inline Instruction(int _type, const vector<int>& _input_indexes):
				type(_type), input_indexes(_input_indexes) {
		}

		inline int apply(int a, int b) const {
			switch (type) {
				case _AND:
					return a & b;
				case _OR:
					return a | b;
				case _XOR:
					return a ^ b;
				default:
					return 0;
			}
		}

		inline int compute(const vector<int>& memory_cells) const {
			int r = memory_cells[input_indexes[0]];
			if (type == _NOT)
				return 1 - r;
			for (int j = 1; j < (int)input_indexes.size(); j++)
				r = apply(r, memory_cells[input_indexes[j]]);
			return r;
		}
	};

	int input_size;
	int total_inputs;
	vector<Instruction> instructions;

public:

	inline void init(int _input_size) {
		this->input_size = _input_size;
		this->total_inputs = 0;
		this->instructions.clear();
	}

	inline int add_instruction(int type, const vector<int>& input_indexes) {
		if (input_indexes.size() == 0)
			error("Instruction with no inputs");

		if (instructions.size() + 1 > MAX_INSTRUCTIONS)
			error("Too many instructions");

		if (total_inputs + input_indexes.size() > MAX_INPUTS)
			error("Too many inputs");

		instructions.emplace_back(type, input_indexes);
		total_inputs += input_indexes.size();
		int new_index = input_size + (int)instructions.size() - 1;

		for (int input_index : input_indexes)
			if (!increasing(0, input_index, new_index-1))
				error("Invalid index");

		return new_index;
	}

	inline int compute(vector<int> &memory_cells) const {
		for (auto &instruction : instructions)
			memory_cells.push_back(instruction.compute(memory_cells));
		return memory_cells.back();
	}
};
static InstructionNetwork instructionNetwork;

int add_and(vector<int> Ns) {
	return instructionNetwork.add_instruction(_AND, Ns);
}

int add_or(vector<int> Ns) {
	return instructionNetwork.add_instruction(_OR, Ns);
}

int add_xor(vector<int> Ns) {
	return instructionNetwork.add_instruction(_XOR, Ns);
}

int add_not(int N) {
	vector<int> Ns = {N};
	return instructionNetwork.add_instruction(_NOT, Ns);
}

//My code is here
#define OR add_or
#define AND add_and
#define XOR add_xor
#define NOT add_not

int N,M;
unordered_map<int,int>one[2],two[2];

int dist(int x, int y, int xx, int yy){
	return abs(x-xx)+abs(y-yy);
}
int f(int x, int y){
	return x*M+y;
}


int check_right(int K){
	vi global;
	FOR(i,0,N+M) if(i+K-1<=N+M-2){
		vi vec,vec2;
		FOR(j,i,i+K) 
			vec.pb(one[0][j]),vec2.pb(two[0][j]);
		int x=XOR(vi{OR(vec),XOR(vec)}); 
		vec2.pb(x);
		global.pb(OR(vec2));
	}
	return OR(global);
}

int check_left(int K){
	vi global;
	FOR(i,-(M-1),N) if(i+K-1<=N-1){
		vi vec,vec2;
		FOR(j,i,i+K) 
			vec.pb(one[1][j]),vec2.pb(two[1][j]);
		int x=XOR(vi{OR(vec),XOR(vec)}); 
		vec2.pb(x);
		global.pb(OR(vec2));
	}
	return OR(global);
}

int check(int k){
	return AND(vi{check_right(k),check_left(k)});
}

void construct_network(int H, int W, int K){
	N=H; M=W;

	FOR(i,0,N+M){
		vi vec;
		FOR(x,0,N) FOR(y,0,M) if(x+y==i) vec.pb(f(x,y));
		if(!sz(vec)) continue;

		one[0][i]=OR(vec);
		two[0][i]=XOR(vi{OR(vec),XOR(vec)});
	}
	FOR(i,-(N+M),N+M){
		vi vec;
		FOR(x,0,N) FOR(y,0,M) if(x-y==i) vec.pb(f(x,y));
		if(!sz(vec)) continue;

		one[1][i]=OR(vec);
		two[1][i]=XOR(vi{OR(vec),XOR(vec)});
	}

	int ans=AND(vi{check(K+1),NOT(check(K))});
}
//end of code


int main() {
	IO();

	int H, W, K;
	assert(3 == scanf("%d%d%d", &H, &W, &K));

	FILE *log_file = fopen("log.txt","w");

	instructionNetwork.init(H * W);
	construct_network(H, W, K);

	while (true) {
		int rowA, colA, rowB, colB;
		assert(1 == scanf("%d", &rowA));
		if (rowA == -1)
			break;
		assert(3 == scanf("%d%d%d", &colA, &rowB, &colB));

		if ((!increasing(0, rowA, H-1)) ||
			(!increasing(0, colA, W-1)) ||
			(!increasing(0, rowB, H-1)) ||
			(!increasing(0, colB, W-1)) ||
			(rowA == rowB && colA == colB)) {
			printf("-1\n");
			fprintf(log_file, "-1\n");
			fflush(stdout);
			fflush(log_file);
			continue;
		}

		vector<int> memory_cells;
		for (int row = 0; row < H; row++)
			for (int col = 0; col < W; col++) {
				bool active = (row == rowA && col == colA) || (row == rowB && col == colB);
				memory_cells.push_back(active ? 1 : 0);
			}
		int computation_result = instructionNetwork.compute(memory_cells);

		printf("%d\n", computation_result);
		fflush(stdout);

		for(int i = 0; i < (int)memory_cells.size(); i++)
			fprintf(log_file, (i ? " %d" : "%d"), memory_cells[i]);
		fprintf(log_file, "\n");
		fflush(log_file);
	}
	fclose(stdin);
}

