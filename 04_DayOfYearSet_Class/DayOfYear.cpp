#include "DayOfYearSet.h"

namespace DoYset{

 typedef DayOfYearSet::DayOfYear DoY; // declaring DayOfYear type.
 
 DoY::DayOfYear(){ //no param constr.
     setDate(1,1);  //Initializes date with 1 January.
 }
 
 DoY::DayOfYear(int d, int m) {
     setDate(d, m);
 }
 
 void DoY::setDate(int dy, int mnth){
     //Ocak-31 Şubat -29 Mart -31 Nisan-30 Mayıs-31 Haziran-30 Temmuz-31 Ağustos-31 Eylül-30 Ekim-31 Kasım-30 Aralık-31
     //  1-3-5-7-8-10-12
     if(mnth == 2 ){  // If Month is February the day will be 29 days maximum.
        if(dy < 29 && dy> 0){
         day = dy;
         month = mnth;
        }
        else{
        cout<<"Error! Invalid month or day!\n";
        }
     }
     else if(mnth == 4 || mnth == 6 || mnth == 9 || mnth == 11 ){ //If month takes 30 days
        if( dy<31 && dy>0){
            day = dy;
            month = mnth;
        }
        else{
            cout<<"Error! Invalid month or day!\n";
        }
         
     }
     else{
         if(dy<32 && dy>0 && mnth < 13 && mnth > 0){ //If month takes 31 days
             day = dy;
             month = mnth;
         }
         else{
             cout<<"Error! Invalid month or day!\n";
             // exit(1);
         }
     }
 }
 
 void DoY::output() const{ //This is just a dummy function to see what's inside in a DayOfYear object.
 
     switch (getMonth())
     {
     case 1: 
         std::cout<<"January ";
         break;
     case 2: 
         std::cout<<"February ";
         break;
     case 3: 
         std::cout<<"March ";
         break;
     case 4: 
         std::cout<<"April ";
         break;
     case 5: 
         std::cout<<"May ";
         break;
     case 6: 
         std::cout<<"June ";
         break;
     case 7: 
         std::cout<<"July ";
         break;
     case 8: 
         std::cout<<"August ";
         break;
     case 9: 
         std::cout<<"September ";
         break;
     case 10: 
         std::cout<<"October ";
         break;
     case 11: 
         std::cout<<"November ";
         break;
     case 12: 
         std::cout<<"December ";
         break;
     
     default:
         break;
     }
 
     std::cout<< getDay();
     std::cout<< endl;
 }
 
 
 bool DoY::operator==(const DayOfYear& other) const{  // Overloaded equality operator.
     return (getMonth() == other.getMonth()) && (getDay() == other.getDay());
 }
 bool DoY::operator!=(const DayOfYear& other) const{
     return !(*this == other);
 }
 
}