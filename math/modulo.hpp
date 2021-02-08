#ifndef SORAIE_MODULO
#define SORAIE_MODULO

#include <vector>
#include "modint.hpp"

template<long long MOD = 1000000007>
struct fac_solver{
    using mint = modint<MOD>;
private:
    std::vector<mint> fac_vec,inv_vec,finv_vec;
    void expand(int n){
        if(fac_vec.size() > n)return;
        else{
            for(int i = fac_vec.size() - 1;i < n;i++){
                fac_vec.push_back(fac_vec[i] * (i + 1));
                inv_vec.push_back(-(inv_vec[MOD % i] * (MOD / i)));
                finv_vec.push_back(finv_vec[i] * inv_vec[i + 1]);
            }
        }
    }
public:
    fac_solver(int n_ = 0){
        if(n_){
            fac_vec.resize(n_);inv_vec.resize(n_);finv_vec.resize(n_);
            fac_vec[0] = fac_vec[1] = inv_vec[0] = inv_vec[1] = finv_vec[0] = finv_vec[1] = 1;
            for(int i = 2;i < n_;i++){
                fac_vec[i] = fac_vec[i - 1] * i;
                inv_vec[i] = -(inv_vec[MOD % i] * (MOD / i));
                finv_vec[i] = finv_vec[i - 1] * inv_vec[i];
            }
        }
    }
    mint fac(int n){
        expand(n);
        return fac_vec[n];
    }
    mint inv(int n){
        expand(n);
        return inv_vec[n];
    }
    mint finv(int n){
        expand(n);
        return finv_vec[n];
    }
    mint PER(int n,int k){
        if(n < 0 || k < 0 || k > n)return 0;
        else return fac(n) * finv(n - k);
    }
    mint COM(int n,int k){
        return PER(n,k) * finv(k);
    }
    mint COM2(long long n,int k){
        mint res(1);
        for(long long i = n - k + 1;i <= n;i++)res *= i;
        for(int i = 1;i <= k;i++)res /= i;
        return res;
    }
};


#endif /*SORAIE_MODULO*/