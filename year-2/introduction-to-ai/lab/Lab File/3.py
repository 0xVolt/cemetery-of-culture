# Code by Desh Iyer

# Experiment 3
# Write a program to implement Tautologies, Contradiction, and Satisfiability

import ttg

print('\nMy Name is "Desh Iyer"\nMy SAP Id is "500081889"\n')

tautologyTable = ttg.Truths(
    ['P', 'Q'],
    ['not P', 'not Q', 'P implies Q', 'not Q implies not P',
        '(P implies Q) = ((not Q) implies (not P))']
)

contradictionTable = ttg.Truths(
    ['P'],
    ['not P', 'P and not P']
)


print('- Example of a Tautology\n')

print(
    f'Truth Table for (p -> q) <-> (~q -> ~p):\n{tautologyTable}\n\nSince the statement produces a True output for any value of P or Q, the statement (p -> q) <-> (~q -> ~p) is a Tautology.\n\n')

print('- Example of a Contradiction\n')
print(
    f'Truth Table for (p ^ ~p):\n{contradictionTable}\n\nSince the statement produces a False output for any value of P, the statement (p ^ ~p) is a Contradiction.')
