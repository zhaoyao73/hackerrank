#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person {
    int age;
    string name;
    protected:
    int pid;
    public:
    Person(): age(0), name(""), pid(0) {}
    Person(int age, const char *name) : age(age), name(name) {}
    virtual void getdata() {
        cin >> name >> age;
    }
    virtual void putdata() {
        cout << name << " " << age;
    }
};

/* yao:
 * static class member seems can only be public
 * and must be declared outside of class
 */
class Professor : public Person {
    int publications;
    public:
    static int id;
    Professor(): publications(0) {}
    void getdata() {
        Person::getdata();
        cin >> publications;
        id++;
        pid = id;
    }
    void putdata() {
        Person::putdata();
        cout << " " << publications << " " << pid << endl;
    }
};
int Professor::id = 0;
//and can't used be static!!!
//static int Professor::id = 0;
class Student : public Person {
    vector<int> marks;
    public:
    static int id;
    void getdata() {
        int m;
        Person::getdata();
        for(int i= 0; i < 6; i++) {
            cin >> m;
            marks.push_back(m);
        }
        id++;
        pid = id;
    }
    void putdata() {
        int m = 0;
        Person::putdata();
        for(int i= 0; i < 6; i++) {
            m += marks.at(i);
        }
        cout << " " << m << " " << pid << endl;
    }
};
int Student::id=0;
int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}

