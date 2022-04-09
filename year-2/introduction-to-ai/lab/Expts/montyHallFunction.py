from pomegranate import DiscreteDistribution
from pomegranate import ConditionalProbabilityTable
from pomegranate import BayesianNetwork, Node
from collections import defaultdict

def build_bayesnet_from_cpts(cpt_txt):
    # Load file content
    node_blobs = open(cpt_txt).read().strip().split("\n\n\n")

    # Track BayesNet nodes along with the node names
    nodes = defaultdict(dict)

    # Track dependency between nodes as tuples of node name pairs.
    # (x, y) means x is the parent of y.
    transition_tracker = []

    # Parse and create individual nodes
    for blob in node_blobs:
        lines = blob.strip().split("\n")

        # Extract the current node name
        node_name = lines[0].split(":")[0] 

        # Extract parents and labels
        parents_line = lines[1].split() 
        curr_node_lbls = parents_line[:3]
        parents = parents_line[3:]

        # Check for root node based on the no. of parents
        if len(parents) == 0:
            probs = [float(v) for v in lines[2].split()]
            nodes[node_name] = DiscreteDistribution(dict(zip(curr_node_lbls, probs)))
        else:
            table = []
            for line in lines[2:]:
                # Read probabilities and parent labels in the current line.
                line = line.split()
                probs = [float(v) for v in line[:3]]
                pa_lbls = line[3:]

                row = []
                for i, lbl in enumerate(curr_node_lbls):
                    # Append order: labels for the parents, then the curr node label.
                    row += pa_lbls
                    row.append(lbl)

                    # Finally the probability value
                    row.append(probs[i])

                table.append(row)

            # Create node
            nodes[node_name] = ConditionalProbabilityTable(table, parents)

            # Track transition
            transition_tracker += [(pa, node_name) for pa in parents]

    # Create Node objects
    states = {k: Node(nodes[k], name=k) for k in nodes}

    # Create the Bayesian network object with a useful name
    model = BayesianNetwork("Monty Hall Network")

    # Add states
    model.add_states(*states.values())

    # Add transitions
    for src, dest in transition_tracker:
        model.add_transition(states[src], states[dest])

    model.bake()

    return model