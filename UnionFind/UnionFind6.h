// Created by dengxin05 on 2019/10/19.
//

#ifndef UNIONFIND_UNIONFIND6_H_
#define UNIONFIND_UNIONFIND6_H_

#include <iostream>
#include <cassert>

using namespace std;

namespace UF6{
    class UnionFind{
    private:
        int* parent;
        int* rank; // rank[i]表示以i为根的集合所表示的树的层数
        int count;

    public:
        UnionFind(int count){
            parent = new int[count];
            rank = new int[count];
            this->count = count;
            for(int i=0; i<count; i++){
                parent[i] = i;
                rank[i] = 1;
            }
        }

        ~UnionFind(){
            delete[] parent;
            delete[] rank;
        }

        int find(int p){
            assert(p >= 0 && p < count);
            if(p != parent[p])
                parent[p] = find(parent[p]);
            return parent[p];
        }

        bool isConnected(int p, int q){
            return find(p) == find(q);
        }

        void unionElements(int p, int q){
            int pRoot = find(p);
            int qRoot = find(q);

            if(pRoot == qRoot)
                return;
            if(rank[pRoot] < rank[qRoot]){
                parent[pRoot] = qRoot;
            }else if(rank[qRoot] < rank[pRoot]){
                parent[qRoot] = pRoot;
            }else{// rank[pRoot] == rank[qRoot]
                parent[pRoot] = qRoot;
                rank[qRoot] += 1;
            }
        }
    };
}
#endif //UNIONFIND_UNIONFIND6_H_