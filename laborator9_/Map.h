//
// Created by Miruna Savin on 5/2/2022.
//

#ifndef LABORATOR9__MAP_H
#define LABORATOR9__MAP_H


template<typename Key, typename Value>
class Map {
    struct Element {
        Key key;
        Value value;
        unsigned int index;

    };
    Element *vector;
    int index; //sau count
    int size;//max map size;
public:
    Map() {
        vector = new Element[1];
        size = 1; //max size
        index = 0;
    }

    void Resize() {
        // sa verific si daca am un elem liber
     //   if (index == size) {
            Element *v = new Element[size * 2];
            memcpy(v, vector, sizeof(Element) * size);
            vector = v;
            size *= 2;
            return;
       //}


    }

    void Set(Value value, Key key) {
        for (int i = 0; i < index; i++) {
            if (this->vector[i].key == key) {
                this->vector[i].value = value;
                size++;
                return;
            }
        }
    }

    bool Get(const Key &key, Value &value) const {
        for (int i = 0; i < index; i++) {
            if (this->vector[i].key == key) {
                value = this->vector[i].value;
                return true;
            }
        }
        return false;
    }

    Element &Get(int indexx) {
        return vector[indexx];
    }

    int Count() const {
        return index;
    }

    bool Delete(const Key &key) {
        for (int i = 0; i < index; i++) {
            if (this->vector[i].key == key) //atunci micsoram
                //size ul si mutam toate elementele de dupa el cu un spatiu
                //in urma
            {
                for (int j = i; j < index - 1; j++)
                    this->vector[j] = this->vector[j + 1];
                index--;
                return true;
            }
        }
        return false;
    }

    // bool Includes(const Map<Key,Value>& map);
    Value &operator[](Key key) {
        for (int i = 0; i < index; i++) {
            if (this->vector[i].key == key)
                return vector[i].value;
        }
        this->index++;

        if (this->index > size)
            Resize();
        this->index--;
        vector[this->index].index = this->index;
        vector[this->index].key = key;

        this->index++;
        return vector[this->index - 1].value;

    }

    class Iterator {
    private :
        Map *m;
        unsigned int current;
    public:
        Iterator(Map *m, unsigned int index) : m(m), current(index) {}

        Iterator &operator++() {
            current++;
            return *this;
        }

        bool operator!=(const Iterator &other) {
            return current != other.current;
        }

        Element operator*() {
            return this->m->Get(current);
        }
    };

    Iterator begin() {
        return Iterator(this, 0);
    }

    Iterator end() {
        return Iterator(this, this->index);
    }
};


#endif //LABORATOR9__MAP_H
