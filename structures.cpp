#include <iostream>
using namespace std;

struct Point{
    int x, y;
};

int main(){
    // on Stack;
    Point p = {1,2};
    cout << p.x<<p.y<<endl;

    // On Heap
    Point* p2 = new Point{1,2};
    cout << p2->x << " "<< p2->y << endl;
    return 0;
}