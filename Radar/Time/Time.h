#include <chrono>

class _Time
{
public:
    _Time()
    {
        start_ = std::chrono::high_resolution_clock::now();
    }

    long time()
    {
        std::chrono::duration<long, std::nano> elap = std::chrono::high_resolution_clock::now() - start_;
        return elap.count();
    }

private:
    std::chrono::high_resolution_clock::time_point start_;
};