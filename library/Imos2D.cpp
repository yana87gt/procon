///
/// for vscode snippet
/// prefix: lib-Imos2D
///

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