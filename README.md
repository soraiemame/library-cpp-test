# これは何？
これはsoraieのライブラリです。([Twitter](https://twitter.com/soraie_),[AtCoder](https://atcoder.jp/users/soraie))  

# 目次
- [これは何？](#これは何？)
- [目次](#目次)
- [datastructure](#datastructure)
- [math](#math)

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

# math

- [floor ceil](#floor-ceil)
- [parse](#parse)
- [modint](#modint)
- [modulo](#modulo)
- [FFT](#FFT)
- [NTT(friendly mod)](#NTT(friendly-mod))

## floor ceil
- 安全な割り算
```C++
long long floordiv(long long a,long long b)
```
a / b 以下の最大の整数を求める
```C++
long long floordiv(long long a,long long b)
```
a / b 以上の最小の整数を求める

## parse
- [abc191-D](https://atcoder.jp/contests/abc191/tasks/abc191_d) を受けて作った
```C++
long long x10(std::string s,size_t n)
```
s * (10 ^ n) を求める

## modint
- mod を自動で取る構造体
```C++
modint(long long a)
```
要素が a の modint を作る

## modulo
- 組み合わせや階乗を mod で割った余りを求める
```C++
fac_solver(int n_)
```
- 上限が n_ のソルバーを作る
```C++
mint fac(int n)
```
n! を mod で割った余りを求める
```C++
mint inv(int n)
```
n の逆元を求める
```C++
mint finv(int n)
```
1~nまでの逆元の総積を求める
```C++
mint PER(int n,int k)
```
nPk を mod で割った余りを求める
```C++
mint COM(int n,int k)
```
- nCk を mod で割った余りを求める
- O(1)
```C++
mint COM2(long long n,int k)
```
- nCk を mod で割った余りを求める
- O(k)

## FFT
複素数を使った畳み込み
```C++
FFT()
```
FFT のソルバーを生成する
```C++
vector<T> convolution(vector<T> A,vector<T> B)
```
A と B を畳みこんだ結果を求める

## NTT(friendly mod)
NTT friendly の mod で畳み込みを行う
```C++
NTT<mod,base,max_exp>()
```
NTT のソルバーを生成する
```C++
vector<mint> convolution(vector<mint> A,vector<mint> B)
```
A と B を畳みこんだ結果 mod. mod を求める

