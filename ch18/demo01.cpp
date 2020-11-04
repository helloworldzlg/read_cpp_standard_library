#include <thread>
#include <random>
#include <chrono>
#include <future>
#include <iostream>

using std::cout;
using std::endl;

int functionA()
{
    std::default_random_engine e(100);
    std::uniform_int_distribution<uint32_t> u(100, 1000);

    for (int i = 0; i < 10; ++i)
    {
        uint32_t random_data = u(e);
        std::this_thread::sleep_for(std::chrono::milliseconds(random_data));
        cout << "functionA sleep: " << random_data << endl;
    }
    return 10;
}

int functionB()
{
    std::default_random_engine e(200);
    std::uniform_int_distribution<uint32_t> u(100, 1000);

    for (int i = 0; i < 10; ++i)
    {
        uint32_t random_data = u(e);
        std::this_thread::sleep_for(std::chrono::milliseconds(random_data));
        cout << "functionB sleep: " << random_data << endl;
    }
    return 20;
}

int main()
{
    std::future<int> fuA(std::async(functionA));
    std::future<int> fuB(std::async(functionB));

    int result = fuA.get() + fuB.get();
    cout << "result = " << result << endl;

    return 0;
}