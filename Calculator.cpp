#include "Calculator.hpp"

// Constructor, set the capacity to the given capacity
Calculator::Calculator(int capacity){
    this->capacity = capacity;
}

bool Calculator::DEF(string name, double val){
    // We check if we are at capacity, otherwise, we create a new node to the list
    if (currentSize == capacity){
        return false;
    }
    // We run through our current linked list to see if the name is already defined
    curPtr = head;
    while (curPtr != nullptr){
        if (curPtr->getName() == name){
            return false;
        }
        curPtr=curPtr->getNext();
    }
    // If it's not defined, start creating a new node
    currentSize+=1;
    Node * newNode = new Node(name, val);
    // If it's not the first node, set the tail's next to the new node and then update tail
    if (currentSize != 1){
        tail->setNext(newNode);
    // If this is the first node, make it the head
    }else{
        head = newNode;
    }
    tail = newNode;
    return true;
}

bool Calculator::ADD(string x, string y, string z){
    //curPtr is our iteration ptr and starts at the head
    curPtr = head;
    Node* xPointer = nullptr;
    Node* yPointer = nullptr;
    Node* zPointer = nullptr;
    while(curPtr !=nullptr){
        string currentName = curPtr->getName();
        // If the current node's name matches x or y, we can say we found those values
        // and update the sum 
        if (currentName==x){
            xPointer = curPtr;
        }
        if (currentName == y){
            yPointer = curPtr;
        }
        // If the current node matches z, we keep a pointer at z so we can update it at the end
        if (currentName==z){
            zPointer=curPtr;
        }
        curPtr = curPtr->getNext();
    }
    // Check if we found all the nodes, if yes change the value at z
    if (xPointer!=nullptr && yPointer!=nullptr && zPointer!=nullptr){
        double sum = (xPointer->getVal() + yPointer->getVal());
        zPointer->setVal(sum);
        return true;
    }
    return false;
}

bool Calculator::SUB(string x, string y, string z){
    curPtr = head;
    Node* xPointer = nullptr;
    Node* yPointer = nullptr;
    Node* zPointer = nullptr;
    // The same as ADD but we do x-y instead of x+y
    while(curPtr !=nullptr){
        string currentName = curPtr->getName();
        if (currentName==x){
            xPointer = curPtr;
        }
        if (currentName == y){
            yPointer = curPtr;
        }
        if (currentName==z){
            zPointer=curPtr;
        }
        curPtr = curPtr->getNext();
    }
    if (xPointer!= nullptr && yPointer!=nullptr && zPointer!=nullptr){
        double diff = (xPointer->getVal() - yPointer->getVal());
        zPointer->setVal(diff);
        return true;
    }
    return false;
}

bool Calculator::REM(string x){
    // Keep track of a previous pointer
    Node* prev = nullptr;
    curPtr=head;
    while (curPtr != nullptr){
        if (curPtr->getName()==x){
            // If it's not the head, set the previous pointer next to the current's next
            if (prev!=nullptr){
                prev->setNext(curPtr->getNext());
            }else{
                // If the node we are removing is the head, move the head up a node
                head = curPtr->getNext();
            }
            // If the tail is what we are removing, we should move the tail back one
            if (curPtr == tail){
                tail = prev;
            }
            delete curPtr;
            currentSize -=1;
            return true;
        }   
        prev=curPtr;
        curPtr=curPtr->getNext();
    }
    return false;

}

void Calculator::PRT(string x){
    curPtr = head;
    while (curPtr != nullptr){
        if (curPtr->getName() == x){
            // Print the found node's values
            std::cout<< curPtr->getVal()<<std::endl;
            return ;
        }
        curPtr = curPtr->getNext();
    }
    std::cout<<"variable " + x + " not found"<<std::endl;
    return ;
}

// Destructor for linked list, traverse through the list and delete all the data
Calculator::~Calculator(){
    while (head != nullptr){
        Node *temp = head->getNext();
        delete head;
        head = temp;
    }
}