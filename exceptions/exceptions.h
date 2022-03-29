//
// Created by Misan on 4/7/2021.
//

#ifndef A67_915_MISAN_TEODORA_EXCEPTIONS_H
#define A67_915_MISAN_TEODORA_EXCEPTIONS_H
using namespace std;

class Exception : public exception
{
    string _msg;
public:
    Exception(const string& msg) : _msg(msg){}

    virtual const char* what() const noexcept override
    {
        return _msg.c_str();
    }
};
#endif //A67_915_MISAN_TEODORA_EXCEPTIONS_H
