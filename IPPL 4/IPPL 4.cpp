#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include <cmath>
#include <chrono>
#include <string>

void process(int x) {
	if (x > 0) {
		std::cout << "Positive\n";
	}
	else if (x < 0) {
		std::cout << "Negative\n";
	}
	else {
		std::cout << "Nol\n";
	}
}

void classifyNumber(int num) {
	if (num > 0) {
		std::cout << "Positive" << std::endl;
	}
	else if (num < 0) {
		std::cout << "Negative" << std::endl;
	}
	else {
		std::cout << "Nol" << std::endl;
	}
}

void process(int a, int b) {
	int result;
	if (a > 0 && b > 0) {
		result = a + b; // Penggunaan data: a dan b
	}
	else {
		result = a - b; // Penggunaan data: a dan b
	}
	std::cout << "Hasil: " << result << std::endl;
}

class Calculator {
public:
	static int add(int a, int b) {
		return a + b;
	}
	static int subtract(int a, int b) {
		return a - b;
	}
	static int multiply(int a, int b) {
		return a * b;
	}
	static double divide(int a, int b) {
		if (b == 0) {
			throw std::invalid_argument("Dibagi dengan nol");
		}
		return static_cast<double>(a) / b;
	}
};

void runTests() {
	assert(Calculator::add(2, 3) == 5);
	assert(Calculator::add(-1, 1) == 0);
	assert(Calculator::add(-2, -3) == -5);
	assert(Calculator::subtract(5, 3) == 2);
	assert(Calculator::subtract(0, 0) == 0);
	assert(Calculator::subtract(-2, -3) == 1);
	assert(Calculator::multiply(4, 3) == 12);
	assert(Calculator::multiply(0, 5) == 0);
	assert(Calculator::multiply(-4, -5) == 20);
	assert(Calculator::divide(10, 2) == 5.0);
	assert(Calculator::divide(7, 3) == 2.3333333333333335);
	try {
		Calculator::divide(1, 0);
		assert(false); // seharusnya tidak mencapai titik ini
	}
	catch (const std::invalid_argument& e) {
		assert(true);
	}
}

void measurePerformance() {
	auto start = std::chrono::high_resolution_clock::now();
	// Simulasikan beban kerja
	for (int i = 0; i < 1000000; ++i) {
		Calculator::add(i, i);
		Calculator::subtract(i, i);
		Calculator::multiply(i, i);
		try {
			Calculator::divide(i, 1);
		}
		catch (const std::invalid_argument& e) {
			// Menangani pengecualian
		}
	}
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> duration = end - start;
	std::cout << "Uji kinerja selesai di " << duration.count() << " detik." << std::endl;
}

void testSecurity() {
	try {
		// Simulasikan uji keamanan
		int a = 10;
		int b = 0;
		std::cout << Calculator::divide(a, b) << std::endl;
	}
	catch (const std::invalid_argument& e) {
		std::cerr << "Menangkap pengecualian yang diharapkan: " << e.what() << std::endl;
	}
}

int main() {
	//std::cout << "1. Pengujian Jalur\n";

	//int number;
	//std::cout << "Masukkan Angka: ";
	//std::cin >> number;
	//process(number);

	//std::cout << "=======================\n";
	//std::cout << "2. Pengujian Cabang\n";

	//std::cout << "Masukkan Angka : ";
	//std::cin >> number;
	//classifyNumber(number);

	//std::cout << "=======================\n";
	//std::cout << "3. Pengujian Aliran Data\n";

	//int num1, num2;
	//std::cout << "Masukkan dua angka: ";
	//std::cin >> num1 >> num2;
	//process(num1, num2);

	//std::cout << "=======================\n";
	//std::cout << "4. Pengujian Kasus Uji\n";

	//runTests();
	//std::cout << "Semua tes lulus!" << std::endl;

	//std::cout << "=======================\n";
	//std::cout << "5. Pengujian Fungsional\n";

	//// Pengujian kasus sederhana
	//int a = 10, b = 2;
	//std::cout << "Penjumlahan: " << Calculator::add(a, b) << std::endl;
	//std::cout << "Pengurangan: " << Calculator::subtract(a, b) << std::endl;
	//std::cout << "Perkalian: " << Calculator::multiply(a, b) << std::endl;
	//try {
	//	std::cout << "Pembagian: " << Calculator::divide(a, b) << std::endl;
	//}
	//catch (const std::invalid_argument& e) {
	//	std::cerr << e.what() << std::endl;
	//}

	//std::cout << "=======================\n";
	//std::cout << "6. Pengujian Non-fungsional\n";

	//measurePerformance();

	std::cout << "=======================\n";
	std::cout << "7. Pengujian Keamanan\n";

	testSecurity();

	return 0;
}
