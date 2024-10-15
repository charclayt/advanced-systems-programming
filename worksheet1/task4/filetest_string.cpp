#include "my_string.hpp"
#include "reference_counter.hpp"

int main() {
    task4::ref_counter<task4::string> s(new task4::string("Hello world!"));

    s->print();
    std::cout << "custom string ref_count: " << s.getReferenceCount() << std::endl;

    {
        task4::ref_counter<task4::string> n = s;
        n->print();
        std::cout << "custom string ref_count: " << n.getReferenceCount() << std::endl;
    }

    std::cout << "custom string ref_count: " << s.getReferenceCount() << std::endl;


    // Test template class with int type
    task4::ref_counter<int> i(new int(5));
    std::cout << "int type: " << i.getReferenceCount() << std::endl;
    {
        task4::ref_counter<int> j = i;
        std::cout << "int type: " << j.getReferenceCount() << std::endl;
    }
    std::cout << "int type: " << i.getReferenceCount() << std::endl;
}
