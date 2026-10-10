
#ifndef DATASET_HPP
#define DATASET_HPP

#include <vector>
#include <string>
#include <cstddef>

using Matrix = std::vector<std::vector<double>>;

struct Dataset{
Matrix values;
std::vector<std::string> column_names;
std::size_t rows() const noexcept{
  return values.size();
}
std::size_t cols() const noexcept{
  return values.empty() ? 0 : values.front().size();
}
};
void validate_dataset(const Dataset& data);
Dataset standardize(const Dataset& data);

#endif
