#pragma once

#include <string>
#include <list>
#include <stdint.h>
#include <memory>

namespace xlog { 

//日志事件
class LogEvent{
public:
    typedef std::shared_ptr<LogEvent> ptr;
    LogEvent();
    ~ LogEvent();
private:
    const char* _file = nullptr;    //文件名
    int32_t _line = 0;              //行号
    uint32_t _elapse;               //启动总时间(ms)
    uint32_t _threadId = 0;         //线程id
    uint32_t _fiberId = 0;          //携程id
    uint64_t _time = 0;             //时间戳
    std::string _content;           //
};


//日志级别
class LogLevel{
public:
    enum Level {
        DEBUG = 1,
        INFO = 2,
        WARNING = 3,
        ERROR = 4,
        FATAL = 5,
    };
};


//日志输出器
class LogAppender{
public:
    typedef std::shared_ptr<LogAppender> ptr;
    virtual ~LogAppender();

    void Log(LogLevel::Level level, const LogEvent::ptr& event);
private:
    LogLevel::Level _level;
};


//日志格式器
class LogFormatter{
public:
    typedef std::shared_ptr<LogFormatter> ptr;

    std::string Formatter(const LogEvent::ptr& event);
private:
};


//Log
class Logger{
public:
    typedef std::shared_ptr<Logger> ptr;

    Logger(const std::string& name = "root");

    void Log(LogLevel::Level level, const LogEvent::ptr& event);
    void Debug(const LogEvent::ptr& event);
    void Info(const LogEvent::ptr& event);
    void Warning(const LogEvent::ptr& event);
    void Error(const LogEvent::ptr& event);
    void Fatal(const LogEvent::ptr& event);

    void AddAppender(LogAppender::ptr& appender);
    void RemoveAppender(LogAppender::ptr& appender);

    LogLevel::Level getLevel() const { return _level; }
    void setLevel(LogLevel::Level val) { _level = val; }
private:
    std::string _name;              //日志名称
    LogLevel::Level _level;         //日志级别
    std::list<LogAppender::ptr> _appender;
};
}
