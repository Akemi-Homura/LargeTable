//
// Created by quals on 2019-11-08.
//

#ifndef LARGETABLE_MEMORY_H
#define LARGETABLE_MEMORY_H

#include <memory>

template<typename T>
std::shared_ptr<T> make_shared_array(size_t size) {
    //default_delete是STL中的默认删除器
    return std::shared_ptr<T>(new T[size], std::default_delete<T[]>());
}

#endif //LARGETABLE_MEMORY_H
