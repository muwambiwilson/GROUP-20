

#ifndef DATASET_HPP
#define DATASET_HPP
#include <vector>
#include <string>
#include <cstddef>

using Matrix =
std::vector<std::vector<double>>;

class Dataset {
private:
    Matrix values_;
    std::vector<std::string> column_names_;

public:
    Dataset() = default;
    Dataset(Matrix values,
std::vector<std::string> column_names =
{});

    std::size_t rows() const noexcept;
    std::size_t cols() const noexcept;

    const Matrix& get_values() const
noexcept;
    void set_values(const Matrix& values);
    const std::vector<std::string>&
get_column_names() const noexcept;
    void validate() const;
    Dataset standardize() const;
};
#endif
