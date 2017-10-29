#include <iostream>
#include <Vector>
#include <stdlib.h>
#include <time.h>
#include <QTime>

using namespace std;

void sort_p (vector<int> &mass, int number)
{
    for (int k=0; k < number - 1; k++)
        for (int m=0; m < number - k - 1; m++)
            if (mass[m] > mass[m + 1])
                swap(mass[m], mass[m + 1]);
}

void sort_h(vector<int> &mass, int left, int right)
{
    int k = left;
    int m = right;
    int middle = (left + right + 1)/2;

    do
    {
        while(mass[k] < mass[middle]) k++;
        while(mass[m] > mass[middle]) m--;
        if (k <= m)
        {
            swap(mass[k], mass[m]);
            k++;
            m--;
        }
    } while (k <= m);
    if (k < right) sort_h(mass, k, right);
    if (left < m) sort_h(mass, left, m);
}

void sort_m (vector<int> &mass, int left, int right, int number)
{
    if (left == right) return;
    if (right - left == 1)
    {
        if (mass[left] > mass[right])
            swap(mass[left], mass[right]);
        return;
    }

    int mid = (left + right)/2;

    sort_m(mass, left, mid, number);
    sort_m(mass, mid + 1, right, number);
    vector<int> mass_temp;
    mass_temp.resize(number);

    int lt = left;
    int rt = mid + 1;
    int curr = 0;

    while (right - left + 1 != curr)
    {
        if (lt > mid)
            mass_temp[curr++] = mass[rt++];
        else if (rt > right)
            mass_temp[curr++] = mass[lt++];
        else if (mass[lt] > mass[rt])
            mass_temp[curr++] = mass[rt++];
        else mass_temp[curr++] = mass[lt++];
    }

    for (int k=0; k < curr; k++)
        mass[k + left] = mass_temp[k];
}

void copy (vector<int> mass, vector<int> &mass_temp, int number)
{
    for (int k = 0; k < number; k++)
        mass_temp[k] = mass[k];
}

void show (vector<int> mass, int number)
{
    for (int k = 0; k < number; k++)
        cout << mass[k] << " ";
    cout << endl;
}

int main()
{
    srand(time(0));

    vector<int> mass;
    int number = 30000;

    cout << "PROCESSING..." << endl;

    for (int k = 0; k < number; k++)
    {
        int temp = rand()%21;
        mass.push_back(temp);
    }

    vector<int> mass_temp;
    mass_temp.resize(number);
    copy(mass, mass_temp, number);

    QTime bubl_time;
    bubl_time.start();
    sort_p(mass_temp, number);

    int bubl_t = bubl_time.elapsed();

    //show(mass_temp, number);
    cout << "SORTING BUBBLE: " << bubl_t << endl;

    copy(mass, mass_temp, number);
    QTime time_h;
    time_h.start();

    sort_h(mass_temp, 0, number - 1);

    int hoar_t = time_h.elapsed();

    //show(mass_temp, number);
    cout << "SORTING HOAR: " << hoar_t << endl;

    copy(mass, mass_temp, number);
    QTime merge_time;
    merge_time.start();
    sort_m(mass_temp, 0, number - 1, number);

    int merge_t = merge_time.elapsed();

    //show(mass_temp, number);
    cout << "SORTING MERGE: " << merge_t << endl;

    copy(mass, mass_temp, number);
    QTime sort_time;
    sort_time.start();
    sort(mass_temp.begin(), mass_temp.begin() + number);

    int sort_t = sort_time.elapsed();

    //show(mass_temp, number);
    cout << "STANDART SORTING: " << sort_t << endl;

    return 0;
}
