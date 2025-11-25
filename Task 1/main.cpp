#include <iostream>
#include "List.h"

int main() {
    List myList;
    
    std::cout << "CS505 List" << std::endl;
    
    myList.insertEnd(1, 'C');
    myList.insertEnd(2, 'S');
    myList.insertEnd(3, '5');
    myList.insertEnd(4, '0');
    myList.insertEnd(5, '5');
    
    std::cout << "list contents: ";
    myList.toFirst();
    while (!myList.curIsEmpty()) {
        std::cout << myList.retrieveData();
        myList.advance();
    }
    std::cout << std::endl;
    
    std::cout << "list size: " << myList.listSize() << std::endl;
    
    if (myList.search(1)) {  
        std::cout << "first character: " << myList.retrieveData() << std::endl;
    }
    
    if (myList.search(5)) {  
        myList.updateData('!');
        std::cout << "updated the last character to '!'" << std::endl;
    }
    
    std::cout << "list after update: ";
    myList.toFirst();
    while (!myList.curIsEmpty()) {
        std::cout << myList.retrieveData();
        myList.advance();
    }
    std::cout << std::endl;
    
    myList.makeListEmpty();
    

    return 0;
}
