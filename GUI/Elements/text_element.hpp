#ifndef TEXT_ELEMENT_HPP
#define TEXT_ELEMENT_HPP

#include "gui_element.hpp"
#include "../gui_config.hpp"

#include <string>

class TextElement : public GUI_Element {
    private:
        std::string &text;
        
        char frameSymbol;

        int width;
    public:
        std::string getInnerLine() const;
        std::string getOuterLine() const;

        void setFrameSymbol(char frameSymbol);

        void setText(std::string newString);
        std::string getText() const;

        void setWidth(int width);

        TextElement(std::string text, char frameSymbol = '#');
};

#endif