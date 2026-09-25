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

class ISort {
public:
    virtual ~ISort() = default;
    virtual void SortAsc() = 0;
    virtual void SortDesc() = 0;
    virtual void SortByParam(bool isAsc) = 0;
};

class Array : public IOutput, public IMath, public ISort {
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

    void SortAsc() override {
        for (int i = 0; i < size - 1; ++i) {
            for (int j = 0; j < size - i - 1; ++j) {
                if (data[j] > data[j + 1]) {
                    int temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                }
            }
        }
    }

    void SortDesc() override {
        for (int i = 0; i < size - 1; ++i) {
            for (int j = 0; j < size - i - 1; ++j) {
                if (data[j] < data[j + 1]) {
                    int temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                }
            }
        }
    }

    void SortByParam(bool isAsc) override {
        if (isAsc) {
            SortAsc();
        }
        else {
            SortDesc();
        }
    }
};

int main() {
    setlocale(LC_ALL, "Ukrainian");
    int numbers[] = { 15, 3, 8, 42, 4, 23 };
    int size = sizeof(numbers) / sizeof(numbers[0]);

    Array arr(numbers, size);
    cout << "Початковий масив:" << endl;
    arr.Show();

    cout << "\nСортування за зростанням (SortAsc):" << endl;
    arr.SortAsc();
    arr.Show();

    cout << "\nСортування за спаданням (SortByParam(false)):" << endl;
    arr.SortByParam(false);
    arr.Show();

    return 0;
}