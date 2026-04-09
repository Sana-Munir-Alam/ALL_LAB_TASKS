#include <iostream>
using namespace std;

class Box{
    private:
        int* BoxSize; // Using int* here cause we need to implement DMA
    public:
        Box(int Size) {                  // Parametrized Constrcutor
            BoxSize = new int(Size);     // Dynmaically Allocating Memory
        }
        // Destructor [Comment the Code to see Shallow Copy at work]
        ~Box(){ 
            delete BoxSize; 
            BoxSize = nullptr;
        }
        // Copy Constructor [Comment the code to see Shallow Copy at work]
        Box(const Box& other){
            BoxSize = new int(*other.BoxSize);  // Copying the Box Size from other to object to new object
        }
        // Copy Assignment Operator [Comment the code to see Shallow Copy at Work]
        Box& operator=(const Box& other){
            if(this != &other){
                delete BoxSize; // Freeing Old Memory
                BoxSize = new int (*other.BoxSize);
            }
            return *this;
        }
        void setBoxSize(int Size){ *BoxSize = Size; }
        int getBoxSize() const { return *BoxSize; }
};

int main() {
    // Cooment the Rule of three to see the following main code run with Shallow Copy 
    // and you will see each object have same value when the main one changes
    cout << "=== Demonstrating Deep and Shallow Copy ===\n\n";

    Box b1(10);
    Box b2 = b1; // Will Call Copy Constructor DEEP COPY
    cout << "----b1 copied into b2 NORMAL COPY CONSTRCUTOR----\n";
    cout << "b1 = " << b1.getBoxSize() << endl;
    cout << "b2 = " << b2.getBoxSize() << endl;

    b1.setBoxSize(20);

    cout << "\nAfter changing b1:\n";
    cout << "b1 = " << b1.getBoxSize() << " (changed)" << endl;
    cout << "b2 = " << b2.getBoxSize() << " (unchanged)" << endl;

    Box b3(100);
    b3 = b1;    // Will Call Copy Assignment Operator DEEP COPY

    cout << "\n----b1 copied into b3 COPY ASSIGNMENT CONSTRCUTOR----";
    cout << "\nAfter assignment (b3 = b1):\n";
    cout << "b1 = " << b1.getBoxSize() << endl;
    cout << "b3 = " << b3.getBoxSize() << endl;

    b1.setBoxSize(50);

    cout << "\nAfter modifying b1 again:\n";
    cout << "b1 = " << b1.getBoxSize() << " (changed)" << endl;
    cout << "b3 = " << b3.getBoxSize() << " (unchanged)" << endl;

    return 0;
}
