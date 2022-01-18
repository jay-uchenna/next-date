//
//  main.cpp
//  next date
//
//  Created by Jedidiah Uchenna on 18.01.2022.
//

#include <iostream>
#include <string>
#include <sstream>

std::string error_message(){
    return "invalid date entered\n";

}
bool leap_year_check(int& year){
    if(year%400 == 0 || (year % 4 == 0 && year % 100 != 0 )){
        return true;
    }
    else {
        return false;
    }
}
std::string get_next_day_date(int& day, int& month, int& year){

    if (year <= 0 || day < 0 || day > 31){
        return error_message();
    }
    int upper_limit = 0;
    switch(month){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
                upper_limit = 31;
                break;
        case 4:
        case 6:
        case 9:
        case 11:
                upper_limit = 30;
                break;
        case 2:
                if (leap_year_check(year)){
                    upper_limit = 29;
                }
                else{
                    upper_limit = 28;
                }
                break;
        default:
                return error_message();
                break;

    }
    if (day < upper_limit){
        day++;
    }
    else if (day == upper_limit){
        day = 1;
        if (month == 12){
            month = 1;
            year++;
        }
        else {
            month ++;
        }
    }
    else {
        return error_message();
    }

    std::ostringstream oss_next_date;
    oss_next_date << day << " " << month << " " << year << "\n";
    std::string next_date = oss_next_date.str();
    return next_date;

}



int main(){
     
     char try_again = '0';

     do{
            std::string date;
            
            int day = 0;
            std::cout << "enter day: ";
            std::cin >> day;

            int month = 0;
            std::cout << "enter month: ";
            std::cin >> month;

            int year = 0;
            std::cout << "enter year: ";
            std::cin >> year;
       
            std::cout << get_next_day_date(day, month, year);

            std::cout << "press y to try try_again: ";
            std::cin >> try_again;


     } while(try_again == 'y' || try_again == 'Y');

    return 0;
}
