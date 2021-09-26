#include <iostream>

using namespace std;
int Joshpus(int numberOfPeople, int position)
{
    if (numberOfPeople == 1)
        return 1;
    else
        return ((Joshpus((numberOfPeople - 1), position)) + position - 1) % numberOfPeople + 1;
}

int main()
{
    int numberOfPeople;
    cout << "Enter the number of people " << endl;
    cin >> numberOfPeople;

    int position;
    cout << "Enter the postion " << endl;
    cin >> position;

    cout << "The chosen place is " << Joshpus(numberOfPeople, position);
    return 0;
}
