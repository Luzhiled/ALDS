#include <iostream>
#include <array>
#include <vector>
#include <string>

struct NodeBase {
    NodeBase *l, *r, *p;
    int key;

    NodeBase() { l = r = p = nullptr; }
    NodeBase(int key) : key(key) { l = r = p = nullptr; }

    void set_key(int k) {
        key = k;
    }
};

template< typename Node, std::size_t LIM >
struct Tree {
    std::size_t idx;
    Node* root;
    std::vector< Node > pool;
    // static std::array< Node, LIM > pool;

    Tree(): idx(0), pool(LIM) { root = nullptr; }

    Node* create() {
        return &pool[idx++];
    }

    Node* create(Node v) {
        return &(pool[idx++] = v);
    }

    void insert(Node v) {
        Node *z = create(v);
        Node* y = nullptr;
        Node* x = root; 

        while (x) {
            y = x;
            if (z->key < x->key) {
                x = x->l; 
            } else {
                x = x->r;
            }
        }

        z->p = y;

        if (!y) {
            root = z;
        } else if (z->key < y->key) {
            y->l = z;
        } else {
            y->r = z;
        }
    }

    Node* find(int key) {
        Node *v = root;
        
        while (v) {
            if (v->key == key) return v;
            if (v->key > key) v = v->l;
            else v = v->r;
        }
        return v;
    }

    void erase(int key) {
        Node *v = find(key);

        while (v) {
            if (v->l && v->r) {
                Node *u = v->r;
                while (u->l) u = u->l;

                v->key = u->key;
                v = u;
            } else if (v->l) {
                Node *p = v->p;
                if (p->l == v) {
                    p->l = v->l;
                    v->l->p = p;
                }
                else {
                    p->r = v->l;
                    v->l->p = p;
                }
                v = nullptr;
            } else if (v->r) {
                Node *p = v->p;
                if (p->l == v) {
                    p->l = v->r;
                    v->r->p = p;
                }
                else {
                    p->r = v->r;
                    v->r->p = p;
                }
                v = nullptr;
            } else {
                Node *p = v->p;
                if (p->l == v) p->l = nullptr;
                else p->r = nullptr;
                v = nullptr;
            }
        }
    }

    void print() {
        std::vector< int > ps;
        inorder_walk(root, ps);
        for (auto &p: ps) std::cout << " " << p;
        std::cout << std::endl;

        ps.clear();
        preorder_walk(root, ps);
        for (auto &p: ps) std::cout << " " << p;
        std::cout << std::endl;
    }

private:
    void inorder_walk(Node *v, std::vector< int > &vs) {
        if (v->l) inorder_walk(v->l, vs);
        vs.emplace_back(v->key);
        if (v->r) inorder_walk(v->r, vs);
    }

    void preorder_walk(Node *v, std::vector< int > &vs) {
        vs.emplace_back(v->key);
        if (v->l) preorder_walk(v->l, vs);
        if (v->r) preorder_walk(v->r, vs);
    }

};

int main() {
    int q;
    std::cin >> q;

    Tree< NodeBase, 500000 > t;
    while (q--) {
        std::string s;
        std::cin >> s;

        if (s[0] == 'i') {
            int key;
            std::cin >> key;

            NodeBase v(key);
            t.insert(v);
        } else if (s[0] == 'f') {
            int key;
            std::cin >> key;
            std::cout << (t.find(key) ? "yes" : "no") << std::endl;
        } else if (s[0] == 'd') {
            int key;
            std::cin >> key;
            t.erase(key);
        } else {
            t.print();
        }
    }
}
