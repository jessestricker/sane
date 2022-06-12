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
//

#ifndef SANE_INTEGER_HPP
#define SANE_INTEGER_HPP

namespace sane {
  namespace detail {
    using SizeType = decltype(sizeof(bool));

    constexpr SizeType pointer_size = sizeof(void*);

    template <bool Signed, SizeType Size>
    consteval auto integer_declval() noexcept {
      if constexpr (Signed) {
        if constexpr (Size == sizeof(signed char)) {
          return static_cast<signed char>(0);
        }
        if constexpr (Size == sizeof(short int)) {
          return static_cast<short int>(0);
        }
        if constexpr (Size == sizeof(int)) {
          return static_cast<int>(0);
        }
        if constexpr (Size == sizeof(long int)) {
          return static_cast<long int>(0);
        }
        if constexpr (Size == sizeof(long long int)) {
          return static_cast<long long int>(0);
        }
      } else {
        if constexpr (Size == sizeof(unsigned char)) {
          return static_cast<unsigned char>(0);
        }
        if constexpr (Size == sizeof(unsigned short int)) {
          return static_cast<unsigned short int>(0);
        }
        if constexpr (Size == sizeof(unsigned int)) {
          return static_cast<unsigned int>(0);
        }
        if constexpr (Size == sizeof(unsigned long int)) {
          return static_cast<unsigned long int>(0);
        }
        if constexpr (Size == sizeof(unsigned long long int)) {
          return static_cast<unsigned long long int>(0);
        }
      }
    }

    template <bool Signed, SizeType Size>
    class IntegerBase {
    public:
      using Value = decltype(integer_declval<Signed, Size>());

      constexpr IntegerBase() noexcept = default;

    private:
      Value value_{};
    };

    template <SizeType Size>
    class UnsignedInteger : public IntegerBase<false, Size> {
    public:
      using IntegerBase<false, Size>::IntegerBase;
    };

    template <SizeType Size>
    class SignedInteger : public IntegerBase<true, Size> {
    public:
      using IntegerBase<false, Size>::IntegerBase;
    };
  }

  using UInt8 = detail::UnsignedInteger<1>;
  using UInt16 = detail::UnsignedInteger<2>;
  using UInt32 = detail::UnsignedInteger<4>;
  using UInt64 = detail::UnsignedInteger<8>;
  using USize = detail::UnsignedInteger<detail::pointer_size>;

  using Int8 = detail::SignedInteger<1>;
  using Int16 = detail::SignedInteger<2>;
  using Int32 = detail::SignedInteger<4>;
  using Int64 = detail::SignedInteger<8>;
  using ISize = detail::SignedInteger<detail::pointer_size>;
}

#endif  // SANE_INTEGER_HPP
