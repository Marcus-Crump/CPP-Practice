#include <iostream>
#include "LinkedList.h"
#include <iostream>
#include <string>
#include <cctype>

void LinkedListTester(LinkedList<std::string>* lstPtr)
{

    std::cout << "The list is " << lstPtr->getSize() << " links long" << std::endl;
    
    std::cout << lstPtr->toString() << std::endl;
    
}

int main()
{
    LinkedList<std::string>* listPtr = new LinkedList<std::string>();

    std::string usrInput;

    while (true)
    {
        std::cout << "Insert string into LinkedList: ";
        std::cin >> usrInput;
        if (usrInput == "^E")
        {
            break;
        }
        
        listPtr->add(usrInput);
    }
    LinkedListTester(listPtr);
    delete listPtr;
    listPtr = nullptr;
    
    return 0;
}