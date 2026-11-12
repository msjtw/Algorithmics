#import "@preview/codelst:2.0.2": sourcecode, code-frame

#set document(title: "CP Algorithms Handbook", author: "Stanisław Fiedler")
#set page(paper: "a4", margin: 1in, numbering: "1")
#set text(size: 11pt)
#set heading(numbering: "1.1")
#set raw(tab-size: 4)
#show raw.where(block: true): set text(size: 9pt)

// Inclusive, one-based source ranges, matching the original listings.
#let snippet(file, first, last) = {
  sourcecode(
    raw(read("code_snippets/" + file), lang: "cpp", block: true),
    showrange: (first, last),
    numbers-start: 1,
    numbers-style: number => text(size: 6pt, fill: gray, number),
    gutter: 5pt,
    tab-size: 4,
    gobble: 0,
    showlines: true,
    // Disable label parsing without codelst 2.0.2's `none` replacement bug.
    label-regex: regex("a^"),
    frame: code-frame.with(fill: rgb("fff7f2"), stroke: none, inset: 6pt, radius: 0pt),
  )
}

#align(center)[
  #text(size: 20pt)[CP Algorithms Handbook] \
  #text(size: 13pt)[for the recently deceased]

  #v(1em)
  Stanisław Fiedler\
  #datetime.today().display("[month repr:long] [day], [year]")

]

#outline(title: [Contents], depth: 3)


= Sorting and Searching

== Quick Sort <sub:quick_sort>
#snippet("sort", 24, 43)

== Merge Sort <sub:merge_sort>
#snippet("sort", 1, 21)

= Dynamic Programming

== State represenation <sub:state_represenation>

=== All subsets <ssub:all_subsets>
This way you can generate all subsets in order ready for DP.
#snippet("dp_states", 1, 5)



= Graph Algorithms

== DFS
#snippet("dfs_bfs", 1, 13)

== BFS
For BFS implementation look in #link(<ssub:dijkstra>)[Dijkstra]

== Shortest Path <sub:shortest_path>
=== Dijkstra <ssub:dijkstra>
Dijkstra's algorithm is a greedy graph-search algorithm that finds the shortest path from a starting source node to all other nodes in a weighted graph.
Does not work for negative edges.
#snippet("shortest_path", 1, 17)
=== Bellman-Ford
Bellman–Ford algorithm is a DP graph-search algorithm that finds the shortest path from a starting source node to all other nodes in a weighted graph.
Works for negative edges, and can detect negative cycle (if n-th iteration changes the distance).
#snippet("shortest_path", 43, 62)
=== Floyd–Warshal
The Floyd–Warshall algorithm is a dynamic programming method used to find the shortest paths between all pairs of vertices in a weighted directed or undirected graph.
#snippet("shortest_path", 19, 41)

== Union Find <sub:union_find>
#snippet("union_find", 7, 51)

== Path through all edges <sub:>
=== Oiler cycle (path), conditions:
- An *undirected* graph has an Eulerian 
  - *cycle* if and only if *every* vertex has *even degree*
  - *trail* if and only if exactly *zero or two* vertices have *odd degree*
- A *directed* graph has an Eulerian 
  - *cycle* if and only if *every* vertex has *equal* *in* degree and *out* degree
  - *trail* if and only if:
    - at most one vertex has (out-degree) − (in-degree) = 1 *(one source)*
    - at most one vertex has (in-degree) − (out-degree) = 1 *(one sink)*
    - every other vertex has equal in-degree and out-degree
=== Implementation
Find if Eulerian trail exists (from 1 - n) in directed graph exists.
#snippet("euleran_apth", 1, 67)

== Topo Sort <sub:topo_sort>
#snippet("topo_sort", 7, 50)

== Flows and Cuts
All problems in this section can be solved using the same basic algorithm defined in @sec:MAXFLOW.

=== Maximum Flow <sec:MAXFLOW>
This implementation of Ford-Fulkerson algorithm (known as Edmonds-Karp algorithm) uses BFS to check if it's possible to expand the flow through the graph and assign depths from the source. Later it uses DFS to expand te flow.
#snippet("max_flow", 11, 66)

To find the flow:
#snippet("max_flow", 89, 97)

=== Minimum Cut
To find Minimum Cut in a graph we need to find the Maximum Flow and check which edges connect two created disjont sets of nodes. This modification to finds them:
#snippet("min_cut", 92, 116)

=== Maximum Matching

== 2SAT

Given logical formula in the conjunctive normal form:
$ (a_1 or b_1) and (a_2 or b_2) and dots.c and (a_n or b_n) $
we can eliminate disjunction by repacing each $(a_i or b_i)$ element with pair:
$ not a_i arrow.r b_i and not b_i arrow.r a_i $

#snippet("2sat", 9, 122)

= Range Queries

== Segment trees

BASE size table:
#align(center)[
  #table(
    columns: 4,
    align: center,
    stroke: 0.5pt,
    [$a$], [$2 dot 10^5$], [$5 dot 10^5$], [$10^6$],
    [$log_2 a$], [18], [19], [20],
  )
]

=== Point-Range Trees
#snippet("segment_trees", 83, 109)

=== Range-Range Trees
+ range ADD insert, range MAX value query
  #snippet("segment_trees", 1, 20)
  #snippet("segment_trees", 22, 39)
+ range ADD insert, range SUM qyerry
  #snippet("segment_trees", 41, 63)
  #snippet("segment_trees", 65, 83)

== Max Subarray Sum <sub:max_subarray_sum>
#snippet("max_subarray", 1, 22)

= Tree Algorithms

== Binary Lifitng <sub:binary_lifitng>
#snippet("trees", 24, 35)

== Tree Traversal <sub:tree_traversal>
#snippet("trees", 1, 16)

== LCA <sub:lca>
LCA can be found using binary lifting or by building a segment tree build on pre- and postorder.

= String Algorithms

== Trie <sub:trie>
#snippet("trie", 9, 34)

== Pattern Finding <sub:pattern_finding>

=== KMP <ssub:kmp>
The Knuth-Morris-Pratt (KMP) algorithm is a linear-time string-searching algorithm that finds occurrences of a word W (pattern) inside a main text string S
#snippet("strings", 7, 29)

=== Hashing <ssub:hashing>
#snippet("strings", 37, 72)



== Palindormes <sub:pal>
Fiding longest palindromic substring.
#snippet("strings", 75, 107)

= Mathematics

== Small Fermat's Theorem (Modular inverse) <sub:fermat_s_theorem>
$ "If m is prime, then: " x^(-1) thin "mod" thin m = x^(m-2) thin "mod" thin m $
$ x^(phi(m)) thin "mod" thin m = x^(k thin "mod" thin (m-1)) thin "mod" thin m $
#snippet("math", 7, 15)

== Fast Fibonacci (Matrix) <sub:fast_fibonacci>
#snippet("math", 39, 74)

== 

== Chinese Remainder Theorem

= Geometry

== Point location <sub:nie_wiem_co_to_robi>
#snippet("geometry", 41, 47)

== Point in polygon <sub:point_in_polygon>
#snippet("geometry", 50, 99)

== Convex hull <sub:convex_hull>
Only finds the smallest convex hull.
Points on the hull are omitted.

#snippet("geometry", 1, 29)
