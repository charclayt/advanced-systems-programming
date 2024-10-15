#include "my_string.hpp"

namespace custom_string {

string::string() {
    // Initialise the data pointer, size and reference count pointer to nullptr / 0
    m_data = nullptr;
    m_size = 0;
    m_referenceCount = nullptr;
}

string::string(const char* data) {
    m_size = strlen(data);
    m_data = new char[m_size];
    m_referenceCount = new size_t;

    // Copy only the characters, no null terminator
    strncpy(m_data, data, m_size);

    // Increment the reference count
    (*m_referenceCount)++;
}

string::string(string const& string) {
    // Copy the data pointer, size, and reference count pointer
    m_data = string.m_data;
    m_size = string.m_size;
    m_referenceCount = string.m_referenceCount;

    // Increment the reference count
    (*m_referenceCount)++;
}

string& string::operator=(string const& s) {
    // Check for self-assignment
    if (this != &s) {
        // Copy the data pointer, size, and reference count pointer
        m_data = s.m_data;
        m_size = s.m_size;
        m_referenceCount = s.m_referenceCount;

        // Increment the reference count
        (*m_referenceCount)++;
    }

    return *this;
}

string::~string() {
    // Decrement the reference count
    (*m_referenceCount)--;

    // If reference count is zero, free the allocated memory
    if ((*m_referenceCount) == 0) {
        delete []m_data;
        delete m_referenceCount;

        // Task 3: Explicitly print a message when the reference count is zero, and the data is deleted
        std::cout << "Destructor called: m_data and m_referenceCount deleted" << std::endl;
    } else {
        // Reference count is not zero, so we don't delete the data
        std::cout << "Destructor called: m_referenceCount decremented to " << *m_referenceCount << std::endl;
    }
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
    std::cout << m_data << "[" << *m_referenceCount << "]" << std::endl;
}

} // namespace custom_string
