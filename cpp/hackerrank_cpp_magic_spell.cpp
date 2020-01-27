#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Spell { 
    private:
        string scrollName;
    public:
        Spell(): scrollName("") { }
        Spell(string name): scrollName(name) { }
        virtual ~Spell() { }
        string revealScrollName() {
            return scrollName;
        }
};

class Fireball : public Spell { 
    private: int power;
    public:
        Fireball(int power): power(power) { }
        void revealFirepower(){
            cout << "Fireball: " << power << endl;
        }
};

class Frostbite : public Spell {
    private: int power;
    public:
        Frostbite(int power): power(power) { }
        void revealFrostpower(){
            cout << "Frostbite: " << power << endl;
        }
};

class Thunderstorm : public Spell { 
    private: int power;
    public:
        Thunderstorm(int power): power(power) { }
        void revealThunderpower(){
            cout << "Thunderstorm: " << power << endl;
        }
};

class Waterbolt : public Spell { 
    private: int power;
    public:
        Waterbolt(int power): power(power) { }
        void revealWaterpower(){
            cout << "Waterbolt: " << power << endl;
        }
};

class SpellJournal {
    public:
        static string journal;
        static string read() {
            return journal;
        }
}; 
string SpellJournal::journal = "";

void counterspell(Spell *spell) {

  /* Enter your code here */
  if (typeid(*spell) == typeid(Fireball)) {
      Fireball * f = dynamic_cast<Fireball*>(spell);
      f->revealFirepower();
  } else 
   if (typeid(*spell) == typeid(Frostbite)) {
      Frostbite * f = dynamic_cast<Frostbite*>(spell);
      f->revealFrostpower();
  } else 
   if (typeid(*spell) == typeid(Waterbolt)) {
      Waterbolt * f = dynamic_cast<Waterbolt*>(spell);
      f->revealWaterpower();
  } else 
   if (typeid(*spell) == typeid(Thunderstorm)) {
      Thunderstorm * f = dynamic_cast<Thunderstorm*>(spell);
      f->revealThunderpower();
  } else {
#if 0
      int s = 0;
      string::size_type cl, dl, dl_start=0;
      string scrollname, journal;

      scrollname = spell->revealScrollName();
      journal = SpellJournal::read();
      for(cl = 0; cl < scrollname.length(); cl++) {
            for(dl=dl_start; dl < journal.length(); dl++) {
                if (scrollname[cl] == journal[dl]) {
                    s++;
                    dl_start = ++dl;
                    break;
                }
            }
           //if (dl == SpellJournal::journal.length()) dl_start++;
        }
        cout << s << endl;
#else
    string spellN = spell->revealScrollName();
    string spellJ = SpellJournal::read();
    int m=spellN.length();
    int n=spellJ.length();
    int array[m+1][n+1]; 

    // solve for LCS
    for (int i=0;i<=m;i++) array[i][0]=0;
    for (int j=0;j<=n;j++) array[0][j]=0;
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            if (spellN[i-1] == spellJ[j-1])
                array[i][j]=array[i-1][j-1]+1;
            else
                array[i][j]=max(array[i][j-1],array[i-1][j]);
        }
    }  
    cout << array[m][n] << endl; 
#endif
  }
}

class Wizard {
    public:
        Spell *cast() {
            Spell *spell;
            string s; cin >> s;
            int power; cin >> power;
            if(s == "fire") {
                spell = new Fireball(power);
            }
            else if(s == "frost") {
                spell = new Frostbite(power);
            }
            else if(s == "water") {
                spell = new Waterbolt(power);
            }
            else if(s == "thunder") {
                spell = new Thunderstorm(power);
            } 
            else {
                spell = new Spell(s);
                cin >> SpellJournal::journal;
            }
            return spell;
        }
};

int main() {
    int T;
    cin >> T;
    Wizard Arawn;
    while(T--) {
        Spell *spell = Arawn.cast();
        counterspell(spell);
    }
    return 0;
}
