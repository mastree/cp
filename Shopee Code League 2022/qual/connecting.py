from collections import defaultdict
 
 
class Interval:
    '''Internal class for PlanarityChecker'''
 
    def __init__(self, low=None, high=None):
        self.low = low
        self.high = high
 
    def empty(self):
        return self.low is None and self.high is None
 
 
class ConflictPair:
    '''Internal class for PlanarityChecker'''
 
    def __init__(self, L=Interval(), R=Interval()):
        self.L = L
        self.R = R
 
 
class PlanarityChecker:
    def __init__(self, n_vertices):
        '''
        :param: n_vertexes - number of vertices in the Graph
        '''
        self.vertex_count = n_vertices
        self.edges_count = 0
        self.adjacency_list = [set() for _ in range(n_vertices)]
 
    def __len__(self):
        '''number of vertexes'''
        return self.vertex_count
 
    def add_edge(self, v, u):
        '''add undirected edge v-u'''
        assert v != u and 0 <= v < self.vertex_count and 0 <= u < self.vertex_count
        self.adjacency_list[v].add(u)
        self.adjacency_list[u].add(v)
        self.edges_count += 1
 
    def is_planar(self):
        """Check that given Graph is planar"""
        if len(self) < 5:
            return True
        if 3 * len(self) - 6 < self.edges_count:
            return False
 
        # initialize variables
        self.__height = [-1 for i in range(len(self))]
        self.__parent = [-1 for i in range(len(self))]
        self.__dir_adjacenty_list = [set() for i in range(len(self))]
        self.__lowpt = dict()
        self.__lowpt2 = dict()
        self.__nesting_depth = dict()
 
        for i in range(len(self)):
            if self.__height[i] == -1:
                self.__orient_edges(i)
 
        self.__Stack = []
        self.__lowpt_edge = dict()
        self.__stack_bottom = dict()
        self.__ref = defaultdict(lambda: None)
        self.__side = defaultdict(lambda: 1)
 
        for i in range(len(self)):
            if self.__height[i] == 0:  # root
                if not self.__check_planarity(i):
                    return False
 
        return True
 
    def __orient_edges(self, v, p=-1, h=0):
        """make graph directied via dfs"""
        self.__height[v] = h
        self.__parent[v] = p
        for to in self.adjacency_list[v]:
            if v in self.__dir_adjacenty_list[to]:  # straight edge
                continue
            else:
                self.__dir_adjacenty_list[v].add(to)
 
            v_to = (v, to)
            self.__lowpt[v_to] = self.__height[v]
            self.__lowpt2[v_to] = self.__height[v]
            if self.__height[to] == -1:  # tree edge
                self.__orient_edges(to, v, h + 1)
            else:  # back edge
                self.__lowpt[v_to] = self.__height[to]
 
            self.__nesting_depth[v_to] = 2 * self.__lowpt[v_to]
            if self.__lowpt2[v_to] < self.__height[v]:
                self.__nesting_depth[v_to] += 1
 
            if p != -1:
                p_v = (p, v)
                if self.__lowpt[v_to] < self.__lowpt[p_v]:
                    self.__lowpt2[p_v] = min(self.__lowpt[p_v], self.__lowpt2[p_v])
                    self.__lowpt[p_v] = self.__lowpt[v_to]
                elif self.__lowpt[v_to] > self.__lowpt[p_v]:
                    self.__lowpt2[p_v] = min(self.__lowpt2[p_v], self.__lowpt[v_to])
                else:
                    self.__lowpt2[p_v] = min(self.__lowpt2[p_v], self.__lowpt2[v_to])
 
    def __check_planarity(self, v):
        """can make LR-partition"""
        p_v = (self.__parent[v], v)
        sorted_adj_list = sorted(self.__dir_adjacenty_list[v], key=lambda u: self.__nesting_depth[(v, u)])
        for to in sorted_adj_list:
            v_to = (v, to)
            self.__stack_bottom[v_to] = (self.__Stack[-1] if len(self.__Stack) > 0 else None)
            if v == self.__parent[to]:  # tree edge
                if not self.__check_planarity(to):
                    return False
            else:  # back edge
                self.__lowpt_edge[v_to] = v_to
                self.__Stack.append(ConflictPair(R=Interval(v_to, v_to)))
 
            if self.__lowpt[v_to] < self.__height[v]:
                if to == sorted_adj_list[0]:
                    self.__lowpt_edge[p_v] = self.__lowpt_edge[v_to]
                else:
                    if not self.__add_constraints(v_to, p_v):
                        return False
 
        if self.__parent[v] != -1:
            p = self.__parent[v]
            #  trim back edges ending at parent
            while len(self.__Stack) > 0 and self.__lowest(self.__Stack[-1]) == self.__height[p]:
                P = self.__Stack.pop()
                if not P.L.empty() and P.L.low is not None:
                    self.__side[P.L.low] = -1
 
            if len(self.__Stack) > 0:
                P = self.__Stack.pop()
                while P.L.high is not None and P.L.high[1] == p:
                    P.L.high = self.__ref[P.L.high]
                if P.L.high is None and P.L.low is not None:
                    self.__ref[P.L.low] = P.R.low
                    self.__side[P.L.low] = -1
                    P.L.low = None
 
                while P.R.high is not None and P.R.high[1] == p:
                    P.R.high = self.__ref[P.R.high]
                if P.R.high is None and P.R.low is not None:
                    self.__ref[P.R.low] = P.L.low
                    self.__side[P.R.low] = -1
                    P.R.low = None
                self.__Stack.append(P)
 
            #  side of (p, v) is side of a highest return edge
            if self.__lowpt[p_v] < self.__height[p]:
                H_l = self.__Stack[-1].L.high
                H_r = self.__Stack[-1].R.high
 
                if H_l is not None and (H_r is None or self.__lowpt[H_l] > self.__lowpt[H_r]):
                    self.__ref[p_v] = H_l
                else:
                    self.__ref[p_v] = H_r
        return True
 
    def __lowest(self, conflict_pair):
        if conflict_pair.L.empty():
            return self.__lowpt[conflict_pair.R.low]
        if conflict_pair.R.empty():
            return self.__lowpt[conflict_pair.L.low]
        return min(self.__lowpt[conflict_pair.R.low],
                   self.__lowpt[conflict_pair.L.low])
 
    def __add_constraints(self, v_to, p_v):
        P = ConflictPair()
        #  merge return edges of (v, to) into P.right
        while True:
            Q = self.__Stack.pop()
            if not Q.L.empty():
                Q.L, Q.R = Q.R, Q.L
            if not Q.L.empty():
                return False
            if self.__lowpt[Q.R.low] > self.__lowpt[p_v]:
                if P.R.empty():
                    P.R = Q.R
                else:
                    self.__ref[P.R.low] = Q.R.high
                P.R.low = Q.R.low
            else:
                self.__ref[Q.R.low] = self.__lowpt_edge[p_v]
            if len(self.__Stack) > 0 and self.__Stack[-1] == self.__stack_bottom[v_to]:
                break
 
        while self.__conflicting(self.__Stack[-1].L, v_to) or self.__conflicting(self.__Stack[-1].R, v_to):
            Q = self.__Stack.pop()
            if self.__conflicting(Q.R, v_to):
                Q.L, Q.R = Q.R, Q.L
            if self.__conflicting(Q.R, v_to):
                return False
 
            self.__ref[P.R.low] = Q.R.high
            if Q.R.low is not None:
                P.R.low = Q.R.low
 
            if P.L.empty():
                P.L = Q.L
            else:
                self.__ref[P.L.low] = Q.L.high
            P.L.low = Q.L.low
 
        if not P.L.empty() or not P.R.empty():
            self.__Stack.append(P)
        return True
 
    def __conflicting(self, interval, edge):
        return not interval.empty() and self.__lowpt[interval.high] > self.__lowpt[edge]
 
 
tc = int(input())
for _ in range(tc):
    n = int(input())
    a = list(map(int, input().split()))
    if (n <= 2):
        print("yes")
        continue
    p = PlanarityChecker(2 * n)
    lst = [[] for _ in range(n + 1)]
    for i in range(2 * n):
        lst[a[i]].append(i)
        p.add_edge(i, (i + 1) % (2 * n))
    for i in range(1, n + 1):
        u, v = lst[i][0], lst[i][1]
        res = abs(u - v)
        if res != 1 and res != 2 * n - 1:
            p.add_edge(u, v)

    print("yes" if p.is_planar() else "no")
    