#include "bump_allocator.test.hpp"

#include "../task1/bump_allocator.hpp"

#include "../simpletest/simpletest.h"

char const* groups[] = {
    "BumpUp",
};

// Allocate single type, check correct size has been allocated
DEFINE_TEST_GF(TestAllocateOneType, BumpUp, BumpFixture) {
    auto firstInt = m_bumpAllocator->allocate<int>(1);

    // Allocate an initial int
    TEST_MESSAGE((firstInt != nullptr), "Allocation of single int type should fit within default allocator");

    auto secondInt = m_bumpAllocator->allocate<int>(1);

    // Allocate another int
    TEST_MESSAGE((secondInt != nullptr), "Allocation of single int type should fit within default allocator");

    // Check sizeof int has been allocated
    auto size = reinterpret_cast<char*>(secondInt) - reinterpret_cast<char*>(firstInt);
    TEST_MESSAGE(size == sizeof(int), "Incorrect size allocated on allocator, should be sizeof(int) but is %d", size);
}

// Allocate more than one different type, check correct size has been allocated
DEFINE_TEST_GF(TestAllocateDifferentTypes, BumpUp, BumpFixture) {
    auto intType = m_bumpAllocator->allocate<int>(1);

    // Allocate an initial int
    TEST_MESSAGE((intType != nullptr), "Allocation of single int type should fit within default allocator");

    auto intType2 = m_bumpAllocator->allocate<int>(1);

    // Allocate another int
    TEST_MESSAGE((intType2 != nullptr), "Allocation of single int type should fit within default allocator");

    // Check sizeof int has been allocated
    auto intSize = reinterpret_cast<char*>(intType2) - reinterpret_cast<char*>(intType);
    TEST_MESSAGE(intSize == sizeof(int), "Incorrect size allocated on allocator, should be sizeof(int) but is %d", intSize);

    auto charType = m_bumpAllocator->allocate<char>(1);

    // Allocate a char
    TEST_MESSAGE((charType != nullptr), "Allocation of single char type should fit within default allocator");

    auto charType2 = m_bumpAllocator->allocate<char>(1);

    // Allocate another char
    TEST_MESSAGE((charType != nullptr), "Allocation of single char type should fit within default allocator");

    // Check sizeof char has been allocated
    auto charSize = reinterpret_cast<char*>(charType2) - reinterpret_cast<char*>(charType);
    TEST_MESSAGE(charSize == sizeof(char), "Incorrect size allocated on allocator, should be sizeof(char) but is %d", charSize);
}

// Check memory is aligned correctly, dependent on type TODO
DEFINE_TEST_GF(TestMemoryAlignment, BumpUp, BumpFixture) {
    auto charType = m_bumpAllocator->allocate<char>(1);

    // Allocate an initial char
    TEST_MESSAGE((charType != nullptr), "Allocation of single char type should fit within default allocator");

    auto intType = m_bumpAllocator->allocate<int>(1);

    // Allocate an int
    TEST_MESSAGE((intType != nullptr), "Allocation of single int type should fit within default allocator");

    std::cout << "alignment=" << reinterpret_cast<std::uintptr_t>(intType) % alignof(int) << std::endl;

    // Check memory is aligned correctly
    // TEST_MESSAGE(((reinterpret_cast<char*>(charType) - reinterpret_cast<char*>(intType)) == sizeof(int)), "Memory is not aligned correctly");
}

// Allocate over size of allocator, check nullptr is returned
DEFINE_TEST_G(TestAllocateOverSize, BumpUp) {
    auto bumpAllocator = task1::bump_allocator(1);

    // Attempt to allocate over size of allocator
    TEST_MESSAGE((bumpAllocator.allocate<char>(2) == nullptr), "Attempt to allocate over size of allocator should return nullptr");
}

// Allocate bytes up to nullptr, check correct size has been allocated
DEFINE_TEST_G(TestConstructionSize, BumpUp) {
    auto bumpAllocator = task1::bump_allocator(10);
    int count = 0;

    // Allocate bytes up to nullptr
    while (bumpAllocator.allocate<char>(1) != nullptr) {
        count++;
    }

    TEST_MESSAGE((count == 10), "Incorrect size allocated on allocator, should be 10 but is %d", count);
}

// Allocate types, check allocation counter is incremented
DEFINE_TEST_GF(TestAllocationCounterAllocate, BumpUp, BumpFixture) {
    auto intType = m_bumpAllocator->allocate<int>(1);

    // Allocate an initial int
    TEST_MESSAGE((intType != nullptr), "Allocation of single int type should fit within default allocator");

    // Check allocation counter
    TEST_MESSAGE((m_bumpAllocator->get_allocationCount() == 1), "Incorrect allocation counter, should be 1 but is %d", m_bumpAllocator->get_allocationCount());

    auto intType2 = m_bumpAllocator->allocate<int>(1);

    // Allocate another int
    TEST_MESSAGE((intType2 != nullptr), "Allocation of single int type should fit within default allocator");

    // Check allocation counter
    TEST_MESSAGE((m_bumpAllocator->get_allocationCount() == 2), "Incorrect allocation counter, should be 2 but is %d", m_bumpAllocator->get_allocationCount());
}

// Deallocate types, check allocation counter is decremented
DEFINE_TEST_GF(TestAllocationCounterDeallocate, BumpUp, BumpFixture) {
    auto intType = m_bumpAllocator->allocate<int>(1);

    // Allocate an initial int
    TEST_MESSAGE((intType != nullptr), "Allocation of single int type should fit within default allocator");

    auto intType2 = m_bumpAllocator->allocate<int>(1);

    // Allocate another int
    TEST_MESSAGE((intType2 != nullptr), "Allocation of single int type should fit within default allocator");

    m_bumpAllocator->deallocate();

    // Deallocate memory
    TEST_MESSAGE((m_bumpAllocator->get_allocationCount() == 1), "Incorrect allocation counter, should be 1 but is %d", m_bumpAllocator->get_allocationCount());

    m_bumpAllocator->deallocate();

    // Deallocate memory
    TEST_MESSAGE((m_bumpAllocator->get_allocationCount() == 0), "Incorrect allocation counter, should be 0 but is %d", m_bumpAllocator->get_allocationCount());
}

// Allocate memory and initialise, then deallocate and check memory has been cleared
DEFINE_TEST_GF(TestDeallocateNullifyMemory, BumpUp, BumpFixture) {
    auto intType = m_bumpAllocator->allocate<int>(2);
    auto intType2 = m_bumpAllocator->allocate<int>(1);

    // Set allocated memory to 1
    *intType2 = 1;

    // Check allocated memory is set to 1
    TEST_MESSAGE((*intType2 == 1), "Memory should be set to 1, but is %d", *intType2);

    // Deallocate both allocations
    m_bumpAllocator->deallocate();
    m_bumpAllocator->deallocate();

    // Check previously allocated memory is set to 0
    TEST_MESSAGE((*intType2 == 0), "Memory should be set to 0, but is %d", *intType2);
}

/**
 * @brief Run all tests
 * 
 * @return `int` pass / fail
 */
int main() {
    bool pass = true;

    for (auto group : groups) {
        pass &= TestFixture::ExecuteTestGroup(group, TestFixture::Verbose);
    }

    return pass ? 0 : 1;
}
