#include <iostream>

template <typename T>
class UF {
    public:
        UF() = delete;
        UF(std::size_t n)
        {
            this->parent = new T(n);
            this->n = n;
            for(std::size_t i = 0; i< n ; i++ )
            {
                this->parent[i] = -1;
            }
        };
        virtual ~UF() 
        {
            delete this->parent;
        };
        virtual T find(const T& a) const
        {
            if ( this->parent[a] == -1 )
            {
                return a;
            }
            return find(this->parent[a]);
        };

        virtual void union_op(const T& a, const T& b) 
        {
            const T& x = find(a);
            const T& y = find(b); 
            if ( x != y )
            {
                this->parent[a] = b;
            }
        };
        virtual void print() const 
        {
            for(std::size_t i = 0; i < n ; ++i )
            {
                std::cout << "i = " << i << " parent = " << parent[i] << std::endl;
            }
        }
    private:
        T* parent;
        std::size_t n;
};

void f(const int* a)
{

}
void f(int* const a)
{

}
void f(const int& a )
{
    std::cout << "void f(const int& a )" << std::endl;
}
void f(const int&& a) 
{
    std::cout << "void f(const int&& a)" << std::endl;
}
#include <queue>
#include <algorithm>
#include <iterator>
struct track {
    int _count;
    int _start;
    int _end;

    track(int count, int start, int end)
        : _count(count), _start(start), _end(end){}
};
struct queue_compare {
    bool operator()(const track&  t1, const track& t2 )
    {
        return t1._count > t2._count;
    }
};
int main()
{
    UF<int> uf(5);
    uf.union_op(1,2);
    uf.union_op(2,3);
    std::cout << "parent of 2 = " << uf.find(2) << std::endl;
    uf.print();
    int&& rvalue = 5;
    rvalue = 6;
    std::cout << "rvalue = " << rvalue << std::endl;
    int i  = 5;
    f(i);
    f(7);
    int& a = i;
    f(a);
    f(rvalue);

    std::priority_queue<int> asimple;
    asimple.push(1);
    auto lambda = [] (const int& t1, const int& t2) -> bool{
        return t1 > t2;
    };
    std::priority_queue<track, std::vector<track>, queue_compare> nesimple;
    nesimple.push(track(5,2,3));
    nesimple.push(track(6,1,4));
    nesimple.push(track(12,3,5));
    std::cout << nesimple.top()._count << std::endl;
    std::cout << nesimple.size() << std::endl;
    nesimple.pop();
    std::cout << nesimple.size() << std::endl;
    std::vector<int> hh = {1,2,3,44,4};
    std::cout << *std::max_element(std::begin(hh), std::end(hh), lambda) << std::endl;
    return 1;
}
