#ifndef PRIZE_H_INCLUDED
#define PRIZE_H_INCLUDED

#include <iomanip>

inline std::string fix(std::string str){
    for (int i = 0; i < str.length(); ++i){
        if (str[i] == '_')
            str[i] = ' ';
    } /// end for loop
    return str;
}

/// Strings used in the input file paths.
const std::string grocInput = "grocerynew.txt";
const std::string smalInput = "small.txt";
const std::string medInput = "medium.txt";
const std::string largInput = "large.txt";
const std::string carInput = "car.txt";

/// Maximum price for cars.
const int maxCar = 35000;

/// Grocery products.
class grocery{

public:
    grocery(){};
    ~grocery(){};

    std::string getDescription(){return description;}
    void setDescription(std::string adescription){description = adescription;}

    std::string getShortName(){return shortName;}
    void setShortName(std::string ashortname){shortName = ashortname;}

    double getPrice(){return price;}
    void setPrice(double aprice){price = aprice;}

    void showPrize()
    {
        std::cout << fix(description);
    }

    void showShortName()
    {
        std::cout << fix(shortName);
    }

    void showARP()
    {
        std::cout << std::fixed << "$" << std::setprecision(2) << price;
    }

private:
    std::string description;
    std::string shortName;
    double price;

};

/// Small prizes, used in games like Plinko, Punch-a-Bunch, and Bonus Game. Usually between $10 and $300.
class small{

public:
    small(){};
    ~small(){};

    std::string getDescription(){return description;}
    void setDescription(std::string adescription){description = adescription;}

    std::string getShortName(){return shortName;}
    void setShortName(std::string ashortname){shortName = ashortname;}

    int getPrice(){return price;}
    void setPrice(int aprice){price = aprice;}

    void showPrize()
    {
        std::cout << fix(description);
    }

    void showShortName()
    {
        std::cout << fix(shortName);
    }

    void showARP()
    {
        std::cout << "$" << price;
    }



private:
    std::string description;
    std::string shortName;
    int price;
};

/// Medium prizes. These include items up for bid and the items in most multi-prize games.
class medium{

public:
    medium(){};
    ~medium(){};

    std::string getDescription(){return description;}
    void setDescription(std::string adescription){description = adescription;}

    std::string getShortName(){return shortName;}
    void setShortName(std::string ashortname){shortName = ashortname;}

    int getPrice(){return price;}
    void setPrice(int aprice){price = aprice;}

    void showPrize()
    {
        std::cout << fix(description);
    }

    void showShortName()
    {
        std::cout << fix(shortName);
    }

    void showARP()
    {
        std::cout << "$" << price;
    }



private:
    std::string description;
    std::string shortName;
    int price;
};

/// Large prizes. This includes any prize over $5000, including most trips. A couple higher-end medium prizes are included here too.
class large{

public:
    large(){};
    ~large(){};

    std::string getDescription(){return description;}
    void setDescription(std::string adescription){description = adescription;}

    std::string getShortName(){return shortName;}
    void setShortName(std::string ashortname){shortName = ashortname;}

    int getPrice(){return price;}
    void setPrice(int aprice){price = aprice;}

    void showPrize()
    {
        std::cout << fix(description);
    }

    void showShortName()
    {
        std::cout << fix(shortName);
    }

    void showARP()
    {
        std::cout << "$" << price;
    }


private:
    std::string description;
    std::string shortName;
    int price;
};

/// A new car... or as Rich Fields says, "A NEW CAAAAAAAAAAHHHHHH!!!!!!!"
class car{

public:
    car(){};
    ~car(){};

    std::string getModel(){return model;}
    void setModel(std::string amodel){model = amodel;}

    std::string getOptions(){return options;}
    void setOptions(std::string aoptions){options = aoptions;}

    int getPrice(){return price;}
    void setPrice(int aprice){price = aprice;}

    void showModel()
    {
        std::cout << fix(model);
    }

    void showOptions()
    {
        std::cout << fix(options);
    }

    void showARP()
    {
        std::cout << "$" << price;
    }


    /// Checks if a car's price contains repeating digits. These cannot be used in games like 3 Strikes, Pocket Change, and Stack the Deck.
    bool hasRepeatingDigits()
    {
        bool flag = false;
        if (price < 100000)
        {
            int digits[5];
            digits[0] = price / 10000 % 10;
            digits[1] = price / 1000 % 10;
            digits[2] = price / 100 % 10;
            digits[3] = price / 10 % 10;
            digits[4] = price % 10;

            if ( (digits[0] == digits[1]) || (digits[0] == digits[2]) || (digits[0] == digits[3]) || (digits[0] == digits[4]) )
                flag = true;
            else if ( (digits[1] == digits[2]) || (digits[1] == digits[3]) || (digits[1] == digits[4]) )
                flag = true;
            else if ( (digits[2] == digits[3]) || (digits[2] == digits[4]) )
                flag = true;
            else if ( (digits[3] == digits[4]) )
                flag = true;
            else
                flag = false;

            if (flag)
                return true;
            else
                return false;


        }
        else
            return true; /// we'll implement this (maybe for MDS/Dream Car Week) later
    }


private:
    std::string model;
    std::string options;
    int price;
};

#endif // PRIZE_H_INCLUDED
