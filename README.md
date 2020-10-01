# Total_correctness

These repository contains demonstrations on how to prove correctness for both sequential and lock-free concurrent objects.

## Sequential Prove

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

## Concurrent Prove (Lock-free objects)

It is easy to prove a concurrent object is correct (deadlock freedom, liveness, starvation freedom) if we use locks, as that forces sequential execution. Nevertheless, this is undesirable because there is no Speedup in multiprocessor environments. 

In order to prove correctness of a lock-free concurrent object we need to show it is linearizable. With Linearizability we map the concurrent object to a sequential object that can be analyzed.
[TODO]
