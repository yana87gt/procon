#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)
#define all(a) (a).begin(),(a).end()
#define each(itr,c) for(auto itr=c.begin(); itr!=c.end(); ++itr)
#define lb(s,x) lower_bound(all(s),x)-s.begin()
#define ub(s,x) upper_bound(all(s),x)-s.begin()
#define uniq(a) a.erase(unique(all(a)),a.end())
#define debug(x) cerr<<#x<<": "<<x<<endl

template<class T,class U>
ostream& operator<<(ostream& o, const pair<T,U> &p){
    o<<"("<<p.first<<", "<<p.second<<")";
    return o;
}

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    fill( (T*)array, (T*)(array+N), val );
}

#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }

#define INF 1e9
typedef long long ll;

using MyClass = pair<int,int>;
namespace std {
    bool operator<(const MyClass a, const MyClass b) {
        return a.first != b.first ? a.first < b.first : a.second < b.second;
    }
}


int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

ll gcd(ll a,ll b){return b==0 ? a : gcd(b,a%b);}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

ll C[60][60]={};
ll com(int n, int r){
    if(C[n][r]!=0) return C[n][r];
    else if(n==r || r==0) return C[n][r]=1;
    else if(r==1 || r==n-1) return C[n][r]=n;
    else return  C[n][r] = C[n][n-r] = com(n-1,r-1) + com(n-1,r);
}

const ll mod = 1e9+7;

ll add(ll a,ll b){ return (a+b)%mod;}

ll sub(ll a,ll b){ return (a-b)%mod;}

ll mul(ll a,ll b){ return (a*b)%mod;}

ll power(ll n, ll r){
    if(r==0) return 1;
    return mul(power(mul(n,n),r/2),(r&1 ? n : 1));
}

ll divm(ll a,ll b){ return mul(a, power(b, mod-2));}

ll f[200000] = {};

ll fact(ll n){
    if(f[n]) return f[n];
    if(n==0) return 1;
    return f[n] = mul(n,fact(n-1));
}

ll com(ll n,ll r){
    if(n<r) return 0;
    return divm(fact(n),mul(fact(n-r),fact(r)));
}

vector<string> split(string s,string d) {
    vector<string> elems;
    s += d;
    int r;
    for(int l=0; l<int(s.size()); l=r+d.size()){
        r = s.find(d,l);
        string item = s.substr(l,r-l);
        if(item!="") elems.push_back(item);
    }
    return elems;
}

void print_char(){
    char c=0;
    rep(i,256){
        printf("%3d(%2x) : %c\n",i,i,c++);
        if(c=='\0')printf("it's NULL\n");
    }
}

void check_sizeof(){
    printf("sizeof int : %ld\n",sizeof(int));
    printf("sizeof unsigned int : %ld\n",sizeof(unsigned int));
    printf("sizeof char : %ld\n",sizeof(char));
    printf("sizeof short : %ld\n",sizeof(short));
    printf("sizeof long : %ld\n",sizeof(long));
    printf("sizeof long long : %ld\n",sizeof(long long));
    printf("sizeof float : %ld\n",sizeof(float));
    printf("sizeof double : %ld\n",sizeof(double));
    printf("sizeof void* : %ld\n",sizeof(void*));
}

/* 10進数(int)を全ビット分,2進数表記で出力 */
void print_binary(int decimal){
    unsigned bit_checker = 1u<<((sizeof(int)<<3)-1);   //1000...000
    do{
        printf("%d",!!(decimal & bit_checker));
    }while(bit_checker>>=1);
}

/* 10進数(int)をnビット分,2進数表記で出力 */
void print_binary(int decimal, int n){
    unsigned bit_checker = 1u<<(n-1);   //1000...000
    do{
        printf("%d",!!(decimal & bit_checker));
    }while(bit_checker>>=1);
}

union Int_Float {
    int ival;
    float fval;
};

/* 10進数(float)を全ビット分,2進数表記で出力 */
void print_binary(float decimal){
    unsigned bit_checker = 1u<<((sizeof(int)<<3)-1);   //1000...000
    union Int_Float target;
    target.fval = decimal;
    do{
        printf("%d",!!(target.ival & bit_checker));
    }while(bit_checker>>=1);
}

union Long_Double {
    long long llval;
    double dval;
};

/* 10進数(double)を全ビット分,2進数表記で出力 */
void print_binary(double decimal){
    union Long_Double target;
    target.dval = decimal;
    unsigned long long bit_checker = 1ull<<((sizeof(long long)<<3)-1);
    do{
        printf("%d",!!(target.llval & bit_checker));
    }while(bit_checker>>=1);
}

int digits(int n){
    return to_string(n).size();
}


#define MAX 100
int main(void){
    int ary[2*MAX + 1];
    int *dp = ary + MAX; // [-MAX, MAX]
    dp[-1] = 3;
    map<string, int> mp;
    mp["hoge"] = 3;
    mp["fuga"] = 5;
    mp["piyo"] = 6;
    print(mp);

    set<double> st;
    st.insert(3.14);
    st.insert(2.71);
    print(st);

    pair<int,pair<int,int>> p = {3,{1,4}};
    cout<<p<<endl;

    bitset<12> bs1(2214);
    bitset<12> bs2(578);
    cout<<bitset<12>(12).to_string('X','Y')<<endl;;

    string l_r = "RLLLRRRLRRLL";
    debug(bs1);
    debug(bs2);
    debug(l_r);
    return 0;
}
