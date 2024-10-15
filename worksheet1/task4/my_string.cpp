#include "my_string.hpp"

#include "reference_counter.hpp" 

namespace task4 {

string::string() {
  m_data = nullptr;
  m_size = 0;
}

string::string(const char* data) {
  m_size = strlen(data) + 1;
  m_data = new char[m_size];
  strcpy(m_data, data);
}

string::string(string const& string) {
  m_data = string.m_data;
  m_size = string.m_size;
}

string& string::operator=(string const& s) {
  if (this != &s) {
    m_data = s.m_data;
    m_size = s.m_size;
  }

  return *this;
}

char string::getChar(const int& i) const {
  if (i < 0 || i >= m_size) {
    throw std::invalid_argument("Index is out of bounds");
  }

  return m_data[i];
}

void string::setChar(const int& i, const char& c) {
  if (i < 0 || i >= m_size) {
    throw std::invalid_argument("Index is out of bounds");
  }

  m_data[i] = c;
}

void string::print() const {
    std::cout << m_data << std::endl;
}

} // namespace task4
