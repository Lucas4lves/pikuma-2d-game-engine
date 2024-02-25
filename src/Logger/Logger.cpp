#include "./Logger.h" 
#include <chrono>
#include <ctime>


std::vector<LogEntry> Logger::messages;

std::string Logger::CurrentDateTimeToString(){

    std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::string output(30, '\0');
    //args first_char, last_char, format, src-time_t
    std::strftime(&output[0], output.size(), "%d-%b-%Y %H:%M:%S", std::localtime(&now));

    return output;
}

void Logger::Log(const std::string &message){

    std::string out = CurrentDateTimeToString();

    LogEntry entry = {};

    entry.type = LOG_INFO;
    entry.message = out + " " + message;

    std::cout << "LOG: " << "[" << entry.message << "]" << std::endl;
    messages.push_back(entry);
}

void Logger::Error(const std::string &message){
    std::string out = CurrentDateTimeToString();

    LogEntry entry = {};

    entry.type = LOG_ERROR;
    entry.message = out + " " + message;

    std::cerr << "LOG: " << "[" << entry.message << "]" << std::endl;
    messages.push_back(entry);
}