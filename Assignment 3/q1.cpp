#include <iostream>
#include <string>
using namespace std;

class Medicine {
protected:
    string name;
    string formula;
    int retail_price;
    int man_date;
    int exp_date;

public:
    Medicine(string name, string formula, int retail_price, int man_date, int exp_date) : name(name), formula(formula), retail_price(retail_price), man_date(man_date), exp_date(exp_date) {}

    void setName(string name) {
        this->name = name;
    }
    void setFormula(string formula) {
        this->formula = formula;
    }
    void setPrice(int retail_price) {
        this->retail_price = retail_price;
    }
    void setManDate(int man_date) {
        this->man_date = man_date;
    }
    void setExpDate(int exp_date) {
        this->exp_date = exp_date;
    }

    string getName() {
        return name;
    }
    string getFormula() {
        return formula;
    }
    int getPrice() {
        return retail_price;
    }
    int getManDate() {
        return man_date;
    }
    int getExpDate() {
        return exp_date;
    }

    virtual void medDetails() {
        cout << "Name: " << name << endl;
        cout << "Formula: " << formula << endl;
        cout << "Price: " << retail_price << endl;
        cout << "Manufacture Date: " << man_date << endl;
        cout << "Expiry Date: " << exp_date << endl;
    }

    bool operator==(const Medicine& other) const {
        return exp_date == other.exp_date;
    }
};

class Tablet : public Medicine {
private:
    int sucroseLevel;

public:
    Tablet(string name, string formula, int retail_price, int man_date, int exp_date, int sucroseLevel) : Medicine(name, formula, retail_price, man_date, exp_date), sucroseLevel(sucroseLevel) {}

    void medDetails() override {
        Medicine::medDetails();
        cout << "Sucrose Level: " << sucroseLevel << endl;
    }
};

class Capsule : public Medicine {
private:
    int absorption_percentage;

public:
    Capsule(string name, string formula, int retail_price, int man_date, int exp_date, int absorption_percentage) : Medicine(name, formula, retail_price, man_date, exp_date), absorption_percentage(absorption_percentage) {}

    void medDetails() override {
        Medicine::medDetails();
        cout << "Absorption Percentage: " << absorption_percentage << endl;
    }
};

class Syrup : public Medicine {
private:
    string viscosity; //thick or thin

public:
    Syrup(string name, string formula, int retail_price, int man_date, int exp_date, string viscosity) : Medicine(name, formula, retail_price, man_date, exp_date), viscosity(viscosity) {}

    void medDetails() override {
        Medicine::medDetails();
        cout << "Viscosity: " << viscosity << endl;
    }
};

class Pharmacist {
public:
    void searchMedicine(string med_name, Medicine& m1, Tablet& t, Capsule& c2, Syrup& s) {
        if (med_name == t.getName()) {
            cout << "MEDICINE FOUND!" << endl;
            t.medDetails();
        }
        else if (med_name == c2.getName()) {
            cout << "MEDICINE FOUND!" << endl;
            c2.medDetails();
        }
        else if (med_name == s.getName()) {
            cout << "MEDICINE FOUND!" << endl;
            s.medDetails();
        }
        else {
            cout << "The medicine is not available!" << endl;
        }
    }
};

class Counter {
    int rev;

public:
    Counter() : rev(0) {}
    void searchMedicine(Medicine& m1, Tablet& t, Capsule& c2, Syrup& s) {
        string med_name;
        if (med_name == m1.getName()) {
            cout << "MEDICINE FOUND!" << endl;
            m1.medDetails();
            updateRevenue(m1.getPrice());
        }
        else if (med_name == t.getName()) {
            cout << "MEDICINE FOUND!" << endl;
            t.medDetails();
            updateRevenue(t.getPrice());
        }
        else if (med_name == c2.getName()) {
            cout << "MEDICINE FOUND!" << endl;
            c2.medDetails();
            updateRevenue(c2.getPrice());
        }
        else if (med_name == s.getName()) {
            cout << "MEDICINE FOUND!" << endl;
            s.medDetails();
            updateRevenue(s.getPrice());
        }
        else {
            cout << "The medicine is not available!" << endl;
        }
    }

    void updateRevenue(int amount) {
        cout << "Updating revenue.." << endl;
        rev += amount;
        cout << "New Revenue = " << rev << endl;
    }
};

int main() {

    cout << "SYEDA RIJA ALI [23K-0057]" << endl;
    cout << endl;

    Counter c;
    Pharmacist p;

    cout << "Output for OPERATOR OVERLOADING defined in Medicine class!" << endl;
    Medicine m1("Panadol", "solid", 200, 2003, 2004);
    Medicine m2("Fish Oil Capsule", "Powder", 500, 2001, 2004);
    //operator overloading being shown
    if (m1 == m2) {
        cout << "Both medicines are going to expire in the same year." << endl;
    }
    else {
        cout << "The expiry years of the two medicines are different." << endl;
    }
    cout << endl;
    Tablet t("Ponstan", "solid", 200, 2003, 2004, 0);
    Capsule c2("Vitamins", "powder", 500, 2001, 2009, 95);
    Syrup s("Brufen", "liquid", 100, 2004, 2005, "thick");

    string prescribedMedicine;
    cout << "Enter the prescribed medicine: ";
    cin >> prescribedMedicine;
    cout << endl;
    cout << "Counter staff forwards the prescription to the pharmacist." << endl;
    cout << endl;
    p.searchMedicine(prescribedMedicine, m1, t, c2, s);
    return 0;
}
