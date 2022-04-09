import pandas as pd

def negation(p):
    return not p

def conjuction(p, q):
    return p and q

def disjunction(p, q):
    return p or q

def implication(p, q):
    result = []

    for i in result:
        result[i] = not p or q

    return result 

def biconditional(p, q):
    return conjuction(implication(p, q), implication(q, p))

P = [True, True, False, False]
Q = [True, False, True, False]

data = {
    "P": P,
    "Q": Q,
    "P->Q": implication(P, Q)
}

df = pd.DataFrame(data, columns=["P", "Q", "P->Q"])
print(df)