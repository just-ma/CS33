int int_shifts_are_arithmetic(void){
    int x = -1>>1;
    //x will be different for arithmetic and logical shifts
    //if int shifts are arithmetic, x should still be -1.
    //Otherwise, it should be INT_MAX
    return (x == -1);
}
