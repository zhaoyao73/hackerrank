#include <iostream>

using namespace std;
//Implement the class Box  
//l,b,h are integers representing the dimensions of the box
class Box {
    int l, b, h;
    public:
    int getLength() { return l; }
    int getBreadth() { return b;}
    int getHeight() { return h; }
    long long CalculateVolume() {
        return (long long)l*b*h;
    }
    Box() { l = b = h = 0; }
    Box(int l, int b, int h) { this->l = l; this->b = b; this->h = h;}
    Box(const Box& anotherB) {
        this->l = anotherB.l;
        this->b = anotherB.b;
        this->h = anotherB.h;
    }
    bool operator<(Box& b) {
        if (this->l < b.l) {
            return true;
        }
        if (this->l > b.l) {
            return false;
        }
        if (this->b < b.b) {
            return true;
        }
        if (this->b > b.b) {
            return false;
        }
        if (this->h < b.h) {
            return true;
        }

        return false;
    }
    friend ostream& operator<<(ostream& out, const Box& b);
};

ostream& operator<<(ostream& out, const Box& b) {
    out<<b.l << " " << b.b << " " << b.h;
    return out;
}
// The class should have the following functions : 

// Constructors: 
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)


void check2()
{
    int n;
    cin>>n;
    Box temp;
    for(int i=0;i<n;i++)
    {
        int type;
        cin>>type;
        if(type ==1)
        {
            cout<<temp<<endl;
        }
        if(type == 2)
        {
            int l,b,h;
            cin>>l>>b>>h;
            Box NewBox(l,b,h);
            temp=NewBox;
            cout<<temp<<endl;
        }
        if(type==3)
        {
            int l,b,h;
            cin>>l>>b>>h;
            Box NewBox(l,b,h);
            if(NewBox<temp)
            {
                cout<<"Lesser\n";
            }
            else
            {
                cout<<"Greater\n";
            }
        }
        if(type==4)
        {
            cout<<temp.CalculateVolume()<<endl;
        }
        if(type==5)
        {
            Box NewBox(temp);
            cout<<NewBox<<endl;
        }

    }
}

int main()
{
    check2();
}
