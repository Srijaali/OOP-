/*
Name: Syeda Rija Ali
ID: 23K-0057
Desc: Restaurant Management system
*/


#include <iostream>
#include <string>

using namespace std;

class Restaurant{
    string restaurant_name;
    string location;
    string menu[3];
    int pricelist[3];
    string validcoupons[3];
    static int redeemedcount;

public:
    Restaurant(string name, string loc, string menulist[3], int price[3], string codes[3])
    {
        restaurant_name = name;
        location = loc;
        for (int i = 0; i < 3; i++)
        {
            menu[i] = menulist[i];
            pricelist[i] = price[i];
            validcoupons[i] = codes[i];
        }
    }

    void display_menu()
    {
        cout << "\t\t   " << restaurant_name << endl;
        cout << "\tItem \t\t\tPrice" << endl;
        cout << "\t--------------------------------" << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << "\t" << menu[i] << "\t\t   |" << "\t" <<   pricelist[i] << endl;
        }
        cout<<"\n\n";
    }

    void generate_bill(int itemIndex, string couponcode)
    {
        int total = pricelist[itemIndex];
        bool discountapplied = apply_discount(couponcode, itemIndex);
        if (discountapplied)
        {
            total /= 2;
            redeemedcount++;
        }
        cout << "Your bill for " << menu[itemIndex] << " is " << total << endl;
    }

    bool apply_discount(string couponcode, int itemIndex)
    {
        for (int i = 0; i < 3; i++)
        {
            if (couponcode == validcoupons[i])
            {
                cout << "Coupon valid for " << menu[itemIndex] << ". YOU GET A 50% DISCOUNT!" << endl;
                return true;
            }
        }
        cout << "Sorry, you don't have a valid coupon for this item!" << endl;
        return false;
    }

    string get_restaurant_name()
    {
        return restaurant_name;
    }

    static int get_redeemedcount()
    {
        return redeemedcount;
    }
};

int Restaurant::redeemedcount = 0;

class BOGOCoupon{
    string couponcode;
    string validfrom;
    string validuntil;
    string resstaurantcode;

public:
    BOGOCoupon(string code, string from, string until, string rest_code)
    {
        couponcode = code;
        validfrom = from;
        validuntil = until;
        resstaurantcode = rest_code;
    }

    bool is_valid(string restname, string today)
    {
        if (restname[0] == resstaurantcode[0] && restname[1] == resstaurantcode[1])
        {
            if (today >= validfrom && today <= validuntil)
            {
                return true;
            }
        }
        return false;
    }

    string get_couponcode()
    {
        return couponcode;
    }
};

class User{
    string name;
    int age;
    string number;
    string couponlist[3];
    string redeemed_couponlist[3];
    int coupons_count;
    int redeemed_count;

public:
    User(string n, int a, string num)
    {
        name = n;
        age = a;
        number = num;
        coupons_count = 0;
        redeemed_count = 0;
    }

    void accumulate_coupon(string coup_name)
    {
        couponlist[coupons_count] = coup_name;
        coupons_count++;
    }

    bool has_valid_coupon(string rest_name, string today)
    {
        for (int i = 0; i < coupons_count; i++)
        {
            BOGOCoupon coupon(couponlist[i], "01-01-2024", "31-12-2024", rest_name.substr(0, 2));
            if (coupon.is_valid(rest_name, today))
            {
                return true;
            }
        }
        return false;
    }

    bool redeem_coupon(string rest_name, string today)
    {
        for (int i = 0; i < coupons_count; i++)
        {
            BOGOCoupon coupon(couponlist[i], "01-01-2024", "31-12-2024", rest_name.substr(0, 2));
            if (coupon.is_valid(rest_name, today))
            {
                redeemed_couponlist[redeemed_count] = coupon.get_couponcode(); 
                redeemed_count++;
                return true;
            }
        }
        return false;
    }

    void display_coupons()
    {
        cout << "You have " << coupons_count << " coupons:" << endl;
        for (int i = 0; i < coupons_count; i++)
        {
            cout << couponlist[i] << endl;
        }
    }

    void display_redeemed_coupons()
    {
        cout << "You have redeemed " << redeemed_count << " coupons:" << endl;
        for (int i = 0; i < redeemed_count; i++)
        {
            cout << redeemed_couponlist[i] << endl;
        }
    }
};

int main()
{

    string foodhaven[3] = {"Sushi", "Pad Thai", "Mango Tango"};
    int foodhavenprice[3] = {1200, 1150, 650};
    string foodhavencodes[3] = {"FH-BOGO-12345", "FH-BOGO-23456", "FH-BOGO-34567"};
    Restaurant fh("Food Haven", "City Center", foodhaven, foodhavenprice, foodhavencodes);

    string pixelbites[3] = {"Binary Burger", "Quantum Quinoa", "Data Donuts"};
    int pixelbitesprice[3] = {1000, 450, 280};
    string pixelbitescodes[3] = {"PB-BOGO-67890", "PB-BOGO-78901", "PB-BOGO-89012"};
    Restaurant pb("Pixel Bites", "Cyber Street", pixelbites, pixelbitesprice, pixelbitescodes);

    User user("Fatima", 19 , "03331234567");

    fh.display_menu();
    pb.display_menu();

    user.accumulate_coupon("FH-BOGO-12345");
    user.accumulate_coupon("PB-BOGO-67890");
    user.accumulate_coupon("FH-BOGO-23456");

    cout << endl;
    user.display_coupons();

    string today = "25-02-2024";

    cout << endl;
    if (user.has_valid_coupon(fh.get_restaurant_name(), today))
    {
        if (user.redeem_coupon(fh.get_restaurant_name(), today))
        {
            fh.generate_bill(0, "FH-BOGO-34521");
        }
    }
    if (user.has_valid_coupon(pb.get_restaurant_name(), today))
    {
        if (user.redeem_coupon(pb.get_restaurant_name(), today))
        {
            pb.generate_bill(1, "PB-BOGO-98567");
        }
    }

    cout << endl;
    user.display_redeemed_coupons();

    cout << endl;
    cout << "Total coupons redeemed: " << Restaurant::get_redeemedcount() << endl;

    return 0;
}
