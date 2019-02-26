//begin person.h

#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;
class Person
{
private:
    string lastName;
    string firstName;
    float  payRate;
    float  hoursWorked;

public:
    Person();
    void setLastName(string lname);
    string getLastName();
    void setFirstName(string fname);
    string getFirstName();
    void setPayRate(float rate);
    float getPayRate();
    void setHoursWorked(float hours);
    float getHoursWorked();
    float totalPay();
    string fullName();
};
#endif // end person.h
