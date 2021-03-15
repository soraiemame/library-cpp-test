#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_B"

#include <iostream>
#include <string>

#include "../string/rolling_hash.hpp"

int main(){
    rolling_hash ro;
    std::string S,T;
    std::cin >> S >> T;
    auto s = ro.build(S),t = ro.build(T);
    for(int i = 0;i < int(S.size()) - int(T.size()) + 1;i++){
        if(ro.get(s,i,i + int(T.size())) == ro.get(t,0,int(T.size())))std::cout << i << "\n";
    }
}