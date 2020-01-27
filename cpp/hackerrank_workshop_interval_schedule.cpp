#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <thread>
using namespace std;

//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops
struct Workshops {
    int start;
    int duration;
    int end;
};
struct Available_Workshops {
    int n;
    struct Workshops *workshops;
};

Available_Workshops* initialize (int start_time[], int duration[], int n) 
{
    Available_Workshops *p = new Available_Workshops;

    p->n = n;
    p->workshops = new Workshops[n];

    for(int i = 0; i < n; i++) {
        p->workshops[i].start = start_time[i];
        p->workshops[i].duration = duration[i];
        p->workshops[i].end = start_time[i] + duration[i];
    }

    return p;
}
int CalculateMaxWorkshopsInt(vector<Workshops *> &v) 
{
    Workshops *wp0, *wp;

#if 1
    static int times=0;
    times++;
    for(auto i : v) {
      cout << i->start << "+" << i->duration << "=" << i->end << " ";//<< endl;
    }
    cout << "times=" << times << endl;
    std::this_thread::sleep_for (std::chrono::seconds(1));
#endif
    if (v.size() == 0) {
        return 0;
    }
    wp0 = v.at(0);
    for(auto it = v.begin() + 1; it != v.end();) {
        wp = *it;
        if (wp->start < wp0->end) {
            it = v.erase(it);
        } else {
            ++it;
        }
    }
    v.erase(v.begin());
    return CalculateMaxWorkshopsInt(v) + 1;
}
int CalculateMaxWorkshopsInt1(vector<Workshops *> &v) 
{
    int w = 0, last_end_time=-1;
    Workshops *wp;

    if (v.size() == 0) {
        return 0;
    }
    for(auto iit = v.begin(); iit != v.end();++iit) {
        wp = *iit;
        if (wp->start >= last_end_time) {
            w+=1;
            last_end_time = wp->end;
        }
    }
    return w;
}

int CalculateMaxWorkshops(Available_Workshops* ptr) 
{
    vector<Workshops*> v;

    for(int i = 0; i < ptr->n; i++) {
        v.push_back(ptr->workshops + i);
    }
    sort(v.begin(), v.end(), [](Workshops *a, Workshops *b) {
        return a->end < b->end;
    });

    return CalculateMaxWorkshopsInt1(v);
}

int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
