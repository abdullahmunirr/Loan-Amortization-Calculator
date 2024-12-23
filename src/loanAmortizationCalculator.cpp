#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

void calculateAmortizationSchedule(double loanAmount, double annualRate, int termMonths,
                                   double additionalPayment = 0.0, bool interestOnly = false,
                                   int interestOnlyMonths = 0, const string& exportFile = "")
{
    double monthlyRate = annualRate / 12 / 100;
    double monthlyPayment = loanAmount * (monthlyRate * pow(1 + monthlyRate, termMonths)) /
                            (pow(1 + monthlyRate, termMonths) - 1);

    if (interestOnly)
    {
        cout << endl << "Monthly Payment: $" << loanAmount * monthlyRate << endl;
        cout << "Period: " << interestOnlyMonths << " months" << endl;
    }

    cout << "Monthly Payment: $" << monthlyPayment << endl << endl;

    double balance = loanAmount;
    double totalInterest = 0.0;
    int month = 1;

    ofstream file;
    if (!exportFile.empty())
    {
        file.open(exportFile);
        if (!file.is_open())
        {
            cout << "Couldnt open the file" << endl;
            return;
        }
        
        file << "Month,Payment,Principal,Interest,Balance\n";
    }

    cout << "Month\tPayment\t\tPrincipal\tInterest\tBalance\n";
    
    while (month <= termMonths)
    {
        double interest = balance * monthlyRate;
        double principal;
        
        if (interestOnly && month <= interestOnlyMonths)
        {
            principal = 0;
        }
        
        else
        {
            principal = monthlyPayment - interest;
        }
        
        totalInterest = totalInterest + interest;
        balance = balance - (principal + additionalPayment);

        if (balance < 0)
        {
            balance = 0;
        }

        cout << month << "\t$" << monthlyPayment << "\t\t$" << principal << "\t\t$" << interest
             << "\t\t$" << balance << endl;

        if (!exportFile.empty())
        {
            file << month << "," << monthlyPayment << "," << principal << "," << interest << "," << balance << endl;
        }

        if (balance == 0)
        {
            break;
        }

        month++;
    }

    cout << endl << "Total Interest Paid: $" << totalInterest << endl;
    cout << "Total Payment: $" << (loanAmount + totalInterest) << endl;

    if (!exportFile.empty())
    {
        file.close();
        cout << "Schedule exported to " << exportFile << endl;
    }
}

void compareLoanOptions(double loanAmount1, double rate1, int term1,
                        double loanAmount2, double rate2, int term2)
{
    cout << endl << "--- Loan Comparison ---" << endl;
    cout << "Option 1:" << endl;
    calculateAmortizationSchedule(loanAmount1, rate1, term1);
    
    cout << endl;
    
    cout << "Option 2:" << endl;
    calculateAmortizationSchedule(loanAmount2, rate2, term2);
}

void displayMenu()
{
    int choice;
    do {
        cout << endl << "--- Loan Amortization Calculator ---" << endl;
        cout << "1. Calculate Amortization Schedule" << endl;
        cout << "2. Compare Loan Options" << endl;
        cout << "3. Exit" << endl;
        
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice)
        {
            case 1:
            {
                double loanAmount, annualRate, additionalPayment = 0.0;
                int termMonths, interestOnlyMonths = 0;
                bool interestOnly = false;
                string exportFile;
                
                cout << "Enter loan amount: ";
                cin >> loanAmount;
                cout << "Enter annual interest rate: ";
                cin >> annualRate;
                cout << "Enter loan term (Months): ";
                cin >> termMonths;
                cout << "Enter additional payment: ";
                cin >> additionalPayment;
                
                char interestOnlyChoice;
                cout << "Is this an interest-only loan? (Y/N): ";
                cin >> interestOnlyChoice;
                
                if (interestOnlyChoice == 'y' || interestOnlyChoice == 'Y')
                {
                    interestOnly = true;
                    cout << "Enter interest-only period (Months): ";
                    cin >> interestOnlyMonths;
                }
                
                cout << "Enter filename to export schedule (Optional): ";
                cin.ignore();
                getline(cin, exportFile);
                
                calculateAmortizationSchedule(loanAmount, annualRate, termMonths, additionalPayment,                                   interestOnly, interestOnlyMonths, exportFile);
                break;
            }
                
            case 2:
            {
                double loanAmount1, rate1, loanAmount2, rate2;
                int term1, term2;
                
                cout << "Enter details for Loan Option 1:" << endl;
                cout << "Loan amount: ";
                cin >> loanAmount1;
                cout << "Annual interest rate: ";
                cin >> rate1;
                cout << "Loan term (Months): ";
                cin >> term1;
                
                cout << "Enter details for Loan Option 2:" << endl;
                cout << "Loan amount: ";
                cin >> loanAmount2;
                cout << "Annual interest rate: ";
                cin >> rate2;
                cout << "Loan term (Months): ";
                cin >> term2;
                
                compareLoanOptions(loanAmount1, rate1, term1, loanAmount2, rate2, term2);
                break;
            }
                
            case 3:
                cout << "Exiting" << endl;
                break;
                
            default:
                cout << "Invalid choice, try again" << endl;
        }
    } while (choice != 3);
}

int main()
{
    displayMenu();
    return 0;
}
