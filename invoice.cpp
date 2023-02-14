//QUESTION 3.10
#include <iostream>
#include <string>

using namespace std;

class Invoice {
    private:
        string partNumber;
        string partDescription;
        int quantity;
        int pricePerItem;
    public:
        Invoice(string pn, string pd, int q, int ppi) {
            partNumber = pn;
            partDescription = pd;
            quantity = q;
            pricePerItem = ppi;
        }
        void setPartNumber(string pn) {
            partNumber = pn;
        }
        string getPartNumber() {
            return partNumber;
        }
        void setPartDescription(string pd) {
            partDescription = pd;
        }
        string getPartDescription() {
            return partDescription;
        }
        void setQuantity(int q) {
            if (q > 0) {
                quantity = q;
            } else {
                quantity = 0;
            }
        }
        int getQuantity() {
            return quantity;
        }
        void setPricePerItem(int ppi) {
            if (ppi > 0) {
                pricePerItem = ppi;
            } else {
                pricePerItem = 0;
            }
        }
        int getPricePerItem() {
            return pricePerItem;
        }
        int getInvoiceAmount() {
            return quantity * pricePerItem;
        }
};

int main() {
    Invoice inv("12345", "Screwdriver", 10, 5);
    inv.setQuantity(-5);
    inv.setPricePerItem(-10);

    cout << "Part Number: " << inv.getPartNumber() << endl;
    cout << "Part Description: " << inv.getPartDescription() << endl;
    cout << "Quantity: " << inv.getQuantity() << endl;
    cout << "Price Per Item: " << inv.getPricePerItem() << endl;
    cout << "Invoice Amount: " << inv.getInvoiceAmount() << endl;

    return 0;
}

