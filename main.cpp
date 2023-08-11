#include <iostream>
using namespace std;

class counter
{
private:
    unsigned int count;
public:
    counter() : count(0)
    { }
    counter(int c) : count(c)
    { }
    void get_detail()
    {
        cout<<"output :"<<count<<endl;
    }
    counter operator ++ ()
    {
        ++count;
        return counter(count);
    }
};

int main()
{
    counter c1,c2;
    cout<<c1.get_detail()<<endl;
    cout<<c2.get_detail()<<endl;
    
    ++c1;
    c2= ++c1;
    cout<<c1.get_detail()<<endl;
    cout<<c2.get_detail()<<endl;
    return 0;
}
