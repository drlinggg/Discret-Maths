#include <bits/stdc++.h>
#define fast std::cin.tie(0);std::ios_base::sync_with_stdio(0);
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ll RBN = 1e9+7;
const ll RSN = -(1e9+7);
const double PI = 3.141592653589793;
//mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count()); ll gen(){return rnd()%100;}

struct Node
{
    string x;
    char x1;
    Node* l = nullptr;
    Node* r = nullptr;
    Node() = default;
};

struct BST {
    Node *root = nullptr;

    Node *findbuf(Node *node, string x) {
        if (node == nullptr) return nullptr;
        if (node->x == x) return node;
        if (node->x > x) {
            return findbuf(node->l, x);
        } else {
            return findbuf(node->r, x);
        }
    }

    Node* insert(Node* node, string x, char x1) {
        if (root == nullptr) {
            Node* new_root = new Node;
            new_root->x = x;
            new_root->x1 = x1;
            new_root->l = new_root->r = nullptr;
            root = new_root;
            return root;
        }
        if (node == nullptr) {
            Node* new_root = new Node;
            new_root->x = x;
            new_root->x1 = x1;
            new_root->l = new_root->r = nullptr;
            return new_root;
        } else if (x < node->x) {
            node->l = insert(node->l, x,x1);
        } else if (x > node->x) {
            node->r = insert(node->r, x,x1);
        }
        return node;
    }
};

signed main() {
    fast;
    BST bst;
    string alph[26]{".-", "-...","-.-.","-..", ".", "..-.", "--.", "....", "..",
                    ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-",
                    ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--",
                    "--.."};
    for (int i = 65; i < 91; i++) {
        bst.insert(bst.root, alph[i-65], (char) i);
    }
    string c;
    cin >> c;
    if (c == "--code") {
        vector<string>ans;
        char ch;
        while (cin >> ch) {
            if (ch == '1') {
                break;
            }
            ans.push_back(alph[ch-65]);
        }
        for (ll i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
    }
    else if (c == "--decode") {
        vector<char>ans;
        string ch;
        while (cin >> ch) {
            Node* n = bst.findbuf(bst.root,ch);
            if (n == nullptr) {
                break;
            }
            ans.push_back(n->x1);
        }
        for (ll i = 0; i < ans.size(); i++) {
            cout << ans[i];
        }
    }
}
