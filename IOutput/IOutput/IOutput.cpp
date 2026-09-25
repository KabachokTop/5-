#include <iostream>
#include <clocale>


using namespace std;

class IOutput {
public:
    virtual ~IOutput() = default;
    virtual void Show() const = 0;
    virtual void Show(const string& info) const = 0;
};

class Array : public IOutput {
private:
    int* data;
    int size;

public:
    Array(const int* arr, int s) : size(s) {
        data = new int[size];
        for (int i = 0; i < size; ++i) {
            data[i] = arr[i];
        }
    }

    ~Array() override {
        delete[] data;
    }

    void Show() const override {
        cout << "Елементи масиву: ";
        for (int i = 0; i < size; ++i) {
            cout << data[i] << (i == size - 1 ? "" : ", ");
        }
        cout << endl;
    }

    void Show(const string& info) const override {
        Show();
        cout << "Інформаційне повідомлення: " << info << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Ukrainian");
    int numbers[] = { 10, 20, 30, 40, 50 };
    int size = sizeof(numbers) / sizeof(numbers[0]);

    Array arr(numbers, size);
    arr.Show();
    cout << endl;
    arr.Show("Масив успішно ініціалізовано!");

    return 0;
}