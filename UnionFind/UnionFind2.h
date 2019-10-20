// Created by dengxin05 on 2019/10/19.
//

#ifndef UNIONFIND_UNIONFIND2_H_
#define UNIONFIND_UNIONFIND2_H_

#include <iostream>
#include <cassert>

using namespace std;

namespace UF2{
    class UnionFind{
    private:
        int* parent;
        int count;

    public:
        UnionFind(int count){
            parent = new int[count];
            this->count = count;
            for(int i=0; i<count; i++){
                parent[i] = i;
            }
        }

        ~UnionFind(){
            delete[] parent;
        }

        int find(int p){
            assert(p >= 0 && p < count);
            while(p != parent[p])
                p = parent[p];
            return p;
        }

        bool isConnected(int p, int q){
            return find(p) == find(q);
        }

        void unionElements(int p, int q){
            int pRoot = find(p);
            int qRoot = find(q);

            if(pRoot == qRoot)
                return;

            parent[pRoot] = qRoot;
        }
    };
}
#endif //UNIONFIND_UNIONFIND2_H_