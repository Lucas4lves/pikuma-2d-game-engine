#include <logger/Logger.h>
#include <chrono>
#include <ctime>

void Logger::Log(const std::string &message){
    auto temp = std::chrono::system_clock::now();

    std::time_t moment = std::chrono::system_clock::to_time_t(temp);

    std::cout << "LOG: " << "[" << std::ctime(&moment) << message << "]" << std::endl;
}

void Logger::Error(const std::string &message){
    std::cerr << message << std::endl;
}