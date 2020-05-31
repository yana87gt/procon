#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;
const int INF = 1e9;

template <typename T>
class MedianQueue{
  public:
    priority_queue<T,vector<T>> leftQ;
    priority_queue<T,vector<T>,greater<T>> rightQ;
    MedianQueue() {}
    ~MedianQueue() {}
    void push(T x) {
        if (leftQ.empty() || x <= leftQ.top()) {
            leftQ.push(x);
        } else {
            rightQ.push(x);
        }
    }
    pair<T,T> median() {
        while (abs((int)leftQ.size() - (int)rightQ.size()) > 1) {
            if (leftQ.size() < rightQ.size()) {
                leftQ.push(rightQ.top());
                rightQ.pop();
            } else {
                rightQ.push(leftQ.top());
                leftQ.pop();
            }
        }
        if (leftQ.size() + 1 == rightQ.size()) {
            return {rightQ.top(), rightQ.top()};
        } else if (leftQ.size() == rightQ.size() + 1){
            return {leftQ.top(), leftQ.top()};
        } else {
            return {leftQ.top(), rightQ.top()};
        }
    }
    int size() {
        return leftQ.size() + rightQ.size();
    }
};

int main(void){
    int Q;
    cin >> Q;
    MedianQueue<ll> qu;
    qu.push(-INF);
    qu.push(+INF);
    pair<ll,ll> med = qu.median();
    ll height = 0;
    rep(i,Q){
        int q;
        cin >> q;
        if (q == 1) {
            ll a,b;
            cin >> a >> b;
            height += b;
            qu.push(a);
            if (a < med.first || med.second < a) {
                height += min(abs(a - med.first), abs(a - med.second));
            }
            med = qu.median();
        } else {
            cout << med.first << " " << height << endl;
        }
    }
    return 0;
}
