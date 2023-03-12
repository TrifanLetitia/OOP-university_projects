//
// Created by Leti on 16.05.2022.
//

#ifndef PROIECTSDA_ABCNODE_H
#define PROIECTSDA_ABCNODE_H

#include<iostream>
using namespace std;
template<typename T>
class ABC;

template<class T>
class ABCNode{
private:
    T info;
    ABCNode<T>* right;
public:
    ABCNode(T info) : info(info) {this->left = nullptr, this->right = nullptr;}

    ABCNode(T info, ABCNode<T> *left, ABCNode<T> *right) : info(info), left(left), right(right) {}

    friend class ABC<T>;

    ABCNode<T>* left;
};

#endif //PROIECTSDA_ABCNODE_H
