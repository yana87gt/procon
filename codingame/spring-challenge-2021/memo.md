# Link

https://www.codingame.com/ide/challenge/spring-challenge-2021
https://www.codingame.com/contests/spring-challenge-2021/top-companies
https://www.codingame.com/contests/spring-challenge-2021/leaderboard/global

https://inaniwa.hatenablog.com/entry/2021/05/07/031102

https://github.com/s-vivien/CGBenchmark

# Run benchmark
https://github.com/shirakia/SpringChallenge2021
http://cgstats.magusgeek.com/app/spring-challenge-2021/

```
java -jar CGBenchmark-1.2.0.jar -c benchmark_config.yml
```

# Replay
- https://www.codingame.com/share-replay/552626226
    - day = 7 ですでに size3 * 3
    - day = 10 ですでに size3 * 5
    - しかも外側の陣地取りをしている
- https://www.codingame.com/replay/552671675
    - 終盤はsize3にGROW(-7以上)してCOMPLETE(-4)して小さい数字(+7とか)を得るよりもday18くらいからはsize2のままSUNを稼ぎけてた方がいい説
    - day18くらいからGROW禁止してみる
- iwashiさんに勝ったとき
    - https://www.codingame.com/replay/557308882

# History
- 6h空けた提出のさらに次に1h空けた提出がよかった

# 作戦

## ボツ案
- COMPLETEは後出しじゃんけん。COMPLETE砲を察知したらこちらもやる。
- 相手のそれぞれの木の個数よりも常に1つ以上多めにCOMPLETEしておく(最優先)
- 最終ターンでSunを使い切って終わる
- 敵の木が邪魔できる影方向にあったらGROW
- SEED は基本的に2個となりの空いているところへ
- my_teritory じゃない && 広く空いているところへもおきたい
- 5連砲 + 計画的完遂*5
    - [PHASE1] 5連砲までは
        - SEED優先？
        - 相手のsize3の個数をみながら、連続砲に対応できるようにSUNを残しておく(むやみにGROWしない)
        - if (my_tree_size_cnt[3] < 4) tree_size 優先でGROWする
        - else my_tree_size_cnt[tree_size + 1] が小さいの優先で SUN を浪費しないようにしながら
    - [PHASE2] 5連砲
    発動条件
        - 自分0で相手が30以上になる
        - my_tree_size_cnt[3] >= 7
        - sizeの合計が 3*5 + 10 以上である
    - [PHASE3] 5連砲しなくてもよく、socre >= oppScore + nutrients + 6 で止めて良い

## 試したい案
- 1日の行動列を決めてからweight調整をする
- 相手のsize3の個数に合わせてSUNを取っておかないとCOMPLETE砲に耐えられない?
- 自給自足
    - 4 + (MAX3-1)+7 + 3 + 1 <= 1 + 2 + 3 * (MAX3)
    - 14 + MAX3 <= 3 + 3*MAX3
    - 11 <= 2 * MAX3
    - 11/2 <= MAX3
- 相手が size3 * 7 持ってる
    - Prioritize COMPLETE してから またprioritize_complete = false;にする

## DONE
- if (day < 23 && forecast_score >= 100) return; の有効性
  -> あんまり
- gold到達のコードと同等のスコアを取る
- recieve_shadow(), affext_shadow()
  明日は
  - neigh[(day+1)%6] の方向にshadowを与える
  - neigh[(day+4)%6] の方向からshadowを受ける
- cand_schedule の 選び方を後半は if (max_grow_cnt < grow_cnt) でないようにする

## TODO
- 相手と自分の nutrients を観測

# Cost
COMPLETE = 4

GROW 
0 -> 1 : 1 + 既存のsize1の木の数(自分の木のみ)
1 -> 2 : 3 + 既存のsize2の木の数(自分の木のみ)
2 -> 3 : 7 + 既存のsize3の木の数(自分の木のみ)
