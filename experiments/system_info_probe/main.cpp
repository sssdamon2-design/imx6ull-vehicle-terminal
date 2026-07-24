#include <fstream>
#include <iostream>

int main()
{
    std::ifstream uptimeFile("/proc/uptime");

    if (!uptimeFile.is_open()) {
        std::cerr << "Failed to open /proc/uptime" << std::endl;
        return 1;
    }

    double uptimeSeconds = 0.0;
    uptimeFile >> uptimeSeconds;

    if (uptimeFile.fail()) {
        std::cerr << "Failed to parse uptime value" << std::endl;
        return 2;
    }

    std::cout << "uptime_seconds=" << uptimeSeconds << std::endl;

    return 0;
}
