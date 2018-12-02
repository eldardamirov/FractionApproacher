//
//  main.cpp
//  FractionApproacher
//
//  Created by Эльдар Дамиров on 09.11.2018.
//  Copyright © 2018 Эльдар Дамиров. All rights reserved.
//

#include <iostream>
#include <vector>

//    result.intPart = temp.denominator / temp.term;
//    result.tempFraction.term = temp.denominator - temp.term;
//    result.tempFraction.denominator = temp.term;
//    


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
    fraction tempFraction { 0, 0 };
    chainFraction* fractionPart = nullptr;
    
    bool flag = true;
    
    chainFraction* iteration()
        {
        printf ( "intPart: %d, tempFraction: %d/%d, term: %d \n", intPart, tempFraction.term, tempFraction.denominator );
        
        fractionPart = new chainFraction;
        if ( tempFraction.term != 0 )
            {
            fractionPart->intPart = tempFraction.denominator / tempFraction.term;
            fractionPart->tempFraction.term = tempFraction.denominator % tempFraction.term;
            }
        // TODO: check for tempFraction.term == 0!
//        fractionPart->tempFraction.term = tempFraction.denominator - tempFraction.term;
//        fractionPart->tempFraction.term = tempFraction.denominator % tempFraction.term;
        fractionPart->tempFraction.denominator = tempFraction.term;
        
        return fractionPart;
        }
        
    bool checkForSimpliness()
        {
        if ( ( tempFraction.term == 1 ) || ( flag == false ) )
            {
            return false;
            }
        else
            {
            return true;
            }
        }
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
        
    Fraction ( int termTemp, int denominatorTemp )
        {
        this->storage.term = termTemp;
        this->storage.denominator = denominatorTemp;
        }
        
    
    Fraction operator+ ( Fraction& fractionToAdd )
        {
        Fraction resultFreaction ( 0, 0 ); 
        resultFreaction.storage.term = ( this->storage.term * fractionToAdd.storage.denominator ) + ( fractionToAdd.storage.term * this->storage.denominator );
        resultFreaction.storage.denominator = ( this->storage.denominator * fractionToAdd.storage.denominator );
        
        simplifyFraction();
        
        return resultFreaction;
        }
        
    Fraction operator- ( Fraction& fractionToAdd )
        {
        Fraction resultFreaction ( 0, 0 ); 
        resultFreaction.storage.term = ( this->storage.term * fractionToAdd.storage.denominator ) - ( fractionToAdd.storage.term * this->storage.denominator );
        resultFreaction.storage.denominator = ( this->storage.denominator * fractionToAdd.storage.denominator );
        
        simplifyFraction();
        
        return resultFreaction;
        }
        
    Fraction operator* ( Fraction& fractionToAdd )
        {
        Fraction resultFreaction ( 0, 0 ); 
        resultFreaction.storage.term = ( this->storage.term * fractionToAdd.storage.term );
        resultFreaction.storage.denominator = ( this->storage.denominator * fractionToAdd.storage.denominator );
        
        simplifyFraction();
        
        return resultFreaction;
        }
    
    Fraction operator/ ( Fraction& fractionToAdd )
        {
        Fraction resultFreaction ( 0, 0 ); 
        resultFreaction.storage.term = ( this->storage.term * fractionToAdd.storage.denominator );
        resultFreaction.storage.denominator = ( this->storage.denominator * fractionToAdd.storage.term );
        
        simplifyFraction();
        
        return resultFreaction;
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
    fraction temp { 54, 100 };
    chainFraction result;

    
    approachingTable table;
    
    bool flag = true;
    
    result.intPart = temp.denominator / temp.term;
    result.tempFraction.term = temp.denominator - temp.term;
    result.tempFraction.denominator = temp.term;
    
    chainFraction* root = &result;
    
    chainFraction* current = result.iteration();
    
    
    int counter = 0;
    
    while ( flag )
        {
        current = current->iteration();
        flag = current->checkForSimpliness();
        counter++;
        }
        
    int* line = new int [ counter + 1 ];
    

    
    for ( int i = 0; i < ( counter + 1 ); i++ )
        {
        line [ i ] = root->intPart;
        printf ( "%d - %d; \n", root->intPart, root->tempFraction.term );
        root = root->fractionPart;
        }

    for ( int i = 0; i < ( counter + 1 ); i++ )
        {
        printf ( "AA: %d ", line [ i ] );
        }
    
    
    table.numberOfIterations = counter + 3;
    table.init(); 
 
    table.storage [ 0 ] = { 1, 0 };
    table.storage [ 1 ] = { 0, 1 };
    
    for ( int i = 2; i < ( counter + 3 ); i++ )
        {
        table.storage [ i ].term = ( table.storage [ ( i - 1 ) ].term * line [ i - 2 ] ) + table.storage [ i - 2 ].term;
        table.storage [ i ].denominator = ( table.storage [ ( i - 1 ) ].denominator * line [ i - 2 ] ) + table.storage [ i - 2 ].denominator;
        }
    
    printf ( "Table: \n" );
    for ( int i = 0; i < ( counter + 3 ); i++ )
        {
        printf ( "%d   ", table.storage [ i ].term );
        }
    printf ( "\n" );
    for ( int i = 0; i < ( counter + 3 ); i++ )
        {
        printf ( "%d   ", table.storage [ i ].denominator );
        }
 
//    for 
 
    return 0;
    }



