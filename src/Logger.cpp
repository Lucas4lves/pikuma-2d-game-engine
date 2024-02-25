#include <logger/Logger.h>
#include <chrono>
#include <ctime>


std::string Logger::CurrentDateTimeToString(){

    std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::string output(30, '\0');
    //args first_char, last_char, format, src-time_t
    std::strftime(&output[0], output.size(), "%d-%b-%Y %H:%M:%S", std::localtime(&now));

    return output;
}

void Logger::Log(const std::string &message){
    std::string out = CurrentDateTimeToString();
    std::cout << "LOG: " << "[" << out << " " << message << "]" << std::endl;
}

void Logger::Error(const std::string &message){
    std::string out = CurrentDateTimeToString();
    std::cerr << "ERROR: " << "[" << out << " " << message << "]" << std::endl;
}