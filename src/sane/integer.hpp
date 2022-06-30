// Copyright (C) 2022  Jesse Stricker
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#ifndef SANE_INTEGER_HPP
#define SANE_INTEGER_HPP

#include <sane/detail/integer.hpp>

namespace sane {
  struct UInt8 : detail::UnsignedIntegerBase<1, UInt8> {
    using UnsignedIntegerBase::UnsignedIntegerBase;
  };

  struct UInt16 : detail::UnsignedIntegerBase<2, UInt16> {
    using UnsignedIntegerBase::UnsignedIntegerBase;
  };

  struct UInt32 : detail::UnsignedIntegerBase<4, UInt32> {
    using UnsignedIntegerBase::UnsignedIntegerBase;
  };

  struct UInt64 : detail::UnsignedIntegerBase<8, UInt64> {
    using UnsignedIntegerBase::UnsignedIntegerBase;
  };

  struct USize : detail::UnsignedIntegerBase<detail::pointer_size, USize> {
    using UnsignedIntegerBase::UnsignedIntegerBase;
  };

  struct Int8 : detail::SignedIntegerBase<1, Int8> {
    using SignedIntegerBase::SignedIntegerBase;
  };

  struct Int16 : detail::SignedIntegerBase<2, Int16> {
    using SignedIntegerBase::SignedIntegerBase;
  };

  struct Int32 : detail::SignedIntegerBase<4, Int32> {
    using SignedIntegerBase::SignedIntegerBase;
  };

  struct Int64 : detail::SignedIntegerBase<8, Int64> {
    using SignedIntegerBase::SignedIntegerBase;
  };

  struct ISize : detail::SignedIntegerBase<detail::pointer_size, ISize> {
    using SignedIntegerBase::SignedIntegerBase;
  };
}

#endif  // SANE_INTEGER_HPP
