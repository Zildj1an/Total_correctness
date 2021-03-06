/* This will not compile (special notation). */
#include <stdio.h>

int main(void){
  int N := 4; 
  int a[N] := {1,2,2,1};
  int sum := sum_digits(a,N);
  
 return 0;
}

/* 
 PRECONDITION: {N >= 0} 
 POSTCONDITION: {x = ∑ (i = 0, i = N-1) a[i]} 
 
 in order to distinguish logical equivalents from instructions
 I will use ':=' for instructions.
 The program computes the sum of values of an array a.
 
 I will prove backwards being that {w [u:= t]} u := t {w} 
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
 
  /* skip
  (THIS EMPTY SPACE IS EQUIVALENT TO INSTRUCTION SKIP)
  And: {p} skip {p} ∀ p logical predicate 
  */
 
  /* Invariant I = {x = ∑ (i = 0, i = k-1) a[i]} */
 
 return x;
}
/* {x = ∑ (i = 0, i = N-1) a[i]} */

/* We have proved backwards:
  (1) {p} → {I} 
  (2) {I ∧ B } → {I} 
  (3) {(I ∧ ¬B)} → {q}
  
  Hence ⊧p {p} S {q}
  
*/

/* Total Correctness: ************************/

/* In this case the boudarie is {N - k} 
   I WILL USE THE EXTRA VARIABLE z TO PROVE
   THE BOUNDARIE DECREASES.
*/

/* {N >= 0} */
inline int sum_digits(int *a, int N){
  /* Axiom of substitution
   {0 = ∑ (i = 0, i = -1) a[i]} 
   Same as for (1) of Partial Correctness
  */
  k := 0;
  x := 0;
  /* Invariant I = {x = ∑ (i = 0, i = k-1) a[i]}{bd: N - k} */
  
  while (k != N) {
    
    /* {x + a[k] = ∑ (i = 0, i = k) a[i]} and N - k > N - (k + 1)
    
       It is trivial that N - k > N - (k + 1)
       therefore the boundarie decreases and as I → bd >= 0
       the program terminates.
    */
    /* EXTRA ASSIGNMENT */
    z := N - k;
    /* {x + a[k] = ∑ (i = 0, i = k) a[i]} and z > N - (k + 1) */
    x := x + a[k]; 
    k := k + 1;
    /* Invariant I = {x = ∑ (i = 0, i = k-1) a[i] and z > N - k} */
  }
   /* (I ∧ ¬B) == {x = ∑ (i = 0, i = k-1) a[i] ∧ ¬(k != N)} ==
     {x = ∑ (i = 0, i = k-1) a[i] ∧ k = N)} ==
     {x = ∑ (i = 0, i = N-1) a[i]} which is equal to I
     Proved {(I ∧ ¬B)} → {q} (3)
   */
 
   /* Identical Substitution Lemma
     {x = ∑ (i = 0, i = k-1) a[i]}
  */
 
   /* skip
   (THIS EMPTY SPACE IS EQUIVALENT TO INSTRUCTION SKIP)
   And: {p} skip {p} ∀ p logical predicate 
   */
 
  /* Invariant I = {x = ∑ (i = 0, i = k-1) a[i]} */
  return x;
}
/* The invariant → true == q */
/* {true} */
/* □ */

