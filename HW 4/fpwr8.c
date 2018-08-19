static float u2f(unsigned u){
  union uni{
    unsigned uns;
    float flo;
  };
    
  union uni combo;
    
  combo.uns = u;
  return combo.flo;
}


float fpwr8(int x){
  unsigned exp, frac;
  unsigned u;
    
  if (x < -149/3){      //(1-127) - 23) / 2
    exp = 0;
    frac = 0;
  }
  else if (x < -126/3){ //(1 - 127) / 2
    exp = 0;
    frac = 1 << (3 * x + 149);
  }
  else if (x < 128/3){  //(254-127) / 2
    exp = x*3 + 127;
    frac = 0;
  }
  else {
    exp = 0xff;
    frac = 0;
  }
    
  u = exp << 23 | frac;
  return u2f(u);
}
 
