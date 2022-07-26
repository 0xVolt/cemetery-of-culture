# Code by Desh Iyer

# Experiment 2
# Write a program to implement propositional logic in AI

# This program makes use of the powerful python library truth-table-generator (i.e., ttg) to generate truth tables. Using this library, I can spend more time and LOC focussing on building propositional logic statements than worrying about the displaying of the final table

import ttg

print('\nMy Name is "Desh Iyer"\nMy SAP Id is "500081889"\n')

conjunctionTable = ttg.Truths(['P', 'Q'], ['P and Q'])
print(f'Table #1 Conjunction:\n{conjunctionTable}')

disjunctionTable = ttg.Truths(['P', 'Q'], ['P or Q'])
print(f'\nTable #2 Disjunction:\n{disjunctionTable}')

negationTable = ttg.Truths(['P'], ['not P'])
print(f'\nTable #3 Negation:\n{negationTable}')

implicationTable = ttg.Truths(['P', 'Q'], ['P implies Q'])
print(f'\nTable #4 Implication:\n{implicationTable}')

bicondTable = ttg.Truths(['P', 'Q'], ['(P implies Q) and (Q implies P)'])
print(f'\nTable #5 Bi-Conditional:\n{bicondTable}')

# To prove deMorgan's law
deMorgan = ttg.Truths(['P', 'Q'], ['not P and not Q', 'not(P or Q)'])
print(f"\nTable #2:\nProve deMorgans Law: (A and B)' == A' or B'\n{deMorgan}")