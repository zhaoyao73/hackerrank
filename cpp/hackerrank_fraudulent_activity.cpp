#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <map>

using namespace std;

vector<string> split_string(string);

#if 0
double get_median(std::vector<int> &v, int start, int end)
{
    static std::multimap<int, int> map;
    static bool first = true;
    int ia, ib = 0;
	  double ret = 0;
    int n = end - start + 1;
    int *arr = v.data();
    static int i = 0;

    if (first) {
        for (int i = start; i <= end; i++) {
            map.insert({arr[i], i});
        }
        first = false;
    } else {
			  auto pos = map.find(arr[start-1]);
			  /* erase with key, will erase all the entries with the same key */
        //map.erase(arr[start - 1]);
			  /* instead use the pointer */
			  map.erase(pos);
        map.insert({arr[end], end});
    }

  if (++i == 2) {
     for (auto e=start; e <= end; ++e) {
        cout << arr[e] << " ";
     }
     cout << endl;
     for (auto e=map.begin(); e != map.end(); ++e) {
        cout << e->first << " ";
     }
     exit(1);
  }
    
       ib = 0;
       if (!(n & 1) ) {
        ia = n/2 - 1;
 
        for(auto &e : map) {
            if (ib == ia) {
                ret = e.first;
            } 
            else if (ib == (ia+1)) {
                ret += e.first;
                ret = ret/2.0;
                break;
            }
            ib++;
        }
    } else {
        ia =  n/2;
        for(auto &e : map) {
            if (ib == ia) {
                ret = e.first;
                break;
            }
            ib++;
        }
    }
    return ret;
}
//#if 0
/* this used partially sort, 
 * remember std::sort sorts a range [first, last)
 * last is open not close, so need to +1
 */
double get_median(std::vector<int> &v, int start, int end)
{
  static std::vector<int> tv;
  double ret;
  static bool first = true;
  int n = end - start + 1, m;
  static int i=0;

	if (first) {
     tv = v;
     first = false; 
     std::sort(tv.begin() + start, tv.begin() + end + 1);
//#if 0
     for (auto e=tv.begin()+start; e <=tv.begin() + end + 1; ++e) {
        cout << *e << " ";
     }
     cout << endl;
//#endif
  } else {
     /* need to find the v[start - 1] in tv and remove it,
      * then tv's end + 1
      * resort
      */
//#if 0
     for (auto e=tv.begin()+start - 1; e <=tv.begin() + end; ++e) {
       if (v[start - 1] == *e) {
         if (e != (tv.begin() + start - 1)) {
           /* need move from [start -1, e -1] to [start, e]
         }
       }
     }
     cout << endl;
//#endif
     std::sort(tv.begin() + start, tv.begin() + end + 1);
  }

//#if 0
  if (++i == 2) {
     for (auto e=start; e <= end; ++e) {
        cout << v[e] << " ";
     }
     cout << endl;
     for (auto e=tv.begin()+start; e <=tv.begin() + end; ++e) {
        cout << *e << " ";
     }
     exit(1);
  }
//#endif
  /* odd */
  if (n & 1) {
     ret = tv.at(start + (end - start)/2);
  } else {
     m = start + (end - start)/2; 
     ret = (tv.at(m) + tv.at(m-1))/2.0; 
  }
  return ret;
}
//#endif
#endif

/* try counting sort
 *  the idea is to calculate the frequency of a number
 * it also asks for the median, so it must be sorted
 * but because of the counting sort nature it is sorted for sure,
 * so from its frequency we could calculate the median just counted the frequency
 * if it is half of the d.
 * each number <=200 so the count sort arrary could be very small
 * if the number is not small, then walk the sorted array might not be ideal
 */
#define MAX_N (2*100+1)
int count_sort[MAX_N];

void
count_sort_add(int a)
{
  count_sort[a]++;
}
void
count_sort_dec(int a)
{
  count_sort[a]--;
}
void
init_count_sort(int *a, int start, int end)
{
  for(int i=start; i <=end; i++) {
    count_sort[a[i]]++;
  }
}

double get_median_i(int n)
{
  int ia=n/2, ib;
  int mid = 0;
  double ret = 0;
  bool ba=false;

  if (n & 1) {
    for(int i=0; i<MAX_N;i++){
      mid += count_sort[i];
      if (mid > ia) {
        ret = i;
        break;
      }
    }
  } else {
    ib = ia + 1;
    for(int i=0; i<MAX_N;i++){
      mid += count_sort[i];
      if (mid >= ia && !ba) {
        ret = i;
        ba = true;
      }
      if (mid >= ib) {
        ret += i;
        ret = ret/2.0;
        break;
      }
    }
  }

  return ret;
}

double get_median(std::vector<int> &v, int start, int end)
{
  double ret;
  static bool first = true;
  int n = end - start + 1;

	if (first) {
     first = false; 
     init_count_sort(v.data(), start, end);
  } else {
    count_sort_dec(v[start-1]);
    count_sort_add(v[end]);
  }

  ret = get_median_i(n);
  return ret;
}

// Complete the activityNotifications function below.
int activityNotifications(vector<int> expenditure, int d) {
    std::vector<int>::size_type e;
    double m, fe, dif;
    int notify=0;

    for (e = d; e < expenditure.size(); ++e) {
        m = get_median(expenditure, e - d, e - 1);
        fe = (double)expenditure.at(e);
        dif = fe - (m*2);
			  //cout << "e is " << fe << " median is " << m << " dif is " << dif << endl;
        if ( (dif > 1e-6) || (dif < 1e-6 && dif > -1e-6)) {
            notify++;
        }
    }
    return notify;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nd_temp;
    getline(cin, nd_temp);

    vector<string> nd = split_string(nd_temp);

    int n = stoi(nd[0]);

    int d = stoi(nd[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split_string(expenditure_temp_temp);

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);

    cout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
