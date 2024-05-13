#pragma once
#include <string>
#include <iostream>
using namespace std;
class Error//базовый класс
{
public:
    virtual void what() {};
};
class IndexError :public Error //ошибка в индексе вектора
{
protected:
    string msg;
public:
    IndexError() { msg = "Index Error\n"; }
    virtual void what() { cout << msg; }
};
class SizeError :public Error //ошибка в размере вектора
{
protected:
    string msg;
public:
    SizeError() { msg = "size error\n"; }
    virtual void what() { cout << msg; }
};
class MaxSizeError :public SizeError //превышение максимального размера
{
protected:
    string msg_;
public:
    MaxSizeError() { SizeError();msg_ = "size > or <\n"; }
    virtual void what() { cout << msg << msg_; }
};
class EmptySizeError :public SizeError //удаление из пустого вектора
{
protected:
    string msg_;
public:
    EmptySizeError() { SizeError();msg_ = "List is empty\n"; }
    virtual void what() { cout << msg << msg_; }
};
