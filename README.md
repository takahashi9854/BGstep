BGstep
======

Baby step, Giant Step.
Since Nov 26th.

=====

This followings are the  algorithm of Baby step, Giant step.
  
Let #E(F_q) = N.
1.Compute Q = (q+1)P.

2.Choose an integer m with more than 4-th root of q. Compute and store
the Points jP for j=0,1,2,...,m.

3.Compute the points
Q + k(2m)P for k=-m,-(m-1),...,m
until there is a match Q+k(2m)P = \pm jP with a point (or its negative) on the stored list.

4.Conclude that (q+1+2mk \mp j)P = \infty. Let M = q+1+2mk \mp j.
	   
5.Factor M. Let p_1,....,p_r be the distinct prime factors of M.

6.Compute (M/p_i) for i=1,...,r. If (M/p_i)P = \infty for some i, replace M with M/p_i and go back to step (5).
If (M/p_i)P \neq \infty for all i then M is the order of the point P.

7.If we are looking for the #E(P_q), then repeat step (1)-(6) with randomly chosen points in E(F_q) until
the greatest common multiple of the orders divides only one integer N between q+1-2\sqrt{q} and q+1+\sqrt{q}.
Then N = #E(F_q).

====

Remarks follows.
  
To save storage space, it might be more efficient to store only the x coordinates of the points jP
(along with the corresponding integer j), since looking for a match with \pm jP only require the x-coordinate
(assuming we are working with a Weierstrass equation). When a match is found, the two possible y-coordinates
can be recomputed.

Computing Q+k(2m)P can be done by computing Q and 2mP once for all. To get from Q+k(2m)P to Q+(k+1)(2mP),
simply add 2mP rather than recomputing everything. Similarly, once jP has been computed, add P to get (j+1)P.

We are assuming that we can factor M. If not, we can at least find all the small prime
factor p_i and check that (M/p_i)P\neq \infty for these. Then M will be good candidate for the order of P.

Why is the method called "Baby Step, Giant Step"? The baby steps are from a point jP to (j+1)P.
The giant steps are from a point k(2m)P to (k+1)(2m)P, since we take the "bigger" step 2mP.

 

