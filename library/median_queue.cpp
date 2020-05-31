///
/// for vscode snippet
/// prefix: lib-MedianQueue
///

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

