//
// Created by stellarterror
//
/* Problem:
 * If we list all the natural multiples below 10 that are multiples of 3 or 5, we get 3,5,6 and 9.
 * The sum of these multiples is 23.
 * Find the sum of all the multiples of 3 or 5 below 1000.
 * Algorithm :
 * We are supposed to find of all multiples of 3 or 5 __below__ the input number, therefore we decrement it by one.
 * In general, the sum of all numbers between 1 and `x` is `sum_{1..x}i=x * (x+1)/2`(see https://en.wikipedia.org/wiki/Triangular_number).
 * There are `floor{x/3}` numbers between 1 and x which are divisible by 3 (assuming `floor{x/3}` is an integer division). e.g. the range `1..10` contains `floor{10/3}=3` such numbers (it's 3, 6 and 9). Their sum is `3+6+9=18`.
 * This can be written as `3/3 * (3+6+9)` which is the same as `3 * (3/3+6/3+9/3)=3 * (1+2+3)`.
 * Those brackets represent ` sum_{1..3}i = sum_{1..10/3}i` (or short: ` sum{10/3}`) and thus our overall formula for the sum of all multiples of 3 becomes `3 * sum{x/3}`.
 * The same formula can be used for 5: The sum of all numbers divisible by 5 is `5 * sum{x/5}`.
 * However, there are numbers divisible by 3 __and__ 5, which means they are part of __both__ sums.
 * We must not count them twice, that's why we (in addition to the aforementioned sums) compute the sum of all numbers divisible by 3*5=15 to correct for this error.
 * In the end we print ''sumThree + sumFive - sumFifteen''
 * Alternative Approach :
 * Looping through all numbers from 1 and 1000 and checking each of those numbers.
 * Whether they are divisible by 3 or 5 easily solves the problem, too, and produces the result pretty much instantly.
 * Even more, the code will be probably a bit shorter.
 */


#include <iostream>

unsigned long long sum(int x);

int main(){
    //tests is only a loop control element!
    int tests{1};
    while(tests--){
        //last represents the limit till which you count the multiples
        unsigned long long last;
        std::cout << "Enter Last number: ";
        std::cin >> last;

        //This is to avoid inclusion of the number itself
        last--;

        //ahh, yes don't forget to subtract sumfifteen to avoid double counting
        auto sumThree = 3*sum(last /3);
        auto sumFive = 5*sum(last / 5);
        auto sumfifteen = 15*sum(last/15);

        std::cout << (sumThree + sumFive - sumfifteen) << std::endl;
    }
    return 0;
}

//using sum of first n natural numbers formula
unsigned long long sum(int x){
    return x*(x+1)/2;
}
