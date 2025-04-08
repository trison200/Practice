#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    std::stringstream ss;
    ss << "The answer is " << 42 << " and pi is " << 3.14;
    std::string result = ss.str();
    std::cout << result << std::endl;

    return 0;
}