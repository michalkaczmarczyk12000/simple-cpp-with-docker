#include <iostream>
#include <zmq.hpp>
#include <thread>
#include <chrono>
#include <fmt/format.h>

int main() {
    std::cout << "Sink application" << std::endl;

    while (true) {
        std::cout << fmt::format("Sink") << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }

    return 0;
}
