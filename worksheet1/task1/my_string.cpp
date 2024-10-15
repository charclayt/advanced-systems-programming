#include "my_string.hpp"

#include <iostream>

namespace custom_string {

string::string() {
    // Initialise the data pointer, and size to nullptr / 0
    m_data = nullptr;
    m_size = 0;
}

string::string(const char* data) {
    m_size = strlen(data);
    m_data = new char[m_size];

    // Copy only the characters, no null terminator
    strncpy(m_data, data, m_size);
}

string::string(string const& string) {
    // Copy the data pointer, and size
    m_data = string.m_data;
    m_size = string.m_size;
}

string& string::operator=(string const& s) {
    // Check for self-assignment
    if (this != &s) {
        // Copy the data pointer, and size
        m_data = s.m_data;
        m_size = s.m_size;
    }

    return *this;
}

char string::getChar(const int& i) const {
    if (m_data == nullptr) { // Throw an exception if the string is empty
        throw std::invalid_argument("String is empty");
    } else if (i < 0 || i >= m_size) { // Throw an exception if the index is out of bounds
        throw std::invalid_argument("Index is out of bounds");
    }

    return m_data[i];
}

void string::setChar(const int& i, const char& c) {
    if (m_data == nullptr) { // Throw an exception if the string is empty
        throw std::invalid_argument("String is empty");
    } else if (i < 0 || i >= m_size) { // Throw an exception if the index is out of bounds
        throw std::invalid_argument("Index is out of bounds");
    }

    m_data[i] = c;
}

void string::print() const {
    std::cout << m_data << std::endl;
}

} // namespace custom_string
