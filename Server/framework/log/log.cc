#include "log.h"

namespace xlog{

Logger::Logger(const std::string& name = "root") 
    :_name(name){
}

void Logger::AddAppender(LogAppender::ptr& appender){
    _appender.push_back(appender);
}

void Logger::RemoveAppender(LogAppender::ptr& appender){
    for(auto it = _appender.begin(); it != _appender.end(); ++it) {
        if(*it == appender){
            _appender.erase(it);
            break;
        }
    }
}

void Logger::Log(LogLevel::Level level, const LogEvent::ptr& event){
    if(level >= _level){
        for(auto& it : _appender){
            it->Log(level, event);
        }
    }
}

void Logger::Debug(const LogEvent::ptr& event){
    Log(LogLevel::DEBUG, event);
}

void Logger::Info(const LogEvent::ptr& event){
    Log(LogLevel::INFO, event);
}

void Logger::Warning(const LogEvent::ptr& event){
    Log(LogLevel::WARNING, event);
}

void Logger::Error(const LogEvent::ptr& event){
    Log(LogLevel::ERROR, event);
}

void Logger::Fatal(const LogEvent::ptr& event){
    Log(LogLevel::FATAL, event);
}


}