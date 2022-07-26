# Import libraries
from pomegranate import DiscreteDistribution
from pomegranate import ConditionalProbabilityTable
from pomegranate import BayesianNetwork, Node

# Print details
print("Bayesian Networks")
print("Desh Iyer, 500081889, B3")

# Created distribution for Burglary occurring
Burglary = DiscreteDistribution({'T': .001, 'F': .999})
 
# Created distribution for Earthquake occurring
Earthquake = DiscreteDistribution({'T': .002, 'F': .998})

# Supposed values of conditional probability for the Alarm going off
# T T 0.95 0.05
# T F 0.94 0.06
# F T 0.29 0.71
# F F 0.001 0.999
# Creating a conditional probability table for the Alarm going off taking into account 
# P(A) = P(A | B, E)
Alarm = ConditionalProbabilityTable([
    ['T', 'T', 'T', .95],
    ['T', 'T', 'F', .05],
    ['T', 'F', 'T', .94],
    ['T', 'F', 'F', .06],
    ['F', 'T', 'T', .29],
    ['F', 'T', 'F', .71],
    ['F', 'F', 'T', .001],
    ['F', 'F', 'F', .999],
], [Burglary, Earthquake])

# Creating three nodes
d1 = Node(Burglary, name="Burglary")
d2 = Node(Earthquake, name="Earthquake")
d3 = Node(Alarm, name="Alarm")
# d4 = Node(John, name="John Calls")
# d5 = Node(Mary, name="Mary Calls")

# Building the Bayesian Network using pomegranate
network = BayesianNetwork("Representing the Alarm System Problem with Bayesian Networks")
network.add_states(d1, d2, d3)
network.add_edge(d1, d3)
network.add_edge(d2, d3)
# network.add_edge(d3, d4)
# network.add_edge(d3, d5)
network.bake()

# Taking user input to put the Bayesian network to use
bVal = input("True or False for Burglary (T/F): ")
eVal = input("True or False for Earthquake (T/F): ")

# Making the prediction
beliefs = network.predict_proba({'Burglary': bVal, 'Earthquake': eVal})

# Displaying details
beliefs = map(str, beliefs)
print("\n".join("{}, {}".format(state.name, belief) for state, belief in zip(network.states, beliefs)))

# John Calls
# T 0.90 0.1
# F 0.05 0.95
# John = ConditionalProbabilityTable([
#         ['T', 'T', 0.9],
#         ['T', 'F', 0.1],
#         ['F', 'T', 0.05],
#         ['F', 'F', 0.95],
#     ]
# )

# Mary Calls
# T 0.7 0.3
# F 0.01 0.99
# Mary = ConditionalProbabilityTable([
#         ['T', 'T', 0.7],
#         ['T', 'F', 0.3],
#         ['F', 'T', 0.01],
#         ['F', 'F', 0.99],
#     ]
# ) 