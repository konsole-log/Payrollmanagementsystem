#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <unistd.h>
#define space 10
const int SIZE = 100;
int count=0;
using namespace std;
int col1=11;//empid
int col2=10;//name
int col3=12;//address
int col4=13;//salary
int col5=13;//allowance
int col6=7;//tax
int col7=15;//fsalary
class Employee
{
private:
    int empid,days;
    string name, address;
    float bsalary, tax, allowance, fsalary,dailyRate=0.12;

public:
    Employee()
    {
        name = address = "empty";
        empid = bsalary = fsalary = allowance = tax = 0;
    }
    Employee(int id,string& n,string& add, float bsal,float all,float tx,float fsal){
        empid=id;
        name=n;
        address=add;
        bsalary=bsal;
        allowance=all;
        tax=tx;
        fsalary=fsal;
    }
    void showData()
    {
        cout<<right;
        cout <<"\t\t| "<< setw(col1) << empid<<" |";
        cout<<left;
        cout << setw(col2) << name<<" |";
        cout << setw(col3) << address<<" |";
        cout << setw(col4) << bsalary<<" |";
        cout << setw(col5) << allowance<<" |";
        cout << setw(col6) << tax<<" |";
        cout << setw(col7) << fsalary<<" |";
        cout << endl;
    }
    void getData()
    {
        cout << "Enter empid, name, address, no. of days worked: ";
        cin >> empid >> name >> address >> days;
    }
    void calFinalSalary(){
        bsalary=dailyRate*days;
        if(bsalary>=20000.00 && bsalary<50000.00)  
        {
            tax=bsalary*0.01;
        }else if(bsalary>=50000.00 && bsalary<100000.00)
        {
            tax=bsalary*0.03;  
        }else if(bsalary>=100000.00)
        {
            tax=bsalary*0.05;
        }else
        {
            tax=0.00;
        }
        allowance=bsalary*0.02;
        fsalary=(bsalary+allowance)-tax;
    }
    friend void saveToFile(int size,char mode);
    friend int searchEmployee(int &count,int key,int &index);
    friend void printPayslip(int &count,int id);
    friend void readFromFile(int &count);
    friend void mainMenu();
};
Employee e[SIZE];//used for writing into file by taking input from user
Employee t[SIZE];//used for reading data from file
int n;