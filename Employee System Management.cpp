#include <iostream>

#include <vector>

#include<string>

#include <fstream>

using namespace std;

const int MAX_SIZE = 1000;

struct stName {

    string FName;
    string MidName; 
    string LName;

};

struct stAdrees {

    string Country;
    string City;
    string StreetName;
    short BuildingNo;

};

struct stSalary {

    short WorkHour;

};

struct stContactInf {

    string Email;
    stAdrees Adrees;
    string PhoneNumber;
    string ID;
};

enum enGender {Male = 1, Female = 2};

enum enStatus {Married = 1, Single = 2, Widower = 3};

string getStringFromGender(enGender Gender) {

    switch (Gender) {

        case enGender::Male:
            return "Male";
            break;

        case enGender::Female:
            return "Falmale";
            break;

        default:
            return "Unknown";

    }
}

string getStringFromStatus(enStatus Status){

    switch (Status) {
    case enStatus::Married :
            return "Married"; 
            break;

    case enStatus::Single:
        return "Single";
        break;

    case enStatus::Widower:
        return "Widower";
        break;

    default :
        return "Unknown";
    }

}

struct stEmployeeInf {

    stName Name[MAX_SIZE];

    stContactInf ContactInf[MAX_SIZE];

    short WorkHour[MAX_SIZE];

    long long Salary [MAX_SIZE];

    enGender Gender[MAX_SIZE];

    enStatus Stat[MAX_SIZE];
};

short TOPINDEX = 0;

stEmployeeInf EmployeeInf;

long long CalacEmployeeSalary(long long Hour) {

    if (Hour > 24)
        return Hour * 50;

    return Hour * 40;

}

struct stUserInputData {

    string fname;
    string midname;
    string lname;
    string email;
    string country;
    string city;
    string street;
    int building;
    string phone;
    string id;
    enGender gender;
    enStatus status;
    short workhour;

};


void SaveOneEmployeeToCSV(int index) {

    ofstream file("employees.csv", ios::app);

    if (index == 0) {
        file << "First Name,Last Name,ID,Country,City,Street,Building,Email,Phone,WorkHour,Salary,Gender,Status\n";
    }

    cout << left;

    file << EmployeeInf.Name[index].FName << ",";
    file << EmployeeInf.Name[index].LName << ",";
    file << EmployeeInf.ContactInf[index].ID << ",";
    file << EmployeeInf.ContactInf[index].Adrees.Country << ",";
    file << EmployeeInf.ContactInf[index].Adrees.City << ",";
    file << EmployeeInf.ContactInf[index].Adrees.StreetName << ",";
    file << EmployeeInf.ContactInf[index].Adrees.BuildingNo << ",";
    file << EmployeeInf.ContactInf[index].Email << ",";
    file << EmployeeInf.ContactInf[index].PhoneNumber << ",";
    file << EmployeeInf.WorkHour[index] << ",";
    file << EmployeeInf.Salary[index] << ",";
    file << getStringFromGender(EmployeeInf.Gender[index]) << ",";
    file << getStringFromStatus(EmployeeInf.Stat[index]) << "\n";

    file.close();
}

int addEmployee(stUserInputData UserInputData) {

    if(TOPINDEX == MAX_SIZE)
        return 1;


    EmployeeInf.Name[TOPINDEX].FName = UserInputData.fname;
    EmployeeInf.Name[TOPINDEX].MidName = UserInputData.midname;
    EmployeeInf.Name[TOPINDEX].LName = UserInputData.lname;
    EmployeeInf.ContactInf[TOPINDEX].Email = UserInputData.email;
    EmployeeInf.ContactInf[TOPINDEX].Adrees.Country = UserInputData.country;
    EmployeeInf.ContactInf[TOPINDEX].Adrees.City = UserInputData.city;
    EmployeeInf.ContactInf[TOPINDEX].Adrees.StreetName = UserInputData.street;
    EmployeeInf.ContactInf[TOPINDEX].Adrees.BuildingNo = UserInputData.building;
    EmployeeInf.ContactInf[TOPINDEX].ID = UserInputData.id;
    EmployeeInf.ContactInf[TOPINDEX].PhoneNumber = UserInputData.phone;
    EmployeeInf.WorkHour[TOPINDEX] = UserInputData.workhour;
    EmployeeInf.Salary[TOPINDEX] = CalacEmployeeSalary(EmployeeInf.WorkHour[TOPINDEX]);
    EmployeeInf.Gender[TOPINDEX] = UserInputData.gender;
    EmployeeInf.Stat[TOPINDEX] = UserInputData.status;

    SaveOneEmployeeToCSV(TOPINDEX);

    ++TOPINDEX;

    return 0;

}

void printAllEmployeesData() {

    if (TOPINDEX == 0) {

        cout << "There is no Employees" << endl;
        return;

    }

    for (int i = 1; i <= TOPINDEX; i++) {
        cout << "Code: " << i << endl;
        cout << "Name: " << EmployeeInf.Name[i - 1].FName + " " + EmployeeInf.Name[i - 1].LName << endl;
        cout << "ID National: " << EmployeeInf.ContactInf[i - 1].ID << endl;
        cout << "Adress: " << endl;
        cout << "       -Country-> " << EmployeeInf.ContactInf[i - 1].Adrees.Country << endl;
        cout << "       -City-> " << EmployeeInf.ContactInf[i - 1].Adrees.City << endl;
        cout << "       -Street Name-> " << EmployeeInf.ContactInf[i - 1].Adrees.StreetName << endl;
        cout << "       -Building No-> " << EmployeeInf.ContactInf[i - 1].Adrees.BuildingNo << endl;
        cout << "Contact: " << endl;
        cout << "        -Email-> " << EmployeeInf.ContactInf[i - 1].Email << endl;
        cout << "        -Phone-> " << EmployeeInf.ContactInf[i - 1].PhoneNumber << endl;
        cout << "Salary: " << endl;
        cout << "       -Working Hours-> " << EmployeeInf.WorkHour[i -1] << endl;
        cout << "       -Monthly Salary-> " << CalacEmployeeSalary(EmployeeInf.Salary[i - 1]);         cout << endl;
        cout << "       -Yearly Salary-> " << 12 * CalacEmployeeSalary(EmployeeInf.Salary[i-1]) << endl;
        cout << "Gender: " << getStringFromGender((enGender)EmployeeInf.Gender[i - 1]) << endl;
        cout << "Statue: " << getStringFromStatus (EmployeeInf.Stat[i - 1] )<< endl;
    }
}

void printEmployeeDataByID(int id) {

    if (TOPINDEX == 0) {
        cout << "There is no Employees" << endl;
        return;
    }
    if (id > TOPINDEX || id < 1) {
        cout << "Enter Valid Code " << endl;
        return;
    }
    cout << "Code: " << id << endl;
    cout << "Name: " << EmployeeInf.Name[id - 1].FName + " " + EmployeeInf.Name[id - 1].LName << endl;
    cout << "ID National: " << EmployeeInf.ContactInf[id - 1].ID << endl;
    cout << "Adress: " << endl;
    cout << "       -Country-> " << EmployeeInf.ContactInf[id - 1].Adrees.Country << endl;
    cout << "       -City-> " << EmployeeInf.ContactInf[id - 1].Adrees.City << endl;
    cout << "       -Street Name-> " << EmployeeInf.ContactInf[id - 1].Adrees.StreetName << endl;
    cout << "       -Building No-> " << EmployeeInf.ContactInf[id - 1].Adrees.BuildingNo << endl;
    cout << "Contact: " << endl;
    cout << "        -Email-> " << EmployeeInf.ContactInf[id - 1].Email << endl;
    cout << "        -Phone-> " << EmployeeInf.ContactInf[id - 1].PhoneNumber << endl;
    cout << "Salary: " << endl;
    cout << "       -Working Hours-> " << EmployeeInf.WorkHour << endl;
    cout << "       -Monthly Salary-> " << CalacEmployeeSalary(EmployeeInf.Salary[id-1]);         cout << endl;
    cout << "       -Yearly Salary-> " << 12 * CalacEmployeeSalary(EmployeeInf.Salary[id-1]) << endl;
    cout << "Gender: " << getStringFromGender(EmployeeInf.Gender[id - 1]) << endl;
    cout << "Statue: " << getStringFromStatus(EmployeeInf.Stat[id - 1] )<< endl;
}

void RunSystem() {

    stUserInputData UserInputData;

    


    cout << "===========================================\n";
    cout << "        Employee Management System         \n";
    cout << "===========================================\n";
    while (true) {
        cout << "Enter 1. to add Employee.\n";
        cout << "Enter 2. to print all Employees\n";
        cout << "Enter 3. to get Employee data by Code\n";
        cout << "Enter 0. to exit\n";
        cout << "------------------------------" << endl;
        int x;
        cout << "Enter choice: ";
        cin >> x;
        cin.ignore();
        cout << "------------------------------" << endl;

        system("pause");
        system("cls");

        if (x == 0) {
            cout << "Good Bye" << endl;
            cout << "===========================================\n";
            cout << "        MADE BY Tarek Mahmoud <T/K>        \n";
            cout << "===========================================\n";
            break;
        }
        switch (x) {
        case 1:
            cout << "-> Name " << endl;
            cout << "       -Enter Employee First Name: " << endl << flush;
            cout << "       -"; getline(cin, UserInputData.fname);
            cout << "       -Enter Employee Last Name: " << endl << flush;
            cout << "       -"; getline(cin, UserInputData.lname);
            cout << "------------------------------" << endl << flush;

            system("pause");
            system("cls");

            cout << "-> ID " << endl << flush;
            cout << "       -Enter Employee ID National: " << endl << flush;
            cout << "       -"; cin >> UserInputData.id;
            cin.ignore();
            cout << "------------------------------" << endl << flush;

            system("pause");
            system("cls");

            cout << "-> Adress " << endl << flush;
            cout << "       -Enter Employee Country: " << endl << flush;
            cout << "       -"; getline(cin, UserInputData.country);
            cout << "       -Enter Employee City: " << endl << flush;
            cout << "       -"; getline(cin, UserInputData.city);
            cout << "       -Enter Employee Street: " << endl << flush;
            cout << "       -"; getline(cin, UserInputData.street);
            cout << "       -Enter Employee Building NO: " << endl << flush;
            cout << "       -"; cin >> UserInputData.building;
            cin.ignore();
            cout << "------------------------------" << endl << flush;

            system("pause");
            system("cls");

            cout << "-> Contact " << endl << flush;
            cout << "       -Enter Employee Email: " << endl << flush;
            cout << "       -"; getline(cin, UserInputData.email);
            cout << "       -Enter Employee Phone: " << endl << flush;
            cout << "       -"; cin >> UserInputData.phone;
            cin.ignore();
            cout << "------------------------------" << endl << flush;

            system("pause");
            system("cls");

            cout << "-> Work Hour " << endl << flush;
            cout << "       -Enter Employee Working Hours: " << endl << flush;
            cout << "       -"; cin >> UserInputData.workhour;
            cin.ignore();

            system("pause");
            system("cls");

            cout << "------------------------------" << endl << flush;
            cout << "-> Gender " << endl << flush;

            cout << "       -Enter Employee Gender: [1]Male, [2]Female" << endl << flush;
            int genderInput;
            cout << "       -"; cin >> genderInput;
            (genderInput == 1) ? UserInputData.gender = enGender::Male : UserInputData.gender = enGender::Female;
            cin.ignore();

            system("pause");
            system("cls");

            cout << "-> Statue " << endl << flush;
            cout << "------------------------------" << endl << flush;
            cout << "       -Enter Employee Statue: [1]Married, [2]Single,[3]Widower " << endl << flush;
            int statusInput;
            cout << "       -"; cin >> statusInput;
            switch (statusInput) {
            case 1: UserInputData.status = enStatus::Married; break;
            case 2: UserInputData.status = enStatus::Single; break;
            case 3: UserInputData.status = enStatus::Widower; break;
            default: UserInputData.status = enStatus::Single; break;
            }
            cin.ignore();
            while (UserInputData.workhour < 0) {
                cout << "Invalid hours! Please enter a positive value: ";
                cin >> UserInputData.workhour;
                cin.ignore();

            }

            cout << "------------------------------" << endl << flush;

            system("pause");
            system("cls");

            if (addEmployee(UserInputData) == 0) {

                cout << "Employee Added Successfully" << endl;
                system("pause");
                system("cls");

            }


            else {
                cout << "Sorry we can't add more employees" << endl;
                system("pause");
                system("cls");
            }


            cout << "=====================================" << endl;
            break;
        case 2:
            printAllEmployeesData();
            cout << "=====================================" << endl;

            system("pause");
            system("cls");

            break;
        case 3:
            int code;
            cout << "Enter Employee code: ";
            cin >> code;

            system("pause");
            system("cls");

            printEmployeeDataByID(code);

            system("pause");
            system("cls");

            cout << "=====================================" << endl;
            break;
        default:
            cout << "Invalid choice. Try again\n";
            cout << "=====================================" << endl;

            system("pause");
            system("cls");

            break;
        }
    }
}

int main() {

    RunSystem();

    return 0;
}
