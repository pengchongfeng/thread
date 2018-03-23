#include <iostream>
#include <vector>
using namespace std;

template<class T>
void print(vector<T> *t)
{
    int i = 0;
    for(;i < t->size(); ++i)
    {
	cout << t->at(i) << "\t";
    }
    cout << endl;
}

int main(void)
{
    vector<int> v;
    int i = 0;
    for(;i < 10000; ++i)
    {
	v.push_back(i);
    }

    cout << "size=" << v.size() << endl;
    cout << "capacity=" << v.capacity() << endl;

    for(i = 0;i < 9990;++i)
    {
	v.pop_back();
    }
    cout << "pop over!" << endl;

    cout << "size=" << v.size() << endl;
    cout << "capacity=" << v.capacity() << endl;

    print(&v);
    cout << "enter swap!" << endl;
    vector<int> v1;
    v1.swap(v);
    cout << "quit swap!" << endl;
    print(&v);

    cout << "v size=" << v.size() << endl;
    cout << "v capacity=" << v.capacity() << endl;
    
    cout << "v1 size=" << v1.size() << endl;
    cout << "v1 capacity=" << v1.capacity() << endl;

    v1.clear();
    cout << "v1 size=" << v1.size() << endl;
    cout << "v1 capacity=" << v1.capacity() << endl;

    return 0;
}

