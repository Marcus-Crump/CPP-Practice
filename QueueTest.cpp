#include "Queue.h"
#include "string"
#include "iostream"

bool test_enqueue(Queue<std::string>* q)
{
    std::cout << "Testing enqueue\n";
    std::string expected = "[lone]";
    q->enqueue("lone");
    std::cout << expected << "\n";
    if (expected != q->to_string())
    {
        std::cout << "Output does not match\n";
        std::cout << "Expected: " << expected << "\n";
        std::cout << "Actual: " <<  q->to_string() << "\n";
        return false;
    }
    std::cout << "PASS: " << q->to_string() << "\n";

    q->enqueue("NOT");
    expected = "[NOT->lone]";

    if (expected != q->to_string())
    {
        std::cout << "Output does not match\n";
        std::cout << "Expected: " << expected << "\n";
        std::cout << "Actual: " <<  q->to_string() << "\n";
        return false;
    }
    std::cout << "PASS: " << q->to_string() << "\n";

    q->enqueue("3");
    q->enqueue("2");
    q->enqueue("1");
    expected = "[1->2->3->NOT->lone]";

    if (expected != q->to_string())
    {
        std::cout << "Output does not match\n";
        std::cout << "Expected: " << expected << "\n";
        std::cout << "Actual: " <<  q->to_string() << "\n";
        return false;
    }
    std::cout << "PASS: " << q->to_string() << "\n";

    return true;
}


int main()
{
    std::cout << "Running Queue Test\n";
    Queue<std::string>* test = new Queue<std::string>();

    test_enqueue(test);

    return 0;
}