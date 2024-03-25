#include <iostream>
#include <vector>
#include <string>
using namespace std;

class BitSet {
public:
    BitSet(int size) {
        bits.resize((size + 31) / 32); //обчислює кількість цілих 32-бітних слів, необхідних для зберігання size бітів.
        //Додавання 31 забезпечує коректність розрахунку, оскільки size може бути не кратним до 32
    }

    void set(int pos) {
        bits[pos / 32] |= (1 << (pos % 32));
    }

    void reset(int pos) {//скидання біту в 0
        bits[pos / 32] &= ~(1 << (pos % 32));// ~змінення біту на протилежний 
    }

    bool test(int pos) const {// перевірка, чи встановлений біт в певній позиції
        return (bits[pos / 32] & (1 << (pos % 32))) != 0;//повертає 0, якщо біт у позиції pos не встановлений і повертає ненульове значення, якщо біт встановлений
    }

    int count() const {
        int cnt = 0;
        for (int i = 0; i < bits.size(); i++) {
            unsigned int x = bits[i];
            while (x) {
                cnt++;
                x &= (x - 1);// змінює значення числа. де його останній встановлений біт стає нулем
            }
        }
        return cnt;
    }

    void shift_left(int pos) {// зсув на позицію вліво
        for (int i = pos; i < bits.size() - 1; i++) {
            bits[i] = (bits[i] << 1) | (bits[i + 1] >> 31);
        }
        bits.back() <<= 1;
    }

    void shift_right(int pos) {//зсув на позицію вправо
        for (int i = pos; i > 0; i--) {
            bits[i] = (bits[i] >> 1) | (bits[i - 1] << 31);
        }
        bits.front() >>= 1;
    }

    void bitwise_and(const BitSet& other) {// побітове і
        for (int i = 0; i < bits.size(); i++) {
            bits[i] &= other.bits[i];
        }
    }

    void bitwise_or(const BitSet& other) {// побітове або
        for (int i = 0; i < bits.size(); i++) {
            bits[i] |= other.bits[i];
        }
    }

    void bitwise_xor(const BitSet& other) {// виключне або, повертає результат в якому біт встановлений на 1
        for (int i = 0; i < bits.size(); i++) {
            bits[i] ^= other.bits[i];
        }
    }

    string to_string() const {//Ця функція конвертує об'єкт BitSet у рядок, який представляє бітову послідовність у двійковій системі числення.
        string result;
        for (int i = 0; i < bits.size(); i++) {
            unsigned int x = bits[i];
            for (int j = 0; j < 32; j++) {
                result.push_back('0' + (x & 1));
                x >>= 1;
            }
        }
        while (!result.empty() && result.back() == '0') {
            result.pop_back();
        }
        if (result.empty()) {
            result.push_back('0');
        }
        std::reverse(result.begin(), result.end());
        return result;
    }

private:
    vector<unsigned int> bits;
};

int main() {
    BitSet myset(8);
    myset.set(1);
    myset.set(3);
    myset.set(5);

    cout << "myset contains " << myset.count() << " set bits\n";
    cout << "All bits: " << myset.to_string() << endl;

    myset.reset(3);
    cout << "After reset(3): " << myset.to_string() << endl;

    myset.shift_left(1);
    cout << "After shift_left(1): " << myset.to_string() << endl;
    BitSet other(8);
    other.set(0);
    other.set(2);
    other.set(4);

    myset.bitwise_and(other);
    cout << "After bitwise_and: " << myset.to_string() << endl;

    myset.bitwise_or(other);
    cout << "After bitwise_or: " << myset.to_string() << endl;

    myset.bitwise_xor(other);
    cout << "After bitwise_xor: " << myset.to_string() << endl;

    return 0;
}
/*#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "x64/Debug/Бітова множина.tlog/doctest.h"

TEST_CASE("BitSet set and test methods") {
    BitSet myset(8);
    myset.set(1);
    myset.set(3);
    myset.set(5);
    CHECK(myset.test(0) == false);
    CHECK(myset.test(1) == true);
    CHECK(myset.test(2) == false);
    CHECK(myset.test(3) == true);
    CHECK(myset.test(4) == false);
    CHECK(myset.test(5) == true);
    CHECK(myset.test(6) == false);
    CHECK(myset.test(7) == false);
}

TEST_CASE("BitSet count method") {
    BitSet myset(8);
    myset.set(1);
    myset.set(3);
    myset.set(5);
    CHECK(myset.count() == 3);
}

TEST_CASE("BitSet reset method") {
    BitSet myset(8);
    myset.set(1);
    myset.set(3);
    myset.set(5);
    myset.reset(3);
    CHECK(myset.to_string() == "100010");
}



TEST_CASE("BitSet bitwise_and method") {
    BitSet myset(8);
    myset.set(2);
    myset.set(3);
    myset.set(4);
    BitSet other(8);
    other.set(0);
    other.set(2);
    other.set(4);
    myset.bitwise_and(other);
    CHECK(myset.to_string() == "10100");
}

TEST_CASE("BitSet bitwise_or method") {
    BitSet myset(8);
    myset.set(2);
    myset.set(3);
    myset.set(4);
    BitSet other(8);
    other.set(0);
    other.set(2);
    other.set(4);
    myset.bitwise_or(other);
    CHECK(myset.to_string() == "11101");
}

TEST_CASE("BitSet bitwise_xor method") {
    BitSet myset(8);
    myset.set(2);
    myset.set(4);
    BitSet other(8);
    other.set(0);
    other.set(2);
    other.set(3);
    myset.bitwise_xor(other);
    CHECK(myset.to_string() == "11001");
}*/


