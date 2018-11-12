"""
usage:
python generate_testcase.py [number of nodes] [number of edges]
"""

import random
import sys

V, E = int(sys.argv[1]), int(sys.argv[2])
edges = set()

print(V)
for i in range(E):
	while True:
		u, v = random.randint(0, V-1), random.randint(0, V-1)
		u, v = min(u, v), max(u, v)
		if u != v and (u, v) not in edges:
			edges.add((u,v))
			print(u, v)
			break
