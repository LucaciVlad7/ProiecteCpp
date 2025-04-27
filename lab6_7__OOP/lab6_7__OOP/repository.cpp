#include "repository.h"

void repository::adaugaElem(const TElem& elem) {
    this->elems.push_back(elem);
}

void repository::modificaElem(const TElem& elem) {
    for (unt i = 0; i < this->elems.getSize(); i++)
        if (this->get_id(this->elems[i]) == this->get_id(elem))
            this->elems[i] = elem;
}

TElem repository::cautaElem(const unt& id) {
    for (unt i = 0; i < this->elems.getSize(); i++)
        if (this->get_id(this->elems[i]) == id)
            return this->elems[i];
}

void repository::stergeElem(const unt& id) {
    for (unt i = 0; i < this->elems.getSize(); i++)
        if (this->get_id(this->elems[i]) == id)
            this->elems.pop(i);
}

bool repository::existaElem(const unt& id) {
    for (unt i = 0; i < this->elems.getSize(); i++)
        if (this->get_id(this->elems[i]) == id)
            return true;
    return false;
}

mvector<TElem> repository::getAllElems() {
    return this->elems;
}

mvector<TElem> repository::setElems(const mvector<TElem>& elemsnew) {
    return this->elems = elemsnew;
}

unt repository::getSize() const {
    return this->elems.getSize();
}