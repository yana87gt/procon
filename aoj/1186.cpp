#include <bits/stdc++.h>
using namespace std;

int main(void){
    int h,w,D;

    while(cin>>h>>w, h|w){
        bool notFound=true;
        for(D=h*h+w*w; notFound; h=0,++D){
            /*高さを1ずつ伸ばして探索*/
            while(++h, h*h<D/2){
                /*高さ固定で幅を伸ばして整長方形になるか調べる*/
                for(w=h; w*w+h*h<D; ++w);
                if(w*w+h*h==D){
                    cout<<h<<" "<<w<<endl;
                    notFound=false;
                    break;
                }
            }
        }
    }
    return 0;
}
