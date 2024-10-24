#ifndef _MY_STRING_HPP_
#define _MY_STRING_HPP_

#include <iostream>
#include <cstring>

#include "reference_counter.hpp"

namespace task4 {

class string {
public:
    /**
     * @brief Construct a new string object
     * 
     */
    string();

    /**
     * @brief Construct a new string object
     * 
     * @param data The `const char*` to construct the string from
     * 
     */
    string(const char* data);

    /**
     * @brief Overloaded assignment operator to shallow copy the string and pointers
     * 
     * @param s The `string` object to copy
     * 
     */
    string(string const& s);

    /**
     * @brief Overloaded assignment operator to shallow copy the string and pointers
     * 
     * @param s The `string` object to copy
     * 
     * @return Reference to `custom_string::string` object
     */
    string& operator=(string const& s);

    /**
     * @brief Get a char from the string at the given index
     * 
     * @param i The index to get the char from
     * 
     * @return `char` The char at the given index
     */
    char getChar(const int& i) const;

    /**
     * @brief Set the Char in the string at the given index
     * 
     * @param i The index to set the char at
     * @param c The char to set at the index
     */
    void setChar(const int& i, const char& c);

    /**
     * @brief Print the string
     *  
     */
    void print() const;

private:
    char* m_data;
    int32_t m_size;
};

} // namespace task4

#endif // __MY_STRING_HPP_
