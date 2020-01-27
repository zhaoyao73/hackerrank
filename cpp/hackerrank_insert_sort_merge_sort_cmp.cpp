
#include <vector>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

vector<string> split_string(string);
#if 1
// Complete the insertionSort function below.
long insertionSort(std::vector<int>::size_type as, int *arr) {
    long s = 0;
    int l, h, m, ti;
//    auto as = arr.size();
    std::vector<int>::size_type i;

    for (i = 1; i < as; ++i) {
        l = 0;
        h = i - 1;
        
        /* in case the worst cae: totally reverse numbers */
        if (arr[i] >= arr[l]) {
        while(l <= h) {
            m = (h - l)/2 + l;
            if (arr[i] < arr[m]) {
                //swap(arr[j], arr[j-1]);
                h = m - 1;
            } else if (arr[i] > arr[m]) {
                l = m + 1;
            } else {
                l = m;
                while(arr[++l] == arr[i]) ;
                break;
            }
        }
        }
        /*
        for(j = i; j > l; --j) {
            if (arr[j] != arr[j-1]) {
              swap(arr[j], arr[j-1]);
              s++;
            } else {
              break;
            }
        }
        */
        if (i > l) {
          ti = arr[i];
          s+= i - l;
          memcpy(&arr[l+1], &arr[l], sizeof(int)*(i-l));
          arr[l] = ti;
        }
    }
    return s;
}
#else
int temp[100000];

long int join(int s[], int left, int mid, int right)
{
    long int shift=0;
    int i=left, j=mid, k=left;
    while(i<mid && j<=right)
    {
        if(s[i] <= s[j]){
            temp[k]=s[i];
            k++, i++;
        }
        else{
            temp[k]=s[j];
            k++, j++;
            shift += mid-i;
        }
    }
    while(i<mid){
        temp[k] = s[i];
        k++, i++;
    }

    while(j<=right){
        temp[k] = s[j];
        k++, j++;
    }

    while(left<=right){
        s[left] = temp[left];
        left++;
    }
    return shift;
}

long int mergeSort(int s[], int left, int right)
{
    long int shift = 0;
    if(left < right)
    {
        int mid = left + (right-left)/2;
        shift += mergeSort(s, left, mid);
        shift += mergeSort(s, mid+1, right);
        shift += join(s, left, mid+1, right);
    }
    return shift;
}

long insertionSort(int s, int *arr)
{
    return mergeSort(arr, 0, s - 1);
}
#endif
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
            //int item;

            //cin >> item;
            arr.push_back(arr_item);
        }

        long result = insertionSort(arr.size(), arr.data());

        cerr << result << "\n";
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

