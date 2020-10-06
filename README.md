# Total_correctness

This repository contains demonstrations on how to prove correctness for both sequential and lock-free concurrent objects.

## 1. Sequential Proof

File sequential.c is a demonstration on how to mathematically prove a sequential program terminates and its "correct" in the sense of
total correctness (and partial) of a simple program.

* _Partial correctness_ means that if the σ state's values satisfy p then σ' of the output will satisfy q.

* _Total correctness_ means that the program will terminate.

Taking into account:

```
Let I be invariant, bd boundarie, p precondition, q postcondition and S my program


  I → bd >= 0
  ⊧p {p} S {q}
  ⊧t {p} S {true}
  _______________
  ⊧t {p} S {q}
```

## 2. Concurrent Proof (Lock-free objects)

It is easy to prove a concurrent object is correct (deadlock freedom, liveness, starvation freedom) if we use locks, as that forces sequential execution. Nevertheless, this is undesirable because there is no Speedup in multiprocessor environments. 

In order to prove correctness of a lock-free concurrent object we need to show it is linearizable. With Linearizability we map the concurrent object to a sequential object that can be analyzed. Formally, we can describe linearizability by defining:

* 1. Each method call has an invocation and a return, that can be a value or an exception. If thread A calls method enq of object q with parameter x we notate 
```
A  q.enq(x)
```
And the return will have the method implicitly described, for example 
```
A  q:void
```

* 2. A History is a finite set of methods that describe the concurrent execution. A History can have method calls without matching method returns, we say it has pending invocations. We can also focus only on events from a specific thread, creating the object subhistory. For example, 
```
H | q
```
and we can similarly do thread projections, for example with 
```
H | B
```

* 3. A history is sequential if we start with a method invocation and each of them is followed by a matching response, the last event being exempt. 
* 4. A history is well-formed if all per-thread projects are sequential.
* 5. Two histories H and G are equivalent if for all thread A at H we know that H|A = H|B.
* 6. A history is legal if for all object x, H|B is the legal sequential specification of x.

### Linearizability
Hence, we can say that a History H is linearizable if:
- We can extend it to History G which is complete by (A) Appending zero or more responses to pending invocations or (B) discarding pending invocations that do not take effect.
- Show that G is equivalent to a history S such that S is legal, S is sequential (we have a total order for the events) and all the existing precedence relations of G are on S.
