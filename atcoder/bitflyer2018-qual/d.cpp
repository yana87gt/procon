#include <bits/stdc++.h>
using namespace std;
#define rep(i,Y) for(int i=0;i<int(Y);++i)
#define all(a) a.begin(),a.end()
typedef long long ll;

template <typename T>
class Imos2D{
  public:
    int Y,X;
    vector<vector<T>> s;

    Imos2D(){}
    ~Imos2D(){}
    Imos2D(int Y_, int X_): Y(Y_),X(X_) {
        s.resize(Y+1);
        rep(y,Y+1) s[y].resize(X+1);
    }

    void add(int y,int x,int h,int w,T v){
        s[y][x] += v;
        s[y][x+w+1] -= v;
        s[y+h+1][x] -= v;
        s[y+h+1][x+w+1] += v;
    }

    void simulate(){
        rep(y,Y)rep(x,X-1){
            s[y][x+1] += s[y][x];
        }
        rep(y,Y-1)rep(x,X){
            s[y+1][x] += s[y][x];
        }
    }
    vector<T>& operator[](std::size_t y) &{ return s[y]; }
};

int main(void){
    ll H,W,Y,X;
    cin>>H>>W>>Y>>X;
    vector<string> a(Y);
    bool zero = true;
    rep(i,Y){
        cin>>a[i];
        if(count(all(a[i]),'#')) zero = false;
    }
    if(zero){
        cout<<0<<endl;
        return 0;
    }

    int YY = min(H,Y*2), XX = min(W,X*2);
    int l = X-1,r = -1, u = Y-1, d = -1;
    Imos2D<int> imos(YY,XX);
    rep(y,Y)rep(x,X){
        if(a[y][x] == '#'){
            imos.add(y,x,YY-Y,XX-X,1);
            l = min(x,l);
            r = max(x,r);
            u = min(y,u);
            d = max(y,d);
        }
    }
    imos.simulate();
    ll space = 0;
    rep(y,YY)rep(x,XX) if(imos[y][x]==0) space++;
    if(H-2*Y > 0) space += (H-2*Y)*(l + X-r-1);
    if(W-2*X > 0) space += (W-2*X)*(u + Y-d-1);

    cout<<H*W-space<<endl;
    return 0;
}
