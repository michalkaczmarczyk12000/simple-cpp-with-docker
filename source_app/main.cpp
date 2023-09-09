#include <iostream>
#include <zmq.hpp>
#include <thread>
#include <chrono>
#include <fmt/format.h>

int main() {
    std::cout << "Source application" << std::endl;

    unsigned long long message_idx = 0;

    zmq::context_t ctx;
    zmq::socket_t sock(ctx, zmq::socket_type::push);
    sock.bind("tcp://0.0.0.0:8081");

    while (true) {
        std::string message = fmt::format("Message {}", message_idx++);
        zmq::message_t msg(message);
        sock.send(msg, zmq::send_flags::dontwait);
        std::cout << fmt::format("Source produced: {}", message) << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }

    return 0;
}
