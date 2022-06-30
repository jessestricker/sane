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

#ifndef SANE_DETAIL_INTEGER_HPP
#define SANE_DETAIL_INTEGER_HPP

namespace sane::detail {
  using SizeType = decltype(sizeof(bool));

  constexpr SizeType pointer_size = sizeof(void*);

  template <bool Signed, SizeType Size>
  consteval auto declval_stdint() noexcept {
    using SignedChar = signed char;
    using ShortInt = short int;
    using Int = int;
    using LongInt = long int;
    using LongLongInt = long long int;

    using UnsignedChar = unsigned char;
    using UnsignedShortInt = unsigned short int;
    using UnsignedInt = unsigned int;
    using UnsignedLongInt = unsigned long int;
    using UnsignedLongLongInt = unsigned long long int;

    if constexpr (Signed && Size == sizeof(SignedChar)) {
      return SignedChar{};
    } else if constexpr (Signed && Size == sizeof(ShortInt)) {
      return ShortInt{};
    } else if constexpr (Signed && Size == sizeof(Int)) {
      return Int{};
    } else if constexpr (Signed && Size == sizeof(LongInt)) {
      return LongInt{};
    } else if constexpr (Signed && Size == sizeof(LongLongInt)) {
      return LongLongInt{};
    } else if constexpr (!Signed && Size == sizeof(UnsignedChar)) {
      return UnsignedChar{};
    } else if constexpr (!Signed && Size == sizeof(UnsignedShortInt)) {
      return UnsignedShortInt{};
    } else if constexpr (!Signed && Size == sizeof(UnsignedInt)) {
      return UnsignedInt{};
    } else if constexpr (!Signed && Size == sizeof(UnsignedLongInt)) {
      return UnsignedLongInt{};
    } else if constexpr (!Signed && Size == sizeof(UnsignedLongLongInt)) {
      return UnsignedLongLongInt{};
    }
  }

  template <bool Signed, SizeType Size, class Self>
  class IntegerBase {
  public:
    using Value = decltype(declval_stdint<Signed, Size>());

    constexpr IntegerBase() noexcept = default;

  private:
    Value value_{};
  };

  template <SizeType Size, class Self>
  struct UnsignedIntegerBase : IntegerBase<false, Size, Self> {
    using IntegerBase<false, Size, Self>::IntegerBase;
  };

  template <SizeType Size, class Self>
  struct SignedIntegerBase : IntegerBase<true, Size, Self> {
    using IntegerBase<true, Size, Self>::IntegerBase;
  };
}

#endif  // SANE_DETAIL_INTEGER_HPP
