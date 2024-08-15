#include <algorithm>
#include <cmath>
#include <complex>
#include <iostream>
#include <limits> 
#include <numeric>
#include <vector>

#define MAX_HISTORY 50

std::vector<std::string> history;

void add_to_history(const std::string &entry) {
  if (history.size() >= MAX_HISTORY) {
    history.erase(history.begin()); 
  }
  history.push_back(entry);
}


double sine(double angle) {
  double result = sin(angle);
  add_to_history("sin(" + std::to_string(angle) +
                 ") = " + std::to_string(result));
  return result;
}

double cosine(double angle) {
  double result = cos(angle);
  add_to_history("cos(" + std::to_string(angle) +
                 ") = " + std::to_string(result));
  return result;
}

double tangent(double angle) {
  double result = tan(angle);
  add_to_history("tan(" + std::to_string(angle) +
                 ") = " + std::to_string(result));
  return result;
}

double logarithm(double value) {
  if (value <= 0) {
    std::cerr << "Error: Logarithm of non-positive value is undefined."
              << std::endl;
    return std::numeric_limits<double>::quiet_NaN(); 
                                                    
  }
  double result = log(value);
  add_to_history("log(" + std::to_string(value) +
                 ") = " + std::to_string(result));
  return result;
}

// Exponential Functions
double exponential(double value) {
  double result = exp(value);
  add_to_history("exp(" + std::to_string(value) +
                 ") = " + std::to_string(result));
  return result;
}

double power(double base, double exponent) {
  double result = pow(base, exponent);
  add_to_history(std::to_string(base) + "^" + std::to_string(exponent) + " = " +
                 std::to_string(result));
  return result;
}

// Complex Number Operations
std::complex<double> add_complex(const std::complex<double> &a,
                                 const std::complex<double> &b) {
  std::complex<double> result = a + b;
  add_to_history("Complex Add: " + std::to_string(a.real()) + " + " +
                 std::to_string(a.imag()) + "i + " + std::to_string(b.real()) +
                 " + " + std::to_string(b.imag()) +
                 "i = " + std::to_string(result.real()) + " + " +
                 std::to_string(result.imag()) + "i");
  return result;
}

// Statistical Functions
double mean(const std::vector<double> &data) {
  double result = std::accumulate(data.begin(), data.end(), 0.0) / data.size();
  add_to_history("Mean = " + std::to_string(result));
  return result;
}

double median(std::vector<double> data) {
  std::sort(data.begin(), data.end());
  double result =
      (data.size() % 2 == 0)
          ? (data[data.size() / 2 - 1] + data[data.size() / 2]) / 2.0
          : data[data.size() / 2];
  add_to_history("Median = " + std::to_string(result));
  return result;
}

double standard_deviation(const std::vector<double> &data) {
  double m = mean(data);
  double sum = 0.0;
  for (double x : data) {
    sum += (x - m) * (x - m);
  }
  double result = sqrt(sum / data.size());
  add_to_history("Standard Deviation = " + std::to_string(result));
  return result;
}

// Function to display history
void display_history() {
  std::cout << "\nCalculation History:\n";
  for (const auto &entry : history) {
    std::cout << entry << std::endl;
  }
}

int main() {
  int choice;
  do {
    std::cout << "\nScientific Calculator Menu:\n";
    std::cout << "1. Sine\n";
    std::cout << "2. Cosine\n";
    std::cout << "3. Tangent\n";
    std::cout << "4. Logarithm\n";
    std::cout << "5. Exponential\n";
    std::cout << "6. Power\n";
    std::cout << "7. Complex Addition\n";
    std::cout << "8. Mean\n";
    std::cout << "9. Median\n";
    std::cout << "10. Standard Deviation\n";
    std::cout << "11. Display History\n";
    std::cout << "0. Exit\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    double angle, value, base, exponent;
    std::vector<double> data;
    std::complex<double> c1, c2;

    switch (choice) {
    case 1:
      std::cout << "Enter angle (in radians): ";
      std::cin >> angle;
      std::cout << "Result: " << sine(angle) << std::endl;
      break;
    case 2:
      std::cout << "Enter angle (in radians): ";
      std::cin >> angle;
      std::cout << "Result: " << cosine(angle) << std::endl;
      break;
    case 3:
      std::cout << "Enter angle (in radians): ";
      std::cin >> angle;
      std::cout << "Result: " << tangent(angle) << std::endl;
      break;
    case 4:
      std::cout << "Enter value: ";
      std::cin >> value;
      std::cout << "Result: " << logarithm(value) << std::endl;
      break;
    case 5:
      std::cout << "Enter value: ";
      std::cin >> value;
      std::cout << "Result: " << exponential(value) << std::endl;
      break;
    case 6:
      std::cout << "Enter base: ";
      std::cin >> base;
      std::cout << "Enter exponent: ";
      std::cin >> exponent;
      std::cout << "Result: " << power(base, exponent) << std::endl;
      break;
    case 7: {
      double real1, imag1, real2, imag2;
      std::cout << "Enter real and imaginary parts of first complex number: ";
      std::cin >> real1 >> imag1;
      c1 = std::complex<double>(real1, imag1);
      std::cout << "Enter real and imaginary parts of second complex number: ";
      std::cin >> real2 >> imag2;
      c2 = std::complex<double>(real2, imag2);
      std::complex<double> result = add_complex(c1, c2);
      std::cout << "Result: " << result.real() << " + " << result.imag() << "i"
                << std::endl;
    } break;
    case 8: {
      int n;
      std::cout << "Enter number of data points: ";
      std::cin >> n;
      data.resize(n);
      std::cout << "Enter data points: ";
      for (int i = 0; i < n; ++i) {
        std::cin >> data[i];
      }
      std::cout << "Result: " << mean(data) << std::endl;
    } break;
    case 9: {
      int n;
      std::cout << "Enter number of data points: ";
      std::cin >> n;
      data.resize(n);
      std::cout << "Enter data points: ";
      for (int i = 0; i < n; ++i) {
        std::cin >> data[i];
      }
      std::cout << "Result: " << median(data) << std::endl;
    } break;
    case 10: {
      int n;
      std::cout << "Enter number of data points: ";
      std::cin >> n;
      data.resize(n);
      std::cout << "Enter data points: ";
      for (int i = 0; i < n; ++i) {
        std::cin >> data[i];
      }
      std::cout << "Result: " << standard_deviation(data) << std::endl;
    } break;
    case 11:
      display_history();
      break;
    case 0:
      std::cout << "Exiting...\n";
      break;
    default:
      std::cout << "Invalid choice. Please try again.\n";
    }
  } while (choice != 0);

  return 0;
}
