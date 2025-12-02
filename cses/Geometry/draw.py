
import sys
import matplotlib.pyplot as plt

points = [
        (-97, 56),
        (-96, -10),
        (-90, -93),
        (-88, 91),
        (-20, 99),
        (47, 98),
        (72, -96),
        (83, -90),
        (89, -61),
        (98, -15),
        (98, 42),
        (98, 69),
    ]

def read_points(lines, count, start_index):
    """Helper to read 'count' points from lines starting at 'start_index'."""
    points = []
    for i in range(count):
        if start_index + i >= len(lines):
            print(f"Expected {count} points but got only {i}.")
            break
        try:
            x, y = map(float, lines[start_index + i].split())
            points.append((x, y))
        except ValueError:
            print(f"Invalid coordinate line: '{lines[start_index + i]}'")
            break
    return points

def main():
    lines = [line.strip() for line in sys.stdin if line.strip()]
    if not lines:
        print("No input provided.")
        return

    # Parse the first line: N M
    try:
        n, m = map(int, lines[0].split())
    except ValueError:
        print("First line must contain two integers: N M")
        return

    # Read points for both polygons
    first_poly = read_points(lines, n, 1)
    second_poly = read_points(lines, m, 1 + n)

    if not first_poly or not second_poly:
        print("Not enough points to draw polygons.")
        return

    # Close polygons
    first_poly.append(first_poly[0])
    second_poly.append(second_poly[0])

    # Unpack for plotting
    x1, y1 = zip(*first_poly)
    x2, y2 = zip(*second_poly)
    xs, ys = zip(*points)

    # Plot
    plt.figure(figsize=(6, 6))
    plt.plot(x1, y1, 'b-', marker='o', label='Polygon 1')
    plt.plot(x2, y2, 'r-', marker='s', label='Polygon 2')
    plt.scatter(xs, ys, c='green', s=100, marker='o', edgecolors='black')
    plt.fill(x1, y1, alpha=0.2, color='blue')
    plt.fill(x2, y2, alpha=0.2, color='red')
    plt.title("Two Polygons from Input Points")
    plt.xlabel("X")
    plt.ylabel("Y")
    plt.legend()
    plt.axis("equal")
    plt.grid(True)
    plt.show()

if __name__ == "__main__":
    main()

