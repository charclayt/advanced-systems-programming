#ifndef _REFERENCE_COUNTER_HPP_
#define _REFERENCE_COUNTER_HPP_

namespace task4 {

template <typename T>
class ref_counter {
public:
    /**
     * @brief Construct a new ref counter object
     * 
     */
    ref_counter() : m_referenceCount(nullptr), m_data(nullptr) {};

    /**
     * @brief Construct a new ref counter object
     * 
     * @param data The pre-allocated data to hold a pointer to 
     */
    ref_counter(T* data) : m_referenceCount(new size_t(1)), m_data(data) {};

    /**
     * @brief Construct a new ref counter object via shallow copy
     * 
     * @param other The `ref_counter` object to copy
     */
    ref_counter(const ref_counter& other) : m_referenceCount(other.m_referenceCount), m_data(other.m_data) {
        ++(*m_referenceCount);
    }

    /**
     * @brief Destroy the ref counter object. If the reference count is zero, free the allocated memory
     * 
     */
    ~ref_counter() {
        if (--(*m_referenceCount) == 0) {
            delete m_referenceCount;
            delete m_data;
        }
    }

    /**
     * @brief Overloaded dereference operator
     * 
     * @return `T&` The dereferenced data
     */
    T& operator* () {
        return *m_data;
    }

    /**
     * @brief Overloaded arrow operator
     * 
     * @return `T*` A pointer to the data
     */
    T* operator-> () {
        return m_data;
    }

    /**
     * @brief Overloaded assignement operator to shallow copy the data and reference count
     * 
     * @param other The `ref_counter` object to copy
     * 
     * @return Reference to `ref_counter` object
     */
    ref_counter& operator= (const ref_counter& other) {
        if (this != &other) {
            m_referenceCount = other.m_referenceCount;
            m_data = other.m_data;

            ++(*m_referenceCount);
        }

        return *this;
    }

    /**
     * @brief Get the reference count value
     * 
     * @return `size_t` The reference count value
     */
    size_t getReferenceCount() const {
        return *m_referenceCount;
    }

private:
    size_t* m_referenceCount;
    T* m_data;
};

} // namespace task4

#endif // _REFERENCE_COUNTER_HPP_
