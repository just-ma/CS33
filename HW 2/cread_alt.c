//compiled using -O

long cread_alt(long *xp){
  long* nullp = (void*)0;
  long zero = 0;
  long* result = &zero;
  if (xp != nullp)
    result = xp;
  return *result;
}

//checks if the pointer is not null before dereferencing it
