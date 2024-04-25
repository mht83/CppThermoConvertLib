//////////////////////////////////////////////written by mht83/////////////////////////////////////////

#include <iostream>
#include <string>

class Temperature {


public:
    Temperature(std::string temp) {
        
        std::string temp_number_str = temp.substr(1);
        double temp_number = std::atof(temp_number_str.c_str());

        
        if (temp[0]=='c') {
            kelvin = celsius_to_kelvin(temp_number);
        }
        else if (temp[0] == 'f') {
            kelvin = fahrenheit_to_kelvin(temp_number);
        }
        else if (temp[0] == 'k') {
            kelvin = temp_number; 
        }
        
    }
    double celsius_to_kelvin(double celsius) {
        return celsius + 273.15;
    }

    double fahrenheit_to_kelvin(double fahrenheit) {
        return (fahrenheit - 32) * 5 / 9 + 273.15;
    }

    double kelvin_to_celsius(double kelvin) {
        return kelvin - 273.15;
    }

    double kelvin_to_fahrenheit(double kelvin) {
        return (kelvin - 273.15) * 9 / 5 + 32;
    }

    bool operator<(const Temperature& other) const {
        return kelvin < other.kelvin;
    }

    bool operator>(const Temperature& other) const {
        return kelvin > other.kelvin;
    }

    bool operator==(const Temperature& other) const {
        return kelvin == other.kelvin;
    }

    bool operator!=(const Temperature& other) const {
        return kelvin != other.kelvin;
    }

    double operator<<(const Temperature& other) const {
        return kelvin;
    }

    Temperature operator+(const Temperature& other) const {
        double sum_kelvin = kelvin + other.kelvin;
        std::string kelvin_temp = "k" + std::to_string(sum_kelvin);
        return Temperature(kelvin_temp);
    }

    double to_kelvin() {
        return kelvin;
    }

    double to_fahrenheit() {
        return kelvin_to_fahrenheit(kelvin);
    }

    double to_celsius() {
        return kelvin_to_celsius(kelvin);
    }


    private:
        double kelvin;

    
};

int main() {
    Temperature temp1 ("c36.5");
    Temperature temp2 ("f97.7");
    Temperature temp3 ("k309.65");

    std::cout << "Temp1 in Fahrenheit: " << temp1.to_fahrenheit() << " f" << std::endl;
    std::cout << "Temp2 in Kelvin: " << temp2.to_kelvin() << " k" << std::endl;
    std::cout << "Temp3 in Celsius: " << temp3.to_celsius() << " C" << std::endl;

    Temperature sum_temp = temp1 + temp2 ;
    
    std::cout << "Sum of Temp1 and Temp2 in Kelvin: " << sum_temp.to_kelvin() << " K" << std::endl;

    
    if (temp1 > temp2) {
        std::cout << "Temp1 is greater than Temp2" << std::endl;
    }
    else {
        std::cout << "Temp1 is not greater than Temp2" << std::endl;
    }

    return 0;
}
