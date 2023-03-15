#include "PFArray.cpp"
#include <algorithm>

using std::cout;
using std::endl;

using namespace TPFA;

template <typename T>
void print_elements(T element){
    cout<<element<<" ";
}

template <typename T>
void print_it(PFArray<T> x, char name){
     PFArray<char>::Iterator it;
    if(x.empty()) cout<<name<<" array is empty!";
    else  cout<<name<<" array contains: ";
   
    for(it= x.begin(); it!=x.end(); ++it) cout<<*it<<" ";
    cout<<endl;
}

template <typename T>
void print_it_int(PFArray<T>& x, char name){
     PFArray<int>::Iterator it;
    if(x.empty()) cout<<name<<" array is empty!";
    else  cout<<name<<" array contains: ";
   
    for(it= x.begin(); it!=x.end(); ++it) cout<<*it<<" ";
    cout<<endl;
}

int main(){
    //Testing PFArray function.
    cout<<"Creating a char PFArray...\n\n\n";
    PFArray<char> a; // NO param constr.

    PFArray<char>::Iterator it;
    cout<<"Checking if the container is empty...\n";
    if(a.empty()) cout<<"It is empty!\n";

    cout<<"---------------------------------------------\n";

    cout<<"Pushing some elements to the array...\n";
    a.push_back('X');
    a.push_back('Y');
    a.push_back('A');
    a.push_back('B');
    a.push_back('C');
    a.push_back('K');
    a.push_back('F');

    print_it(a,'a');
    cout<<"---------------------------------------------\n";

    cout<<"Size of a array is: "<< a.size()<<endl;

    cout<<"---------------------------------------------\n";

    cout<<"Testing copy constr on new PFArray object b with a...\n";

    PFArray <char> b(a);  // Copy constr.

    print_it(b,'b');

    cout<<"---------------------------------------------\n";

    cout<<"\nTesting move constr on new PFArray object c with b...\n";
    PFArray <char> c(std::move(b));  // Move constr.
    cout<<"Printing elements of c using RANGE BASED FOR LOOP...\n";

    for(auto ch : c) cout<<ch<<" "; // RANGE BASED FOR LOOP.
    cout<<endl;

    // print_it(c,'c');

    cout<<"---------------------------------------------\n";

    cout<<"\nTesting overloaded = operator on new PFArray object d with c...\n";
    PFArray<char> d ;
    d = c;  // assignment operator
    print_it(d,'d');

    cout<<"---------------------------------------------\n";

    cout<<"\nTesting overloaded move = operator on new PFArray object f with c...\n";
    PFArray<char> f ;
    f = std::move(c); // move assignment operator
    print_it(f,'f');

    cout<<"---------------------------------------------\n";
    
    cout<<"\nTesting overloaded two erase functions...\n";

    cout<<"Deleting the first element of d using erase(Iterator& it)...\n";
    d.erase(d.begin());
    print_it(d,'d');
    cout<<"size of d is: "<<d.size()<<endl;

    cout<<"---------------------------------------------\n";

    cout<<"Deleting 'B' element from the d array using erase(T& element)...\n";
    d.erase('B');

    print_it(d,'d');
    cout<<"size of d is: "<<d.size()<<endl;

    cout<<"---------------------------------------------\n";

    cout<<"Testing exception in erase function...\n";
    try{
        d.erase(d.begin()-100);  // Invalid iterator.
    }
    catch(const char *e){
        cerr<<e<<endl<<endl;
    }

    cout<<"Testing exception in other erase function...\n";
    d.erase('M');
    

    cout<<"Testing std::find function with PFArray d object...\n";
    cout<<"Looking for 'X' element in d...\n";
    auto element = std::find(d.begin(), d.end(), 'X');

    if(element!=d.end())
        cout<<*element<<" element found in array. "<<endl;
    else cout<<"Element couldn't be found!\n\n";

    cout<<"Looking for 'K' element in d...\n";
    auto element1 = std::find(d.begin(), d.end(), 'K');  // Testing our array with std::find

    if(element1!=d.end())
        cout<<*element1<<" element found in array. "<<endl;

    else cout<<"Element couldn't be found!\n";

    cout<<"---------------------------------------------\n";


    cout<<"Testing global print_elements function using std::for_each with PFArray d object...\n";

    std::for_each(d.begin(), d.end(), print_elements<char>); // Testing our array with std::for_each
    cout<<endl;

    cout<<"---------------------------------------------";

    cout<<"\nTesting default sorting algorithm using std::sort with PFArray d object...\n";

    std::sort(d.begin(), d.end()); // Testing our array with std::sort

    cout<<"Sorted elements in d are: \n";
    for(it= d.begin(); it!=d.end(); ++it) cout<<*it<<" ";
    cout<<endl;

    cout<<"---------------------------------------------\n";

    cout<<"Cleaning the PFArray d object using clean function...\n";
    d.clean();
    print_it(d,'d');
    cout<<"Size of d is : "<<d.size()<<endl;

    cout<<"---------------------------------------------\n";
    cout<<"---------------------------------------------\n";
    cout<<"---------------------------------------------\n\n";


    /////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////
    cout<<"Creating an int PFArray...\n\n\n";
    PFArray<int> x; // NO param constr.

    PFArray<int>::Iterator it1;
    cout<<"Checking if the container is empty...\n";
    if(x.empty()) cout<<"It is empty!\n";

    cout<<"---------------------------------------------\n";

    cout<<"Pushing some elements to the array...\n";
    x.push_back(15);
    x.push_back(20);
    x.push_back(37);
    x.push_back(5);
    x.push_back(12);
    x.push_back(12);

    print_it_int(x,'x');
    cout<<"---------------------------------------------\n";

    cout<<"Size of x array is: "<< x.size()<<endl;

    cout<<"---------------------------------------------\n";

    cout<<"Testing copy constr on new PFArray object y with x...\n";

    PFArray <int> y(x); // Copy constr.

    print_it_int(y,'y');

    cout<<"---------------------------------------------\n";

    cout<<"\nTesting move constr on new PFArray object z with y...\n";
    PFArray <int> z(std::move(y));  // Move constr.

    cout<<"Printing elements of z using RANGE BASED FOR LOOP...\n";

    for(auto ch : z) cout<<ch<<" "; // RANGE BASED FOR LOOP.
    cout<<endl;

    // print_it_int(z,'z');

    cout<<"---------------------------------------------\n";

     cout<<"\nTesting overloaded = operator on new PFArray object k with z...\n";
     PFArray<int> k; 
    k = z; // assignment operator
    print_it_int(k,'k');

    cout<<"---------------------------------------------\n";

    cout<<"\nTesting overloaded move = operator on new PFArray object m with z...\n";
    PFArray<int> m;
    m = std::move(z); // move assignment operator
    print_it_int(m,'m');

    cout<<"---------------------------------------------\n";
    
    cout<<"\nTesting overloaded two erase functions...\n";

    cout<<"Deleting the first element of x using erase(Iterator& it)...\n"; 
    x.erase(x.begin());
    print_it_int(x,'x');
    cout<<"size of x is: "<<x.size()<<endl;

    cout<<"---------------------------------------------\n";

    cout<<"Deleting 12 element from the k array using erase(T& element)...\n";
    x.erase(12);

    print_it_int(x,'x');
    cout<<"size of x is: "<<x.size()<<endl;

    cout<<"---------------------------------------------\n";

     cout<<"Testing exception in erase function...\n";
    try{
        k.erase(k.begin()-20);  // Invalid iterator.
    }
    catch(const char *e){
        cerr<<e<<endl<<endl;
    }

    cout<<"Testing exception in other erase function...\n";
    k.erase(125);


    cout<<"Testing std::find function with PFArray k object...\n";
    cout<<"Looking for element 15 in k...\n";
    auto element2 = std::find(x.begin(), x.end(), 15);

    if(element2!=x.end())
        cout<<*element<<" element found in array. "<<endl;
    else cout<<"Element couldn't be found!\n\n";

    cout<<"Looking for element 37 in x...\n";
    auto element3 = std::find(x.begin(), x.end(), 37);  // Testing our array with std::find

    if(element3!=x.end())
        cout<<*element3<<" element found in array. "<<endl;

    else cout<<"Element couldn't be found!\n";

    cout<<"---------------------------------------------\n";


    cout<<"Testing global print_elements function using std::for_each with PFArray x object...\n";

    std::for_each(x.begin(), x.end(), print_elements<int>);    // Testing our array with std::for_each
    cout<<endl;

    cout<<"---------------------------------------------";

    cout<<"\nTesting default sorting algorithm using std::sort with PFArray x object...\n";

    std::sort(x.begin(), x.end());    // Testing our array with std::sort

    cout<<"Sorted elements in x are: \n";
    for(it1= x.begin(); it1!=x.end(); ++it1) cout<<*it1<<" ";
    cout<<endl;

    cout<<"---------------------------------------------\n";

    cout<<"Cleaning the PFArray x object using clean function...\n";
    x.clean();
    print_it_int(x,'x');
    cout<<"Size of x is : "<<x.size()<<endl;


    cout<<"---------------------------------------------\n";
    cout<<"---------------------------------------------\n";
    cout<<"---------------------------------------------\n\n";

    return 0;
}