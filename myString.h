#pragma once

class myString {
private:
    size_t _length = 0;
    size_t _capacity = 16;
    char* _text = nullptr;

    void setText(const char* text) {
        assert(text != nullptr);
        _length = 0;

        while (text[_length] != '\0') {
            _length++;
        }

        if (_capacity < _length + 1) {
            delete[] _text;
            _capacity = _length + 1;
            _text = new char[_capacity];
        }

        for (size_t i = 0; i <= _length; ++i) {
            _text[i] = text[i];
        }
    }

public:
    myString() {
        _text = new char[_capacity];
        _text[0] = '\0';
    }

    myString(const char* text) {
        _text = new char[_capacity];
        setText(text);
    }

    myString(const myString& other) {
        _capacity = other._length + 1;  
        _length = other._length;
        _text = new char[_capacity];

        for (size_t i = 0; i < _length; ++i) {
            _text[i] = other._text[i];
        }

        _text[_length] = '\0';  
    }



    myString(const size_t count, const char text) {
        _text = new char[count + 1];
        _length = count;
        _capacity = count + 1;
        for (size_t i = 0; i < count; ++i) {
            _text[i] = text;
        }
        _text[count] = '\0';
    }

    ~myString() {
        delete[] _text;
    }

    myString& operator=(const myString& other) {
        if (this == &other) {
            return *this;
        }

        delete[] _text;

        _length = other._length;
        _capacity = _length + 1; 

        _text = new char[_capacity];

        for (size_t i = 0; i < _length; ++i) {
            _text[i] = other._text[i];
        }

        _text[_length] = '\0'; 
        return *this;
    }




    char& front() {
        assert(_length > 0);
        return _text[0];
    }

    char& back() {
        assert(_length > 0);
        return _text[_length - 1];
    }

    char& at(size_t index) {
        assert(index < _length);
        return _text[index];
    }

    size_t capacity() const {
        return _capacity;
    }

    size_t size() const {
        return _length;
    }

    size_t find(char chr) const {
        for (size_t i = 0; i < _length; ++i) {
            if (_text[i] == chr) {
                return i;
            }
        }
        return _length;
    }

    size_t rfind(char chr) const {
        for (size_t i = _length; i > 0; --i) {
            if (_text[i - 1] == chr) {
                return i - 1;
            }
        }
        return _length;  
    }

    void clear() {
        _text[0] = '\0';
        _length = 0;
    }

    void resize(size_t newSize) {
        if (newSize > _capacity) {
            delete[] _text;
            _capacity = newSize + 1;
            _text = new char[_capacity];
        }
        _text[newSize] = '\0';
        _length = newSize;
    }

    void reserve(size_t newCapacity) {
        if (newCapacity > _capacity) {
            char* newText = new char[newCapacity];
            for (size_t i = 0; i <= _length; ++i) {
                newText[i] = _text[i];
            }
            delete[] _text;
            _text = newText;
            _capacity = newCapacity;
        }
    }

    void shrink_to_fit() {
        if (_capacity > _length + 1) {
            reserve(_length + 1);
        }
    }

    bool empty() const {
        return _length == 0;
    }

    myString append(const char* text) {
        size_t newLength = _length;

        for (size_t i = 0; text[i] != '\0'; ++i) {
            if (newLength >= _capacity) {
                reserve(newLength + 1);
            }
            _text[newLength++] = text[i];
        }

        _text[newLength] = '\0';
        _length = newLength;

        return *this;
    }

    int compare(const myString right) {
        if (_length < right._length) {
            return -1;
        }
        if (_length > right._length) {
            return 1;
        }
        for (size_t i = 0; i < _length; ++i) {
            if (_text[i] < right._text[i]) {
                return -1;
            }
            if (_text[i] > right._text[i]) {
                return 1;
            }
        }
        return 0;
    }

    bool contains(char chr) const {
        for (size_t i = 0; i < _length; ++i) {
            if (_text[i] == chr) {
                return true;
            }
        }
        return false;
    }

    size_t count(char chr) const {
        size_t counter = 0;
        for (size_t i = 0; i < _length; ++i) {
            if (_text[i] == chr) {
                counter++;
            }
        }
        return counter;
    }

    myString substr(size_t pos, size_t len) const {
        assert(pos < _length);

        if (pos + len > _length) {
            len = _length - pos;
        }

        myString subStr;
        subStr._text = new char[len + 1];
        subStr._capacity = len + 1;
        subStr._length = len;

        for (size_t i = 0; i < len; ++i) {
            subStr._text[i] = _text[pos + i];
        }
        subStr._text[len] = '\0';
        return subStr;
    }

    const char* print() const {
        return _text;
    }
};
