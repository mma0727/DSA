#include <iostream>

/*
 * The following code shows the order in which base class and member ctors are 
 * called in the ctor for a derived class. 
 * 1. the base ctor is called.
 * 2. initialize the base-class members in the order in which they appear in 
 *    the class declaration.
 * 3. the dervied ctor is called.
 */
class father {
public:
    father() {
        std::cout << "father, I love you.\n";
    }
};
class mother {
public:
    mother() {
        std::cout << "mother, I love you.\n";
    }
};
class myself {
public:
    myself() {
        std::cout << "hello world.\n";
    }
};
class parent {
public:
    parent() {
        std::cout << "happy together.\n";
    }
private:
    father my_father;
    mother my_mother;
};
class derived_person: public parent {
public:
    derived_person():parent() {
        std::cout << "myself.\n";
    }
private:
    myself me;
};


int main() {
    derived_person dp;
    return 0;
}
