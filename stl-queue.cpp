#include <bits/stdc++.h>
using namespace std;
int main()
{
    int range;
    cin >> range;
    queue<string> myQueue;
    myQueue.push("1");
    cout << myQueue.front() << endl;
    for (int i = 2; i <= range; i++)
    {
        string newF = myQueue.front() + '0';
        string newS = myQueue.front() + '1';
        myQueue.push(newF);
        myQueue.push(newS);
        myQueue.pop();
        cout << myQueue.front() << endl;
    }

    return 0;
}