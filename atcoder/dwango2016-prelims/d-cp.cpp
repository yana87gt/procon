#include <algorithm>
using namespace std;

int H, W;
long long B[300][300];

void flip(){
    long long B2[300][300];
    for (int i = 0; i < W; ++i) for (int j = 0; j < H; ++j) B2[i][j] = B[j][i];
    for (int i = 0; i < W; ++i) for (int j = 0; j < H; ++j) B[i][j] = B2[i][j];
    swap(H, W);
}

long long rowacc[305][305];
long long best[300][300];

long long subproblem(int L, int R)
{
    // [L, R]
    long long tmp[305];
    for (int i = 0; i < H; ++i) tmp[i] = rowacc[i][R + 1] - rowacc[i][L];

    long long ret = -(1LL << 60LL);

    long long sum = 0, sumsmall = 0;
    for (int i = 0; i < H; ++i) {
        long long sum2 = sum + tmp[i];
        ret = max(ret, sum2 - sumsmall);
        sumsmall = min(sumsmall, sum2);
        sum = sum2;
    }
    return ret;
}

long long solve(){
    for(int i=0;i<H;++i){
        rowacc[i][0] = 0;
        for(int j=0;j<W;++j){
            rowacc[i][j+1] = rowacc[i][j] + B[i][j];
        }
    }

    for(int i=0;i<W;++i) for(int j=i;j<W;++j) best[i][j] = subproblem(i,j);

    for(int i=W-1;i>=0;--i){
        for(int j=i;j<W;++j){
            if(i>0) best[i - 1][j] = max(best[i - 1][j], best[i][j]);
            if(j<W-1) best[i][j + 1] = max(best[i][j + 1], best[i][j]);
        }
    }

    long long ret = -(1LL << 60LL);
    for(int s=0;s<W-1;++s)ret = max(ret, best[0][s] + best[s + 1][W - 1]);
    return ret;
}

int main(){
    scanf("%d%d",&H,&W);
    for(int i=0;i<H;++i) for(int j=0;j<W;++j) scanf("%lld",&B[i][j]);

    long long ret = -(1LL << 60LL);

    ret = solve();
    flip();
    ret = max(ret, solve());

    printf("%lld\n", ret);
    return 0;
}
