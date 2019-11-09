#pragma once

#include <vector>

template<typename RowType>
class QueryResult {
public:
    using ROW_T = RowType;

    QueryResult() : results(results_), status_(0), maxSize_(0), size_(0) {

    }

    ~QueryResult() {
    }

    template<typename LineHolder>
    QueryResult(const LineHolder &lines, int status, int maxSize = 10) : status_(status), results(results_), maxSize_(maxSize) {

        new(&results_) std::vector<RowType>(maxSize);
        int sum = 0;
        for (const auto &line : lines) {
            if (sum++ == maxSize) {
                break;
            }
            results_[sum - 1] = line;
        }
        size_ = sum;
    }

    QueryResult(const QueryResult &rhs) : QueryResult(rhs.results_, rhs.maxSize_) {

    }

    bool isSuccess() {
        return status_ != -1;
    }

    int size() {
        return size_;
    }

    int getStatus(){
        return status_;
    }

    const std::vector<RowType> &results;
private:
    int size_;
    int status_;
    int maxSize_;
    std::vector<RowType> results_;
};

