#ifndef _SoleException_H_
#define _SoleException_H_
#include <stdexcept>

namespace sole
{
    struct RunException : public std::runtime_error
    {
        RunException(const std::string& s) : std::runtime_error(s) {}
    };

    struct OperatorException : public RunException
    {
        OperatorException(const std::string& s) : RunException(s) {}
    };

    struct DataException : public RunException
    {
        DataException(const std::string& s) : RunException(s) {}
    };

    struct ReaderException : public RunException
    {
        ReaderException(const std::string& s) : RunException(s) {}
    };

    struct StatmentException : public RunException
    {
        StatmentException(const std::string& s) : RunException(s) {}
    };
}
#endif