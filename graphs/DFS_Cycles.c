//
// Created by danie on 27.06.2023.
//
/**
 * Same pseudo code as in slides but instead of void return true or false
 * and check if true was returned
 *
 * DFS-Cycle-Detection(G)
1. For each vertex v in G.V
2.     v.color = WHITE
3.     v.pred = NIL
4. cycleExists = FALSE
5. For each vertex v in G.V
6.     if v.color == WHITE and cycleExists == FALSE
7.         cycleExists = DFS-Visit(v)
8. return cycleExists

DFS-Visit(v)
1. v.color = GRAY
2. For each u in v.adj
3.     if u.color == WHITE
4.         u.pred = v
5.         if DFS-Visit(u) == TRUE
6.             return TRUE
7.     else if u != v.pred
8.         return TRUE
9. v.color = BLACK
10. return FALSE


 print Khop neighbors
 init nodes of the graph, all white
 foreach v in G.V
    printKHop(V, 0, 2)

 printKHop(V, currentTravel, k):
 currentTravel = currentTravel + 1;
 v.color = black
 foreach u in v.adj
   if u.color == WHITE
     u.pred = v
     if(currentTravel == k)
       print(u)
       return
      else printKHop(u, currentTravel, k)
 v.color = white
 */
