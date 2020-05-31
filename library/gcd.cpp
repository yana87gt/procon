///
/// for vscode snippet
/// prefix: lib-gcd
///

long long gcd(long long  a, long long  b) { return b==0 ? a : gcd(b,a%b); }
