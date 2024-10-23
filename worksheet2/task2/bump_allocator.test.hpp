#include <memory>

#include "../task1/bump_allocator.hpp"

#include "../simpletest/simpletest.h"

class BumpFixture : public TestFixture {

public:
    void Setup() override {
        m_bumpAllocator = std::make_unique<task1::bump_allocator>(1024);
    }

    void TearDown() override {
        std::cout << m_bumpAllocator->get_allocationCount() << std::endl;
        auto allocCount = m_bumpAllocator->get_allocationCount();

        while (allocCount > 0) {
            m_bumpAllocator->deallocate();
            allocCount--;
        }

        m_bumpAllocator.reset();
    }

    std::unique_ptr<task1::bump_allocator> m_bumpAllocator;
};;
