#ifndef SORAIE_NTT_PRIMITIVE
#define SORAIE_NTT_PRIMITIVE

#include <vector>
#include <assert.h>

#include "modint.hpp"
#include "math.hpp"

//ex. (2013265921,137,27),(998244353,31,23),(469762049,30,26)
template<long long MOD,int base,int max_exp>
struct NTT_primitive{
    using mint = modint<MOD>;
    std::vector<mint> bases,invs;
    NTT_primitive(){
        bases.resize(max_exp + 1);invs.resize(max_exp + 1);
        bases[max_exp] = base;
        invs[max_exp] = mint(base).inv();
        for(int i = max_exp - 1;i >= 0;i--){
            bases[i] = bases[i + 1] * bases[i + 1];
            invs[i] = invs[i + 1] * invs[i + 1];
        }
    }
    void dft(std::vector<mint>& vec,int t){
        int sz = vec.size();
        if(sz == 1)return;
        std::vector<mint> veca,vecb;
        for(int i = 0;i < sz / 2;i++){
            veca.push_back(vec[i * 2]);
            vecb.push_back(vec[i * 2 + 1]);
        }
        dft(veca,t);
        dft(vecb,t);
        
        int e = __builtin_ffsll(sz) - 1;
        mint now = 1,zeta = (t == 1 ? bases[e]:invs[e]);
        for(int i = 0;i < sz;i++){
            vec[i] = veca[i % (sz / 2)] + now * vecb[i % (sz / 2)];
            now *= zeta;
        }
    }
    std::vector<mint> convolution(const std::vector<mint>& A,const std::vector<mint>& B){
        // assert(A.size() == B.size());
        int sz = 1;
        while(sz < int(A.size() + B.size()))sz <<= 1;
        std::vector<mint> f(sz),g(sz);
        for(int i = 0;i < int(A.size());i++)f[i] = A[i];
        for(int i = 0;i < int(B.size());i++)g[i] = B[i];
        dft(f,1);dft(g,1);
        for(int i = 0;i < sz;i++)f[i] = f[i] * g[i];
        dft(f,-1);
        mint inv = mint(sz).inv();
        for(int i = 0;i < sz;i++)f[i] *= inv;
        return f;
    }
    void dft(std::vector<long long>& vec,int t){
        int sz = vec.size();
        if(sz == 1)return;
        std::vector<long long> veca,vecb;
        for(int i = 0;i < sz / 2;i++){
            veca.push_back(vec[i * 2]);
            vecb.push_back(vec[i * 2 + 1]);
        }
        dft(veca,t);
        dft(vecb,t);
        
        int e = __builtin_ffsll(sz) - 1;
        long long now = 1,zeta = (t == 1 ? bases[e].x:invs[e].x);
        for(int i = 0;i < sz;i++){
            vec[i] = (veca[i % (sz / 2)] + now * vecb[i % (sz / 2)] % MOD) % MOD;
            now = now * zeta % MOD;
        }
    }
    std::vector<long long> convolution(const std::vector<long long>& A,const std::vector<long long>& B){
        // assert(A.size() == B.size());
        int sz = 1;
        while(sz < int(A.size() + B.size()))sz <<= 1;
        std::vector<long long> f(sz),g(sz);
        for(int i = 0;i < int(A.size());i++)f[i] = A[i] % MOD;
        for(int i = 0;i < int(B.size());i++)g[i] = B[i] % MOD;
        dft(f,1);dft(g,1);
        for(int i = 0;i < sz;i++)f[i] = f[i] * g[i] % MOD;
        dft(f,-1);
        long long inv = modinv(sz,MOD);
        for(int i = 0;i < sz;i++)f[i] = f[i] * inv % MOD;
        return f;
    }
};



#endif /*SORAIE_NTT_PRIMITIVE*/