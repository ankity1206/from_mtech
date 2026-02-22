## Date-wise Details of the Lectures:

## 07-01-2026, Class 1:
```sql
    i. Introductory Lecture
(ch1 of B1, ch1 of B3)
```
## 09-01-2026, Class 2:
```sql
    i. Kerckhoffs' Principle
    ii. Old Classical Ciphers: Caesar's Cipher, Shift Cipher, Substitute Cipher, Vigenere Cipher, and their Cryptanalysis
(ch1 of B1, ch2 of B3)
```
## 14-01-2026, Class 3:
```sql
    i. Shannon and Perfect Secrecy:
         a. Different Definitions and their equivalence
         b. Shift Cipher and Perfect Secrecy
         c. Perfect Indistinguishability and Perfect Secrecy
(ch2 of B1, ch1 of B2, ch3 of B3)
```

## 21-01-2026, Class 4:
```sql
    i. Shannon and Perfect Secrecy (cont.):
         a. Perfect Indistinguishability (Adversarial Model) and Perfect Secrecy
         b. One-Time Pad and Perfect Security
         c. Limitations of Perfect Security
         d. Shannon's Theorem
(ch2 of B1, ch1 of B2, ch3 of B3)
```

## 28-01-2026, Class 5:
```sql
    i. Computational Encryption Scheme
    ii. Concrete approach and Asymptotic Approach
    iii. Negligible Function
    iv. Semantic Security and Indistinguishability
    v. Different definitions of Indistinguishability in the presence of eavesdropper, and their equivalence.
(ch3 of B1, ch1 of B2)
```

## 30-01-2026, Class 6:
```sql
    i. Message Recovery (MR) Attack
    ii. Relation between MR attack and Indistinguishability
    iii. Parity Prediction Attack
    iv. Relation between MR attack and Indistinguishability
(ch3 of B1, ch1 of B2)
```

## 04-02-2026, Class 7:
```sql
    i. Introduction to Psudorandomness
    ii. Pseudorandom Generator and the corresponding Indistinguishability attack
    iii. Discussion: PRG is far from random
    iv. Existance of PRG
    v. Construction of One-Time-Pad using PRG and proof of its security
(ch3 of B1, ch2 of B2)
```

## 06-02-2026, Class 8:
```sql
    i. Composing PGR
        -- Parallel Construction and its security proof (Introduction to Hybrid games)
        -- Sequential construction: the Blum-Micali method, and its proof
    ii. The Next Bit test: Unpredictability
    iii. Proof of equivalance between Unpredictability and Indistinguishability
        -- Distinguisher/predictor lemma
(ch2 of B2)
```

## 11-02-2026, Class 9:
```sql
    i. Stream Cipher
    ii. Linear-Feedback Shift Register and adding Nonlinearity
    iii. Practical Construction: Trivium and RC4
    **Also study Salsa and Chacha, and Content Scrambling System (CSS).
(ch6 of B1, ch2 of B2)
```

## 13-02-2026, Class 10:
```sql
    i. Definition of Psudorandom Function (PRF) and weak Psudorandom Function (wPRF)
         -- Efficient Implementation of Random Function
    ii. Definition of Psudorandom Permutation and  strong Psudorandom Permutation (sPRP)
         -- Efficient Implementation of Random Permutation
    iii. Is a PRP a PRF? (Following is my personal choice of sequence of reading)
        -- The Birthday Problem (A4 of B1)
        -- Difference Lemma (Theorem 4.7 of B2)
        -- Permutation vs Function (Theorem 4.6 of B2)
        -- PRF Switching Lemma (Theorem 4.4 of B2)
        -- Corollary 4.5 of B2
        -- Now read the Section 4.4.3 of B2 once again
(ch3 of B1, ch4 of B2)
```

[NOTE!] Reference Books:
> B1. Introduction to Modern Cryptography ~ J. Katz, Y. Lindell 
> B2. A Graduate Course in Applied Cryptography ~ D. Boneh, V. Shoup (Version 0.6, Jan. 2023)
> B3. Cryptography Theory and Practice ~ D. Stinson (Fourth Edition)
