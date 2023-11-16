#include <algorithm>
#include <cassert>
#include <utility>

// -----------------------------------------------------------------------------

template<typename T>
constexpr auto min(T&& t)
{
    return std::forward<T>(t);
}

template<typename T, typename ... Ts>
constexpr auto min(T&& t, Ts&& ... ts)
{
    return std::min( std::forward<T>(t), min(std::forward<Ts>(ts)...) );
}

// -----------------------------------------------------------------------------

int main()
{
    static_assert(min(3, 1, 2) == 1, "Bad minimum result");
    assert(min(3, 1, 2) == 1);

    return 0;
}
