# これは何？
これはsoraieのライブラリです。([Twitter](https://twitter.com/soraie_),[AtCoder](https://atcoder.jp/users/soraie))  

# 目次
- [これは何？](#これは何？)

# datastructure
- [unionfind](##unionfind)
- [binary indedxed tree](##binrayindexedtree)

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

