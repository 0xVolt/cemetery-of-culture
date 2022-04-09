# travelling salesman problem for 3 nodes taken up
from itertools import permutations


def distance(p1, p2):  # eucledian distance taken up here
    return ((p1[0] - p2[0])**2 + (p1[1] - p2[1])**2) ** 0.5


def traveling_salesman(points, start=None):  # function for salesman approach
    if start is None:
        start = points[0]
    return min([perm for perm in permutations(points) if perm[0] == start], key=total_distance)


def total_distance(points):  # function for distance shortest distance
    return sum([distance(point, points[index + 1]) for index, point in enumerate(points[:-1])])


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


if __name__ == "__main__":
    main()
