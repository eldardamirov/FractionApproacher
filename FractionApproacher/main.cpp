//
//  main.cpp
//  FractionApproacher
//
//  Created by Эльдар Дамиров on 09.11.2018.
//  Copyright © 2018 Эльдар Дамиров. All rights reserved.
//

#include <iostream>
#include <vector>


struct fraction
    {
    void divideBy ( int divider )
        {
        denominator /= divider;
        term /= divider;
        }
    
    int term = 0;
    int denominator = 0;
    };

struct chainFraction
    {
    int intPart = 0;
    fraction tempFraction = NULL;
    chainFraction* fractionPart = nullptr;
    };
    
struct approachingTable
    {
    size_t numberOfIterations = 0;
    fraction* storage = nullptr;
    
    void init()
        {
        storage = new fraction [ numberOfIterations ];
        }
    };


    
class Fraction
    {
    public:
    
    Fraction ( double initialNumber )
        {
        
        }
    
    
    private:
        fraction storage { 0, 0 };
        
        void simplifyFraction()
            {
            std::vector <int> termDividers = defineDividers ( storage.term );
            std::vector <int> denominatorDividers = defineDividers ( storage.denominator );
            
            int overallCommonMultiplier = 1;
            
            for ( auto i = termDividers.begin(); i != termDividers.end(); i++ )
                {
                if ( std::find ( denominatorDividers.begin(), denominatorDividers.end(), *i ) != denominatorDividers.end() )
                    {
                    overallCommonMultiplier *= *i;
                    }
                }
                
            storage.divideBy ( overallCommonMultiplier );
            }
            
        std::vector <int> defineDividers ( int number )
            {
            std::vector <int> result{};
            
            for ( int i = 1; i <= number; i++ )
                {
                if ( number % i == 0 )
                    {
                    result.push_back ( i );
                    }
                }
                
            return result;
            }
        
        
    
    };



int main()
    {
    fraction temp { 21, 7 };

    
    approachingTable table;
    
    bool flag = true;
    
    while ( flag )
        {
        
        }
    
    
    return 0;
    }

