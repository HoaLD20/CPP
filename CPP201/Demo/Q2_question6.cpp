#include <iostream>

using namespace std;
class Education
{
    char name[10];

public:
    void disp()
    {
        cout << "Its education system";
    }
};

class Shool : public Education
{
public:
    void disp()
    {
        cout << "It school"
    }
};