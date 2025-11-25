#include "List.h"
#include <iostream>

List::List() {
    head = NULL;
    cursor = NULL;
    prev = NULL;
}

List::~List() {
    makeListEmpty();
}

bool List::listIsEmpty() const {
    return head == NULL;
}

bool List::curIsEmpty() const {
    return cursor == NULL;
}

void List::toFirst() {
    cursor = head;
    prev = NULL;
}

bool List::atFirst() const {
    if(listIsEmpty() || curIsEmpty()) {
        return false;
    } else {
        return cursor == head;
    }
}

void List::advance() {
    if (cursor != NULL) {
        prev = prev->next;
        cursor = cursor->next;
    }
}

void List::toEnd() {
    if (head == NULL) {
        cursor = prev = NULL;
        return;
    }
    
    toFirst();
    if (!listIsEmpty()) {
        while (cursor->next != NULL) {
            advance();
        }
    }
}

bool List::atEnd() const {
    if(listIsEmpty() || curIsEmpty()) {
        return true;
    } else {
        return cursor->next == NULL;
    }
}

int List::listSize() const {
    int count = 0;
    node* p = head;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    return count;
}

void List::updateData(const char &d) {
    if (cursor != NULL) {
        cursor->data = d;
    }
}

void List::updateKey(const char &k) {
    if (cursor != NULL) {
        cursor->key = k;
    }
}

char List::retrieveData() const {
    if (cursor != NULL) {
        return cursor->data;
    } else {
        return NULL;
    }
}

void List::retrieveData(const char &d) const {
    if (cursor != NULL) {
        d = cursor->data;
    }
}

void List::insertFirst(const int &k, const char &d) {
    node* p = new node;
    p->key = k;
    p->data = d;
    p->next = head;
    head = p;
    cursor = head;
    prev = NULL;
}

void List::insertAfter(const int &k, const char &d) {
    node* p = new node;
    p->key = k;
    p->data = d;
    p->next = cursor->next;
    cursor->next = p;
    prev = cursor;
    cursor = p;
}

void List::insertBefore(const int &k, const char &d) {
    node *p = new node;
    p->key = k;
    p->data = d;
    p->next = cursor;
    prev->next = p;
    cursor = p;
}

void List::insertEnd(const int &k, const char &d) {
    if (listIsEmpty()) {
        insertFirst(k, d);
    } else {
        toEnd();
        insertAfter(k, d);
    }
}

void List::deleteNode() {
    node *p = cursor;
    if(curIsEmpty()){
        if(atFirst()){
            cursor = cursor->next;
            head = cursor;
            delete p;
        } else {
            cursor = cursor->next;
            prev->next = cursor;
            delete p;
        }
    }
}

void List::deleteFirst() {
    if (!listIsEmpty()){
        toFirst();
        deleteNode();
    }
}

void List::deleteEnd() {
    if (!listIsEmpty()){
        toEnd();
        deleteNode();
    }
}

void List::makeListEmpty() {
    toFirst();
    while (!listIsEmpty()) {
        deleteNode();
    }
}

bool List::search(const int &k) {
    bool found = false;
    toFirst();
    while(!found && !curIsEmpty()){
        if(k == cursor->key) {
            found = true;
        } else {
            advance();
        }
    }
    return found;
}

void List::orderInsert(const int &k, const char &d) {
    toFirst();
    while(!curIsEmpty() && cursor->key < k) {
        advance();
    }
    if(prev == NULL) {
        insertFirst(k, d);
    } else {
        insertBefore(k, d);
    }
}

void List::traverse() {
    if (listIsEmpty()) {
        std::cout << "List is empty" << std::endl;
        return;
    }
    
    node* p = head;
    std::cout << "List contents: ";
    while (p != NULL) {
        std::cout << "(" << p->key << "," << p->data << ") ";
        p = p->next;
    }
    std::cout << std::endl;
}
