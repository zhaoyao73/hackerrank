#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

struct my_tag {
    string                tagname;
    vector<my_tag>        subtag;
    map<string, string>   attribute;
};
class work {
    char buf[201];
    vector<my_tag> level_top;

public:
    int n, q;

    work(int an, int aq) : n(an), q(aq) {}

    void parse_tags() {
        string s;
        string::size_type pos = 0, npos=0;
        my_tag t;

        cout << "start to input tags"<<endl;
        for(int i =0 ; i < n; ++i) {
            cin.getline(buf, sizeof(buf));
            cout << buf << endl;
            s = buf;
            for(pos = 0;pos!= string::npos;) {
              npos = s.find_first_of(" ", pos);
              if (npos != string::npos) {/* means just tag, no attributes */
                  if (s.substr(pos, npos - pos).at(0) == '<') {
                      cout << "<" << "npos=" << pos;
                      t.tagname = s.substr(pos + 1, npos-pos);
                      pos = npos + 1;
                  } else { /* attribute name = value */
                      string n, v;

                      n = s.substr(pos, npos-pos);
                      pos = npos;
                      npos = s.find_first_of(" ", pos);/* = */
                      pos = npos+2; /* +1 should be left " */
                      npos = s.find_first_of("\"", pos); /* "value" or "value">*/
                      v = s.substr(pos, npos-pos);
                      t.attribute.insert({n, v});
                      if (s[npos+1] == '>') {
                        break;
                      }
                  }
              } else {
                  cout << "no space,";
                  npos = s.find_first_of(">", pos);
                  t.tagname = s.substr(pos+1, npos-pos);
                  break;
              }
            }
        }
    }
    void parse_query() {
        for(int i =0; i < q; ++i) {
        }
    }
};
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n, q;

    cin >> n;
    cin >> q;
    cin.ignore(100, '\n');

    work w(n, q);
    w.parse_tags();
    w.parse_query(); 

    return 0;
}
