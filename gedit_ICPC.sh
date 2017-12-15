$ alias g='g++ -O2 -std=c++11 -Wall -Wextra -Wshadow'
g++ -O2 -std=c++11 -Wall -Wextra -Wshadow の部分をクリップボードにコピー
$ mkdir work
$ cd work
$ touch {a..k}.cpp


geditをクリック
Ctrl+Oで全て開く
編集（edit） -> 設定(setting) ->
「表示」のチェックボックス
- 行番号を表示
- ステータスバーを表示
- テキストの折り返しを有効にする
- 単語を二行以上に分割しない
- カーソルのある行を強調表示する
- 対応するカッコを強調する
「エディター」のチェックボックス
- 自動インデントを有効にする
「フォントと色」
システムの固定幅フォント(Ubuntu Mono 13)を使う
「プラグイン」
- コードスニペット
- 外部ツール


Manage External Tools
+ New tool -> compile

t=$GEDIT_CURRENT_DOCUMENT_NAME
g++ -O2 -std=c++11 -Wall -Wextra -Wshadow $t
（クリップボードから貼り付け）
（この二行をクリップボードにコピー）

ショートカットキー　Ctrl+G
保存　編集中のドキュメント
入力　なし
出力　ボトムペインに表示


a.cpp にテンプレートを書き込む
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<int(n);++(i))
#define all(a) (a).begin(),(a).end()
#define debug(x) cout<<(#x)<<": "<<(x)<<endl
typedef long long ll;

int main(){
	return 0;
}


サンプル入力を全て保存

+ New tool -> compile and show

t=$GEDIT_CURRENT_DOCUMENT_NAME
g++ -O2 -std=c++11 -Wall -Wextra -Wshadow $t &&
（クリップボードから貼り付け）
echo "compiled!!"
for i in $(ls | egrep "^${t%.cpp}.*in$"); do
	o=${i%.in}.out
	echo --- $i ---
	cat $i
	echo --- $o --
	./a.out < $i > $o
	cat $o
done

ショートカットキー　Shift+Ctrl+G
保存　編集中のドキュメント
入力　なし
出力　ボトムペインに表示
