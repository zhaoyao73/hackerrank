#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

vector<string> split_string(string);

// Complete the insertionSort function below.
long insertionSort(vector<int> &arr) {
    long s = 0;
    int j;
    int l, h, m, ti;

    for (int i = 1; i < arr.size(); ++i) {
        l = 0;
        h = i - 1;
        
        while(l <= h) {
            m = (h - l)/2 + l;
            if (arr[i] < arr[m]) {
                h = m - 1;
            } else if (arr[i] > arr[m]) {
                l = m + 1;
            } else {
                /* arr[m] == arr[i], 
                 *find the first != arr[i] and that is the place to insert
                 */
                l = m;
                while(arr[++l] == arr[i]) ;
                break;
            }
        }
        if (i > l) {
        ti = arr[i];
        s+= i - l;
        memcpy(&arr[l+1], &arr[l], sizeof(int)*(i-l));
        arr[l] = ti;
        }
        /*
        for(j=i; j > l; --j) {
                swap(arr[j], arr[j-1]);
                s++;
        }
        */
    }
    return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<int> arr;
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    arr.reserve(100000);
    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split_string(arr_temp_temp);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr.push_back(arr_item);
        }

        long result = insertionSort(arr);

        fout << result << "\n";
        arr.clear();
    }

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
