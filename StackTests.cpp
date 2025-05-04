#include "Stack.h"
#include "string"
#include "iostream"

void checkResults(Stack<std::string>* testStack)
{
    
    int count = 9;
    bool PASS = true;
    std::string exString = "9\n8\n7\n6\n5\n4\n3\n2\n1\n0";
    std::string acString = testStack->toString();
   
    while(testStack->peek() != nullptr)
    {
        std::cout<<testStack->toString() << std::endl;
        std::string expected = std::to_string(count);
        Node<std::string>* testPtr = testStack->pop();
        std::string actual = testPtr->getItem();
        if (expected != actual)
        {
            std::cout<<"Expected != Actual\n" << "dif: " << expected << "|"<< actual <<
            "\nExpected:\n\"" <<exString << "\"\nActual:\n\"" << acString << "\"";
            PASS = false;
            break;
        }
        count--;
    }
    if(PASS)
    {
        std::cout<<"Passed while loop" << std::endl;
        if (testStack->toString() != "\"\"")
        {
            std::cout << "Stack not empty after calling POP()\n";
            std::cout << testStack->toString();
            PASS = false;
        }
        else{
            std::cout << "PASSED" << std::endl;
        }
        
    }


    if (PASS)
    {
        std::cout <<"ALL TESTS PASSED";
    }
    
}

int main()
{
    Stack<std::string>* tester = new Stack<std::string>();
    for(int i = 0; i < 10; i++)
    {
        std::cout<<i;
        tester->push(std::to_string(i));
    }
    std::cout << std::endl;
    
    checkResults(tester);
    return 0;
}