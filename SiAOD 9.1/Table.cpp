#include "Table.h"
std::string utf8_to_cp1251(const char* str) {
    std::string res;
    WCHAR* ures = NULL;
    char* cres = NULL;
    int result_u = MultiByteToWideChar(CP_UTF8, 0, str, -1, 0, 0);
    if (result_u != 0)
    {
        ures = new WCHAR[result_u];
        if (MultiByteToWideChar(CP_UTF8, 0, str, -1, ures, result_u))
        {
            int result_c = WideCharToMultiByte(1251, 0, ures, -1, 0, 0, 0, 0);
            if (result_c != 0)
            {
                cres = new char[result_c];
                if (WideCharToMultiByte(1251, 0, ures, -1, cres, result_c, 0, 0))
                {
                    res = cres;
                }
            }
        }
    }

    delete[] ures;
    delete[] cres;

    return res;
}
Table::HNPrecord inline Table::convert_2_HNPrecord(UI cadastral_number, std::string adress) {
    return HNPrecord{ cadastral_number , adress };
};

//Constructors
Table::Table() {
    fill_adresses();
};
Table::Table(size_t size) {
    fill_adresses();
    storage.resize(size);
};
Table::Table(UI cadastral_number, string adress) {
    storage.push_back(convert_2_HNPrecord(cadastral_number, adress));
    fill_adresses();
};
    //Operations with table
void Table::insert(UI cadastral_number, string adress) {
    if (!barrier_search(cadastral_number).empty()) { cerr << "Такое значение уже есть в таблице!\n"; return; }
    storage.push_back(convert_2_HNPrecord(cadastral_number, adress));
};
void Table::fill_adresses() {
    fstream f("SNT.txt", ios::in);
    string t;
    while (getline(f, t)) {
        rand_adresses.push_back(utf8_to_cp1251(t.c_str()));
    }
    f.close();
};
void Table::rand_init(size_t size) {
    storage.resize(size);
    vector<UI> t_vec(size);
    iota(t_vec.begin(), t_vec.end(), 1000000);
    random_shuffle(t_vec.begin(), t_vec.end());
    for (int i = 0; i < storage.size(); i++)
        storage[i] = convert_2_HNPrecord(t_vec[i], rand_adresses[rand() % rand_adresses.size()]);
    t_vec.clear();
};
void Table::keyboard_init(size_t size) {
    storage.resize(size);
    for (int i = 0; i < storage.size(); i++) {
        UI key;
        string t_s;
        cout << "Введите кадастровый номер: ";
        cin >> key;
        cout << "Введите адрес: ";
        cin.ignore();
        getline(cin, t_s);
        insert(key, t_s);
    }
};
void Table::print_table() {
    /*for (int i = 0; i < storage.size(); i++) {
        cout << "Key: " << storage[i].cadastral_number << " adress:" << storage[i].adress << '\n';
    }*/
    cout << "Key^ " << storage[storage.size() - 2].cadastral_number << '\n';
};
    //Searching algorithms
string Table::brute_force(UI key) {
    if (storage.empty()) return string();
    for(int i=0;i<storage.size();i++)
        if (storage[i].cadastral_number == key) return storage[i].adress;
    return string();
};
string Table::barrier_search(UI key) {
    if (storage.empty()) return string();
    UI last = storage[storage.size() - 1].cadastral_number;
    if (key == last) return storage[storage.size() - 1].adress;
    storage[storage.size() - 1].cadastral_number = key;
    size_t i = 0;
    while (storage[i].cadastral_number != key) i++;
    storage[storage.size() - 1].cadastral_number = last;
    return (i != storage.size() - 1) ? storage[i].adress : string();
};