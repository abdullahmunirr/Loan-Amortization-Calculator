# **Loan Amortization Calculator**

**Description**  
A command-line program to calculate loan amortization schedules and compare loan options. This tool helps users understand their monthly payments, interest paid, and remaining loan balance over time. Additional features include interest-only payments, additional monthly payments, and the ability to export amortization schedules to a file.

---

## **Table of Contents**

1. [Features](#features)  
2. [How It Works](#how-it-works)  
3. [Installation](#installation)  
4. [Technologies Used](#technologies-used)  
5. [Future Enhancements](#future-enhancements) 

---

## **Features**

### **1. Amortization Schedule Calculation**
- Calculates monthly payments, principal, and interest.  
- Supports interest-only loans for a defined period.  
- Allows additional monthly payments to accelerate loan payoff.  

### **2. Loan Comparison**
- Compare two loan options side-by-side.  
- Displays amortization schedules and total payments for both options.  

### **3. Export Functionality**
- Export amortization schedules to a CSV file for record-keeping.  

### **4. User-Friendly Interface**
- Intuitive menu-driven interface with numbered options.  
- Clear error messages for invalid inputs.

---

## **How It Works**

1. **Calculate Amortization Schedule**:  
   - Input loan amount, annual interest rate, and loan term (in months).  
   - Optionally, specify additional monthly payments.  
   - For interest-only loans, specify the duration of the interest-only period.  
   - View the complete amortization schedule on the terminal or export it to a file.  

2. **Compare Loan Options**:  
   - Enter details for two different loans (amount, interest rate, term).  
   - Compare the monthly payments, total interest paid, and total payments side-by-side.  

3. **Amortization Details**:  
   - **Monthly Payment**: Calculated based on the loan amount and interest rate.  
   - **Interest**: The portion of the monthly payment applied to interest.  
   - **Principal**: The portion of the monthly payment applied to the loan balance.  
   - **Balance**: The remaining loan amount after each payment.  

---

## **Installation**

Follow these steps to set up and run the program locally:

1. Clone the repository:
   ```bash
   git clone <repo-url>
   cd LoanAmortizationCalculator
   ```

2. Compile the program:
   ```bash
   g++ -o loan_calculator loan_calculator.cpp
   ```

3. Run the program:
   ```bash
   ./loan_calculator
   ```

---

## **Example Menu**

```plaintext
--- Loan Amortization Calculator ---
1. Calculate Amortization Schedule
2. Compare Loan Options
3. Exit
Enter your choice:
```

---

## **Technologies Used**

- **Language**: C++  
- **Libraries**: `<cmath>`, `<fstream>`  

---

## **Future Enhancements**

- Add graphical visualization of the amortization schedule.  
- Implement support for variable interest rates.  
- Include features for early payoff analysis.  
- Allow importing loan details from a file.  

---
