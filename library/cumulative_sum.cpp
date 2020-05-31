///
/// for vscode snippet
/// prefix: lib-cumulative_sum
///

template<typename T>
vector<T> cumulative_sum(vector<T> &v) {
    vector<T> sum(v.size() + 1);
    rep(i,v.size()){
        sum[i+1] = sum[i] + v[i];
    }
    return sum;
}
