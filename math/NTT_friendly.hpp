#ifndef SORAIE_NTT_FRIENDLY
#define SORAIE_NTT_FRIENDLY

#include <vector>
#include "../math/modint.hpp"


//ex. (2013265921,137,27),(998244353,31,23),(469762049,30,26)
template<long long MOD,int base,int max_exp>
struct NTT{
    using mint = modint<MOD>;
    std::vector<mint> bases,invs;
    NTT(){
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
        int sz = 1;
        while(sz < A.size() + B.size())sz <<= 1;
        std::vector<mint> f(sz),g(sz);
        for(int i = 0;i < A.size();i++){
            f[i] = A[i];
            g[i] = B[i];
        }
        dft(f,1);dft(g,1);
        for(int i = 0;i < sz;i++)f[i] = f[i] * g[i];
        dft(f,-1);
        mint inv = mint(sz).inv();
        for(int i = 0;i < sz;i++)f[i] *= inv;
        return f;
    }
};

#endif /*SORAIE_NTT_FRIENDLY*/