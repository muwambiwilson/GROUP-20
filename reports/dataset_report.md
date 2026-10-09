Dataset loading is the first stage.
Why validation matters
The algorithm uses matrix operations, so malformed data would cause problems later. The loader therefore rejects an unreadable file, inconsistent row widths, empty datasets, missing features, and non-finite numeric values.
How the code works
The code checks that every row has the same number of columns.
Non-finite or invalid numeric values cause an error.
The completed Dataset is validated before it is returned.
