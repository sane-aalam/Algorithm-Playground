

// weekly contest - Greedly solved

class Solution {
public:
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
         
    // Algorithm - Greedly maximum energyDrink take kar lunga
    // Exchange the process - if you want to switch from consuming one energy drink to the other,
    // maximum total enery boost you can gain 
    // What i am doing here, every itreation, i am just checking with exchaging the taking

    // energyDrinkA and energyDrinkB of the same length n 
     long long n = energyDrinkA.size();
     long long maximumDrinkA = 0;
     long long maximumDrinkB = 0;

     for(long long i = 0; i<n; i++){
        // Exchange the process, accoring to maximum energy boost 
        // Greedy Approach hai ye 
        long long exchangeDrinkA = max(energyDrinkA[i] + maximumDrinkA, maximumDrinkB);
        long long exchangeDrinkB = max(energyDrinkB[i] + maximumDrinkB, maximumDrinkA);

        maximumDrinkA = exchangeDrinkA;
        maximumDrinkB = exchangeDrinkB;
     }
    
     long long maximumTotalEngeryBoost = max(maximumDrinkA,maximumDrinkB);
     return maximumTotalEngeryBoost;
    }
};

// Line 18: Char 50: runtime error: signed integer overflow: 36784 + 2147480207 cannot be represented in type 'int' (solution.cpp)
// SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior solution.cpp:18:50
//----------to fix this error -- 
// i need to used long long data types 
// integer overflow error (long long int used it) or (long long)