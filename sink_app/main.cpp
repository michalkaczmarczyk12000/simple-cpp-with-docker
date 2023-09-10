#include <iostream>
#include <zmq.hpp>
#include <thread>
#include <chrono>
#include <fmt/format.h>

int main() {
    std::cout << "Sink application" << std::endl;

    zmq::context_t ctx;
    zmq::socket_t sock(ctx, zmq::socket_type::pull);
    sock.bind("tcp://0.0.0.0:8081");

    while (true) {
        zmq::message_t msg;
        auto res = sock.recv(msg, zmq::recv_flags::none);

        if(res == -1)
            break;

        auto received = std::string((char*)msg.data(), msg.size());
        std::cout << fmt::format("Sink received: {}", received) << std::endl;
    }

    return 0;
}
