#ifndef GUI_EXCEPTIONS_HPP
#define GUI_EXCEPTIONS_HPP

#include <string>

class GUI_Exception {
    protected:
        static int exceptionID;
        const std::string message;
    public:
        GUI_Exception(std::string msg);

        std::string const print_what() const;
};

class InputParsingError : public GUI_Exception {
    public:
        InputParsingError();
        InputParsingError(std::string msg);
};

#endif