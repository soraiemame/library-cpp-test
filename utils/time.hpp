#ifndef SORAIE_TIME
#define SORAIE_TIME

#include <chrono>
#include <assert.h>

struct mytime{
    bool started;
    std::chrono::_V2::system_clock::time_point start;
    mytime(){started = false;}
    void s(){
        started = true;
        start = std::chrono::system_clock::now();
    }
    long long get(){
        assert(started);
        auto end = std::chrono::system_clock::now();
        auto diff = end - start;
        return std::chrono::duration_cast<std::chrono::milliseconds>(diff).count();
    }
    void out(){
        cout << "Elapsed Time: " << get() << " ms\n";
    }
};

#endif /*SORAIE_TIME*/