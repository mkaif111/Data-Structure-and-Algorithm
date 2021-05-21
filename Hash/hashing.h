#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Node
{
public:
    string key;
    T val;
    Node<T> *next;
    Node(string k, T v)
    {
        key = k;
        val = v;
        next = NULL;
    }
    ~Node()
    {
        if (next != NULL)
            delete next;
    }
};
template <typename T>
class HashTable
{
    int tableSize;
    int currSize;
    Node<T> **table;
    int hasFunc(string s)
    {
        int idx = 0;
        int p = 1;
        for (int i = 0; i < s.length(); i++)
        {
            idx = idx + (p * s[i]) % tableSize;
            idx = idx % tableSize;
            p = (p * 27) % tableSize;
        }
        return idx;
    }
    void rehash()
    {
        Node<T> **oldTable = table;
        int oldTableSize = tableSize;
        tableSize = 2 * tableSize;
        table = new Node<T> *[tableSize];

        for (int i = 0; i < tableSize; i++)
            table[i] = NULL;
        currSize = 0;
        for (int i = 0; i < oldTableSize; i++)
        {
            Node<T> *temp = oldTable[i];
            while (temp != NULL)
            {
                insert(temp->key, temp->val);
                temp = temp->next;
            }
            if (oldTable[i] != NULL)
            {
                // delete provokes desconstructor
                delete oldTable[i];
            }
        }
        delete[] oldTable;
    }

public:
    HashTable(int ts = 7)
    {

        tableSize = ts;
        table = new Node<T> *[tableSize];
        currSize = 0;
        for (int i = 0; i < tableSize; i++)
            table[i] = NULL;
    }
    void insert(string key, T value)
    {
        int idx = hasFunc(key);
        Node<T> *n = new Node<T>(key, value);

        // add at head of linkedlist if idx idex;

        n->next = table[idx];
        table[idx] = n;
        currSize++;

        //rehashing ..
        float loadFactor = currSize / tableSize;
        if (loadFactor > 0.75)
            rehash();
    }
    void print()
    {
        for (int i = 0; i < tableSize; i++)
        {
            cout << "Bucket " << i << " -> ";
            Node<T> *temp = table[i];
            while (temp != NULL)
            {
                cout << temp->key << "-> ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
    T *search(string key)
    {
        int idx = hasFunc(key);
        Node<T> *temp = table[idx];
        while (temp != NULL)
        {
            if (temp->key == key)
                return &temp->val; //send address or pointer
            temp = temp->next;
        }
        return NULL;
    }
    void erase(string key)
    {
        int idx = hasFunc(key);
        Node<T> *temp;
        temp= table[idx];
        Node<T> *prev = NULL;
        while (temp != NULL)
        {   if(temp->key == key)
            break;
           prev = temp;
            temp = temp->next;
        }
        if(temp == NULL)
            return ;
        if(prev !=NULL)
            prev->next = temp->next;
        else
            table[idx] = temp->next;
        return;
    }
    T& operator[](string key){
        T *f = search(key);{
            if(f==NULL){
                T garbage;
                insert(key,garbage);
                f = search(key);
            }
        }
        return *f;
    }
};