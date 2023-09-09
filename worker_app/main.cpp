#include <iostream>
#include <zmq.hpp>
#include <thread>
#include <chrono>
#include <fmt/format.h>

int main() {
    std::cout << "Worker application" << std::endl;

    zmq::context_t ctx;
    zmq::socket_t sock_1(ctx, zmq::socket_type::pull);
    sock_1.connect("ipc:///zmq/source");

    while (true) {
        zmq::message_t msg;
        auto res = sock_1.recv(msg, zmq::recv_flags::none);

    // if res than cokolwoek? 

        auto received = std::string((char*)msg.data(), msg.size());
        std::cout << fmt::format("Worker received: {}", received) << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }

    return 0;
}
