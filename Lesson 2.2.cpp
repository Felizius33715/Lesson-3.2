#include <fstream>
#include <iostream>

struct adress {
    std::string city;
    std::string street;
    int house_num;
    int home_num;
};

static void fout(adress& a, std::ofstream& out) {
    out << "" << a.city;
    out << ", " << a.street;
    out << ", " << a.house_num;
    out << ", " << a.home_num << std::endl;
}

static void fin(adress& a, std::ifstream& in) {
    in >> a.city;
    in >> a.street;
    in >> a.house_num;
    in >> a.home_num;
}

void sort(adress* ad, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (ad[j].city > ad[j + 1].city) {
                std::swap(ad[j], ad[j + 1]);
            }
            else if (ad[j].street > ad[j + 1].street) {
                std::swap(ad[j], ad[j + 1]);
            }
            else if (ad[j].house_num > ad[j + 1].house_num) {
                std::swap(ad[j], ad[j + 1]);
            }
            else if (ad[j].home_num > ad[j + 1].home_num) {
                std::swap(ad[j], ad[j + 1]);
            }
        }
    }
}

int main() {
    int a;
    std::ifstream in;
    in.open("in.txt");
    in >> a;
    adress* adress_array = new adress[a];
    for (int i = 0; i < a; ++i) {
        fin(adress_array[i], in);
    }
    in.close();
    sort(adress_array, a);
    std::ofstream out;
    out.open("out.txt");
    for (int i = 0; i < a; ++i) {
        fout(adress_array[i], out);
    }
    out.close();
    delete[] adress_array;
    return 0;
}