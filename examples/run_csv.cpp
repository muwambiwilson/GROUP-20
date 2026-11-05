#include "affinity_propagation.hpp"
#include "dataset.hpp"
#include "evaluation.hpp"

#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

namespace {
Dataset load_csv(const std::string& path, bool has_header) {
    std::ifstream input(path);
    if (!input) {
        throw std::runtime_error("Could not open CSV file: " + path);
    }

    Matrix values;
    std::string line;
    std::size_t line_number = 0;
    while (std::getline(input, line)) {
        ++line_number;
        if (line_number == 1 && has_header) {
            continue;
        }
        if (line.empty()) {
            continue;
        }

        std::stringstream row_stream(line);
        std::string field;
        std::vector<double> row;
        while (std::getline(row_stream, field, ',')) {
            std::size_t parsed = 0;
            const double value = std::stod(field, &parsed);
            if (parsed != field.size()) {
                throw std::runtime_error("Invalid numeric value on CSV line " +
                                         std::to_string(line_number));
            }
            row.push_back(value);
        }
        values.push_back(std::move(row));
    }

    Dataset data(std::move(values));
    data.validate();
    return data;
}
}

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: run_csv <csv-file> [has-header:0|1]\n";
        return 1;
    }

    try {
        const bool has_header = argc >= 3 && std::string(argv[2]) == "1";
        const Dataset data = load_csv(argv[1], has_header);

        APConfig config;
        config.damping = 0.7;
        config.max_iterations = 500;
        config.convergence_iterations = 15;
        config.preference = -3.0;

        AffinityPropagation model(config);
        const auto result = model.run(data);

        std::cout << "Rows: " << data.rows() << "\n";
        std::cout << "Features: " << data.cols() << "\n";
        std::cout << "Converged: " << std::boolalpha << result.converged << "\n";
        std::cout << "Iterations: " << result.iterations << "\n";
        std::cout << "Exemplars: ";
        for (auto e : result.exemplars) std::cout << e << ' ';
        std::cout << "\nCluster count: "
                  << ClusterEvaluator::cluster_count(result.labels) << "\n";

        std::cout << "Assignments:\n";
        for (std::size_t i = 0; i < result.labels.size(); ++i) {
            std::cout << "  point " << i << " -> exemplar " << result.labels[i] << "\n";
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 2;
    }
    return 0;
}
