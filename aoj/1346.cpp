/*掛け算優先と順序優先の２通りで加算・乗算のみの計算を行う*/
/*
＜解法＞
順序優先の方は、合計に随時演算を行うだけ。
掛け算優先は、掛け算または式自体が終わるまでその項をとっておき、終わったら合計に足していく
*/
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    int product,sum1,sum2=0,ans; //項、順序優先、掛け算優先、答え(入力)
    char c;

    cin>>product;
    sum1=product;
    while(1){
        c=getchar();

        //式の終わりで掛け算優先に項を足す
        if(c=='\n'){
            sum2+=product;
            break;
        }

        cin>>n;

        switch(c){
        case '+':
            sum1+=n;
            sum2+=product;
            product=n;
            break;
        case '*':
            sum1*=n;
            product*=n;
            break;
        }
    }
    cin>>ans;

    /*入力の数に対して２つとも同じならU、順序優先だけ同じならL、掛け算優先だけ同じならM、どちらも違うならIを出力*/
    if(sum1==ans) c=(sum1==sum2 ? 'U' : 'L');
    else if(sum2==ans) c='M';
    else c='I';
    cout<<c<<endl;

    return 0;
}
