#include <zmq.hpp>
#include <string>
#include <iostream>

int main() {
    zmq::context_t context(1);
    zmq::socket_t socket(context, ZMQ_PUSH);
    socket.bind("tcp://*:5555");

    std::string message = "기가차드가 보낸 메시지!";
    zmq::message_t zmq_message(message.size());
    memcpy(zmq_message.data(), message.c_str(), message.size());

    std::cout << "Sending: " << message << std::endl;
    socket.send(zmq_message, zmq::send_flags::none);

    return 0;
}
