# Total_correctness
Demonstration on how to mathematically prove a sequential program terminates and its "correct" in the sense of
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
