#include <iostream>

/*
# [Josephus problem](https://en.wikipedia.org/wiki/Josephus_problem)

There are n people are standing in a circle waiting to be executed. The counting out begins at some point in the circle and proceeds around the circle in a fixed direction. In each tep,a certrain number of people are skipped and the next person is executed. THe eliminatiuon proceeds around the circle.(which is becoming smaller and smaller as the executed people are remofeed), until only the last perosn remains , who is given freedom. Five the total lnumber of person n anda number kwhihc indicates that k-1 persons are skipped and kth person is killed and kth person is killed in circle. The eas is to choose the place in theinitial circle so that you are the last one remaining and so survive.

    For example , if n = 5 and k = 2, then the safe position is 3. Firstly, the person at position 2 is killed, then person at position 4 is killed, then person at position 1 is killed. Finally, the person at position 5 is killed. So the person at position 3 survives. If n = 7 and k = 3, then the safe position is 4. The persons at positions 3, 6, 2, 7, 5, 1 are killed in order, and person at position 4 survives.

Recursion equation :

    josephus(n, k) = (josephus(n - 1, k) + k-1) % n + 1
    josephus(1, k) = 1
*/
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
