// DO NOT EDIT! This file was auto-generated by crates/build/re_types_builder/src/codegen/cpp/mod.rs
// Based on "crates/store/re_types/definitions/rerun/testing/components/fuzzy.fbs".

#pragma once

#include "../datatypes/affix_fuzzer1.hpp"

#include <cstdint>
#include <memory>
#include <optional>
#include <rerun/collection.hpp>
#include <rerun/result.hpp>
#include <utility>

namespace arrow {
    class Array;
    class DataType;
    class ListBuilder;
} // namespace arrow

namespace rerun::components {
    struct AffixFuzzer7 {
        std::optional<rerun::Collection<rerun::datatypes::AffixFuzzer1>> many_optional;

      public:
        AffixFuzzer7() = default;

        AffixFuzzer7(std::optional<rerun::Collection<rerun::datatypes::AffixFuzzer1>> many_optional_
        )
            : many_optional(std::move(many_optional_)) {}

        AffixFuzzer7& operator=(
            std::optional<rerun::Collection<rerun::datatypes::AffixFuzzer1>> many_optional_
        ) {
            many_optional = std::move(many_optional_);
            return *this;
        }
    };
} // namespace rerun::components

namespace rerun {
    template <typename T>
    struct Loggable;

    /// \private
    template <>
    struct Loggable<components::AffixFuzzer7> {
        static constexpr std::string_view ComponentType = "rerun.testing.components.AffixFuzzer7";

        /// Returns the arrow data type this type corresponds to.
        static const std::shared_ptr<arrow::DataType>& arrow_datatype();

        /// Serializes an array of `rerun::components::AffixFuzzer7` into an arrow array.
        static Result<std::shared_ptr<arrow::Array>> to_arrow(
            const components::AffixFuzzer7* instances, size_t num_instances
        );

        /// Fills an arrow array builder with an array of this type.
        static rerun::Error fill_arrow_array_builder(
            arrow::ListBuilder* builder, const components::AffixFuzzer7* elements,
            size_t num_elements
        );
    };
} // namespace rerun
