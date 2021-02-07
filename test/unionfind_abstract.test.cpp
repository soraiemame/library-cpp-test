#define PROBLEM "https://atcoder.jp/contests/abc183/tasks/abc183_f"

#include <iostream>
#include <map>

#include "../data-structure/unionfind_abstract.hpp"

typedef std::map<int,int> T;
void fx(T& a,T& b){
    for(auto &x : b){
        a[x.first] += x.second;
        x.second = 0;
    }
}
int main(){
    int N,M;
    std::cin >> N >> M;
    UnionFind<T> UF(N,fx);
    for(int i = 0;i < N;i++){
        T ma;
        int n;
        std::cin >> n;
        ma[n]++;
        UF.set(i,ma);
    }
    for(int i = 0;i < M;i++){
        int t,a,b;
        std::cin >> t >> a >> b;
        if(t == 1){
            a--;b--;
            UF.unite(a,b);
        }
        if(t == 2){
            a--;
            std::cout << UF.dat[UF.find(a)][b] << "\n";
        }
    }
}