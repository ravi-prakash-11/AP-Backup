#include <iostream>
using namespace std;
void TowerOfHanoi(int n, char from, char to, char mid)
{
    if (n == 1)
    {
        cout <<"\tDisk "<<n<<"--->\tRod "<<from<<"\tto\tRod "<<to <<endl;
        return;
    }
    TowerOfHanoi(n - 1, from, mid, to);
    cout <<"\tDisk "<<n<<"--->\tRod "<<from<<"\tto\tRod "<<to <<endl;
    TowerOfHanoi(n - 1, mid, to, from);
}

int main()
{
    int n;cout<<endl;
    cout<<"\nEnter no of Disks: ";
    cin>>n;
    cout<<endl;
    TowerOfHanoi(n, '1', '3', '2');
    cout<<endl<<endl<<endl;
    return 0;
}
