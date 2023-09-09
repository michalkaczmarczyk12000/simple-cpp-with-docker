#include <iostream>
#include <zmq.hpp>
#include <thread>
#include <chrono>
#include <fmt/format.h>

int main() {
    std::cout << "Worker application" << std::endl;

    zmq::context_t ctx;
    zmq::socket_t in_socket(ctx, zmq::socket_type::pull);
    zmq::socket_t out_socket(ctx, zmq::socket_type::push);

    in_socket.connect("tcp://source:8081");
    out_socket.connect("tcp://sink:8081");

    while (true) {
        zmq::message_t msg;
        auto res = in_socket.recv(msg, zmq::recv_flags::none);

    // if res than cokolwoek? 

        auto received = std::string((char*)msg.data(), msg.size());
        std::cout << fmt::format("Worker received: {}", received) << std::endl;
        
        auto processed_msg = zmq::message_t(fmt::format("{}_processed_by_worker", received));
        
        out_socket.send(processed_msg, zmq::send_flags::dontwait);
    }

    return 0;
}
