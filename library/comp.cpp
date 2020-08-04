///
/// for vscode snippet
/// prefix: lib-comp
///

bool comp(${1:Point} &lhs, ${1:Point} &rhs) { return ${2:(lhs.x != rhs.x ? lhs.x < rhs.x : lhs.y < rhs.y)}; }
