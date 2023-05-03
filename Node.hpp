using namespace std;

class Node{
    private:
        string name;
        double val;
        Node * next = nullptr;
    public:
        Node(string name, double val);
        ~Node();
        void setName(string name);
        void setVal(double val);
        void setNext(Node * next);
        string getName();
        double getVal();
        Node * getNext ();

};