#include <stdio.h>
#include <iostream>
#include "graphics.h"
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <ctime>
#pragma comment(lib,"graphics.lib")
#define _CRT_SECURE_NO_DEPRECATE
class driver {
private:
    std::string userName;
    std::string passWord;
    std::string birthDay;
    std::string numberCCCD;
    std::string numberDriver;
    std::string address;
    std::string email;
    std::string numberPhone;
    std::string timeRunGrab;
    std::string position;
public:
    int id;
    std::string fullName;
    void setupFirstDriver();
    void loadDriver(std::ifstream& readD);
    void saveDriver();
    void signUpDriver(std::vector<driver>& listDriver);
    bool checkLoginDriver(std::string& userName, std::string& passWord);
    void printInfoDriver(int x, int y);
    void editProfile(std::vector<driver> &listDriver);
    std::pair<int, int> getPosDriver();
};
void driver::setupFirstDriver() {
    driver::id = 0;
    driver::userName = "";
    driver::passWord = "";
    driver::fullName = "";
    driver::birthDay = "";
    driver::numberCCCD = "";
    driver::numberDriver = "";
    driver::address = "";
    driver::email = "";
    driver::numberPhone = "";
    driver::timeRunGrab = "";
    driver::position = "";
}
void driver::saveDriver() {
    std::ofstream saveD("dataDriver.txt", std::ios::out | std::ios::app);
    saveD << "id: " << driver::id << std::endl;
    saveD << driver::userName << std::endl;
    saveD << driver::passWord << std::endl;
    saveD << driver::fullName << std::endl;
    saveD << driver::birthDay << std::endl;
    saveD << driver::numberCCCD << std::endl;
    saveD << driver::numberDriver << std::endl;
    saveD << driver::address << std::endl;
    saveD << driver::email << std::endl;
    saveD << driver::numberPhone << std::endl;
    saveD << driver::timeRunGrab << std::endl;
    saveD << driver::position << std::endl;
}
void driver::loadDriver(std::ifstream &readD) {
    readD >> driver::id;
    readD >> driver::userName;
    readD >> driver::passWord;
    readD.ignore();
    getline(readD, driver::fullName);
    readD >> driver::birthDay;
    readD >> driver::numberCCCD;
    readD >> driver::numberDriver;
    readD.ignore();
    getline(readD, driver::address);
    readD >> driver::email;
    readD >> driver::numberPhone;
    readD >> driver::timeRunGrab;
    readD >> driver::position;
}
void driver::signUpDriver(std::vector<driver>& listDriver) {
    std::string userName = "";
    std::string passWord = "";
    std::string fullName = "";
    std::string birthDay = "";
    std::string numberCCCD = "";
    std::string numberDriver = "";
    std::string address = "";
    std::string email = "";
    std::string numberPhone = "";
    std::string timeRunGrab = "";
    std::string position = "";
    std::string hidePass = "";
    char t = ' ';
    outtextxy(20, 1, (char*)"Resgister");
    outtextxy(1, 20, (char*)"Username: ");
    outtextxy(1, 40, (char*)"Password: ");
    while (userName == "") {
        outtextxy(1, 20, (char*)"Username:                               ");
        while (int(t = getch()) != 13) {
            if (((t >= 'a') && (t <= 'z')) || ((t >= 'A' && t <= 'Z')) || ((t >= '0') && t <= '9'))
                userName += t;
            outtextxy(textwidth((char*)"Username:  "), 20, (char*)userName.c_str());
        }
        for (int i = 1; i < listDriver.size() - 1; i++)
            if (userName == listDriver[i].userName)
                userName = "";
    }
    while (passWord == "") {
        outtextxy(1, 40, (char*)"Password:      ");
        while (int(t = getch()) != 13) {
            if (int(t) >= 33 && int(t) <= 126) {
                passWord += t;
                hidePass += '*';
            }
            outtextxy(textwidth((char*)"Password:  "), 40, (char*)hidePass.c_str());
        }
    }
    cleardevice();
    outtextxy(20, 1, (char*)"Resgister");
    outtextxy(1, 20, (char*)"Fullname: ");
    outtextxy(1, 40, (char*)"Birth Day: ");
    outtextxy(1, 60, (char*)"Number CCCD: ");
    outtextxy(1, 80, (char*)"Number Driver: ");
    outtextxy(1, 100, (char*)"Address: ");
    outtextxy(1, 120, (char*)"Email: ");
    outtextxy(1, 140, (char*)"Number Phone: ");
    outtextxy(1, 160, (char*)"Time run grab: ");
    outtextxy(1, 180, (char*)"Position: ");
    while (fullName == "") {
        outtextxy(1, 20, (char*)"Fullname: ");
        while (int(t = getch()) != 13) {
            fullName = ' ' + fullName;
            if (t == ' ' && fullName.back() == ' ')
                goto next;
            if (t == ' ' && fullName.back() != ' ') {
                fullName += t;
                goto next;
            }
            if ((t >= 'a' && t <= 'z' && fullName.back() == ' ')) {
                t -= 32;
                fullName += t;
            }
            else
                if (t >= 'A' && t <= 'Z' && fullName.back() == ' ') {
                    fullName += t;
                }
                else
                    if (t >= 'a' && t <= 'z' && ((fullName.back() >= 'a' && fullName.back() <= 'z') || (fullName.back() >= 'A' && fullName.back() <= 'Z'))) {
                        fullName += t;
                    }
                    else
                        if (t >= 'A' && t <= 'Z' && fullName.back() >= 'a' && fullName.back() <= 'z') {
                            t += 32;
                            fullName += t;
                        }
        next:
            fullName.erase(0, 1);
            outtextxy(textwidth((char*)"Fullname:  "), 20, (char*)fullName.c_str());
        }
    }
    while (birthDay == "") {
        outtextxy(1, 40, (char*)"Birth Day:                    ");
        while (int(t = getch()) != 13) {
            if ((t >= '0') && (t <= '9') || (t == '/'))
                birthDay += t;
            outtextxy(textwidth((char*)"Birth Day:  "), 40, (char*)birthDay.c_str());
        }
        if (birthDay.size() < 5) {
            birthDay = "";
            continue;
        }
        if (birthDay[1] == '/')
            birthDay = '0' + birthDay;
        if (birthDay[4] == '/')
            birthDay.insert(3, "0");
        if ((birthDay[0] == '0' && birthDay[1] == '0') || (birthDay[3] == '0' && birthDay[4] == '0') || birthDay.size() != 10 || birthDay[2] != '/' || birthDay[5] != '/') {
            birthDay = "";
            continue;
        }
        std::string dd = "";
        std::string mm = "";
        std::string yyyy = "";
        dd += birthDay[0]; dd += birthDay[1];
        mm += birthDay[3]; mm += birthDay[4];
        yyyy += birthDay[6]; yyyy += birthDay[7]; yyyy += birthDay[8]; yyyy += birthDay[9];
        if (dd > "31" || mm > "12") {
            birthDay = "";
            continue;
        }
        if ((stoi(yyyy) % 4 == 0) && (mm == "02") && (dd > "29")) {
            birthDay = "";
            continue;
        }
        if ((stoi(yyyy) % 4 != 0) && (mm == "02") && (dd > "28")) {
            birthDay = "";
            continue;
        }
        if (((mm == "01") || (mm == "03") || (mm == "05") || (mm == "07") || (mm == "08") || (mm == "10") || (mm == "12")) && (dd > "31")) {
            birthDay = "";
            continue;
        }
        if (((mm == "04") || (mm == "06") || (mm == "09") || (mm == "11")) && (dd > "30")) {
            birthDay = "";
            continue;
        }
    }
    while (numberCCCD == "") {
        outtextxy(1, 60, (char*)"Number CCCD:                                   ");
        while (int(t = getch()) != 13)
            if (t >= '0' && t <= '9') {
                numberCCCD += t;
                outtextxy(textwidth((char*)"Number CCCD:  "), 60, (char*)numberCCCD.c_str());
            }
        if (numberCCCD.size() != 12)
            numberCCCD = "";
    }
    while (numberDriver == "") {
        outtextxy(1, 80, (char*)"Number Driver:                                   ");
        while (int(t = getch()) != 13)
            if (t >= '0' && t <= '9') {
                numberDriver += t;
                outtextxy(textwidth((char*)"Number Driver:  "), 80, (char*)numberDriver.c_str());
            }
        if (numberDriver.size() != 12)
            numberDriver = "";
    }
    while (address == "") {
        outtextxy(1, 100, (char*)"Address: ");
        while (int(t = getch()) != 13) {
            address = ' ' + address;
            if (t == ' ' && address.back() == ' ') {
                address.erase(0, 1);
                outtextxy(textwidth((char*)"Fullname:  "), 100, (char*)address.c_str());
                continue;
            }
            if (t == ',' && address.back() == ',') {
                address.erase(0, 1);
                outtextxy(textwidth((char*)"Fullname:  "), 100, (char*)address.c_str());
                continue;
            }
            if (t == ' ' && address.back() != ' ') {
                address += t;
                address.erase(0, 1);
                outtextxy(textwidth((char*)"Fullname:  "), 100, (char*)address.c_str());
                continue;
            }
            if (t == ',' && address.back() != ',' && address.size() > 1) {
                address += t;
                address.erase(0, 1);
                outtextxy(textwidth((char*)"Fullname:  "), 100, (char*)address.c_str());
                continue;
            }
        
            if (((t >= 'a' && t <= 'z') || (t >= 'A' && t <= 'Z') || (t >= '0' && t <= '9')) && address.back() == ',')
                address += ' ';
            if (t >= '0' && t <= '9') {
                address += t;
                address.erase(0, 1);
                outtextxy(textwidth((char*)"Fullname:  "), 100, (char*)address.c_str());
                continue;
            }
            if ((t >= 'a' && t <= 'z' && address.back() == ' ')) {
                t -= 32;
                address += t;
            }
            else
                if (t >= 'A' && t <= 'Z' && address.back() == ' ') {
                    address += t;
                }
                else
                    if (t >= 'a' && t <= 'z' && ((address.back() >= 'a' && address.back() <= 'z') || (address.back() >= 'A' && address.back() <= 'Z'))) {
                        address += t;
                    }
                    else
                        if (t >= 'A' && t <= 'Z' && address.back() >= 'a' && address.back() <= 'z') {
                            t += 32;
                            address += t;
                        }
            address.erase(0, 1);
            outtextxy(textwidth((char*)"Fullname:  "), 100, (char*)address.c_str());
        }

    }
    while (email == "") {
        outtextxy(1, 120, (char*)"Email:                                                 ");
        while (int(t = getch()) != 13) {
            if ((t >= 'a' && t <= 'z') || (t >= 'A' && t <= 'Z') || (t >= '0' && t <= '9') || (t == '@') || (t == '-') || (t == '_') || (t == '.')) {
                email += t;
                outtextxy(textwidth((char*)"Email:  "), 120, (char*)email.c_str());
            }
        }
        std::vector<std::vector<int>> pos(2);
        for (int i = 0; i < email.size(); i++)
            if (email[i] == '@')
                pos[0].push_back(i);
            else
                if (email[i] == '.')
                    pos[1].push_back(i);
        if (pos[0].size() != 1 || pos[1].size() == 0 || pos[0].back() > pos[1].back() || pos[1].back() == email.size() - 1)
            email = "";
    }
    while (numberPhone == "") {
        outtextxy(1, 140, (char*)"Number Phone:                             ");
        while (int(t = getch()) != 13) {
            if (t >= '0' && t <= '9') {
                numberPhone += t;
                outtextxy(textwidth((char*)"Number Phone:  "), 140, (char*)numberPhone.c_str());
            }
        }
        if (numberPhone.size() != 10 || numberPhone[0] != '0')
            numberPhone = "";
    }
    while (timeRunGrab == "") {
        outtextxy(1, 160, (char*)"Time run grab:                        ");
        while (int(t = getch()) != 13) {
            if ((t >= '0') && (t <= '9') || (t == '/'))
                timeRunGrab += t;
            outtextxy(textwidth((char*)"Time run grab:  "), 160, (char*)timeRunGrab.c_str());
        }
        if (timeRunGrab.size() < 5) {
            timeRunGrab = "";
            continue;
        }
        if (timeRunGrab[1] == '/')
            timeRunGrab = '0' + timeRunGrab;
        if (timeRunGrab[4] == '/')
            timeRunGrab.insert(3, "0");
        if ((timeRunGrab[0] == '0' && timeRunGrab[1] == '0') || (timeRunGrab[3] == '0' && timeRunGrab[4] == '0') || timeRunGrab.size() != 10 || timeRunGrab[2] != '/' || timeRunGrab[5] != '/') {
            timeRunGrab = "";
            continue;
        }
        std::string dd = "";
        std::string mm = "";
        std::string yyyy = "";
        dd += timeRunGrab[0]; dd += timeRunGrab[1];
        mm += timeRunGrab[3]; mm += timeRunGrab[4];
        yyyy += timeRunGrab[6]; yyyy += timeRunGrab[7]; yyyy += timeRunGrab[8]; yyyy += timeRunGrab[9];
        if (dd > "31" || mm > "12") {
            timeRunGrab = "";
            continue;
        }
        if ((stoi(yyyy) % 4 == 0) && (mm == "02") && (dd > "29")) {
            timeRunGrab = "";
            continue;
        }
        if ((stoi(yyyy) % 4 != 0) && (mm == "02") && (dd > "28")) {
            timeRunGrab = "";
            continue;
        }
        if (((mm == "01") || (mm == "03") || (mm == "05") || (mm == "07") || (mm == "08") || (mm == "10") || (mm == "12")) && (dd > "31")) {
            timeRunGrab = "";
            continue;
        }
        if (((mm == "04") || (mm == "06") || (mm == "09") || (mm == "11")) && (dd > "30")) {
            timeRunGrab = "";
            continue;
        }
    }
    while (position == "") {
        outtextxy(1, 180, (char*)"Position:                                     ");
        std::pair<bool, int> check = { false,-1 };
        while (int(t = getch()) != 13) {
            if (t == '(')
                if (position.size() == 0) {
                    position += t;
                    outtextxy(textwidth((char*)"Position:  "), 180, (char*)position.c_str());
                    continue;
                }
                else
                    continue;
            if (position.size() == 0)
                continue;
            if (position.back() == ')')
                continue;
            if (t == ',')
                if (position.back() >= '0' && position.back() <= '9' && check.first == false) {
                    check.first = true;
                    check.second = position.size();
                    position += t;
                    outtextxy(textwidth((char*)"Position:  "), 180, (char*)position.c_str());
                    continue;
                }
                else
                    continue;
            if (t == ')')
                if (position.back() >= '0' && position.back() <= '9') {
                    position += t;
                    outtextxy(textwidth((char*)"Position:  "), 180, (char*)position.c_str());
                }
            if ((t >= '0' && t <= '9')) {
                position += t;
                outtextxy(textwidth((char*)"Position:  "), 180, (char*)position.c_str());
            }
            if (t == '-')
                if (position.size() > 0)
                    if (position.back() == '(' || position.back() == ',') {
                        position += t;
                        outtextxy(textwidth((char*)"Position:  "), 180, (char*)position.c_str());
                    }
        }
        if (position.size() == 0)
            continue;
        if (position[0] != '(' || position.back() != ')') {
            position = "";
            continue;
        }
        if (check.first == false) {
            position = "";
            continue;
        }
    }
    driver::id = listDriver[listDriver.size() - 2].id + 1;
    driver::userName = userName;
    driver::passWord = passWord;
    driver::fullName = fullName;
    driver::birthDay = birthDay;
    driver::numberCCCD = numberCCCD;
    driver::numberDriver = numberDriver;
    driver::address = address;
    driver::email = email;
    driver::numberPhone = numberPhone;
    driver::timeRunGrab = timeRunGrab;
    driver::position = position;
    driver::saveDriver();
}
void driver::printInfoDriver(int x, int y) {
    outtextxy(x, y, (char*)"Found Driver:");
    outtextxy(x, y + 20, (char*)"Name: ");
    outtextxy(x + textwidth((char*)"Name:  "), y + 20, (char*)driver::fullName.c_str());
    outtextxy(x, y + 40, (char*)"Birth Day: ");
    outtextxy(x + textwidth((char*)"Birth Day:  "), y + 40, (char*)driver::birthDay.c_str());
    outtextxy(x, y + 60, (char*)"Position Driver: ");
    outtextxy(x + textwidth((char*)"Position Driver:  "), y + 60, (char*)driver::position.c_str());
    outtextxy(x, y + 80, (char*)"Have good day <3");
}
bool driver::checkLoginDriver(std::string& userName, std::string& passWord) {
    if (driver::userName == userName && driver::passWord == passWord)
        return true;
    return false;
}
void driver::editProfile(std::vector<driver> &listDriver) {
loopSeven:
    std::string userName = "";
    std::string passWord = "";
    std::string fullName = "";
    std::string birthDay = "";
    std::string numberCCCD = "";
    std::string numberDriver = "";
    std::string address = "";
    std::string email = "";
    std::string numberPhone = "";
    std::string position = "";
    std::string hidePass = "";
    outtextxy(20, 1, (char*)"Edit Profile Driver");
    outtextxy(1, 20, (char*)"0. Edit Username");
    outtextxy(1, 40, (char*)"1. Edit Password");
    outtextxy(1, 60, (char*)"2. Edit Full Name");
    outtextxy(1, 80, (char*)"3. Edit Birth Day");
    outtextxy(1, 100, (char*)"4. Edit Number CCCD");
    outtextxy(1, 120, (char*)"5. Edit Number Driver");
    outtextxy(1, 140, (char*)"6. Edit Address");
    outtextxy(1, 160, (char*)"7. Edit Email");
    outtextxy(1, 180, (char*)"8. Edit Number Phone");
    outtextxy(1, 200, (char*)"9. Edit Position");
    outtextxy(1, 220, (char*)"b. Go back");
    char l, t;
    l = getch();
    if (l < '0' && l > '9' && l != 'b')
        goto loopSeven;
    cleardevice();
    if (l == '0') {
        outtextxy(20, 1, (char*)"Edit Profile Driver");
        while (userName == "") {
            outtextxy(1, 20, (char*)"Username:                               ");
            while (int(t = getch()) != 13) {
                if (((t >= 'a') && (t <= 'z')) || ((t >= 'A' && t <= 'Z')) || ((t >= '0') && t <= '9'))
                    userName += t;
                outtextxy(textwidth((char*)"Username:  "), 20, (char*)userName.c_str());
            }
            for (int i = 1; i < listDriver.size() - 1; i++)
                if (userName == listDriver[i].userName)
                    userName = "";
        }
        driver::userName = userName;
    }
    if (l == '1') {
        outtextxy(20, 1, (char*)"Edit Profile Driver");
        while (passWord == "") {
            outtextxy(1, 20, (char*)"Password:      ");
            while (int(t = getch()) != 13) {
                if (int(t) >= 33 && int(t) <= 126) {
                    passWord += t;
                    hidePass += '*';
                }
                outtextxy(textwidth((char*)"Password:  "), 20, (char*)hidePass.c_str());
            }
        }
        driver::passWord = passWord;
    }
    if (l == '2') {
        outtextxy(20, 1, (char*)"Edit Profile Driver");
        while (fullName == "") {
            outtextxy(1, 20, (char*)"Fullname: ");
            while (int(t = getch()) != 13) {
                fullName = ' ' + fullName;
                if (t == ' ' && fullName.back() == ' ')
                    goto next;
                if (t == ' ' && fullName.back() != ' ') {
                    fullName += t;
                    goto next;
                }
                if ((t >= 'a' && t <= 'z' && fullName.back() == ' ')) {
                    t -= 32;
                    fullName += t;
                }
                else
                    if (t >= 'A' && t <= 'Z' && fullName.back() == ' ') {
                        fullName += t;
                    }
                    else
                        if (t >= 'a' && t <= 'z' && ((fullName.back() >= 'a' && fullName.back() <= 'z') || (fullName.back() >= 'A' && fullName.back() <= 'Z'))) {
                            fullName += t;
                        }
                        else
                            if (t >= 'A' && t <= 'Z' && fullName.back() >= 'a' && fullName.back() <= 'z') {
                                t += 32;
                                fullName += t;
                            }
            next:
                fullName.erase(0, 1);
                outtextxy(textwidth((char*)"Fullname:  "), 20, (char*)fullName.c_str());
            }
        }
        driver::fullName = fullName;
    }
    if (l == '3') {
        outtextxy(20, 1, (char*)"Edit Profile Driver");
        while (birthDay == "") {
            outtextxy(1, 20, (char*)"Birth Day:                    ");
            while (int(t = getch()) != 13) {
                if ((t >= '0') && (t <= '9') || (t == '/'))
                    birthDay += t;
                outtextxy(textwidth((char*)"Birth Day:  "), 20, (char*)birthDay.c_str());
            }
            if (birthDay.size() < 5) {
                birthDay = "";
                continue;
            }
            if (birthDay[1] == '/')
                birthDay = '0' + birthDay;
            if (birthDay[4] == '/')
                birthDay.insert(3, "0");
            if ((birthDay[0] == '0' && birthDay[1] == '0') || (birthDay[3] == '0' && birthDay[4] == '0') || birthDay.size() != 10 || birthDay[2] != '/' || birthDay[5] != '/') {
                birthDay = "";
                continue;
            }
            std::string dd = "";
            std::string mm = "";
            std::string yyyy = "";
            dd += birthDay[0]; dd += birthDay[1];
            mm += birthDay[3]; mm += birthDay[4];
            yyyy += birthDay[6]; yyyy += birthDay[7]; yyyy += birthDay[8]; yyyy += birthDay[9];
            if (dd > "31" || mm > "12") {
                birthDay = "";
                continue;
            }
            if ((stoi(yyyy) % 4 == 0) && (mm == "02") && (dd > "29")) {
                birthDay = "";
                continue;
            }
            if ((stoi(yyyy) % 4 != 0) && (mm == "02") && (dd > "28")) {
                birthDay = "";
                continue;
            }
            if (((mm == "01") || (mm == "03") || (mm == "05") || (mm == "07") || (mm == "08") || (mm == "10") || (mm == "12")) && (dd > "31")) {
                birthDay = "";
                continue;
            }
            if (((mm == "04") || (mm == "06") || (mm == "09") || (mm == "11")) && (dd > "30")) {
                birthDay = "";
                continue;
            }
        }
        driver::birthDay = birthDay;
    }
    if (l == '4') {
        outtextxy(20, 1, (char*)"Edit Profile Driver");
        while (numberCCCD == "") {
            outtextxy(1, 20, (char*)"Number CCCD:                                   ");
            while (int(t = getch()) != 13)
                if (t >= '0' && t <= '9') {
                    numberCCCD += t;
                    outtextxy(textwidth((char*)"Number CCCD:  "), 20, (char*)numberCCCD.c_str());
                }
            if (numberCCCD.size() != 12)
                numberCCCD = "";
        }
        driver::numberCCCD = numberCCCD;
    }
    if (l == '5') {
        outtextxy(20, 1, (char*)"Edit Profile Driver");
        while (numberDriver == "") {
            outtextxy(1, 20, (char*)"Number Driver:                                   ");
            while (int(t = getch()) != 13)
                if (t >= '0' && t <= '9') {
                    numberDriver += t;
                    outtextxy(textwidth((char*)"Number Driver:  "), 20, (char*)numberDriver.c_str());
                }
            if (numberDriver.size() != 12)
                numberDriver = "";
        }
        driver::numberDriver = numberDriver;
    }
    if (l == '6') {
        outtextxy(20, 1, (char*)"Edit Profile Driver");
        while (address == "") {
            outtextxy(1, 20, (char*)"Address: ");
            while (int(t = getch()) != 13) {
                address = ' ' + address;
                if (t == ' ' && address.back() == ' ') {
                    address.erase(0, 1);
                    outtextxy(textwidth((char*)"Fullname:  "), 20, (char*)address.c_str());
                    continue;
                }
                if (t == ',' && address.back() == ',') {
                    address.erase(0, 1);
                    outtextxy(textwidth((char*)"Fullname:  "), 20, (char*)address.c_str());
                    continue;
                }
                if (t == ' ' && address.back() != ' ') {
                    address += t;
                    address.erase(0, 1);
                    outtextxy(textwidth((char*)"Fullname:  "), 20, (char*)address.c_str());
                    continue;
                }
                if (t == ',' && address.back() != ',' && address.size() > 1) {
                    address += t;
                    address.erase(0, 1);
                    outtextxy(textwidth((char*)"Fullname:  "), 20, (char*)address.c_str());
                    continue;
                }

                if (((t >= 'a' && t <= 'z') || (t >= 'A' && t <= 'Z') || (t >= '0' && t <= '9')) && address.back() == ',')
                    address += ' ';
                if (t >= '0' && t <= '9') {
                    address += t;
                    address.erase(0, 1);
                    outtextxy(textwidth((char*)"Fullname:  "), 20, (char*)address.c_str());
                    continue;
                }
                if ((t >= 'a' && t <= 'z' && address.back() == ' ')) {
                    t -= 32;
                    address += t;
                }
                else
                    if (t >= 'A' && t <= 'Z' && address.back() == ' ') {
                        address += t;
                    }
                    else
                        if (t >= 'a' && t <= 'z' && ((address.back() >= 'a' && address.back() <= 'z') || (address.back() >= 'A' && address.back() <= 'Z'))) {
                            address += t;
                        }
                        else
                            if (t >= 'A' && t <= 'Z' && address.back() >= 'a' && address.back() <= 'z') {
                                t += 32;
                                address += t;
                            }
                address.erase(0, 1);
                outtextxy(textwidth((char*)"Fullname:  "), 20, (char*)address.c_str());
            }

        }
        driver::address = address;
    }
    if (l == '7') {
        outtextxy(20, 1, (char*)"Edit Profile Driver");
        while (email == "") {
            outtextxy(1, 20, (char*)"Email:                                                 ");
            while (int(t = getch()) != 13) {
                if ((t >= 'a' && t <= 'z') || (t >= 'A' && t <= 'Z') || (t >= '0' && t <= '9') || (t == '@') || (t == '-') || (t == '_') || (t == '.')) {
                    email += t;
                    outtextxy(textwidth((char*)"Email:  "), 20, (char*)email.c_str());
                }
            }
            std::vector<std::vector<int>> pos(2);
            for (int i = 0; i < email.size(); i++)
                if (email[i] == '@')
                    pos[0].push_back(i);
                else
                    if (email[i] == '.')
                        pos[1].push_back(i);
            if (pos[0].size() != 1 || pos[1].size() == 0 || pos[0].back() > pos[1].back() || pos[1].back() == email.size() - 1)
                email = "";
        }
        driver::email = email;
    }
    if (l == '8') {
        outtextxy(20, 1, (char*)"Edit Profile Driver");
        while (numberPhone == "") {
            outtextxy(1, 20, (char*)"Number Phone:                             ");
            while (int(t = getch()) != 13) {
                if (t >= '0' && t <= '9') {
                    numberPhone += t;
                    outtextxy(textwidth((char*)"Number Phone:  "), 20, (char*)numberPhone.c_str());
                }
            }
            if (numberPhone.size() != 10 || numberPhone[0] != '0')
                numberPhone = "";
        }
        driver::numberPhone = numberPhone;
    }
    if (l == '9') {
        outtextxy(20, 1, (char*)"Edit Profile Driver");
        while (position == "") {
            outtextxy(1, 20, (char*)"Position:                                     ");
            std::pair<bool, int> check = { false,-1 };
            while (int(t = getch()) != 13) {
                if (t == '(')
                    if (position.size() == 0) {
                        position += t;
                        outtextxy(textwidth((char*)"Position:  "), 20, (char*)position.c_str());
                        continue;
                    }
                    else
                        continue;
                if (position.size() == 0)
                    continue;
                if (position.back() == ')')
                    continue;
                if (t == ',')
                    if (position.back() >= '0' && position.back() <= '9' && check.first == false) {
                        check.first = true;
                        check.second = position.size();
                        position += t;
                        outtextxy(textwidth((char*)"Position:  "), 20, (char*)position.c_str());
                        continue;
                    }
                    else
                        continue;
                if (t == ')')
                    if (position.back() >= '0' && position.back() <= '9') {
                        position += t;
                        outtextxy(textwidth((char*)"Position:  "), 20, (char*)position.c_str());
                    }
                if ((t >= '0' && t <= '9')) {
                    position += t;
                    outtextxy(textwidth((char*)"Position:  "), 20, (char*)position.c_str());
                }
                if (t == '-')
                    if (position.size() > 0)
                        if (position.back() == '(' || position.back() == ',') {
                            position += t;
                            outtextxy(textwidth((char*)"Position:  "), 20, (char*)position.c_str());
                        }
            }
            if (position.size() == 0)
                continue;
            if (position[0] != '(' || position.back() != ')') {
                position = "";
                continue;
            }
            if (check.first == false) {
                position = "";
                continue;
            }
        }
        driver::position = position;
    }
}
void readDataDriver(std::vector<driver>& listDriver) {
    std::ifstream readD("dataDriver.txt");
    std::string s = "";
    while (readD >> s) {
        if (s == "id:") {
            listDriver.push_back({});
            listDriver.back().loadDriver(readD);
        }
    }
}
void deleteOrEditAccountDriver(std::vector<driver>& listDriver, int& id, bool t, driver &Driver) {
    std::ofstream SaveD("dataDriver.txt");
    SaveD << "";
    for (int i = 1; i < listDriver.size(); i++)
        if (listDriver[i].id != id)
            listDriver[i].saveDriver();
        else
            if (t == true)
                Driver.saveDriver();
    listDriver.resize(1);
    readDataDriver(listDriver);
}
std::pair<int, int> driver::getPosDriver() {
    std::string pos = driver::position;
    std::pair<int, int> posDriver;
    std::pair<bool, bool> check = { false, false };
    pos.erase(0, 1);
    if (pos[0] == '-') {
        check.first = true;
        pos.erase(0, 1);
    }
    int value = 0;
    while (pos[0] != ',') {
        value = value * 10 + int(pos[0] - '0');
        pos.erase(0, 1);
    }
    posDriver.first = value;
    if (check.first == true)
        posDriver.first = -posDriver.first;
    pos.erase(0, 1);
    if (pos[0] == '-') {
        check.second = true;
        pos.erase(0, 1);
    }
    value = 0;
    while (pos[0] != ')') {
        value = value * 10 + int(pos[0] - '0');
        pos.erase(0, 1);
    }
    posDriver.second = value;
    if (check.second == true)
        posDriver.second = -posDriver.second;
    return posDriver;
}
driver loginEmployee(std::vector<driver>& listDriver) {
loop:
    outtextxy(20, 1, (char*)"Login");
    outtextxy(1, 20, (char*)"Username:                               ");
    outtextxy(1, 40, (char*)"Password:                               ");
    char t;
    std::string hidePass = "";
    std::string userName = "";
    std::string passWord = "";
    while (userName == "") {
        outtextxy(1, 20, (char*)"Username:                           ");
        while (int(t = getch()) != 13) {
            if (((t >= 'a') && (t <= 'z')) || ((t >= 'A' && t <= 'Z')) || ((t >= '0') && t <= '9'))
                userName += t;
            outtextxy(textwidth((char*)"Username:  "), 20, (char*)userName.c_str());
        }
    }
    while (passWord == "") {
        outtextxy(1, 40, (char*)"Password:                           ");
        while (int(t = getch()) != 13) {
            if (int(t) >= 33 && int(t) <= 126) {
                passWord += t;
                hidePass += '*';
            }
            outtextxy(textwidth((char*)"Password:  "), 40, (char*)hidePass.c_str());
        }
    }
    for (int i = 1; i < listDriver.size(); i++)
        if (listDriver[i].checkLoginDriver(userName, passWord))
            return listDriver[i];
    goto loop;
}
class customer {
private:
    std::string passWord;
    std::string fullName;
    std::string birthDay;
    std::string numberCCCD;
    std::string email;
    std::string numberPhone;
public:
    int id;
    std::string userName;
    void signUpCustomer(std::vector<customer> &listCustomer);
    void setupFirstCustomer();
    void saveCustomer();
    void loadCustomer(std::ifstream& readC);
    bool checkLoginCustomer(std::string& userName, std::string& passWord);
    void editProfile(std::vector<customer> &listCustomer);
};
void customer::setupFirstCustomer() {
    id = 0;
    userName = "-1";
    passWord = "-1";
    fullName = "";
    birthDay = "";
    numberCCCD = "";
    email = "";
    numberPhone = "";
}
void customer::saveCustomer() {
    std::ofstream saveC("dataCustomer.txt", std::ios::out | std::ios::app);
    saveC << "id: " << customer::id << std::endl;
    saveC << customer::userName << std::endl;
    saveC << customer::passWord << std::endl;
    saveC << customer::fullName << std::endl;
    saveC << customer::birthDay << std::endl;
    saveC << customer::numberCCCD << std::endl;
    saveC << customer::email << std::endl;
    saveC << customer::numberPhone << std::endl;
}
void customer::loadCustomer(std::ifstream &readC) {
    readC >> customer::id;
    readC >> customer::userName;
    readC >> customer::passWord;
    readC.ignore();
    getline(readC, customer::fullName);
    readC >> customer::birthDay;
    readC >> customer::numberCCCD;
    readC >> customer::email;
    readC >> customer::numberPhone;
}
void customer::signUpCustomer(std::vector<customer>& listCustomer) {

    std::string userName = "";
    std::string hidePass = "";
    std::string passWord = "";
    std::string fullName = "";
    std::string birthDay = "";
    std::string numberCCCD = "";
    std::string email = "";
    std::string numberPhone = "";
    char t = ' ';
    outtextxy(20, 1, (char*)"Resgister");
    outtextxy(1, 20, (char*)"Username: ");
    outtextxy(1, 40, (char*)"Password: ");
    while (userName == "") {
        outtextxy(1, 20, (char*)"Username:                               ");
        while (int(t = getch()) != 13) {
            if (((t >= 'a') && (t <= 'z')) || ((t >= 'A' && t <= 'Z')) || ((t >= '0') && t <= '9'))
                userName += t;
            outtextxy(textwidth((char*)"Username:  "), 20, (char*)userName.c_str());
        }
        for (int i = 1; i < listCustomer.size() - 1; i++)
            if (userName == listCustomer[i].userName)
                userName = "";
    }
    while (passWord == "") {
        outtextxy(1, 40, (char*)"Password:      ");
        while (int(t = getch()) != 13) {
            if (int(t) >= 33 && int(t) <= 126) {
                passWord += t;
                hidePass += '*';
            }
            outtextxy(textwidth((char*)"Password:  "), 40, (char*)hidePass.c_str());
        }
    }
    cleardevice();
    outtextxy(20, 1, (char*)"Resgister");
    outtextxy(1, 20, (char*)"Fullname: ");
    outtextxy(1, 40, (char*)"Birth Day: ");
    outtextxy(1, 60, (char*)"Number CCCD: ");
    outtextxy(1, 80, (char*)"Email: ");
    outtextxy(1, 100, (char*)"Number Phone: ");
    while (fullName == "") {
        outtextxy(1, 20, (char*)"Fullname: ");
        while (int(t = getch()) != 13) {
            fullName = ' ' + fullName;
            if (t == ' ' && fullName.back() == ' ')
                goto next;
            if (t == ' ' && fullName.back() != ' ') {
                fullName += t;
                goto next;
            }
            if ((t >= 'a' && t <= 'z' && fullName.back() == ' ')) {
                t -= 32;
                fullName += t;
            }
            else
                if (t >= 'A' && t <= 'Z' && fullName.back() == ' ') {
                    fullName += t;
                }
                else
                    if (t >= 'a' && t <= 'z' && ((fullName.back() >= 'a' && fullName.back() <= 'z') || (fullName.back() >= 'A' && fullName.back() <= 'Z'))) {
                        fullName += t;
                    }
                    else
                        if (t >= 'A' && t <= 'Z' && fullName.back() >= 'a' && fullName.back() <= 'z') {
                            t += 32;
                            fullName += t;
                        }
        next:
            fullName.erase(0, 1);
            outtextxy(textwidth((char*)"Fullname:  "), 20, (char*)fullName.c_str());
        }
    }
    while (birthDay == "") {
        outtextxy(1, 40, (char*)"Birth Day:                    ");
        while (int(t = getch()) != 13) {
            if ((t >= '0') && (t <= '9') || (t == '/'))
                birthDay += t;
            outtextxy(textwidth((char*)"Birth Day:  "), 40, (char*)birthDay.c_str());
        }
        if (birthDay.size() < 5) {
            birthDay = "";
            continue;
        }
        if (birthDay[1] == '/')
            birthDay = '0' + birthDay;
        if (birthDay[4] == '/')
            birthDay.insert(3, "0");
        if ((birthDay[0] == '0' && birthDay[1] == '0') || (birthDay[3] == '0' && birthDay[4] == '0') || birthDay.size() != 10 || birthDay[2] != '/' || birthDay[5] != '/') {
            birthDay = "";
            continue;
        }
        std::string dd = "";
        std::string mm = "";
        std::string yyyy = "";
        dd += birthDay[0]; dd += birthDay[1];
        mm += birthDay[3]; mm += birthDay[4];
        yyyy += birthDay[6]; yyyy += birthDay[7]; yyyy += birthDay[8]; yyyy += birthDay[9];
        if (dd > "31" || mm > "12") {
            birthDay = "";
            continue;
        }
        if ((stoi(yyyy) % 4 == 0) && (mm == "02") && (dd > "29")) {
            birthDay = "";
            continue;
        }
        if ((stoi(yyyy) % 4 != 0) && (mm == "02") && (dd > "28")) {
            birthDay = "";
            continue;
        }
        if (((mm == "01") || (mm == "03") || (mm == "05") || (mm == "07") || (mm == "08") || (mm == "10") || (mm == "12")) && (dd > "31")) {
            birthDay = "";
            continue;
        }
        if (((mm == "04") || (mm == "06") || (mm == "09") || (mm == "11")) && (dd > "30")) {
            birthDay = "";
            continue;
        }
    }
    while (numberCCCD == "") {
        outtextxy(1, 60, (char*)"Number CCCD:                                   ");
        while (int(t = getch()) != 13)
            if (t >= '0' && t <= '9') {
                numberCCCD += t;
                outtextxy(textwidth((char*)"Number CCCD:  "), 60, (char*)numberCCCD.c_str());
            }
        if (numberCCCD.size() != 12)
            numberCCCD = "";
    }
    while (email == "") {
        outtextxy(1, 80, (char*)"Email:                                                 ");
        while (int(t = getch()) != 13) {
            if ((t >= 'a' && t <= 'z') || (t >= 'A' && t <= 'Z') || (t >= '0' && t <= '9') || (t == '@') || (t == '-') || (t == '_') || (t == '.')) {
                email += t;
                outtextxy(textwidth((char*)"Email:  "), 80, (char*)email.c_str());
            }
        }
        std::vector<std::vector<int>> pos(2);
        for (int i = 0; i < email.size(); i++)
            if (email[i] == '@')
                pos[0].push_back(i);
            else
                if (email[i] == '.')
                    pos[1].push_back(i);
        if (pos[0].size() != 1 || pos[1].size() == 0 || pos[0].back() > pos[1].back() || pos[1].back() == email.size() - 1)
            email = "";
    }
    while (numberPhone == "") {
        outtextxy(1, 100, (char*)"Number Phone:                             ");
        while (int(t = getch()) != 13) {
            if (t >= '0' && t <= '9') {
                numberPhone += t;
                outtextxy(textwidth((char*)"Number Phone:  "), 100, (char*)numberPhone.c_str());
            }
        }
        if (numberPhone.size() != 10 || numberPhone[0] != '0')
            numberPhone = "";
    }
    customer::id = listCustomer[listCustomer.size() - 2].id + 1;
    customer::userName = userName;
    customer::passWord = passWord;
    customer::fullName = fullName;
    customer::birthDay = birthDay;
    customer::numberCCCD = numberCCCD;
    customer::email = email;
    customer::numberPhone = numberPhone;
    customer::saveCustomer();
}
bool customer::checkLoginCustomer(std::string& userName, std::string& passWord) {
    if (customer::userName == userName && customer::passWord == passWord)
        return true;
    return false;
}
void customer::editProfile(std::vector<customer> &listCustomer) {
loopSix:
    std::string userName = "";
    std::string hidePass = "";
    std::string passWord = "";
    std::string fullName = "";
    std::string birthDay = "";
    std::string numberCCCD = "";
    std::string email = "";
    std::string numberPhone = "";
    outtextxy(20, 1, (char*)"Edit Profile Customer");
    outtextxy(1, 20, (char*)"1. Edit Username");
    outtextxy(1, 40, (char*)"2. Edit Password");
    outtextxy(1, 60, (char*)"3. Edit Full Name");
    outtextxy(1, 80, (char*)"4. Edit Birth Day");
    outtextxy(1, 100, (char*)"5. Edit Number CCCD");
    outtextxy(1, 120, (char*)"6. Edit Email");
    outtextxy(1, 140, (char*)"7. Edit Number Phone");
    outtextxy(1, 160, (char*)"b. Go back");
    char l, t;
    l = getch();
    if (l < '1' && l > '7' && l != 'b')
        goto loopSix;
    cleardevice();
    if (l == '1') {
        outtextxy(20, 1, (char*)"Edit Profile Customer");
        while (userName == "") {
            outtextxy(1, 20, (char*)"Username:                               ");
            while (int(t = getch()) != 13) {
                if (((t >= 'a') && (t <= 'z')) || ((t >= 'A' && t <= 'Z')) || ((t >= '0') && t <= '9'))
                    userName += t;
                outtextxy(textwidth((char*)"Username:  "), 20, (char*)userName.c_str());
            }
            for (int i = 1; i < listCustomer.size() - 1; i++)
                if (userName == listCustomer[i].userName)
                    userName = "";
        }
        customer::userName = userName;
    }
    if (l == '2') {
        outtextxy(20, 1, (char*)"Edit Profile Customer");
        while (passWord == "") {
            outtextxy(1, 20, (char*)"Password:      ");
            while (int(t = getch()) != 13) {
                if (int(t) >= 33 && int(t) <= 126) {
                    passWord += t;
                    hidePass += '*';
                }
                outtextxy(textwidth((char*)"Password:  "), 20, (char*)hidePass.c_str());
            }
        }
        customer::passWord = passWord;
    }
    if (l == '3') {
        outtextxy(20, 1, (char*)"Edit Profile Customer");
        while (fullName == "") {
            outtextxy(1, 20, (char*)"Fullname: ");
            while (int(t = getch()) != 13) {
                fullName = ' ' + fullName;
                if (t == ' ' && fullName.back() == ' ')
                    goto next;
                if (t == ' ' && fullName.back() != ' ') {
                    fullName += t;
                    goto next;
                }
                if ((t >= 'a' && t <= 'z' && fullName.back() == ' ')) {
                    t -= 32;
                    fullName += t;
                }
                else
                    if (t >= 'A' && t <= 'Z' && fullName.back() == ' ') {
                        fullName += t;
                    }
                    else
                        if (t >= 'a' && t <= 'z' && ((fullName.back() >= 'a' && fullName.back() <= 'z') || (fullName.back() >= 'A' && fullName.back() <= 'Z'))) {
                            fullName += t;
                        }
                        else
                            if (t >= 'A' && t <= 'Z' && fullName.back() >= 'a' && fullName.back() <= 'z') {
                                t += 32;
                                fullName += t;
                            }
            next:
                fullName.erase(0, 1);
                outtextxy(textwidth((char*)"Fullname:  "), 20, (char*)fullName.c_str());
            }
        }
        customer::fullName = fullName;
    }
    if (l == '4') {
        outtextxy(20, 1, (char*)"Edit Profile Customer");
        while (birthDay == "") {
            outtextxy(1, 20, (char*)"Birth Day:                    ");
            while (int(t = getch()) != 13) {
                if ((t >= '0') && (t <= '9') || (t == '/'))
                    birthDay += t;
                outtextxy(textwidth((char*)"Birth Day:  "), 20, (char*)birthDay.c_str());
            }
            if (birthDay.size() < 5) {
                birthDay = "";
                continue;
            }
            if (birthDay[1] == '/')
                birthDay = '0' + birthDay;
            if (birthDay[4] == '/')
                birthDay.insert(3, "0");
            if ((birthDay[0] == '0' && birthDay[1] == '0') || (birthDay[3] == '0' && birthDay[4] == '0') || birthDay.size() != 10 || birthDay[2] != '/' || birthDay[5] != '/') {
                birthDay = "";
                continue;
            }
            std::string dd = "";
            std::string mm = "";
            std::string yyyy = "";
            dd += birthDay[0]; dd += birthDay[1];
            mm += birthDay[3]; mm += birthDay[4];
            yyyy += birthDay[6]; yyyy += birthDay[7]; yyyy += birthDay[8]; yyyy += birthDay[9];
            if (dd > "31" || mm > "12") {
                birthDay = "";
                continue;
            }
            if ((stoi(yyyy) % 4 == 0) && (mm == "02") && (dd > "29")) {
                birthDay = "";
                continue;
            }
            if ((stoi(yyyy) % 4 != 0) && (mm == "02") && (dd > "28")) {
                birthDay = "";
                continue;
            }
            if (((mm == "01") || (mm == "03") || (mm == "05") || (mm == "07") || (mm == "08") || (mm == "10") || (mm == "12")) && (dd > "31")) {
                birthDay = "";
                continue;
            }
            if (((mm == "04") || (mm == "06") || (mm == "09") || (mm == "11")) && (dd > "30")) {
                birthDay = "";
                continue;
            }
        }
        customer::birthDay = birthDay;
    }
    if (l == '5') {
        outtextxy(20, 1, (char*)"Edit Profile Customer");
        while (numberCCCD == "") {
            outtextxy(1, 20, (char*)"Number CCCD:                                   ");
            while (int(t = getch()) != 13)
                if (t >= '0' && t <= '9') {
                    numberCCCD += t;
                    outtextxy(textwidth((char*)"Number CCCD:  "), 20, (char*)numberCCCD.c_str());
                }
            if (numberCCCD.size() != 12)
                numberCCCD = "";
        }
        customer::numberCCCD = numberCCCD;
    }
    if (l == '6') {
        outtextxy(20, 1, (char*)"Edit Profile Customer");
        while (email == "") {
            outtextxy(1, 20, (char*)"Email:                                                 ");
            while (int(t = getch()) != 13) {
                if ((t >= 'a' && t <= 'z') || (t >= 'A' && t <= 'Z') || (t >= '0' && t <= '9') || (t == '@') || (t == '-') || (t == '_') || (t == '.')) {
                    email += t;
                    outtextxy(textwidth((char*)"Email:  "), 20, (char*)email.c_str());
                }
            }
            std::vector<std::vector<int>> pos(2);
            for (int i = 0; i < email.size(); i++)
                if (email[i] == '@')
                    pos[0].push_back(i);
                else
                    if (email[i] == '.')
                        pos[1].push_back(i);
            if (pos[0].size() != 1 || pos[1].size() == 0 || pos[0].back() > pos[1].back() || pos[1].back() == email.size() - 1)
                email = "";
        }
        customer::email = email;
    }
    if (l == '7') {
        outtextxy(20, 1, (char*)"Edit Profile Customer");
        while (numberPhone == "") {
            outtextxy(1, 20, (char*)"Number Phone:                             ");
            while (int(t = getch()) != 13) {
                if (t >= '0' && t <= '9') {
                    numberPhone += t;
                    outtextxy(textwidth((char*)"Number Phone:  "), 20, (char*)numberPhone.c_str());
                }
            }
            if (numberPhone.size() != 10 || numberPhone[0] != '0')
                numberPhone = "";
        }
        customer::numberPhone = numberPhone;
    }
}
void readDataCustomer(std::vector<customer>& listCustomer) {
    std::ifstream readC("dataCustomer.txt");
    std::string s = "";
    while (readC >> s) {
        if (s == "id:") {
            listCustomer.push_back({});
            listCustomer.back().loadCustomer(readC);
        }
    }
}
void deleteOrEditAccountCustomer(std::vector<customer>& listCustomer, int &id, bool t, customer &Customer) {
    std::ofstream SaveC("dataCustomer.txt");
    SaveC << "";
    for (int i = 1; i < listCustomer.size(); i++)
        if (listCustomer[i].id != id)
            listCustomer[i].saveCustomer();
        else
            if (t == true)
                Customer.saveCustomer();
    listCustomer.resize(1);
    readDataCustomer(listCustomer);
}
customer loginCustomer(std::vector<customer>& listCustomer) {
    loop:
    outtextxy(20, 1, (char*)"Login");
    outtextxy(1, 20, (char*)"Username:                               ");
    outtextxy(1, 40, (char*)"Password:                               ");
    char t;
    std::string hidePass = "";
    std::string userName = "";
    std::string passWord = "";
    while (userName == "") {
        outtextxy(1, 20, (char*)"Username:                           ");
        while (int(t = getch()) != 13) {
            if (((t >= 'a') && (t <= 'z')) || ((t >= 'A' && t <= 'Z')) || ((t >= '0') && t <= '9'))
                userName += t;
            outtextxy(textwidth((char*)"Username:  "), 20, (char*)userName.c_str());
        }
    }
    while (passWord == "") {
        outtextxy(1, 40, (char*)"Password:                           ");
        while (int(t = getch()) != 13) {
            if (int(t) >= 33 && int(t) <= 126) {
                passWord += t;
                hidePass += '*';
            }
            outtextxy(textwidth((char*)"Password:  "), 40, (char*)hidePass.c_str());
        }
    }
    for (int i = 1; i < listCustomer.size(); i++)
        if (listCustomer[i].checkLoginCustomer(userName, passWord))
            return listCustomer[i];
    goto loop;
}
class bookingCar {
    public:
        int idBookCar;
        int idCustomer;
        int idDriver;
        std::string nameCustomer;
        std::string timeBookCar;
        std::string fromPos;
        std::string toPos;
        void bookCar(customer &Customer, std::vector<driver>& listDriver, std::vector<bookingCar>& listBookCar, std::string timeBookCar);
        void setupFirstBookCar();
        void loadBookCar(std::ifstream& readB);
        void saveBookCar();
};
void bookingCar::setupFirstBookCar() {
    bookingCar::idBookCar = 0;
    bookingCar::nameCustomer = "";
    bookingCar::idCustomer = 0;
    bookingCar::idDriver = 0;
    bookingCar::timeBookCar = "";
    bookingCar::fromPos = "";
    bookingCar::toPos = "";
}
void bookingCar::saveBookCar() {
    std::ofstream saveB("dataBookCar.txt", std::ios::out | std::ios::app);
    saveB << "idBookCar: " << bookingCar::idBookCar << std::endl;
    saveB << bookingCar::idCustomer << std::endl;
    saveB << bookingCar::idDriver << std::endl;
    saveB << bookingCar::nameCustomer << std::endl;
    saveB << bookingCar::timeBookCar << std::endl;
    saveB << bookingCar::fromPos << std::endl;
    saveB << bookingCar::toPos << std::endl;
 
}
void bookingCar::loadBookCar(std::ifstream& readB) {
    readB >> bookingCar::idBookCar;
    readB >> bookingCar::idCustomer;
    readB >> bookingCar::idDriver;
    readB.ignore();
    getline(readB, bookingCar::nameCustomer);
    readB >> bookingCar::timeBookCar;
    readB >> bookingCar::fromPos;
    readB >> bookingCar::toPos;
}
void bookingCar::bookCar(customer &Customer, std::vector<driver>& listDriver, std::vector<bookingCar>& listBookCar, std::string timeBookCar) {
    cleardevice();
    outtextxy(20, 1, (char*)"Book Car");
    outtextxy(1, 20, (char*)"From Position: ");
    outtextxy(1, 40, (char*)"To Position: ");
    std::string fromPos = "";
    std::string toPos = "";
    char t;
    while (fromPos == "") {
        outtextxy(1, 20, (char*)"From Position:                                     ");
        std::pair<bool, int> check = { false,-1 };
        while (int(t = getch()) != 13) {
            if (t == '(')
                if (fromPos.size() == 0) {
                    fromPos += t;
                    outtextxy(textwidth((char*)"From Position:  "), 20, (char*)fromPos.c_str());
                    continue;
                }
                else
                    continue;
            if (fromPos.size() == 0)
                continue;
            if (fromPos.back() == ')')
                continue;
            if (t == ',')
                if (fromPos.back() >= '0' && fromPos.back() <= '9' && check.first == false) {
                    check.first = true;
                    check.second = fromPos.size();
                    fromPos += t;
                    outtextxy(textwidth((char*)"From Position:  "), 20, (char*)fromPos.c_str());
                    continue;
                }
                else
                    continue;
            if (t == ')')
                if (fromPos.back() >= '0' && fromPos.back() <= '9') {
                    fromPos += t;
                    outtextxy(textwidth((char*)"From Position:  "), 20, (char*)fromPos.c_str());
                }
            if ((t >= '0' && t <= '9')) {
                fromPos += t;
                outtextxy(textwidth((char*)"From Position:  "), 20, (char*)fromPos.c_str());
            }
            if (t == '-')
                if (fromPos.size() > 0)
                    if (fromPos.back() == '(' || fromPos.back() == ',') {
                        fromPos += t;
                        outtextxy(textwidth((char*)"From Position:  "), 20, (char*)fromPos.c_str());
                    }
        }
        if (fromPos.size() == 0)
            continue;
        if (fromPos[0] != '(' || fromPos.back() != ')') {
            fromPos = "";
            continue;
        }
        if (check.first == false) {
            fromPos = "";
            continue;
        }
    }
    while (toPos == "") {
        outtextxy(1, 40, (char*)"To Position:                                     ");
        std::pair<bool, int> check = { false,-1 };
        while (int(t = getch()) != 13) {
            if (t == '(')
                if (toPos.size() == 0) {
                    toPos += t;
                    outtextxy(textwidth((char*)"To Position:  "), 40, (char*)toPos.c_str());
                    continue;
                }
                else
                    continue;
            if (toPos.size() == 0)
                continue;
            if (toPos.back() == ')')
                continue;
            if (t == ',')
                if (toPos.back() >= '0' && toPos.back() <= '9' && check.first == false) {
                    check.first = true;
                    check.second = toPos.size();
                    toPos += t;
                    outtextxy(textwidth((char*)"To Position:  "), 40, (char*)toPos.c_str());
                    continue;
                }
                else
                    continue;
            if (t == ')')
                if (toPos.back() >= '0' && toPos.back() <= '9') {
                    toPos += t;
                    outtextxy(textwidth((char*)"To Position:  "), 40, (char*)toPos.c_str());
                }
            if ((t >= '0' && t <= '9')) {
                toPos += t;
                outtextxy(textwidth((char*)"To Position:  "), 40, (char*)toPos.c_str());
            }
            if (t == '-')
                if (toPos.size() > 0)
                    if (toPos.back() == '(' || toPos.back() == ',') {
                        toPos += t;
                        outtextxy(textwidth((char*)"To Position:  "), 40, (char*)toPos.c_str());
                    }
        }
        if (toPos.size() == 0)
            continue;
        if (toPos[0] != '(' || toPos.back() != ')') {
            toPos = "";
            continue;
        }
        if (check.first == false) {
            toPos = "";
            continue;
        }
    }
    if (listDriver.size() == 1) {
        outtextxy(50, 250, (char*)"The driver is busy");
        outtextxy(1, 60, (char*)"b. Go back");
        while (t = getch())
            if (t == 'b')
                return;
    }
    std::string copyFromPos = fromPos;
    std::pair<int, int> posCustomer;

    std::pair<bool, bool> check = { false, false };
    fromPos.erase(0, 1);
    if (fromPos[0] == '-') {
        check.first = true;
        fromPos.erase(0, 1);
    }
    int value = 0;
    while (fromPos[0] != ',') {
        value = value * 10 + int(fromPos[0] - '0');
        fromPos.erase(0, 1);
    }
    posCustomer.first = value;
    if (check.first == true)
        posCustomer.first = -posCustomer.first;
    fromPos.erase(0, 1);
    if (fromPos[0] == '-') {
        check.second = true;
        fromPos.erase(0, 1);
    }
    value = 0;
    while (fromPos[0] != ')') {
        value = value * 10 + int(fromPos[0] - '0');
        fromPos.erase(0, 1);
    }
    posCustomer.second = value;
    if (check.second == true)
        posCustomer.second = -posCustomer.second;

    std::pair<long long, driver> searchDriver = { 9223372036854775807, {}};
    for (int i = 1; i < listDriver.size(); i++) {
        std::pair<int, int> posDriver = listDriver[i].getPosDriver();
        long long distance = (static_cast<long long>(posCustomer.first) - posDriver.first) * (static_cast<long long>(posCustomer.first) - posDriver.first) + (static_cast<long long>(posCustomer.second) - posDriver.second) * (static_cast<long long>(posCustomer.second) - posDriver.second);
        if (distance < searchDriver.first) {
            searchDriver = { distance, listDriver[i] };
        } else 
            if (distance == searchDriver.first) {
                if (searchDriver.second.fullName > listDriver[i].fullName)
                    searchDriver = { distance, listDriver[i] };
            }
    }
    searchDriver.second.printInfoDriver(50, 250);
    bookingCar::idBookCar = listBookCar[listBookCar.size() - 2].idBookCar + 1;
    bookingCar::idCustomer = Customer.id;
    bookingCar::idDriver = searchDriver.second.id;
    bookingCar::nameCustomer = Customer.userName;
    bookingCar::timeBookCar = timeBookCar;
    bookingCar::fromPos = copyFromPos;
    bookingCar::toPos = toPos;
    bookingCar::saveBookCar();
    outtextxy(1, 60, (char*)"b. Go back");
    while (int(t = getch()) != 'b');
}
void readDataBookCar(std::vector<bookingCar>& listBookCar) {
    std::ifstream readB("dataBookCar.txt");
    std::string s = "";
    while (readB >> s) {
        if (s == "idBookCar:") {
            listBookCar.push_back({});
            listBookCar.back().loadBookCar(readB);
        }
    }
}
void searchRequest(std::vector<bookingCar>& listBookCar) {
    outtextxy(20, 1, (char*)"Requests Received From The Driver");
    outtextxy(1, 20, (char*)"ID driver: ");
    char t;
    std::string id = "";
    while (id == "") {
        while (int(t = getch()) != 13) {
            if (t >= '0' && t <= '9') {
                id += t;
                outtextxy(textwidth((char*)"Id driver:  "), 20, (char*)id.c_str());
            }
        }
    }
    int idDriver = stoi(id);
    int line = 0;
    std::cout << listBookCar.size();
    for (int i = listBookCar.size() - 1; i > 0; i--) {
        if (listBookCar[i].idDriver == idDriver) {
            outtextxy(240, 50 + line, (char*)"- ID Request: ");
            outtextxy(240 + textwidth((char*)"- ID Request:  "), 50 + line, (char*)(std::to_string(listBookCar[i].idBookCar).c_str()));
            outtextxy(250, 50 + line + 20, (char*)"   Time Request: ");
            outtextxy(250 + textwidth((char*)"   Time Request:  "), 50 + line + 20, (char*)listBookCar[i].timeBookCar.c_str());
            outtextxy(250, 50 + line + 40, (char*)"   ID Customer: ");
            outtextxy(250 + textwidth((char*)"   ID Customer:  "), 50 + line + 40, (char*)(std::to_string(listBookCar[i].idCustomer).c_str()));
            line += 60;
        };
    }
    if (line == 0) {
        outtextxy(250, 50, (char*)"Not Found!");
    }
    outtextxy(1, 40, (char*)"b. Go back");
    while ((t = getch()) != 'b');
}
void searchCustomerUseTheService(std::vector<bookingCar>& listBookCar) {
    outtextxy(20, 1, (char*)"Customers use the service");
    outtextxy(1, 20, (char*)"Time: ");
    std::string time = "";
    char t;
    while (time == "") {
        outtextxy(1, 20, (char*)"Time:                      ");
        while (int(t = getch()) != 13) {
            if ((t >= '0') && (t <= '9') || (t == '/'))
                time += t;
            outtextxy(textwidth((char*)"Time:  "), 20, (char*)time.c_str());
        }
        if (time.size() < 5) {
            time = "";
            continue;
        }
        if (time[1] == '/')
            time = '0' + time;
        if (time[4] == '/')
            time.insert(3, "0");
        if ((time[0] == '0' && time[1] == '0') || (time[3] == '0' && time[4] == '0') || time.size() != 10 || time[2] != '/' || time[5] != '/') {
            time = "";
            continue;
        }
        std::string dd = "";
        std::string mm = "";
        std::string yyyy = "";
        dd += time[0]; dd += time[1];
        mm += time[3]; mm += time[4];
        yyyy += time[6]; yyyy += time[7]; yyyy += time[8]; yyyy += time[9];
        if (dd > "31" || mm > "12") {
            time = "";
            continue;
        }
        if ((stoi(yyyy) % 4 == 0) && (mm == "02") && (dd > "29")) {
            time = "";
            continue;
        }
        if ((stoi(yyyy) % 4 != 0) && (mm == "02") && (dd > "28")) {
            time = "";
            continue;
        }
        if (((mm == "01") || (mm == "03") || (mm == "05") || (mm == "07") || (mm == "08") || (mm == "10") || (mm == "12")) && (dd > "31")) {
            time = "";
            continue;
        }
        if (((mm == "04") || (mm == "06") || (mm == "09") || (mm == "11")) && (dd > "30")) {
            time = "";
            continue;
        }
    }
    std::vector<std::pair<int, std::string>> listOne;
    std::vector<std::pair<std::string, std::pair<int, int>>> listTwo;
    for (int i = 1; i < listBookCar.size(); i++)
        if (time == listBookCar[i].timeBookCar)
            listOne.push_back({ listBookCar[i].idCustomer, listBookCar[i].nameCustomer });
    if (listOne.size() != 0) {
        for (int i = 0; i < listOne.size() - 1; i++)
            for (int j = i + 1; j < listOne.size(); j++)
                if (listOne[i].first > listOne[j].first)
                    swap(listOne[i], listOne[j]);
        listOne.push_back({ -1, "" });
        int cur = 1;
        for (int i = 1; i < listOne.size(); i++) {
            if (listOne[i].first == listOne[i - 1].first)
                cur++;
            else {
                listTwo.push_back({ listOne[i - 1].second, {cur, listOne[i - 1].first} });
                cur = 1;
            }
        }
        for (int i = 0; i < listTwo.size() - 1; i++)
            for (int j = i + 1; j < listTwo.size(); j++)
                if (listTwo[i].second.first < listTwo[j].second.first)
                    swap(listTwo[i], listTwo[j]);
    }
    if (listOne.size() == 0)
        outtextxy(250, 50, (char*)"Not Found!");
    else {
        int line = 0;
        for (int i = 0; i < listTwo.size(); i++) {
            outtextxy(240, 50 + line, (char*)"- ID Customer: ");
            outtextxy(240 + textwidth((char*)"- ID Customer:  "), 50 + line, (char*)(std::to_string(listTwo[i].second.second).c_str()));
            outtextxy(250, 50 + line + 20, (char*)"Name: ");
            outtextxy(250 + textwidth((char*)"Name:  "), 50 + line + 20, (char*)listTwo[i].first.c_str());
            outtextxy(250, 50 + line + 40, (char*)"Use Times: ");    
            outtextxy(250 + textwidth((char*)"Use Times:  "), 50 + line + 40, (char*)(std::to_string(listTwo[i].second.first).c_str()));
            line += 60;
        }
    }
    outtextxy(1, 40, (char*)"b. Go back");
    while ((t = getch()) != 'b');
};
void searchPlace(std::vector<bookingCar>& listBookCar) {
    outtextxy(250, 50, (char*)"Favorite Place:");
    std::vector<std::string> placeOne;
    std::vector<std::pair<std::string, int>> placeTwo;
    int line = 30;
    char t;
    for (int i = 1; i < listBookCar.size(); i++) {
        placeOne.push_back(listBookCar[i].toPos);
    }
    if (placeOne.size() == 0) {
        outtextxy(250, 50 + line, (char*)"Not Found!");
        line += 30;
    } else {
        for (int i = 0; i < placeOne.size() - 1; i++)
            for (int j = i + 1; j < placeOne.size(); j++)
                if (placeOne[i] > placeOne[j])
                    swap(placeOne[i], placeOne[j]);
        int cur = 1;
        placeOne.push_back("-1");
        for (int i = 1; i < placeOne.size(); i++)
            if (placeOne[i] == placeOne[i - 1])
                cur++;
            else {
                placeTwo.push_back({ placeOne[i - 1], cur });
                cur = 1;
            }
        for (int i = 0; i < placeTwo.size() - 1; i++)
            for (int j = i + 1; j < placeTwo.size(); j++)
                if (placeTwo[i].second < placeTwo[j].second)
                    swap(placeTwo[i], placeTwo[j]);
        for (int i = 0; i < placeTwo.size(); i++) {
            outtextxy(250, 50 + line, (char*)placeTwo[i].first.c_str());
            line += 20;
        }
    }
    outtextxy(250, 50 + line, (char*)"b. Go back");
    while ((t = getch()) != 'b');
}
void service(std::vector<customer> &listCustomer, std::vector<driver> &listDriver, std::vector<bookingCar> &listBookCar) {
    loopp:
    cleardevice();
    outtextxy(20, 1, (char*)"Welcome: ");
    outtextxy(1, 20, (char*)"1. Customer");
    outtextxy(1, 40, (char*)"2. Driver");
    outtextxy(1, 60, (char*)"3. Statistics");
    outtextxy(1, 80, (char*)"e. Exit");
    char Service = getch();
    if (Service != '1' && Service != '2' && Service != 'e' && Service != '3')
        goto loopp;
    if (Service == 'e')
        return;
    if (Service == '1') {
        loopOne:
        cleardevice();
        outtextxy(20, 1, (char*)"Customer");
        outtextxy(1, 20, (char*)"1. LogIn");
        outtextxy(1, 40, (char*)"2. SignUp");
        outtextxy(1, 60, (char*)"b. Go back");
        Service = getch();
        if (Service != '1' && Service != '2' && Service != 'b')
            goto loopOne;
        cleardevice();
        if (Service == 'b')
            goto loopp;
        
        if (Service == '1') {
            customer Customer = loginCustomer(listCustomer);
            loopThree:
            cleardevice();
            outtextxy(20, 1, (char*)"Customer");
            outtextxy(1, 20, (char*)"1. Book car");
            outtextxy(1, 40, (char*)"2. Edit Profile");
            outtextxy(1, 60, (char*)"3. Delete Account");
            outtextxy(1, 80, (char*)"b. Go back");
            Service = getch();
            if (Service != '1' && Service != 'b' && Service != '2' && Service != '3')
                goto loopThree;
            if (Service == 'b')
                goto loopOne;
            if (Service == '1') {
                char timeBookCar[80];
                time_t t = time(0);
                strftime(timeBookCar, 80, "%d/%m/%Y", localtime(&t));
                std::string time = "";
                for (int i = 0; i < 10; i++)
                    time += timeBookCar[i];
                listBookCar.resize(listBookCar.size() + 1);
                listBookCar.back().bookCar(Customer, listDriver, listBookCar, time);
                goto loopThree;
            }
            if (Service == '2') {
                cleardevice();
                Customer.editProfile(listCustomer);
                deleteOrEditAccountCustomer(listCustomer, Customer.id, true, Customer);
                goto loopThree;
            }
            if (Service == '3') {
                cleardevice();
                deleteOrEditAccountCustomer(listCustomer, Customer.id, false, Customer);
                goto loopOne;
            }
        } 
        if (Service == '2') {
            listCustomer.resize(listCustomer.size() + 1);
            listCustomer.back().signUpCustomer(listCustomer);
            goto loopOne;
        }
    } 
    if (Service == '2') {
        loopTwo:
        cleardevice();
        outtextxy(20, 1, (char*)"Driver");
        outtextxy(1, 20, (char*)"1. LogIn");
        outtextxy(1, 40, (char*)"2. SignUp");
        outtextxy(1, 60, (char*)"b. Go back");
        Service = getch();
        if (Service != '1' && Service != '2' && Service != 'b')
            goto loopTwo;
        cleardevice();
        if (Service == 'b')
            goto loopp;
        if (Service == '1') {
            driver Driver = loginEmployee(listDriver);
            loopFive:
            cleardevice();
            outtextxy(20, 1, (char*)"Driver");
            outtextxy(1, 20, (char*)"1. Edit Profile");
            outtextxy(1, 40, (char*)"2. Delete Account");
            outtextxy(1, 60, (char*)"b. Go back");
            Service = getch();
            if (Service != '1' && Service != '2' && Service != 'b')
                goto loopFive;
            if (Service == 'b')
                goto loopTwo;
            if (Service == '1') {
                cleardevice();
                Driver.editProfile(listDriver);
                deleteOrEditAccountDriver(listDriver, Driver.id, true, Driver);
                goto loopFive;
            }
            if (Service == '2') {
                cleardevice();
                deleteOrEditAccountDriver(listDriver, Driver.id, false, Driver);
                goto loopTwo;
            }
        }
        if (Service == '2') {
            listDriver.resize(listDriver.size() + 1);
            listDriver.back().signUpDriver(listDriver);
            goto loopTwo;
        }
    } 
    if (Service == '3') {
        loopFour:
        cleardevice();
        outtextxy(20, 1, (char*)"Statistics");
        outtextxy(1, 20, (char*)"1. Requests Received From The Driver");
        outtextxy(1, 40, (char*)"2. Customers Use The Service");
        outtextxy(1, 60, (char*)"3. Favorite Place");
        outtextxy(1, 80, (char*)"b. Go back");
        Service = getch();
        if (Service != '1' && Service != '2' && Service != '3' && Service != 'b')
            goto loopFour;
        cleardevice();
        if (Service == 'b')
            goto loopp;
        if (Service == '1') {
            searchRequest(listBookCar);
            goto loopFour;
        }
        if (Service == '2') {
            searchCustomerUseTheService(listBookCar);
            goto loopFour;
        }
        if (Service == '3') {
            searchPlace(listBookCar);
            goto loopFour;
        }
    }
}
int main() {
    ShowWindow(GetConsoleWindow(), SW_HIDE);
    initwindow(700, 700);
    std::vector<customer> listCustomer(1);
    std::vector<driver> listDriver(1);
    std::vector<bookingCar> listBookCar(1);
    listCustomer[0].setupFirstCustomer();
    listDriver[0].setupFirstDriver();
    listBookCar[0].setupFirstBookCar();
    readDataDriver(listDriver);
    readDataCustomer(listCustomer);
    readDataBookCar(listBookCar);
    service(listCustomer, listDriver, listBookCar);
    closegraph();
    return 0;
}