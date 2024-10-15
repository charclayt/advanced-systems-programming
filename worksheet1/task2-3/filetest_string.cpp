#include "my_string.hpp"

#include <iostream>

int main() {
    // Create a string object
    custom_string::string s("Hello world");
    s.print();

    {
        // Create a new string object via overloaded assignment operator
        custom_string::string t = s;
        s.print();
        t.print();

        // Get the char at index 1 in the string object
        std::cout << s.getChar(1) << std::endl;
        s.print();
        t.print();
    }

    // Set the char at index 1 in the string object and print
    s.setChar(1, 'E');
    s.print();
}
