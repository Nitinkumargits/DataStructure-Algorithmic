#include <iostream>
using namespace std;
unsigned int rotateLeft(unsigned int num, unsigned int
                                              rotation)
{
    return (num << rotation) | (num >> (32 -
                                        rotation));
}
unsigned int rotateRight(unsigned int num, unsigned int
                                               rotation)
{
    return (num >> rotation) | (num << (32 -
                                        rotation));
}
6 | P a g e int main()
{
    unsigned int num = 16; //
    00000000000000000000000000010000 in binary unsigned int rotation = 2;
    unsigned int leftRotated = rotateLeft(num,
                                          rotation);
    unsigned int rightRotated = rotateRight(num,
                                            rotation);
    cout << "Original number: " << num << endl;
    cout << "Left rotated by " << rotation << " bits: "
         << leftRotated << endl;
    cout << "Right rotated by " << rotation << " bits: 
                                               " << rightRotated << endl;
        return 0;
}
