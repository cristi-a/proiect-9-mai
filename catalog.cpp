#include <bits/stdc++.h>
using namespace std;
ifstream f ("clase.txt");

vector<string> materii = {"romana", "matematica", "informatica", "engleza", "tic", "fizica", "chimie"};

struct clasa {
private:
  struct elev {
    string nume, prenume;
    vector<pair<string,vector<int>>> note;
    float medieGenerala;
    int absente;
  };
  vector<elev> v;
  string face = "";

public:
  void newFace(string temp) {
    face = temp;
  }
  string pullFace() {
    return face;
  }
  int pullSize() {
    return int(v.size());
  }
  int pullAbsente(string nume, string prenume) {
    for(vector<elev>::iterator it=v.begin(); it!=v.end(); it++)
      if(it->nume == nume and it->prenume == prenume)
        return it->absente;
  }
  vector<int> pullNote(string nume, string prenume, string materie) {
    vector<int> temp; temp.resize(0);
    for(vector<elev>::iterator it=v.begin(); it!=v.end(); it++)
      if(it->nume == nume and it->prenume == prenume)
        for(vector<pair<string,vector<int>>>::iterator it2=it->note.begin(); it2!=it->note.end(); it2++)
          if(it2->first==materie) {
            for(vector<int>::iterator it3=it2->second.begin(); it3!=it2->second.end(); it3++)
              temp.emplace_back(*it3);
            return temp;
          }
    return temp;
  }
  float pullMedieGenerala(string nume, string prenume) {
    for(vector<elev>::iterator it=v.begin(); it!=v.end(); it++)
      if(it->nume == nume and it->prenume == prenume) {
        float sumAll = 0;
        float nrmat = 0;
        for(vector<pair<string,vector<int>>>::iterator it2=it->note.begin(); it2!=it->note.end(); it2++) {
          if(it2->second.size()) nrmat++;
          float s = 0;
          for(vector<int>::iterator it3=it2->second.begin(); it3!=it2->second.end(); it3++)
            s += *it3;
          float temp = float(s);
          float tempSize = float(it2->second.size());
          if(tempSize) sumAll = sumAll + (temp/tempSize);
        }
        return (sumAll / nrmat);
      }
  }
  string pullElevi() {
    string temp;
    for(vector<elev>::iterator it=v.begin(); it!=v.end(); it++)
      temp = temp + it->nume + " " + it->prenume + "\n";
    return temp;
  }
  void addPerson(string nume, string prenume) {
    elev temp;
    temp.nume = nume; temp.prenume = prenume;
    temp.note.clear();
    vector<int> placeholder; placeholder.clear();
    for(vector<string>::iterator it=materii.begin(); it!=materii.end(); it++)
      temp.note.emplace_back(*it,placeholder);
    temp.medieGenerala = 0;
    temp.absente = 0;
    v.emplace_back(temp);
  }
  void remove(string nume, string prenume) {
    for(vector<elev>::iterator it=v.begin(); it!=v.end(); it++)
      if(it->nume == nume and it->prenume == prenume) {
        v.erase(it);
        break;
      }
  }
  void addGrade(string nume, string prenume, string materie, int val) {
    for(vector<elev>::iterator it=v.begin(); it!=v.end(); it++)
      if(it->nume == nume and it->prenume == prenume) {
        for(vector<pair<string,vector<int>>>::iterator it2=it->note.begin(); it2!=it->note.end(); it2++)
          if(it2->first == materie)
            it2->second.emplace_back(val);
        break;
      }
  }
  void addAbsenta(string nume, string prenume) {
    for(vector<elev>::iterator it=v.begin(); it!=v.end(); it++)
      if(it->nume == nume and it->prenume == prenume) {
        it->absente++;
        break;
      }
  }
};

int main() {
  clasa catalog[100] = {};
  int nr = 0;
  string in,face;
  while(getline(f,in)) {
    if(in=="new") {
      getline(f,face);
      nr++;
      catalog[nr].newFace(face);
    }
    else {
      string nume = "";
      string prenume = "";
      bool trecut = false;
      for(int i=0; i<in.size(); i++) {
        if(in[i]==' ') {
          trecut = true;
          continue;
        }
        if(!trecut) nume = nume + in[i];
        if(trecut) prenume = prenume + in[i];
      }
      for(int i=1; i<=nr; i++)
        if(catalog[i].pullFace()==face)
          catalog[i].addPerson(nume,prenume);
    }
  }
  int type;
  do {
    system("cls");
    cout << "0 -> exit\n1 -> lista clase\n2 -> adauga clasa\n";
    cout << "op = "; cin >> type;
    if(type==1) {
      system("cls");
      int t2;
      do {
        system("cls");
        for(int i=1; i<=nr; i++, cout << "\n") cout << catalog[i].pullFace();
        cout << "\n";
        cout << "0 -> exit\n1 -> lista elevi\n2 -> adauga elev\n";
        cout << "op = "; cin >> t2;
        if(t2==1) {
          cout << "clasa(numar roman gen IX, X) = "; string in1; cin >> in1;
          cout << "litera(litera mare) = "; string in2; cin >> in2;
          string in = in1 + " " + in2;
          int t3;
          for(int i=1; i<=nr; i++)
            if(catalog[i].pullFace()==in)
              do {
                system("cls");
                cout << catalog[i].pullElevi();
                cout << "0 -> exit\n1 -> lista note\n2 -> absente\n3 -> media generala\n4 -> adauga nota\n5 -> adauga absenta\n6 -> elimina elev\n";
                cout << "op = "; cin >> t3;
                if(t3==1) {
                  cout << "nume = "; string nume; cin >> nume;
                  cout << "prenume = "; string prenume; cin >> prenume;
                  cout << "romana, matematica informatica engleza tic fizica chimie\nmaterie = "; string mat; cin >> mat;
                  vector<int> grd = catalog[i].pullNote(nume,prenume,mat);
                  for(vector<int>::iterator it = grd.begin(); it!=grd.end(); it++)
                    cout << *it << " ";
                }
                if(t3==2) {
                  cout << "nume = "; string nume; cin >> nume;
                  cout << "prenume = "; string prenume; cin >> prenume;
                  cout << catalog[i].pullAbsente(nume,prenume);
                }
                if(t3==3) {
                  cout << "nume = "; string nume; cin >> nume;
                  cout << "prenume = "; string prenume; cin >> prenume;
                  cout << catalog[i].pullMedieGenerala(nume,prenume);
                }
                if(t3==4) {
                  cout << "nume = "; string nume; cin >> nume;
                  cout << "prenume = "; string prenume; cin >> prenume;
                  cout << "romana, matematica informatica engleza tic fizica chimie\nmaterie = "; string mat; cin >> mat;
                  cout << "nota = "; int val; cin >> val;
                  catalog[i].addGrade(nume,prenume,mat,val);
                }
                if(t3==5) {
                  cout << "nume = "; string nume; cin >> nume;
                  cout << "prenume = "; string prenume; cin >> prenume;
                  catalog[i].addAbsenta(nume,prenume);
                }
                if(t3==6) {
                  cout << "nume = "; string nume; cin >> nume;
                  cout << "prenume = "; string prenume; cin >> prenume;
                  catalog[i].remove(nume,prenume);
                }
                cout << "\n";
                if(t3) system("pause");
              }while(t3);
        }
        if(t2==2) {
          cout << "clasa(numar roman gen IX, X) = "; string in1; cin >> in1;
          cout << "litera(litera mare) = "; string in2; cin >> in2;
          cout << "nume = "; string nume; cin >> nume;
          cout << "prenume = "; string prenume; cin >> prenume;
          string in = in1 + " " + in2;
          for(int i=1; i<=nr; i++)
            if(catalog[i].pullFace()==in)
              catalog[i].addPerson(nume,prenume);
        }
        if(t2) system("pause");
      }while(t2);
    }
    if(type==2) {
      cout << "clasa(numar roman gen IX, X) = "; string in1; cin >> in1;
      cout << "litera(litera mare) = "; string in2; cin >> in2;
      string in = in1 + " " + in2;
      nr++;
      catalog[nr].newFace(in);
    }
    if(type) system("pause");
  } while(type);
  f.close();
  ofstream g ("clase.txt");
  for(int i=1; i<=nr; i++)
    g << "new\n" << catalog[i].pullFace() << "\n" << catalog[i].pullElevi() << "\n";
  return 0;
}
