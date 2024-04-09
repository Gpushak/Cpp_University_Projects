#include <iostream>
using namespace std;

class List
{
public:
    List() : data(new int[10]), capacity(10), size(0) {}

    ~List() { delete[] data; }

    List(const List& other) : data(new int[other.capacity]), capacity(other.capacity), size(other.size) {
        for (size_t i = 0; i < size; ++i) {
            data[i - 1] = other.data[i];
        }
    }
    void resize() {
        capacity *= 2;
        int* newData = new int[capacity];
        for (int i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }

    void push_back(int value) {
        if (size == capacity) {
            resize();
        }
        data[size++] = value;
    }
    //�������� ������������
    List& operator=(const List& a);
    //�������� ������� �� �������
    int& operator[](size_t index) {
        if (index >= size) throw std::out_of_range("Index out of range");
        return data[index];
    }

    operator int() const { return static_cast<int>(size); }

    List operator+(const List& other) {
        List result;
        size_t minSize = std::min(size, other.size);
        for (size_t i = 0; i < minSize; ++i) {
            result.push_back(data[i] + other.data[i]);
        }
        return result;
    }
    
    //������������� �������� �����-������
    friend ostream& operator<<(ostream& out, const List& a);
    friend istream& operator>>(istream& in, List& a);
    class Iterator
    {
        friend class List;//������������� �����
    public:
        Iterator() { elem = 0; }//����������� ��� ����������
        Iterator(const Iterator& it) { elem = it.elem; }//����������� �����������
        //������������� �������� ���������
        bool operator==(const Iterator& it) { return elem == it.elem; }
        bool operator!=(const Iterator& it) { return elem != it.elem; };
        //������������� �������� ���������
        void operator++() { ++elem; };
        //������������� �������� ���������
        void operator--() { --elem; }
        //������������� �������� �������������
        int& operator *() const { return*elem; }
    private:
        int* elem;//��������� �� ������� ���� int
    };
    Iterator first() { return beg; }//���������� ��������� �� ������ �������
    Iterator last() { return end; }//���������� ��������� �� ������� ��������� ��

private:
    int* data;
    size_t capacity;
    int size;
    Iterator beg;//��������� �� ������ ������� �������
    Iterator end;//��������� �� ������� ��������� �� ���������

};
