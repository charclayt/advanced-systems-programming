#include "bump_allocator.hpp"

int main() {
    task1::bump_allocator a(40);

    char* b = a.allocate<char>(1);

    int* x = a.allocate<int>(1);

    char* y = a.allocate<char>(1);

    char* z = a.allocate<char>(3);

    int* w = a.allocate<int>(1);

    // // char* ptr3 = a.allocate<char>(1);

    // // int* ptr = a.allocate<int>(1);

    // // *ptr = 2;

    // // if (ptr != nullptr) {
    // //     std::cout << *ptr << std::endl;
    // // } else {
    // //     std::cout << "nullptr" << std::endl;
    // // }

    // // char* ptr2 = a.allocate<char>(1);

    // // *ptr2 = 'a';

    // int* ptr2 = a.allocate<int>(1);

    // if (ptr2 != nullptr) {
    //     std::cout << *ptr2 << std::endl;
    // } else {
    //     std::cout << "nullptr" << std::endl;
    // }

    // a.deallocate();

    // int* ptr3 = a.allocate<int>(1);
    // // *ptr3 = 3;
    
    // if (ptr3 != nullptr) {
    //     std::cout << *ptr3 << std::endl;
    // } else {
    //     std::cout << "nullptr" << std::endl;
    // }

    return 0;
}
