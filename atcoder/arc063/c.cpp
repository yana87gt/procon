#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
	cin>>s;
	cout<<unique(s.begin(),s.end())-s.begin()-1<<endl;
}