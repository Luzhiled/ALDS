#include <iostream>
#include <array>
#include <vector>
#include <string>

struct NodeBase {
    NodeBase *l, *r, *p;
    int key, priority;

    NodeBase() { l = r = p = nullptr; }
    NodeBase(int key, int priority) : key(key), priority(priority) { l = r = p = nullptr; }
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
        root = insert(root, v);
    }

    Node* insert(Node *t, Node v) {
        if (!t) {
            t = create(v);
            return t;
        }

        if (v.key == t->key) {
            return t;
        }

        if (v.key < t->key) {
            t->l = insert(t->l, v);
            if (t->priority < t->l->priority) {
                t = right_rotate(t);
            }
        } else {
            t->r = insert(t->r, v);
            if (t->priority < t->r->priority) {
                t = left_rotate(t);
            }
        }

        return t;
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
        root = erase(root, key);
    }

    Node* erase(Node *t, int key) {
        if (!t) {
            return nullptr;
        }

        if (key < t->key) {
            t->l = erase(t->l, key);
        } else if (key > t->key) {
            t->r = erase(t->r, key);
        } else {
            return erase_action(t, key);
        }

        return t;
    }

    Node* erase_action(Node *t, int key) {
        if (!t->l && !t->r) {
            return nullptr;
        } else if (!t->l) {
            t = left_rotate(t);
        } else if (!t->r) {
            t = right_rotate(t);
        } else {
            if (t->l->priority > t->r->priority) {
                t = right_rotate(t);
            } else {
                t = left_rotate(t);
            }
        }

        return erase(t, key);
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
    Node* right_rotate(Node *t) {
        Node *s = t->l;
        t->l = s->r;
        s->r = t;
        return s;
    }

    Node* left_rotate(Node *t) {
        Node *s = t->r;
        t->r = s->l;
        s->l = t;
        return s;
    }

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
            int key, priority;
            std::cin >> key >> priority;

            NodeBase v(key, priority);
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

