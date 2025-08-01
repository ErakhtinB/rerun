// DO NOT EDIT! This file was auto-generated by crates/build/re_types_builder/src/codegen/cpp/mod.rs
// Based on "crates/store/re_types/definitions/rerun/archetypes/annotation_context.fbs".

#include "annotation_context.hpp"

#include "../collection_adapter_builtins.hpp"

namespace rerun::archetypes {
    AnnotationContext AnnotationContext::clear_fields() {
        auto archetype = AnnotationContext();
        archetype.context =
            ComponentBatch::empty<rerun::components::AnnotationContext>(Descriptor_context)
                .value_or_throw();
        return archetype;
    }

    Collection<ComponentColumn> AnnotationContext::columns(const Collection<uint32_t>& lengths_) {
        std::vector<ComponentColumn> columns;
        columns.reserve(1);
        if (context.has_value()) {
            columns.push_back(context.value().partitioned(lengths_).value_or_throw());
        }
        return columns;
    }

    Collection<ComponentColumn> AnnotationContext::columns() {
        if (context.has_value()) {
            return columns(std::vector<uint32_t>(context.value().length(), 1));
        }
        return Collection<ComponentColumn>();
    }
} // namespace rerun::archetypes

namespace rerun {

    Result<Collection<ComponentBatch>> AsComponents<archetypes::AnnotationContext>::as_batches(
        const archetypes::AnnotationContext& archetype
    ) {
        using namespace archetypes;
        std::vector<ComponentBatch> cells;
        cells.reserve(1);

        if (archetype.context.has_value()) {
            cells.push_back(archetype.context.value());
        }

        return rerun::take_ownership(std::move(cells));
    }
} // namespace rerun
