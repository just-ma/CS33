#include <limits.h>

int saturating_add(int x, int y)
{
    int len, xsign, ysign, samesign, sum, sumsign, overflow, sumsignsmear, overflowsmear, finalsum, sum1, sum2, sum3;
    
    len = (sizeof(int)<<3)-1;   //This finds the word length
    xsign = !(x >> len);        //Smears the most significant bit entirely across. xsign becomes 1 if
    ysign = !(y >> len);        //x is positive and 0 if x is negative
    samesign = !(xsign^ysign);  //1 if x and y have the same sign and 0 if they don't
    sum = x+y;
    sumsign = !(sum >> len);    //Again, 1 means positive, 0 means negative
    overflow = !(xsign^!sumsign) & samesign;        //if x and y had the same sign AND
    //the sum did not have a matching sign
    //then overflow occured (1)
    sumsignsmear = (sumsign << len) >> len;
    overflowsmear = (overflow << len) >> len;
    sum1 = sum & ~overflowsmear;                            //normal sum if no overflow occured, else 0
    sum2 = overflowsmear & (sumsignsmear & INT_MIN);        //becomes INT_MIN if overflowed under, else 0
    sum3 = overflowsmear & ((sumsignsmear^-1) & INT_MAX);   //becomes INT_MAX if overflowed over, else 0
    finalsum = sum1 + sum2 + sum3;                          //only one of the sums is nonzero
    return finalsum;
}
