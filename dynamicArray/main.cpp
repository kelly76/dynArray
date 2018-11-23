#include <iostream>

using namespace std;

class point{
private:
    int x,y;
public:
    point();
    point(int,int);
    int get_x();
    int get_y();
    point operator + (point p);
};

point::point(){
x=0;y=0;}

point::point(int _x,int _y){
x=_x; y=_y;}

int point::get_x(){
return x;}

int point::get_y(){
return y;}

std::ostream& operator << (std::ostream& output,point& p){   //imprimir puntos
output << "(" << p.get_x() << "," << p.get_y() << ")";
return output;
}

point point::operator + (const point p){    //sumar puntos
point result;
result.x= (this->x + p.x);
result.y= (this->y + p.y);
return result;
}

template<typename T>
class dynArray{
private:
    int s;
    T *arr;
public:
    dynArray(){
        s=0;
        arr=new T[s];
        }
    dynArray(T a[],int _s){
        s=_s;
        arr=new T[s];
        for(int i=0;i<s;i++)
            arr[i]=a[i];
        }
    ~dynArray(){
        delete[] arr;
        }
    dynArray(dynArray &o){
        arr=new T[o.s];
        for(int i=0;i<s;i++)
            arr[i]=o.arr[i];
        }
    void printArray(){
        for(int i=0;i<s;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
        }
    void pushBack(const T &p){
        this->s+=1;
        T*new_arr=new T[s];
        for(int i=0;i<s;i++)
            new_arr[i]=arr[i];
        new_arr[s-1]=p;
        delete[] arr;
        arr=new_arr;
        }
    void insert(const T p,int pos){
        this->s+=1;
        T *new_arr=new T[s];
        for(int i=0;i<s;i++)
            new_arr[i]=arr[i];
        delete[] arr;
        arr=new_arr;
        for(int j=s-1;j>pos;j--)
            arr[j]=arr[j-1];
        arr[pos]=p;
        }
    void remove(int pos){
        for(int j=pos;j<s-1;j++)
            arr[j]=arr[j+1];
        this->s-=1;
        T *new_arr1=new T[s];
        for(int i=0;i<s;i++)
            new_arr1[i]=arr[i];
        delete[] arr;
        arr=new_arr1;
        }
};

int main()
{
int arr[]={1,4,6};
char arr1[]={'u','i','o'};
point a(1,2),b(3,4),c(5,6),d(8,9);
point pArr[]={a,b,c};
dynArray<point> p(pArr,3);
p.insert(d,0);

p.printArray();
return 0;
}
