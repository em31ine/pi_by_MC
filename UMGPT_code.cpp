#include <iostream>     // For input/output (like std::cout)
#include <vector>       // For using lists/vectors like in Python
#include <random>       // For generating random numbers
#include <chrono>       // For timing code execution
#include <iomanip>      // For setting output formatting (like precision)

// The main function, where execution begins
int main() {
    // Define a list of N values as given in your assignment
    // "long long" type supports large numbers, especially up to 1e8
    std::vector<long long> N_list = {100, 1000, 10000, 100000, 1000000, 10000000, 100000000};

    // Set the true value of pi
    const double true_pi = 3.14159265359;

    // Random number generator setup:
    // Use 'random_device' and 'mt19937' as the engine, 'uniform_real_distribution' for numbers in [-1, 1]
    std::random_device rd;  // Seed for the random number generator (RNG)
    std::mt19937 gen(rd()); // Mersenne Twister RNG, seeded with rd()
    std::uniform_real_distribution<double> dist(-1.0, 1.0); // Uniform distribution [-1, 1]

    // Traverse through each sample size N and perform calculations
    for (auto N : N_list) {
        // Start timing using high_resolution_clock
        auto start = std::chrono::high_resolution_clock::now();

        long long in_circle_count = 0; // Count how many samples land inside the circle (x^2 + y^2 <= 1)

        // Iterate N times to sample random (x, y) coordinates
        for (long long i = 0; i < N; ++i) {
            double x = dist(gen); // Generate random x in [-1, 1]
            double y = dist(gen); // Generate random y in [-1, 1]
            // If x^2 + y^2 <= 1, the point is inside the unit circle
            if (x*x + y*y <= 1.0)
                ++in_circle_count; // Increase count
        }

        // Calculate the ratio of points inside the circle to total points
        double ratio = static_cast<double>(in_circle_count) / N;

        // Estimate pi
        double pi_estimate = 4.0 * ratio;

        // Calculate percent error against the "true" value of pi
        double percent_error = (std::abs(pi_estimate - true_pi) / true_pi) * 100.0;

        // End timing
        auto end = std::chrono::high_resolution_clock::now();

        // Compute elapsed time in seconds
        std::chrono::duration<double> elapsed = end - start;

        // Print the result for this N value
        std::cout << "N = " << std::setw(9) << N
                  << " ; π ≈ " << std::fixed << std::setprecision(6) << pi_estimate
                  << " ; % error = " << std::setprecision(4) << percent_error
                  << "; time = " << std::setprecision(4) << elapsed.count() << " sec"
                  << std::endl;
    }

    // Indicate successful program completion
    return 0;
}