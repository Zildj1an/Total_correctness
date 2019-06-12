/* 
 PRECONDITION: {N >= 0} 
 POSTCONDITION: {x = ∑ (i = 0, i = N-1) a[i]} 
 
 This will not compile without a main. Also,
 in order to distinguish logical equivalents from instructions
 I will use ':=' for instructions.
 The program computes the sum of values of an array a.
 
*/

/* Partial Correctness: ************************/

/* {N >= 0} */
inline int sum_digits(int *a, int N){
 
  /* Axiom of substitution
   {0 = ∑ (i = 0, i = -1) a[i]}
   This is correct as the sum from 0 to -1 is zero, this equals true.
   {N >= 0} → {true}
   Proved {p} → {I} (1)
  */
  k := 0; 
  /* Axiom of substitution
   {0 = ∑ (i = 0, i = k-1) a[i]}
  */
  x := 0;
  /* Invariant I = {x = ∑ (i = 0, i = k-1) a[i]} */
  while (k != N) {
  
   /* (I and B) = (I and (k != N))
       {x = ∑ (i = 0, i = k-1) a[i] ∧ (k != N)} → (2)
    */
  
    /* Axiom of subsitution
    Invariant I = {x + a[k] = ∑ (i = 0, i = k) a[i]} 
    This is true as a[k] = a[k] and x =  ∑ (i = 0, i = k-1) a[i] (invariant)
    Proved {I ∧ B } → {I} (2)
    */
    x := x + a[k];
    /* Axiom of subsitution
    Invariant I = {x = ∑ (i = 0, i = k) a[i]} 
    */
    k := k + 1;
    /* Invariant I = {x = ∑ (i = 0, i = k-1) a[i]} */
  }
  /* (I ∧ ¬B) == {x = ∑ (i = 0, i = k-1) a[i] ∧ ¬(k != N)} ==
     {x = ∑ (i = 0, i = k-1) a[i] ∧ k = N)} ==
     {x = ∑ (i = 0, i = N-1) a[i]} which is equal to I
     Proved {(I ∧ ¬B)} → {q} (3)
  */
 
  /* Identical Substitution Lemma
     {x = ∑ (i = 0, i = k-1) a[i]}
  */
  /* THIS IS EQUIVALENT TO INSTRUCTION SKIP */
  /* Invariant I = {x = ∑ (i = 0, i = k-1) a[i]} */
  return x;
}
/* {x = ∑ (i = 0, i = N-1) a[i]} */

/* We have proved:
  (1) {p} → {I} 
  (2) {I ∧ B } → {I} 
  (3) {(I ∧ ¬B)} → {q}
  
  Hence 
  
*/



/* Total Correctness: ************************/


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
/* {true} */
