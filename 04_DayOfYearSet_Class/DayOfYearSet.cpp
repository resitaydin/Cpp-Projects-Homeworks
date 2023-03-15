#include "DayOfYearSet.h"

using namespace std;

namespace DoYset{

 DayOfYearSet::DayOfYearSet(){ //no param constr.
     array = new DayOfYear[10]; 
 }
 
 DayOfYearSet::DayOfYearSet(const list <DayOfYear>& days){
     _size = days.size();
     array = new DayOfYear[size()];
 
     int i = 0;
     for(auto j= days.begin(); i< size() && j!=days.end() ; ++i, ++j){ // using iterator 
         array[i] = *j; // assigning the elements of list to our array using iterator.
     }
 }
 
 DayOfYearSet::~DayOfYearSet(){ // Destructor
     array = nullptr;
     delete [] array;
 }
 
 const ostream& operator<<(ostream& outStr, const DayOfYearSet& other) {
     outStr<<"{";
     for(int i=0; i<other.size(); i++){
         outStr<<"("<< other.array[i].getDay();
         outStr << "/" << other.array[i].getMonth()<<")";  // Outputting the result.
         if(i!=other.size() -1) outStr <<", ";
     }
     outStr<<"}"<<endl;
     return outStr;
 }
 
 bool DayOfYearSet::operator== (const DayOfYearSet& other) const{
     int counter= 0;
     for(decltype(counter) i=0; i<size(); ++i){  //using decltype
         for(decltype(counter)  j=0; j<size(); ++j){  //using decltype
             if(array[i] == other.array[j]) counter++;  // Counting how many elements are equal.
         }
     }
     if(counter == size()) return true;
     else return false;
 }
 bool DayOfYearSet::operator!= (const DayOfYearSet& other) const{
     return !(*this == other);
 }
 
 void DayOfYearSet::remove (const DayOfYear& obj){
     int loc;
     DayOfYear* temp =new DayOfYear[size()];
     for(int i=0; i<size(); ++i) temp[i] = array[i];
     delete [] array;
     array = new DayOfYear[size() -1 ];
 
     if(temp[0] == obj){  // If the object locate at the head of array.
         for(int i=1; i<size() ; ++i){
             array[i-1] = temp[i];
         }
     }
     else if(temp[size()-1] == obj){ // If the object locate at the end of array.
         for(int i=0; i<size() - 1 ; ++i){
             array[i] = temp[i];
         }
     }
     
     else{   // // If the object locate at the middle of array.
         for(int i=0; i<size(); ++i){
             if(temp[i] == obj) loc = i;
         }
         for(int i=0; i<loc; ++i){
             array[i] = temp[i];
         }
         for(int i=loc; i<size()-1; ++i){
             array[i] = temp[i+1];
         }
     }
 
     _size -= 1; // decrementing size by 1, because we removed an element.
     delete [] temp;
 }
 
 
 DayOfYearSet::DayOfYear& DayOfYearSet::operator[] (int index) const{
     if(index < 0 || index > size()) {
         cout<< "Invalid index for this operator!\n";
         exit(1);
     }
     return array[index];
 }
 
 void DayOfYearSet::operator+ (const DayOfYear& newElement){ //Overloaded + operator for adding element.
     for(int i=0; i<size(); ++i) 
         if(array[i] == newElement){
             cout<< "This element is already in the set!\n";
             return;
         }
     
     DayOfYear* temp = new DayOfYear[size()];
     for(int i=0; i<size(); ++i) temp[i] = array[i];
 
     delete [] array;
     array = new DayOfYear[size() + 1 ]; // reallocating array with size+1.
 
     for(int i=0; i<size() ; ++i){
         array[i] = temp[i];
     }
     array[size()] = newElement; // Adding the element at the end.
 
     _size += 1;
 }
 
 DayOfYearSet DayOfYearSet::operator^ (const DayOfYearSet& other) const{
     std::list <DayOfYear> intersect; //Intersection can be have max number of size elements.
 
     for(int i=0; i<size(); ++i){
         for(int j=0; j<other.size(); ++j){
             if(array[i] == other.array[j]) intersect.push_back(array[i]); // pushing common elements to the object we'll return.
         }
     }
     auto intersection = DayOfYearSet(intersect);
     return intersection;
 }
 
 void DayOfYearSet::operator- (const DayOfYear& obj){
     remove(obj); // calling member function to remove an element. We don't like copying code :)
 }
 
 DayOfYearSet::DayOfYearSet(const DayOfYearSet& other){  // Copy constructor.
     _size = other.size(); 
     array = new DayOfYear[size()];
     for(int i=0; i<size(); ++i){
         array[i] = other.array[i];
     }
 }
 
 DayOfYearSet& DayOfYearSet::operator=(const DayOfYearSet& other){ // Overloaded = operator for deep copying.
     _size = other.size();
     delete [] array;
 
     array = new DayOfYear[size()];
     for(int i=0; i<size(); ++i)
         array[i] = other.array[i];
 
     return *this;  
 }
 
 DayOfYearSet DayOfYearSet::operator- (const DayOfYearSet& other) const{ //Difference is A-A^B, so we can use ^ operator as we overloaded before.
     DayOfYearSet intersect = *this ^ other;
     DayOfYearSet difference = *this;
     for(int i=0; i<intersect.size(); ++i){
         difference.remove(intersect.array[i]);  // Removing intersection elements.
     }
 
     return difference;  // ASSIGN SIZES
 }
 
 DayOfYearSet DayOfYearSet:: operator+ (const DayOfYearSet& other) const{  // equivalent of A/B + B
     DayOfYearSet diff = *this - other; // A/B
     decltype(diff) unionSet = other;
     for(int i=0; i< diff.size(); ++i){
         unionSet + diff.array[i]; // adding different set(using overloaded + operator.) to our set to find unionset.
     }
 
     return unionSet;
 }
 
 DayOfYearSet DayOfYearSet::operator! () { // E (365 days) - this object
     DayOfYearSet AllDays = createAllDays();
     
     return AllDays - *this;
 }
 
 DayOfYearSet DayOfYearSet::createAllDays(){
     //Ocak-31 Şubat -29 Mart -31 Nisan-30 Mayıs-31 Haziran-30 Temmuz-31 Ağustos-31 Eylül-30 Ekim-31 Kasım-30 Aralık-31
     std::list <DayOfYear> allDays;
     
     for(int i =1; i<32; ++i){  // Creating DayOfYear objects for the months that takes 31 days.
         allDays.push_back(DayOfYear(i,1));
         allDays.push_back(DayOfYear(i,3));
         allDays.push_back(DayOfYear(i,5));
         allDays.push_back(DayOfYear(i,7));
         allDays.push_back(DayOfYear(i,8));
         allDays.push_back(DayOfYear(i,10));
         allDays.push_back(DayOfYear(i,12));
     }
     for(int i =1; i<31; ++i){  // Creating DayOfYear objects for the months that takes 30 days.
         allDays.push_back(DayOfYear(i,4));
         allDays.push_back(DayOfYear(i,6));
         allDays.push_back(DayOfYear(i,9));
         allDays.push_back(DayOfYear(i,11));
     }
     for(int i=1; i<29; ++i){
         allDays.push_back(DayOfYear(i,2)); // DayOfYear object for February.
     }
 
     DayOfYearSet allDay(allDays);
     allDay.sortDates(); // sorting all the dates.
 
     return allDay;
 }
 
 void DayOfYearSet::sortDates(){  //This function is just for sorting all days that we created to see clearly what is inside in a complement set.
 
     for(int i=0; i<size(); ++i){
         for(int j = i+1; j<size(); j++){
             if(array[j].getMonth() < array[i].getMonth()){   // Bubble sort
                 auto temp = array[i];
                 array[i] = array[j];
                 array[j] = temp;
             }
             else if(array[j].getMonth() == array[i].getMonth()){ // If months are equal we sort days.
                 if(array[j].getDay() < array[i].getDay()){
                     auto temp = array[i];
                     array[i] = array[j];
                     array[j] = temp;
                 }
             }
         }
 
     }
 }

} //End of namespace.