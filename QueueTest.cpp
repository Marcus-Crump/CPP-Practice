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

bool test_dequeue(Queue<std::string>* q)
{
    std::string expected[5] = {"lone", "NOT", "3", "2", "1"};
    for(int i = 0; i < 5; i++)
    {
        Node<std::string>* actual = q->dequeue();
        if (expected[i] != actual->getItem())
        {
            std::cout << "Actual does not match expected\n";
            std::cout << "Actual: " << actual->getItem() << "\n";
            std::cout << "Expected: " << expected[i] << "\n";
            return false;
        }
        std::cout << "PASS" << i << " " << actual->getItem() << "\n";
    }
    Node<std::string>* actual = q->dequeue();
    if(actual != nullptr)
    {
        std::cout<<"LOSER!! " << actual->getItem() << "\n";
        return false;
    }

    return true;
}

bool test_size(Queue<std::string>* q)
{
    if (!q->is_empty())
    {
        std::cout << "Queue should be empty but is not: " << q->size() << "\n";\
        return false;
    }

    for(int i = 0; i < 100; i++)
    {
        Node<std::string>* none = q->dequeue();
        if (none != nullptr)
        {
            std::cout<<"empty dequeue doesn't work\n";
            return false;
        }
    }
    

    for(int i = 0; i < 30; i++)
    {
        q->enqueue(std::to_string(i));
        if (q->size() != i+1)
        {
            std::cout<< "Queue size is NOT incrementing properly\n";
            std::cout<< "Expected: " << i+1 << "\n";
            std::cout<< "Actual: " << q->size();
            return false;
        }
    }
    std::cout<< "Pass with a size of " << q->size() << "\n";
    q->clear();
    if (q->size() != 0)
    {
        std::cout << "Queue size not 0\nSize: " << q->size() << "\n";
    }
    
    for(int i = 0; i < 100; i++)
    {
        Node<std::string>* none = q->dequeue();
        if (none != nullptr)
        {
            std::cout<<"empty dequeue doesn't work\n";
            return false;
        }
    }
    std::cout<<"queue size and clear methods working as expected\n";
    return true;
}

int main()
{
    std::cout << "Running Queue Test\n";
    Queue<std::string>* test = new Queue<std::string>();

    test_enqueue(test);
    test_dequeue(test);
    test_size(test);

    std::cout << "End of tests\n";
    return 0;
}