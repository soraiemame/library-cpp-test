#ifndef SORAIE_NTT
#define SORAIE_NTT

#include <vector>
#include <assert.h>

#include "garner.hpp"
#include "NTT_primitive_mod.hpp"

template<long long MOD>
struct NTT_all{
    NTT_primitive<2013265921,137,27> ntt1;
    NTT_primitive<998244353,31,23> ntt2;
    NTT_primitive<469762049,30,26> ntt3;
    using mint = modint<MOD>;
    using mint1 = modint<2013265921>;
    using mint2 = modint<998244353>;
    using mint3 = modint<469762049>;
    NTT_all(){}
    
    std::vector<mint> convolution(const std::vector<mint>& A,const std::vector<mint>& B){
        assert(A.size() == B.size());
        int sz = A.size();
        std::vector<mint1> A1(sz),B1(sz);
        std::vector<mint2> A2(sz),B2(sz);
        std::vector<mint3> A3(sz),B3(sz);
        for(int i = 0;i < sz;i++){
            A1[i] = A[i].x;A2[i] = A[i].x;A3[i] = A[i].x;
            B1[i] = B[i].x;B2[i] = B[i].x;B3[i] = B[i].x;
        }
        auto C1 = ntt1.convolution(A1,B1);
        auto C2 = ntt2.convolution(A2,B2);
        auto C3 = ntt3.convolution(A3,B3);
        int rs = C1.size();
        std::vector<mint> res(rs);
        for(int i = 0;i < rs;i++){
            std::vector<long long> r = {C1[i].x,C2[i].x,C3[i].x},m = {2013265921,998244353,469762049};
            res[i] = garner(r,m,MOD);
        }
        return res;
    }
    std::vector<long long> convolution(const std::vector<long long>& A,const std::vector<long long>& B){
        assert(A.size() == B.size());
        int sz = A.size();
        std::vector<long long> A1(sz),B1(sz),A2(sz),B2(sz),A3(sz),B3(sz);
        for(int i = 0;i < sz;i++){
            A1[i] = A[i] % 2013265921;B1[i] = B[i] % 2013265921;
            A2[i] = A[i] % 998244353;B2[i] = B[i] % 998244353;
            A3[i] = A[i] % 469762049;B3[i] = B[i] % 469762049;
        }
        auto C1 = ntt1.convolution(A1,B1);
        auto C2 = ntt2.convolution(A2,B2);
        auto C3 = ntt3.convolution(A3,B3);
        int rs = C1.size();
        std::vector<long long> res(rs);
        for(int i = 0;i < rs;i++){
            std::vector<long long> r = {C1[i],C2[i],C3[i]},m = {2013265921,998244353,469762049};
            res[i] = garner(r,m,MOD) % MOD;
        }
        return res;
    }
};

#endif /*SORAIE_NTT*/