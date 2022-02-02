#include <iostream>


    //base case = final case, when the recursion stops 
    //base case 
    //always do base case first then recursive statement 

int stepPerms(int n) { 
    

    if (n == 1) { 
        return 1;
    }
    if (n == 2) {
        return 2;
    }
    if (n == 3) { 
        return 4; 
    }
    else { 
        return stepPerms(n-1) + stepPerms(n-2) + stepPerms(n-3);

    }
}

int main() { 
    std::cout << "Number of steps: 5 " << std::endl << "Number of possible ways: " << stepPerms(5) << std::endl << std::endl; 
    std::cout << "Number of steps: 6 " << std::endl << "Number of possible ways: " << stepPerms(6) << std::endl << std::endl; 
    std::cout << "Number of steps: 7 " << std::endl << "Number of possible ways: " << stepPerms(7) << std::endl << std::endl; 
}