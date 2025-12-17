#include <renderer/Logger.h>

static std::vector<std::string> messages;

void Logger::Log(const std::string& msg) {
    messages.push_back(msg);
}

const std::vector<std::string>& Logger::Get_messages() {
    return messages;
}

