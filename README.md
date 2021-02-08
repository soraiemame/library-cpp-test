# これは何？
これはsoraieのライブラリです。([Twitter](https://twitter.com/soraie_),[AtCoder](https://atcoder.jp/users/soraie))  

# 目次
- [これは何？](#これは何？)

# datastructure
- [unionfind](#unionfind)
- [unionfind abstract](#unionfind-abstract)
- [binary indedxed tree](#binray-indexed-tree)
- [sparse table](#sparse-table)
- [segtree](#segtree)
- [lazy segtree](#lazy-segtree)

## unionfind
- union find木
- 経路圧縮のみ

```C++
UnionFind(int n_)
```
要素数 n_ の UnionFind を作る
```C++
int find(int v)
```
v の根を求める
```C++
void unite(int a,int b)
```
a を含む木と b 含む木を併合する
```C++
bool same(int a,int b)
```
a と b が同じ木に含まれているかを求める
```C++
int size(int v)
```
v を含む木の要素数を求める

## unionfind abstract
- 抽象化された Union Find 木
- 経路圧縮のみ

```C++
UnionFind(int n_,function<void(T&,T&)> f_)
```
要素数 n_ 関数 f_ の unionfind を作る
```C++
void set(int a,T m)
```
要素 a を m にする
```C++
int find(int v)
```
v の根を求める
```C++
void unite(int a,int b)
```
- a を含む木と b 含む木を併合する
- 併合が成功した場合 a の根のデータと b の根のデータに f を適応する
- 要素数の大きい方の木が a
```C++
bool same(int a,int b)
```
a と b が同じ木に含まれているかを求める
```C++
int size(int v)
```
v を含む木の要素数を求める

## binray indexed tree
- binray indexed tree(fenwick tree)
- 1点加算 区間総和
- 0indexed

```C++
BinaryIndexedTree(int n_)
```
要素数 n_ 型が T の BinaryIndexedTree を作る
```C++
void add(int m,T a)
```
要素mにaを加える
```C++
T sum(int m)
```
区間 [0,m) の要素の和を求める
```C++
T sum(int l,int r)
```
区間 [l,r) の要素の和を求める
```C++
void deb()
```
要素を全て出力する

## sparse table
- sparse table
- 区間最小値を求める

```C++
SparseTable(vector<T> table_)
```
table_ をもとにした sparse table を構築する
```C++
T query(int l,int r)
```
[l,r) における区間最小値を求める

## segtree
- segment tree

```C++
SegTree(int n_,T e_,function<T(T,T)> f_)
```
要素数 n_ 単位元 e_ 関数 f_ の segtree を作る
```C++
void set(int m,T a)
```
要素 m を a にする
```C++
void build()
```
segtree を構築する
```C++
void update(int m,T a)
```
要素 m を a にする
```C++
void add(int m,T a)
```
要素 m に a を加える
```C++
T query(int l,int r)
```
[l,r) への結果を求める
```C++
T get(int a)
```
要素 a を取得する

## lazy segtree
- 遅延セグメント木
- 抽象化**していない**

```C++
SegTree(int n_,T e)
```
要素数 n_ 上限 e のsegtreeを作る
```C++
void set(int a,T x)
```
要素 a を x にする
```C++
void build()
```
segtree を構築する
```C++
T range_add(int a,int b,T x)
```
[a,b) に x を足す
```C++
T range_update(int a,int b,T x)
```
[a,b) を x にする
```C++
T range_min(int a,int b)
```
[a,b) の最小値を求める
```C++
T range_max(int a,int b)
```
[a,b) の最大値を求める
```C++
T range_sum(int a,int b)
```
[a,b) の総和を求める
```C++
T get(int a)
```
要素 a を取得する

