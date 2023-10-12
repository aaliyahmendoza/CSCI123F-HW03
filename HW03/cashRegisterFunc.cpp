
#include <iostream>
using namespace std;

// Function for item scanning
double ItemScan(int numItems) {
    int itemNum = 1;
    double subtotal = 0.0;

    while (numItems > 0) {
        cout << "Please enter the cost of item #" << itemNum << ": $";
        double itemCost;
        cin >> itemCost;

        subtotal += itemCost;

        itemNum++;
        numItems--;
    }

    return subtotal;
}

// Function for payment
void Payment(char response, double total) {
    if (response == 'C' || response == 'c') {
        double cash;
        cout << "Enter the amount of cash received: $";
        cin >> cash;

        if (cash < total) {
            cout << "Insufficient cash. Please enter a valid amount." << endl;
            Payment('C', total); 
        } else {
            double change = cash - total;
            cout << "Change: $" << change << endl;
        }
    } else if (response == 'T' || response == 't') {
        cout << "Payment successfully processed with credit." << endl;
    }
}

int main() {
    int userItem;
    cout << "How many items? ";
    cin >> userItem;

    double subtotal = ItemScan(userItem);

    cout << "Subtotal: $" << subtotal << endl;

    double salesTax = 0.0775;
    cout << "Tax(7.75%): $" << salesTax * subtotal << endl;

    double total = subtotal + (salesTax * subtotal);
    cout << "Total: $" << total << endl;

    char payment;
    while (true) {
        cout << "Cash or credit? Enter 'C' for Cash or 'T' for Credit:" << endl;
        cin >> payment;

        if (payment == 'C' || payment == 'T' || payment == 'c' || payment == 't') {
            break;
        } else {
            cout << "Incorrect selection…" << endl;
        }
    }

    Payment(payment, total);

    return 0;
}
