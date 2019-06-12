/* 
 PRECONDITION: {N >= 0} 
 POSTCONDITION: {x = ∑ (i = 0, i = k-1) a[i]} 
 
 This will not compile without a main. Also,
 in order to distinguish logical equivalents from instructions
 I will use ':=' for instructions.
 The program computes the sum of values of an array a.
 
*/

/* {N >= 0} */
inline int sum_digits(int *a, int N){
  
  k := 0;
  
  x := 0;
  
  while (k != N) {
    
    x := x + a[k];
  
  
    k := k + 1;
  
  }

  return x;
}
/* {x = ∑ (i = 0, i = k-1) a[i]} */
