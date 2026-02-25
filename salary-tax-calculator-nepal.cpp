#include<iostream>
#include<iomanip>

using namespace std;

class Employee{
    private:
    double monthlySalary;
    double bonus;
    double SSF;
    double EPF;
    double CIT;
    double insurance;

    public:
    Employee(double m, double b, double s, double e, double c, double i){
        monthlySalary = m;
        bonus = b;
        SSF = s;
        EPF = e;
        CIT = c;
        insurance = i;
    }

    double getTotalIncome(){
        return (monthlySalary * 12) + bonus;
    }

    double getTotalDeductions(){
        return (SSF + EPF + CIT + insurance);
    }

    double getNetAssessable(){
        return getTotalIncome() - getTotalDeductions();
    }

    bool hasSSF(){
        return SSF > 0;
    }

    void displayIncome(){
        cout << "\n========================================\n";
        cout << "          INCOME BREAKDOWN              \n";
        cout << "========================================\n";
        cout << "Total Income (TI):          Rs. " << getTotalIncome() << endl;
        cout << "\nSum of SSF, EPF and CIT:    Rs. " << (SSF + EPF + CIT) << endl;
        cout << "  - SSF:                    Rs. " << SSF << endl;
        cout << "  - EPF:                    Rs. " << EPF << endl;
        cout << "  - CIT:                    Rs. " << CIT << endl;
        cout << "\nInsurance:                  Rs. " << insurance << endl;
        cout << "Total Deduction (TD):       Rs. " << getTotalDeductions() << endl;
        cout << "Net Assessable (TI-TD):     Rs. " << getNetAssessable() << endl;
    }
};

class SingleEmployee: public Employee{
    public:
    SingleEmployee(double m, double b, double s, double e, double c, double i)
        : Employee(m, b, s, e, c, i){}

    double calculateTax(){
        double assessable = getNetAssessable();
        double tax = 0;

        if (assessable <= 500000){
            if(hasSSF()){
                tax = 0;
            } else {
                tax = assessable * 0.01;
            }
        }
        else if(assessable <= 700000){
            if(hasSSF()){
                tax = (assessable - 500000) * 0.1;
            } else {
                tax = 5000 + ((assessable - 500000) * 0.1);
            }
        }
        else if(assessable <= 1000000){
            if(hasSSF()){
                tax = 20000 + ((assessable - 700000) * 0.2);
            } else {
                tax = 25000 + ((assessable - 700000) * 0.2);
            }
        }
        else if(assessable <= 2000000){
            if(hasSSF()){
                tax = 80000 + ((assessable - 1000000) * 0.3);
            } else {
                tax = 85000 + ((assessable - 1000000) * 0.3);
            }
        }
        else if(assessable <= 5000000){
            if(hasSSF()){
                tax = 380000 + ((assessable - 2000000) * 0.36);
            } else {
                tax = 385000 + ((assessable - 2000000) * 0.36);
            }
        }
        else {
            if(hasSSF()){
                tax = 1460000 + ((assessable - 5000000) * 0.39);
            } else {
                tax = 1465000 + ((assessable - 5000000) * 0.39);
            }
        }
        return tax;
    }
};

class MarriedEmployee: public Employee{
    public:
    MarriedEmployee(double m, double b, double s, double e, double c, double i)
        : Employee(m, b, s, e, c, i){}

    double calculateTax(){
        double assessable = getNetAssessable();
        double tax = 0;

        if (assessable <= 600000){
            if(hasSSF()){
                tax = 0;
            } else {
                tax = assessable * 0.01;
            }
        }
        else if(assessable <= 800000){
            if(hasSSF()){
                tax = (assessable - 600000) * 0.1;
            } else {
                tax = 6000 + ((assessable - 600000) * 0.1);
            }
        }
        else if(assessable <= 1100000){
            if(hasSSF()){
                tax = 20000 + ((assessable - 800000) * 0.2);
            } else {
                tax = 26000 + ((assessable - 800000) * 0.2);
            }
        }
        else if(assessable <= 2000000){
            if(hasSSF()){
                tax = 80000 + ((assessable - 1100000) * 0.3);
            } else {
                tax = 86000 + ((assessable - 1100000) * 0.3);
            }
        }
        else if(assessable <= 5000000){
            if(hasSSF()){
                tax = 350000 + ((assessable - 2000000) * 0.36);
            } else {
                tax = 356000 + ((assessable - 2000000) * 0.36);
            }
        }
        else {
            if(hasSSF()){
                tax = 1430000 + ((assessable - 5000000) * 0.39);
            } else {
                tax = 1436000 + ((assessable - 5000000) * 0.39);
            }
        }
        return tax;
    }
};

int main(){
    cout << fixed << setprecision(2);
    
    cout << "\n========================================\n";
    cout << "   NEPAL TAX CALCULATOR FY 2082/2083   \n";
    cout << "========================================\n\n";

    int choice;
    cout << "Nature of Employee:\n";
    cout << "1. Unmarried\n";
    cout << "2. Married\n";
    cout << "Enter choice (1 or 2): ";
    cin >> choice;

    while(choice != 1 && choice != 2){
        cout << "Invalid choice! Please enter 1 or 2: ";
        cin >> choice;
    }

    cout << "\nFiscal Year: 2082/2083\n";
    cout << "\n--- ANNUAL INCOME ---\n";
    double monthly, bonus;

    cout << "Monthly Salary: Rs. ";
    cin >> monthly;

    cout << "Bonus: Rs. ";
    cin >> bonus;

    double totalSalary = (monthly * 12) + bonus;
    cout << "Annual Salary: Rs. " << totalSalary << endl;

    cout << "\n--- ANNUAL DEDUCTIONS ---\n";
    double ssf, epf, cit, insurance;

    cout << "Social Security Fund (SSF): Rs. ";
    cin >> ssf;

    cout << "Employees Provident Fund (EPF): Rs. ";
    cin >> epf;

    cout << "Citizen Investment Trust (CIT): Rs. ";
    cin >> cit;

    cout << "Insurance: Rs. ";
    cin >> insurance;

    if(choice == 1){
        SingleEmployee emp(monthly, bonus, ssf, epf, cit, insurance);
        emp.displayIncome();
        double tax = emp.calculateTax();
        cout << "\n=======================================\n";
        cout << "       TAX CALCULATION       \n";
        cout << "========================================\n";

        cout << "\nNet Tax Liability (Monthly):  Rs. " << (tax / 12) << endl;
        cout << "Net Tax Liability (Yearly):   Rs. " << tax << endl;
    }
    else{
        MarriedEmployee emp(monthly, bonus, ssf, epf, cit, insurance);
        emp.displayIncome();
        double tax = emp.calculateTax();
        cout << "\n=======================================\n";
        cout << "       TAX CALCULATION       \n";
        cout << "========================================\n";

        cout << "\nNet Tax Liability (Monthly):  Rs. " << (tax / 12) << endl;
        cout << "Net Tax Liability (Yearly):   Rs. " << tax << endl;
    }
    cout << "\n========================================\n";
    return 0;
}
