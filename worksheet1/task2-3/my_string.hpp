#ifndef _MY_STRING_HPP_
#define _MY_STRING_HPP_

#include <iostream>
#include <cstring>

namespace custom_string {

class string {
  public:
    /**
     * @brief Construct a new string object
     * 
     */
    string();

    /**
     * @brief Construct a new string object
     * @param data The `const char*` to construct the string from
     */
    string(const char* data);

    /**
     * @brief Construct a new string object via shallow copy
     * 
     * @param s The `string` object to copy
     */
    string(string const& s);

    /**
     * @brief Overloaded assignment operator to shallow copy the string and pointers
     * 
     * @param s The `string` object to copy
     * @return
     */
    string& operator=(string const& s);

    /**
     * @brief Destroy the string object. If the reference count is zero, free the allocated memory
     * 
     */
    ~string();

    /**
     * @brief Get a char from the string at the given index
     * 
     * @param i The index to get the char from
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
     * @brief Print the string and the reference count
     * 
     */
    void print() const;

  private:
    char* m_data;
    size_t m_size;
    size_t* m_referenceCount;
};

} // namespace custom_string

#endif // __MY_STRING_HPP_
