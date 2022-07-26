# Code by Desh Iyer

# Experiment 6
# Write a program to solve the Travelling Salesperson algorithm for a real-world problem (Using 3 nodes)

from itertools import permutations

print('\nMy Name is "Desh Iyer"\nMy SAP Id is "500081889"\n')

# Function to calculate the Euclidian distance between two points
def distance(p1, p2):
    return ((p1[0] - p2[0])**2 + (p1[1] - p2[1])**2) ** 0.5


# Function to implement the Traveling Salesman Approach
def traveling_salesman(points, start=None):
    if start is None:
        start = points[0]
    return min([perm for perm in permutations(points) if perm[0] == start], key=total_distance)


# Function to calculate the shortest distance
def total_distance(points):
    return sum([distance(point, points[index + 1]) for index, point in enumerate(points[:-1])])


# Start of main function
def main():
    points = [[1, 2], [45, 65], [20, 30]]
    points = points[:3]
    result = traveling_salesman(points)
    distance_result = total_distance(result)

    print("""
            The path provided is {0}\nFrom starting {1} distance is {2} path followed {3}
        """.format(
            points,
            points[0],
            distance_result,
            result
        )
    )


# Main function call
if __name__ == "__main__":
    main()
