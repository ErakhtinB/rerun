// DO NOT EDIT! This file was auto-generated by crates/build/re_types_builder/src/codegen/cpp/mod.rs
// Based on "crates/store/re_types/definitions/rerun/testing/components/fuzzy_deps.fbs".

#pragma once

#include <cstdint>
#include <memory>
#include <rerun/result.hpp>
#include <string>
#include <utility>

namespace arrow {
    class Array;
    class DataType;
    class StringBuilder;
} // namespace arrow

namespace rerun::datatypes {
    struct StringComponent {
        std::string value;

      public:
        StringComponent() = default;

        StringComponent(std::string value_) : value(std::move(value_)) {}

        StringComponent& operator=(std::string value_) {
            value = std::move(value_);
            return *this;
        }
    };
} // namespace rerun::datatypes

namespace rerun {
    template <typename T>
    struct Loggable;

    /// \private
    template <>
    struct Loggable<datatypes::StringComponent> {
        static constexpr std::string_view ComponentType = "rerun.testing.datatypes.StringComponent";

        /// Returns the arrow data type this type corresponds to.
        static const std::shared_ptr<arrow::DataType>& arrow_datatype();

        /// Serializes an array of `rerun::datatypes::StringComponent` into an arrow array.
        static Result<std::shared_ptr<arrow::Array>> to_arrow(
            const datatypes::StringComponent* instances, size_t num_instances
        );

        /// Fills an arrow array builder with an array of this type.
        static rerun::Error fill_arrow_array_builder(
            arrow::StringBuilder* builder, const datatypes::StringComponent* elements,
            size_t num_elements
        );
    };
} // namespace rerun
