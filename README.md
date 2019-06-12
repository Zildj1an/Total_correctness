# Total_correctness
Demonstration on how to mathematically probe total correctness (and partial) of a simple program.
Partial correctness means that if the σ state's values satisfy p then σ' of the output will satisfy q.
Total correctness means that the program will terminate.
Taking into account:

```
Let I be invariant, bd boundarie, p precondition, q postcondition and S my program


  I → bd >= 0
  ⊧p {p} S {q}
  ⊧t {p} S {true}
  _______________
  ⊧t {p} S {q}
```
