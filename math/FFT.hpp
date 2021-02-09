#ifndef SORAIE_FFT
#define SORAIE_FFT

#include <vector>
#include <complex>

struct FFT{
    using C = std::complex<long double>;
    void dft(std::vector<C>& vec,int t){
        int sz = vec.size();
        if(sz == 1)return;
        std::vector<C> veca,vecb;
        for(int i = 0;i < sz / 2;i++){
            veca.push_back(vec[i * 2]);
            vecb.push_back(vec[i * 2 + 1]);
        }
        dft(veca,t);dft(vecb,t);
        C now = 1.0,z = std::polar(1.0,2.0 * std::acos(-1) * t / sz);
        for(int i = 0;i < sz;i++){
            vec[i] = veca[i % (sz / 2)] + now * vecb[i % (sz / 2)];
            now *= z;
        }
    }
    template<class T>
    std::vector<T> convolution(const std::vector<T>& A,const std::vector<T>& B){
        int sz = 1;
        while(sz < A.size() + B.size())sz <<= 1;
        std::vector<C> f(sz),g(sz);
        for(int i = 0;i < A.size();i++){
            f[i] = A[i];
            g[i] = B[i];
        }
        dft(f,1);dft(g,1);
        for(int i = 0;i < sz;i++)f[i] *= g[i];
        dft(f,-1);
        std::vector<T> res(sz);
        for(int i = 0;i < sz;i++)res[i] = T(f[i].real() / sz + 0.1);
        return res;
    }
};

#endif /*SORAIE_FFT*/