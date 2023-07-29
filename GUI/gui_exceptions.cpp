#include "gui_exceptions.hpp"

int GUI_Exception::exceptionID = 0;

GUI_Exception::GUI_Exception(std::string msg) : message(msg) {
    GUI_Exception::exceptionID++;
}

std::string const GUI_Exception::print_what() const {
    std::string msg = message + "   ID: " + std::to_string(GUI_Exception::exceptionID);
    return msg;
}

InputParsingError::InputParsingError() : GUI_Exception("An Input Parsing Error has occured!") {

}

InputParsingError::InputParsingError(std::string msg) : GUI_Exception(msg) {
    
}