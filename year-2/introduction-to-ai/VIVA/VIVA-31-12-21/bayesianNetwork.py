# Code by Desh Iyer

import random
from pomegranate import *
from pomegranate import Node

# Print details
print("Bayesian Networks")
print("Desh Iyer, 500081889, B3")

# Create two independent events using discrete distributions
guest = DiscreteDistribution({'A': 1. / 3, 'B': 1. / 3, 'C': 1. / 3})
prize = DiscreteDistribution({'A': 1. / 3, 'B': 1. / 3, 'C': 1. / 3})

# Creating a dependent event using a conditional probability table taking the above tables into account
monty = ConditionalProbabilityTable([
        ['A', 'A', 'A', 0.0], 
        ['A', 'A', 'B', 0.5], 
        ['A', 'A', 'C', 0.5], 
        ['A', 'B', 'A', 0.0], 
        ['A', 'B', 'B', 0.0], 
        ['A', 'B', 'C', 1.0], 
        ['A', 'C', 'A', 0.0], 
        ['A', 'C', 'B', 1.0], 
        ['A', 'C', 'C', 0.0], 
        ['B', 'A', 'A', 0.0], 
        ['B', 'A', 'B', 0.0], 
        ['B', 'A', 'C', 1.0], 
        ['B', 'B', 'A', 0.5], 
        ['B', 'B', 'B', 0.0], 
        ['B', 'B', 'C', 0.5], 
        ['B', 'C', 'A', 1.0], 
        ['B', 'C', 'B', 0.0], 
        ['B', 'C', 'C', 0.0], 
        ['C', 'A', 'A', 0.0], 
        ['C', 'A', 'B', 1.0], 
        ['C', 'A', 'C', 0.0], 
        ['C', 'B', 'A', 1.0], 
        ['C', 'B', 'B', 0.0], 
        ['C', 'B', 'C', 0.0], 
        ['C', 'C', 'A', 0.5], 
        ['C', 'C', 'B', 0.5], 
        ['C', 'C', 'C', 0.0]
    ], 
    [guest, prize]
)

# Creating 3 nodes to the bayesian distribution
d1 = Node(guest, name="guest")
d2 = Node(prize, name="prize")
d3 = Node(monty, name="monty")

# Creating the table
network = BayesianNetwork("Solving the Monty Hall Problem With Bayesian Networks")

network.add_states(d1, d2, d3)
network.add_edge(d1, d3)
network.add_edge(d2, d3)

network.bake()

# Taking user input for which door to choose
door = input("Enter the Door to choose: [A, B, C]: ")
optionsList = ['A', 'B', 'C']
optionsList.remove(door)

# Calculating probability and Printing results
print("\nPrinting output:\n")
beliefs = network.predict_proba({'guest': door, 'monty': random.choice(optionsList)})
print("\n".join( "{}\t{}".format(state.name, str(belief)) for state, belief in zip(network.states, beliefs)))