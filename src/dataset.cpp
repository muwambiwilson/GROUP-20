#include "dataset.hpp"
#include <cmath>
#include <stdexcept>

Dataset::Dataset(Matrix values, std::vector<std::string> column_names)
    : values_(std::move(values)), column_names_(std::move(column_names)) {}

std::size_t Dataset::rows() const noexcept { 
    return values_.size(); 
}

std::size_t Dataset::cols() const noexcept { 
    return values_.empty() ? 0 : values_.front().size(); 
}
const Matrix& Dataset::get_values() const noexcept { 
    return values_; 
}
void Dataset::set_values(const Matrix& values) { 
    values_ = values; 
}
const std::vector<std::string>& Dataset::get_column_names() const noexcept { 
    return column_names_; 
}
void Dataset::validate() const {
    if (values_.empty()) {
        throw std::runtime_error("Dataset is empty!");
    }
    std::size_t c = cols();
    for (const auto& row : values_) {
        if (row.size() != c) {
            throw std::runtime_error("Inconsistent row dimensions in dataset.");
        }
    }
}

Dataset Dataset::standardize() const {
    validate();
    std::size_t n = rows();
    std::size_t d = cols();
    Matrix standardized_values = values_;

    for (std::size_t j = 0; j < d; ++j) {
        double mean = 0.0;
        for (std::size_t i = 0; i < n; ++i)
            mean += values_[i][j];
        mean /= static_cast<double>(n);

        double variance = 0.0;
        for (std::size_t i = 0; i < n; ++i) {
            const double diff = values_[i][j] - mean;
            variance += diff * diff;
        }
        variance /= static_cast<double>(n);
        const double sd = std::sqrt(variance);

        for (std::size_t i = 0; i < n; ++i) {
            standardized_values[i][j] = (sd > 0.0) ? (values_[i][j] - mean) / sd : 0.0;
        }
    }
    return Dataset(standardized_values, column_names_);
}
