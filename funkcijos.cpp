#include "mylib.h"

// Funkcija, kuri parodo galimus failus ir leidzia vartotojui pasirinkti faila
string GautiPasirinkima() {

    cout << "\nGalimi failai:" << endl;
    string dirPath = "./";
    for (const auto& i : fs::directory_iterator(dirPath)) {
        if (i.is_regular_file() && i.path().extension() == ".txt") {
            cout << i.path().filename() << endl;
        }
    }
    string failoPasirinkimas;
    cout << "\nIveskite failo, kuri norite nuskaityti, pavadinima: "<< endl;
    cin >> failoPasirinkimas; 

    if (failoPasirinkimas.size() < 4 || failoPasirinkimas.substr(failoPasirinkimas.size() - 4) != ".txt")
        failoPasirinkimas += ".txt";

    return failoPasirinkimas.empty() ? "text.txt" : failoPasirinkimas;
}

// Funkcija, kuri tikrina ar failas atsidaro
bool ArAtsidaro (const string& failoPasirinkimas) {
    ifstream in(failoPasirinkimas);
    return in.good();
}

// Funkcija, kuri tikrina ar zodis yra URL
bool TikrinameArUrl (const string& zodis) {
    // regex naudojimas tam, kad tikrintu ar zodis yra URL
    regex urlRegex("(((http|https)://)?www\\.)?[a-zA-Z0-9@:%._\\+~#?&//=]{2,256}\\.[a-z]{2,6}\\b([-a-zA-Z0-9@:%._\\+~#?&//=]*)");
    // regex_match grazina true, jei zodis yra URL
    return regex_match(zodis, urlRegex);
}

// Funkcija, kuri tvarko zodi
string ZodzioTvarkymas(const string& zodis) {
    regex SuSimboliais("[^\\w]+");// regex naudojimas tam, kad is zodzio ismesti visus simbolius, isskyrus raides ir skaicius
    string BeSimboliu = regex_replace(zodis, SuSimboliais, ""); // 
    transform(BeSimboliu.begin(), BeSimboliu.end(), BeSimboliu.begin(), ::tolower);
    return BeSimboliu;
}

// Funkcija, kuri prideda zodi i sarasa
void pridedameISarasa(const string& zodis, map<string, vector<int>>& sarasas, int eilutesNumeris) {
    if (zodis.empty()) 
        return;

    auto it = sarasas.find(zodis);

    if (it == sarasas.end()) { // jei zodzio nera sarase
        vector<int> eiluciuNr;
        eiluciuNr.push_back(eilutesNumeris);
        sarasas[zodis] = eiluciuNr;
    }
    else {
        vector<int>& eiluciuNr = it->second;
        if (eilutesNumeris != eiluciuNr.back()) {
            eiluciuNr.push_back(eilutesNumeris);
        }
    }
}

// Funkcija, kuri nuskaito faila
void failoSkaitymas(const string& failoPasirinkimas,  map<string, vector<int>>& sarasas, vector<string>& urls) {
    ifstream failas;
    failas.open(failoPasirinkimas);
    stringstream tekstas;
    tekstas << failas.rdbuf();
    failas.close();

    string eilute;
    int eilutesNumeris = 0;
    while(getline(tekstas, eilute)) {
        eilutesNumeris++;
        string zodis;
        istringstream in(eilute);
        while( in >> zodis) {
            bool arYraSkaicius = false; 
            for (char c : zodis) {
                if (isdigit(c)) {
                    arYraSkaicius = true;
                    break;
                }
            }
            if(TikrinameArUrl(zodis)) {
                urls.push_back(zodis);
            }
            else if (!arYraSkaicius) {
                zodis = ZodzioTvarkymas(zodis);
                pridedameISarasa(zodis, sarasas,eilutesNumeris);
            }
        }
    }
}

// Funkcija, kuri rasys i faila
void rasymas (map<string, vector<int>>& sarasas,vector<string> urls) {
    ofstream out("rezultatai.txt");
    if (!out.good()) {
        cout << "Failo nepavyko sukurti." << endl;
        return;
    }

    out << "URLS skaicius: " << urls.size() << " " << endl;
    for (const auto& url : urls)
        out << url << endl;

    out << endl;

   if (!sarasas.empty()) {
        out << left << setw(30) << "ZODIS" << setw(10) << "KIEKIS" << "EILUCIU NR." << endl;

        for (const auto& i : sarasas) {
            if (i.second.size() > 1){
                out << left << setw(30) << i.first << setw(10) << i.second.size();

                for (int j : i.second) {
                    out << setw(4) << j;
                }

            out << endl;
            }
        }
    }

    out.close();
}
  
