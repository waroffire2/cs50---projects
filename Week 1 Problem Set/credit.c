#include <cs50.h>
#include <stdio.h>

int main(void){

    //every 2nd number starting 2nd to last multiplied by 2 then sum
    //Add that sum to the sum of each other number
    //if that sum %10 = 0, then card is valid, otherwise invalid
    // MASTERCARD 16 digits
    long card;

    do {
    card = get_long("Number: ");
    }
    while (card < 0);
    
}
