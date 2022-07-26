# Code by Desh Iyer

# Experiment 3
# Write a program to implement Tautologies, Contradiction, and Satisfiability

import numpy as np

print('\nMy Name is "Desh Iyer"\nMy SAP Id is "500081889"\n')

print('Example of Tautology : ')
print('Truth Table for (p->q)<->(~q->~p) : ')

p = [True, True, False, False]
q = [True, False, True, False]

print('q:', p)
print('q:', q)

not_q = np.logical_not(q)
not_p = np.logical_not(p)
implication1 = np.logical_or(not_p, q)

print('~p : ', not_p)
print('~q : ', not_q)
print('p => q :', implication1)

implication2 = np.logical_or(q, not_p)
print('~q -> ~p :', implication2)

xor_operation = np.logical_xor(implication1, implication2)
result = np.logical_not(xor_operation)

print('')
print('Final Truth Table for the Statement, (p->q)<->(~q->~p) :', result)
print("All values are True. Hence, It is a Tautology.")
print('\nExample of Contradiction : ')
print('Truth Table for (p ^ ~p) : ')

p = [True, False]
not_p = np.logical_not(p)

print('p: ', p)
print('~p: ', not_p)
print("")

result = np.logical_and(p, not_p)

print('Final Truth Table for the Statement, (p ^ ~p) :', result)
print("All values are False. Hence, It is a Contradiction.\n")
