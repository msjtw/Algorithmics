import sys
import matplotlib.pyplot as plt

# Read all lines from stdin
lines = sys.stdin.read().strip().splitlines()

N = int(lines[0])
points = [tuple(map(float, line.split())) for line in lines[1:N+1]]

# Separate x and y
xs = [p[0] for p in points]
ys = [p[1] for p in points]

# Close polygon
xs.append(points[0][0])
ys.append(points[0][1])

# Draw
plt.plot(xs, ys)
plt.scatter(xs, ys)
plt.gca().set_aspect('equal', adjustable='box')
plt.show()
