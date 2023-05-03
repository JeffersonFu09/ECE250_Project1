#include <iostream>
#include "Node.hpp"
using namespace std;


class Calculator{
    private:
        // Current size and head will always be 0 and null when created
        int currentSize =0;
        int capacity;
        Node*tail;
        Node*head = nullptr;
        Node*curPtr;
    public:
        Calculator(int capacity);
        bool DEF(string name, double val);
        bool ADD(string x, string y, string z);
        bool SUB(string x, string y, string z);
        bool REM(string x);
        void PRT(string x);
        ~Calculator();
    
};
