#include <bits/stdc++.h>
using namespace std;

int main(void){
    char c;
    cin>>c;
    char vowels[] = {'a', 'i', 'u', 'e', 'o'};
    bool ok = false;
    for (char vowel: vowels){
        if(c==vowel) ok = true;
    }
    cout<<((ok) ? "vowel" : "consonant")<<endl;
    return 0;
}
