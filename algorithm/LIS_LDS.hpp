#ifndef SORAIE_LIS_LDS
#define SORAIE_LIS_LDS

#include <vector>
#include <algorithm>

template<class T>
std::vector<int> LIS(const std::vector<T>& vec){
    int n = vec.size();
    std::vector<int> memo(n,INT32_MAX);
    for(T a : vec)*std::lower_bound(memo.begin(),memo.end(),a) = a;
    return std::vector<int>(memo.begin(),std::lower_bound(memo.begin(),memo.end(),INT32_MAX));
}
template<class T>
std::vector<int> LDS(const std::vector<T>& _vec){
    std::vector<T> vec = _vec;
    std::reverse(vec.begin(),vec.end());
    auto res = LIS(vec);
    std::reverse(res.begin(),res.end());
    return res;
}

#endif/*SORAIE_LIS_LDS*/