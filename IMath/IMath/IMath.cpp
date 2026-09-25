#include <iostream>
#include <clocale>

using namespace std;

class IOutput {
public:
    virtual ~IOutput() = default;
    virtual void Show() const = 0;
    virtual void Show(const string& info) const = 0;
};

class IMath {
public:
    virtual ~IMath() = default;
    virtual int Max() const = 0;
    virtual int Min() const = 0;
    virtual float Avg() const = 0;
    virtual bool Search(int valueToSearch) const = 0;
};

class Array : public IOutput, public IMath {
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

    int Max() const override {
        if (size == 0) return 0;
        int maxVal = data[0];
        for (int i = 1; i < size; ++i) {
            if (data[i] > maxVal) maxVal = data[i];
        }
        return maxVal;
    }

    int Min() const override {
        if (size == 0) return 0;
        int minVal = data[0];
        for (int i = 1; i < size; ++i) {
            if (data[i] < minVal) minVal = data[i];
        }
        return minVal;
    }

    float Avg() const override {
        if (size == 0) return 0.0f;
        float sum = 0.0f;
        for (int i = 0; i < size; ++i) {
            sum += data[i];
        }
        return sum / size;
    }

    bool Search(int valueToSearch) const override {
        for (int i = 0; i < size; ++i) {
            if (data[i] == valueToSearch) return true;
        }
        return false;
    }
};

int main() {
    setlocale(LC_ALL, "Ukrainian");
    int numbers[] = { 15, 3, 8, 42, 4, 23 };
    int size = sizeof(numbers) / sizeof(numbers[0]);

    Array arr(numbers, size);
    arr.Show();

    cout << "\nМаксимум: " << arr.Max() << endl;
    cout << "Мінімум: " << arr.Min() << endl;
    cout << "Середнє арифметичне: " << arr.Avg() << endl;
    cout << "Чи є 42 у масиві? " << (arr.Search(42) ? "Так" : "Ні") << endl;
    cout << "Чи є 100 у масиві? " << (arr.Search(100) ? "Так" : "Ні") << endl;

    return 0;
}