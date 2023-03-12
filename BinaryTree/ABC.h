//
// Created by Leti on 16.05.2022.
//

#ifndef SOCIALNETWORK_ABC_H
#define SOCIALNETWORK_ABC_H


#include <queue>
#include "ABCNode.h"
#include "../TADList/List.h"

template<class T>
class ABC {
private:
    ABCNode<T> *root;
    int size;

    /*
     * add an element to tree
     */
    void add(ABCNode<T> *ad, T elem) {
        if (ad->info > elem) { // adaugam pe stanga
            if (ad->left != nullptr) {
                add(ad->left, elem);
            } else {
                ad->left = new ABCNode<T>(elem, nullptr, nullptr);
            }
        } else {  //adaugam in dreapta
            if (ad->right != nullptr) {
                add(ad->right, elem);
            } else {
                ad->right = new ABCNode<T>(elem, nullptr, nullptr);
            }
        }
    }

    void afisareIN(ABCNode<T> *ad) {
        if (ad != nullptr) {
            afisareIN(ad->left);
            cout << ad->info << endl;
            afisareIN(ad->right);
        }
    }

    void getAll(ABCNode<T> *node, List<T> &elements) {
        if (node != nullptr) {
            getAll(node->left, elements);
            elements.add(node->info);
            getAll(node->right, elements);
        }
    }

    /*
     * remove an element from the tree
     */
    ABCNode<T> *removeElem(ABCNode<T> *node, T elem) {
        if (node == NULL) {
            return NULL;
        }
        if (node->info > elem) {
            node->left = removeElem(node->left, elem);
        } else if (node->info < elem) {
            node->right = removeElem(node->right, elem);
        } else {
            if (node->left == NULL) {
                ABCNode<T> *temp = node->right;
                free(node);
                return temp;
            } else if (node->right == NULL) {
                ABCNode<T> *temp = node->left;
                free(node);
                return temp;
            } else {
                ABCNode<T> *temp = node->right;
                while (temp->left != NULL) temp = temp->left;
                node->info = temp->info;
                node->right = removeElem(node->right, temp->info);
            }
        }
        return node;
    }
    /*
     * search an element in the tree
     *///return true or false
    bool search1(ABCNode<T> *node, T val) {
        if (node == NULL) {
            return false;
        } else {
            if (val == node->info) {
                return true;
            }
            if (val > node->info) {
                return search1(node->right, val);
            } else {
                return search1(node->left, val);
            }
        }
    }

    /*
     * add elements from tree to a list
     */
    void AddToList(ABCNode<T> *node, List<T> &list, int &i) {
        if (node == NULL)
            return;
        if (node->left != NULL)
            AddToList(node->left, list, i);
        list[i] = node->info;
        i++;
        if (node->right != NULL)
            AddToList(node->right, list, i);
    }

public:
    /*
     * remove element from tree
     */
    void removeElem(T elem);

    /*
     * get all elements from tree
     */
    List<T> getAll(List<T> &elements);

    /*
     * search for element in the tree
     */
    bool search(T val);

    /*
     * return size of tree
     */
    int Size();

    bool operator==(const ABC<T> &tree) const;

    List<T> addToList(List<T> list) {
        int i = 0;
        AddToList(root, list, i);
        list.size = size;
        return list;
    }

    ABC() {
        this->root = nullptr;
        this->size = 0;
    }

    void add(T elem) {
        if (this->root == nullptr) {
            this->root = new ABCNode<T>(elem, nullptr, nullptr);
        } else add(this->root, elem);
        size++;
    }

    void afisare() {
        afisareIN(this->root);
    }

    ~ABC();
};

template<class T>
void ABC<T>::removeElem(T elem) {
    removeElem(root, elem);
    size--;
}

template<class T>
bool ABC<T>::search(T val) {
    return search1(root, val);
}

template<class T>
int ABC<T>::Size() {
    return this->size;
}

template<class T>
bool ABC<T>::operator==(const ABC<T> &tree) const {
    return (root == 0 && tree.root == 0)
           || (root != 0 && tree.root != 0 && *root == *tree.root);
}

template<class T>
List<T> ABC<T>::getAll(List<T> &elements) {
    getAll(root, elements);
    return elements;
}

template<class T>
ABC<T>::~ABC() = default;


#endif //SOCIALNETWORK_ABC_H
