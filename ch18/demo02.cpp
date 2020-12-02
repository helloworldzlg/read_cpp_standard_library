#include <iostream>
#include <thread>

using std::cout;
using std::endl;

void function()
{
    cout << "this is thread" << endl;
}

int main()
{
    std::thread t1(function);

    t1.join();
    return 0;
}