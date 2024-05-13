#pragma once
#include <string>
#include <iostream>
using namespace std;
class Error//������� �����
{
public:
    virtual void what() {};
};
class IndexError :public Error //������ � ������� �������
{
protected:
    string msg;
public:
    IndexError() { msg = "Index Error\n"; }
    virtual void what() { cout << msg; }
};
class SizeError :public Error //������ � ������� �������
{
protected:
    string msg;
public:
    SizeError() { msg = "size error\n"; }
    virtual void what() { cout << msg; }
};
class MaxSizeError :public SizeError //���������� ������������� �������
{
protected:
    string msg_;
public:
    MaxSizeError() { SizeError();msg_ = "size > or <\n"; }
    virtual void what() { cout << msg << msg_; }
};
class EmptySizeError :public SizeError //�������� �� ������� �������
{
protected:
    string msg_;
public:
    EmptySizeError() { SizeError();msg_ = "List is empty\n"; }
    virtual void what() { cout << msg << msg_; }
};
