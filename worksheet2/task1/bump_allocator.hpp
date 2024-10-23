#ifndef _BUMP_ALLOCATOR_HPP_
#define _BUMP_ALLOCATOR_HPP_

#include <cstring>
#include <cstdint>
#include <iostream>

namespace task1 {

class bump_allocator {
    public:
        bump_allocator(size_t size) :
            m_start(reinterpret_cast<std::uintptr_t>(new char[size])),
            m_allocationCounter(0),
            m_size(size),
            m_next(m_start) {};
        
        ~bump_allocator() {
            std::cout << "Destructor called, deallocating memory" << std::endl;
            delete reinterpret_cast<char*>(m_start);
            m_start = reinterpret_cast<std::uintptr_t>(nullptr);
        };
    
        template <typename T>
        T* allocate(size_t num) {
            std::uintptr_t current = m_next;

            size_t alignment = (m_next + alignof(T) - 1) & ~(alignof(T) - 1);
            size_t diff = alignment - current;

            if ((m_next + (sizeof(T) * num)) + diff > m_start + m_size) {
                std::cout << "Out of memory, returning nullptr" << std::endl;
                return nullptr;
            }

            m_next += ((sizeof(T) * num) + diff);

            m_allocationCounter++;

            return reinterpret_cast<T*>(current);
        };

        void deallocate() {
            m_allocationCounter--;

            if (m_allocationCounter == 0) {
                std::cout << "Allocation counter = 0, deallocating all memory" << std::endl;
                std::memset(reinterpret_cast<void*>(m_start), 0, m_size);
                m_next = m_start;
            }

            return;
        };

        size_t get_allocationCount() {
            return m_allocationCounter;
        }
    
    private:
        std::uintptr_t m_start;
        size_t m_allocationCounter;
        size_t m_size;
        std::uintptr_t m_next;
};

} // namespace task1

#endif // _BUMP_ALLOCATOR_HPP_
