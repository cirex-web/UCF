// ♬ I got my head out the sunroof ♬


#include <bits/stdc++.h>

using namespace std;

template<class ...Args>
auto &read(Args &...args) { return (cin >> ... >> args); }

#define READ(...) __VA_ARGS__; read(__VA_ARGS__)
#define mp(a, b)(make_pair(a,b))
#define pb(a) push_back(a)
#define FORE(i, a, b) for (int i = (a); i <= (b); ++i)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define ROF(i, a, b) for (int i = (a); i >= (b); --i)
#define RF(i, a) ROF(i,a,0)
#define FR(i, a) FOR(i,0,a)
#define FRE(i, a) FORE(i,0,a)

#define fast ios::sync_with_stdio(0);cin.tie(0)
#define sz(x) ((int)(x.size()))
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define in(r, R) (r>=0&&r<R)

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vl = vector<ll>;
using vd = vector<double>;
using vvi = vector<vi>;
using vvd = vector<vd>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;

using vs = vector<string>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vvs = vector<vs>;
using vpii = vector<pii>;
using vvpii = vector<vpii>;
using vvvi = vector<vvi>; //are you sure about this?
using vvvl = vector<vvl>; //are you sure about this?



ll MOD = 1000000007;


template<typename T>
void setmax(T &a, T b) { if (b > a) a = b; }

template<typename T>
void setmin(T &a, T b) { if (b < a) a = b; }

/*Insights


*/

/*Debugging


*/

/*Code Improvements



*/
// TAG: 
/*


*/

void print(vvi& g){
    FR(i,sz(g))FR(j,sz(g))cout<<g[i][j]<<" \n"[j==sz(g)-1];
}
struct DSU{
    vi ar;
    DSU(int N){ //NOLINT
        ar.resize(N,-1);
    }
    int par(int a){
        return ar[a]<0?a:ar[a]=par(ar[a]);
    }
    void merge(int a, int b){
        a = par(a);
        b = par(b);
        if(a!=b){
            if(ar[a]>ar[b])swap(a,b);
            ar[a]+=ar[b];
            ar[b] = a;
        }
    }
};
int main() {
    fast;

    int T; cin>>T;
    FR(t,T){
        int N; cin>>N;
        vvi g(N,vi(N));
        FR(i,N)FR(j,N)cin>>g[i][j];
        DSU dsu(2*N);
        FR(r,N){
            FOR(c,r+1,N){
                if(g[r][c]>g[c][r]){
                    if(dsu.par(r)!=dsu.par(c)){
                        dsu.merge(r,c+N);
                        dsu.merge(c,r+N);
                    }
                }else if(g[r][c]<g[c][r]){
                    if(dsu.par(r)!=dsu.par(c+N)){
                        dsu.merge(r,c);
                        dsu.merge(r+N,c+N);
                    }
                }
            }
        }
        FR(r,N){
            FOR(c,r+1,N){
                if(dsu.par(r)==dsu.par(c+N)){
                    //swap!
                    swap(g[r][c],g[c][r]);
                }
            }
        }
        print(g);

    }
    return 0;
}

/*
 *
1
3
2 2 2
1 2 2
1 1 2

1
5
0 1 1 1 1
0 0 1 1 1
0 0 0 1 1
1 1 1 0 0
0 1 1 1 0


0 0 0 1 0
1 0 1 1 1
1 0 0 1 1
1 1 1 0 0
1 1 1 1 0

0 0 0 1 0
1 0 1 1 1
1 0 0 1 1
1 1 1 0 0
1 1 1 1 0
 */