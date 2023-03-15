#include "DayOfYearSet.h"
#include  <list>

using namespace DoYset;

int main(){

    auto d1 = DayOfYearSet::DayOfYear(2,8);
    auto d2 = DayOfYearSet::DayOfYear(15,2);
    auto d3 = DayOfYearSet::DayOfYear(6,7);
    auto d4 = DayOfYearSet::DayOfYear(1,11);
    auto d5 = DayOfYearSet::DayOfYear(23,5);
    auto d6 = DayOfYearSet::DayOfYear(3,6);
    auto d7 = DayOfYearSet::DayOfYear(19,9);

    auto d8 = DayOfYearSet::DayOfYear(3,2);
    auto d9 = DayOfYearSet::DayOfYear(5,10);
    auto d10 = DayOfYearSet::DayOfYear(8,11);
    auto d11 = DayOfYearSet::DayOfYear(21,2);
    auto d12 = DayOfYearSet::DayOfYear(17,7);
    auto d13 = DayOfYearSet::DayOfYear(12,8);
    auto d14 = DayOfYearSet::DayOfYear(1,1);
    auto d15 = DayOfYearSet::DayOfYear(18,5);

    cout<<"Note: Outputs are day/month formatted!!!\n";
    cout<<"Trying to create  DayOfYear objects with invalid inputs...\n"; 
    cout<< "day=5 month=13  \n";
    auto dd = DayOfYearSet::DayOfYear(5,13);
    cout<< "day=31 month=2  \n";
    auto dd1 = DayOfYearSet::DayOfYear(31,2);
    cout<< "day=32  month=12  \n";
    auto dd2 = DayOfYearSet::DayOfYear(32,12);

    cout<<"----------------------------------------\n";

    list <DayOfYearSet::DayOfYear> myList = {d1, d3 ,d4, d5, d8, d14, d2};
    list <DayOfYearSet::DayOfYear> othList = {d3, d8, d12, d13, d14, d15};

    cout<< "Creating two DayOfYearSet objects using list constr...\n";
    DayOfYearSet Days(myList);
    DayOfYearSet myDays(othList);
    cout<<"They are created...\n";
    cout<< "Creating a DayOfYearSet object using copy constr...\n";
    DayOfYearSet copy_days(Days);
    cout<<"It is created...\n";
    cout<< "Creating a DayOfYearSet object using no param constr...\n";
    DayOfYearSet no_param;
    cout<< "It is created.\n";

    cout<<"----------------------------------------\n";

    cout<<"Size of set A: "<<Days.size()<<endl;
    cout<<"Set A: \n";
    cout<<Days;

    cout<<"----------------------------------------\n";

    cout<<"Size of set B: "<<myDays.size()<<endl;
    cout<<"Set B: \n";
    cout<<myDays;

    cout<<"----------------------------------------\n\n";

    cout<< "Trying == operator on A and B: \n";
    if(Days==myDays) cout<< "Sets are equal.(True)\n";
    else cout<< "Sets are not equal!(False)\n";

    cout<<"----------------------------------------\n\n";

    cout<< "Trying != operator on A and B: \n";
    if(Days!=myDays) cout<< "Sets are not equal!(True)\n";
    else cout<< "Sets are equal.(False)\n";

    cout<<"----------------------------------------\n\n";

    cout<< "Testing [] operator on A: \n";
    cout<< "4th element in set A is: ";
    Days[3].output();

    cout<<"----------------------------------------\n";

    cout<< "Testing [] operator on B: \n";
    cout<< "1st element in set B is: ";
    myDays[0].output();

    cout<<"----------------------------------------\n\n";


    DayOfYearSet intersection =  Days ^ myDays;
    cout<<"Size of intersection set (A^B): "<< intersection.size()<<endl;
    cout<< "Intersection set (A^B): \n";
    cout<< intersection;

    cout<<"----------------------------------------\n\n";

    DayOfYearSet unionSet =  Days + myDays;
    cout<<"Size of union set (A+B):  "<< unionSet.size()<<endl;
    cout<< "Union set (A+B): \n";
    cout<< unionSet;

    cout<<"----------------------------------------\n\n";

    DayOfYearSet diffSet =  Days - myDays;
    cout<<"Size of difference set (A-B): "<< diffSet.size()<<endl;
    cout<< "Difference set (A-B): \n";
    cout<< diffSet;

    cout<<"----------------------------------------\n";

    DayOfYearSet diffSet2 = myDays - Days;
    cout<<"Size of difference set (B-A): "<< diffSet2.size()<<endl;
    cout<< "Difference set (B-A): \n";
    cout<< diffSet2;

    cout<<"----------------------------------------\n\n";

    //Adding element part.

    cout<<"Adding new element to the Set A...\n";
    Days + d11;
    cout<<"Size of set A after adding an element : "<< Days.size()<<endl;
    cout<<"Set A after adding an element : \n";
    cout<< Days;
    
    cout<<"----------------------------------------\n";

    cout<<"Adding new element to the Set B...\n";
    myDays + d2;
    cout<<"Size of set B after adding an element : "<< myDays.size()<<endl;
    cout<<"Set B after adding an element : \n";
    cout<< myDays;

    cout<<"----------------------------------------\n\n";

    intersection =  Days ^ myDays;
    cout<<"Size of intersection set (A^B) after adding an element : "<< intersection.size()<<endl;
    cout<< "Intersection set (A^B) after adding an element : \n";
    cout<< intersection;

    cout<<"----------------------------------------\n\n";

    unionSet =  Days + myDays;
    cout<<"Size of union set (A+B) after adding an element: "<< unionSet.size()<<endl;
    cout<< "Union set (A+B) after adding an element: \n";
    cout<< unionSet;

    cout<<"----------------------------------------\n\n";


    diffSet =  Days - myDays;
    cout<<"Size of difference set (A-B) after adding an element:  "<< diffSet.size()<<endl;
    cout<< "Difference set (A-B) after adding an element: \n";
    cout<< diffSet;

    cout<<"----------------------------------------\n";

    diffSet2 = myDays - Days;
    cout<<"Size of difference set (B-A) after adding an element: "<< diffSet2.size()<<endl;
    cout<< "Difference set (B-A) after adding an element: \n";
    cout<< diffSet2;

    cout<<"----------------------------------------\n";
    cout<<"----------------------------------------\n\n";


    // Removing part

    cout<<"Removing an element from the Set A...\n";
    Days - d3;
    cout<<"Size of set A after removing an element : "<< Days.size()<<endl;
    cout<<"Set A after removing  an element : \n";
    cout<< Days;
    
    cout<<"----------------------------------------\n";

    cout<<"Removing an element from the Set B...\n";
    myDays - d14;
    cout<<"Size of set B after removing an element : "<< myDays.size()<<endl;
    cout<<"Set B after removing an element : \n";
    cout<< myDays;

    cout<<"----------------------------------------\n\n";

    intersection =  Days ^ myDays;
    cout<<"Size of intersection set (A^B) after removing an element: "<< intersection.size()<<endl;
    cout<< "Intersection set (A^B) after removing an element: \n";
    cout<< intersection;

    cout<<"----------------------------------------\n\n";

    unionSet =  Days + myDays;
    cout<<"Size of union set (A+B) after removing an element: "<< unionSet.size()<<endl;
    cout<< "Union set (A+B) after removing an element: \n";
    cout<< unionSet;

    cout<<"----------------------------------------\n\n";


    diffSet =  Days - myDays;
    cout<<"Size of difference set (A-B) after removing an element:  "<< diffSet.size()<<endl;
    cout<< "Difference set (A-B) after removing an element: \n";
    cout<< diffSet;

    cout<<"----------------------------------------\n";

    diffSet2 = myDays - Days;
    cout<<"Size of difference set (B-A) after removing an element: "<< diffSet2.size()<<endl;
    cout<< "Difference set (B-A) after removing an element: \n";
    cout<< diffSet2;

    cout<<"----------------------------------------\n\n";



    DayOfYearSet comp =  !Days;
    cout<<"The size of complement set of set A: " << comp.size();
    cout<<endl<< "The complement set: \n";
    cout<< comp;



    cout<<"----------------------------------------\n";
    cout<<"----------------------------------------\n";

    return 0;
}
