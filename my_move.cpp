#include <type_traits>

using namespace std;

template <typename T>
typename remove_reference<T>::type &&my_move(T &&param)
{
    using ReturnType = typename remove_reference<T>::type &&;
    return static_cast<ReturnType>(param);
}