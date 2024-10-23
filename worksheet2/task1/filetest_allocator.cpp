#include "bump_allocator.hpp"

int main() {
    // Create bump_allocator object with size 40
    task1::bump_allocator allocator(40);

    // Allocate space for one char
    char* test_char = allocator.allocate<char>(1);

    // Allocate space for one int
    int* test_int = allocator.allocate<int>(1);

    // Initialise int pointer to 2
    *test_int = 2;

    // Print the value of the int pointer if allocation successful
    if (test_int != nullptr) {
        std::cout << *test_int << std::endl;
    } else {
        std::cout << "nullptr" << std::endl;
    }

    // Allocate space for another char
    char* test_char2 = allocator.allocate<char>(1);

    // Initialise int pointer to 'a'
    *test_char2 = 'a';

    // Print the value of the char pointer if allocation successful
    if (test_char2 != nullptr) {
        std::cout << *test_char2 << std::endl;
    } else {
        std::cout << "nullptr" << std::endl;
    }

    // Deallocate all allocations, should print "Allocation counter = 0, deallocating all memory" and reset pointer to start
    allocator.deallocate();
    allocator.deallocate();
    allocator.deallocate();

    return 0;
}
