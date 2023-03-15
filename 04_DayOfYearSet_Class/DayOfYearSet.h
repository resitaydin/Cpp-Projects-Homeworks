#ifndef DAYOFYEARSET_H
#define DAYOFYEARSET_H

#include <iostream>
#include <list>

using namespace std;

namespace DoYset
{
     
 class DayOfYearSet{
 
     public:
         class DayOfYear{ //Inner class
 
             private:
                 int day;
                 int month;
 
             public:
                 int getDay() const {return day;};
                 int getMonth() const {return month;};
                 void setDate(int, int);
                 void output() const; //to debug code.
 
                 bool operator==(const DayOfYear& other) const;
                 bool operator!=(const DayOfYear& other) const;
                 
                 DayOfYear();
                 DayOfYear(int , int );
         };
     DayOfYearSet();
     DayOfYearSet(const DayOfYearSet& other); //Copy Constructor
     DayOfYearSet(const list <DayOfYear>& days); 
     ~DayOfYearSet(); //Destructor
 
     friend const ostream& operator<<(ostream& outStr, const DayOfYearSet& other);
     bool operator== (const DayOfYearSet& other) const; 
     bool operator!= (const DayOfYearSet& other) const;
     DayOfYearSet operator- (const DayOfYearSet& other) const; // Difference operator
     DayOfYearSet operator+ (const DayOfYearSet& other) const; // Union operator.
     DayOfYearSet operator^ (const DayOfYearSet& other) const; // Intersection operator
     DayOfYearSet operator! (); // Complement operator
     DayOfYear& operator[](int index) const;
     void remove (const DayOfYear& obj); // removing an element from the set.
     void operator-(const DayOfYear& obj); // removing element from the set.
     void operator+ (const DayOfYear& newElement);
     
     
     DayOfYearSet& operator= (const DayOfYearSet& other); //overloaded assignment operator for deep copying. 
     int size() const {return _size; } ;
     DayOfYearSet createAllDays(); // Helper function
     void sortDates(); // Helper function
 
     private:
         DayOfYear* array;
         int _size;
 };

}

#endif