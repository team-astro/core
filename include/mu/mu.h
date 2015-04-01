/**
* Copyright 2015 Matt Rudder. All rights reserved.
*/

#ifndef MU_H
#define MU_H

#include <stdint.h> // uint32_t
#include <stdlib.h> // size_t

#include "config.h"
#include "macros.h"

namespace mu
{
  // http://cnicholson.net/2011/01/stupid-c-tricks-a-better-sizeof_array/
  template<typename T, size_t N> char (&COUNTOF_REQUIRES_ARRAY_ARGUMENT(const T(&)[N]) )[N];
#define MU_COUNTOF(_x) sizeof(mu::COUNTOF_REQUIRES_ARRAY_ARGUMENT(_x) )

  template<typename Ty>
  inline void xchg(Ty& _a, Ty& _b)
  {
    Ty tmp = _a; _a = _b; _b = tmp;
  }

  template <typename Ty>
  inline Ty max(Ty a, Ty b) { return a > b ? a : b; }

  template <typename Ty>
  inline Ty min(Ty a, Ty b) { return a < b ? a : b; }

} // namespace mu

// Annoying C++0x stuff..
namespace std { namespace tr1 {}; using namespace tr1; }

#endif