/*
* Programa: Valiutos keitykla
 * Autorius: Dovydas Kazakevičius
 * Data: 2026-03-09
 * Aprašymas: Programa konvertuoja EUR į GBP, USD, INR
 */
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

// Valiutų kursai
const double GBP_BENDAS = 0.8729;
const double GBP_PIRKTI = 0.8600;
const double GBP_PARDUOTI = 0.9220;

const double USD_BENDAS = 1.1793;
const double USD_PIRKTI = 1.1460;
const double USD_PARDUOTI = 1.2340;

const double INR_BENDAS = 104.6918;
const double INR_PIRKTI = 101.3862;
const double INR_PARDUOTI = 107.8546;

// Funkcija valiutos pavadinimui gauti
string getCurrencyName(int choice) {
    switch(choice) {
        case 1: return "EUR (Euras)";
        case 2: return "GBP (Didžiosios Britanijos svaras)";
        case 3: return "USD (JAV doleris)";
        case 4: return "INR (Indijos rupija)";
        default: return "Nežinoma valiuta";
    }
}

// Funkcija valiutos kodui gauti
string getCurrencyCode(int choice) {
    switch(choice) {
        case 1: return "EUR";
        case 2: return "GBP";
        case 3: return "USD";
        case 4: return "INR";
        default: return "";
    }
}

// Funkcija kursui gauti
double getRate(int currency, int operationType) {
    switch(currency) {
        case 2: // GBP
            if(operationType == 1) return GBP_BENDAS;
            else if(operationType == 2) return GBP_PIRKTI;
            else return GBP_PARDUOTI;
        case 3: // USD
            if(operationType == 1) return USD_BENDAS;
            else if(operationType == 2) return USD_PIRKTI;
            else return USD_PARDUOTI;
        case 4: // INR
            if(operationType == 1) return INR_BENDAS;
            else if(operationType == 2) return INR_PIRKTI;
            else return INR_PARDUOTI;
        default: return 0;
    }
}

// TIK VIENA MAIN FUNKCIJA
int main() {
    int pasirinkimas, valiuta;
    double kiekis, rezultatas;
    char testi;

    cout << "=====================================\n";
    cout << "     VALIUTOS KEITYKLA     \n";
    cout << "=====================================\n\n";

    do {
        cout << "Pasirinkite operacija:\n";
        cout << "1 - Valiutos kurso palyginimas\n";
        cout << "2 - Pirkti valiuta (EUR -> kita valiuta)\n";
        cout << "3 - Parduoti valiuta (kita valiuta -> EUR)\n";
        cout << "Jusu pasirinkimas: ";
        cin >> pasirinkimas;

        while(pasirinkimas < 1 || pasirinkimas > 3) {
            cout << "Neteisingas pasirinkimas! Iveskite skaicių nuo 1 iki 3: ";
            cin >> pasirinkimas;
        }

        cout << "\nPasirinkite valiuta:\n";
        cout << "1 - EUR (Euras)\n";
        cout << "2 - GBP (Didziosios Britanijos svaras)\n";
        cout << "3 - USD (JAV doleris)\n";
        cout << "4 - INR (Indijos rupija)\n";
        cout << "Jusu pasirinkimas: ";
        cin >> valiuta;

        while(valiuta < 1 || valiuta > 4) {
            cout << "Neteisingas pasirinkimas! Iveskite skaiciu nuo 1 iki 4: ";
            cin >> valiuta;
        }

        if(valiuta == 1 && pasirinkimas != 1) {
            cout << "\nEUR yra pagrindine valiuta. ";
            if(pasirinkimas == 2)
                cout << "Pirkti galite tik kita valiuta.\n";
            else
                cout << "Parduoti galite tik kitą valiuta.\n";
            continue;
        }

        cout << "\nĮveskite ";
        if(pasirinkimas == 1 || pasirinkimas == 2) {
            cout << getCurrencyName(1);
        } else {
            cout << getCurrencyName(valiuta);
        }
        cout << " kieki: ";
        cin >> kiekis;

        while(kiekis <= 0) {
            cout << "Kiekis turi buti teigiamas! Iveskite dar karta: ";
            cin >> kiekis;
        }

        cout << fixed << setprecision(2);

        if(pasirinkimas == 1) {
            double kursas = getRate(valiuta, 1);
            rezultatas = kiekis * kursas;
            cout << "\n--- REZULTATAS ---\n";
            cout << kiekis << " EUR = " << rezultatas << " " << getCurrencyCode(valiuta) << "\n";
            cout << "Kursas: 1 EUR = " << kursas << " " << getCurrencyCode(valiuta) << "\n";
        } else if(pasirinkimas == 2) {
            double kursas = getRate(valiuta, 2);
            rezultatas = kiekis * kursas;
            cout << "\n--- REZULTATAS ---\n";
            cout << "Už " << kiekis << " EUR gausite " << rezultatas << " " << getCurrencyCode(valiuta) << "\n";
            cout << "Pirkimo kursas: 1 EUR = " << kursas << " " << getCurrencyCode(valiuta) << "\n";
        } else {
            double kursas = getRate(valiuta, 3);
            rezultatas = kiekis / kursas;
            cout << "\n--- REZULTATAS ---\n";
            cout << "Už " << kiekis << " " << getCurrencyCode(valiuta) << " gausite " << rezultatas << " EUR\n";
            cout << "Pardavimo kursas: 1 EUR = " << kursas << " " << getCurrencyCode(valiuta) << "\n";
        }

        cout << "\nAr norite atlikti dar viena operacija? (t/n): ";
        cin >> testi;
        cout << "\n";

    } while(testi == 't' || testi == 'T');

    cout << "Programa baigta. Aciu!\n";
    return 0;
}