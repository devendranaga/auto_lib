/**
 *
 * @brief - implements enum class definition
 *
 * @copyright - 2020-present (devnaga@tuta.io) Devendra Naga
 */
#ifndef __AUTO_LIB_ENUM_CLASS_H__
#define __AUTO_LIB_ENUM_CLASS_H__

namespace auto_os::lib {

template <typename T> T operator|(T a, T b);
template <typename T> T operator&(T a, T b);
template <typename T> bool operator==(T a, T b);

};

#endif


