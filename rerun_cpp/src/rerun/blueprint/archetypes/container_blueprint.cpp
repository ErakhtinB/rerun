// DO NOT EDIT! This file was auto-generated by crates/build/re_types_builder/src/codegen/cpp/mod.rs
// Based on "crates/store/re_types/definitions/rerun/blueprint/archetypes/container_blueprint.fbs".

#include "container_blueprint.hpp"

#include "../../collection_adapter_builtins.hpp"

namespace rerun::blueprint::archetypes {
    ContainerBlueprint ContainerBlueprint::clear_fields() {
        auto archetype = ContainerBlueprint();
        archetype.container_kind =
            ComponentBatch::empty<rerun::blueprint::components::ContainerKind>(
                Descriptor_container_kind
            )
                .value_or_throw();
        archetype.display_name =
            ComponentBatch::empty<rerun::components::Name>(Descriptor_display_name)
                .value_or_throw();
        archetype.contents =
            ComponentBatch::empty<rerun::blueprint::components::IncludedContent>(Descriptor_contents
            )
                .value_or_throw();
        archetype.col_shares =
            ComponentBatch::empty<rerun::blueprint::components::ColumnShare>(Descriptor_col_shares)
                .value_or_throw();
        archetype.row_shares =
            ComponentBatch::empty<rerun::blueprint::components::RowShare>(Descriptor_row_shares)
                .value_or_throw();
        archetype.active_tab =
            ComponentBatch::empty<rerun::blueprint::components::ActiveTab>(Descriptor_active_tab)
                .value_or_throw();
        archetype.visible =
            ComponentBatch::empty<rerun::components::Visible>(Descriptor_visible).value_or_throw();
        archetype.grid_columns =
            ComponentBatch::empty<rerun::blueprint::components::GridColumns>(Descriptor_grid_columns
            )
                .value_or_throw();
        return archetype;
    }

    Collection<ComponentColumn> ContainerBlueprint::columns(const Collection<uint32_t>& lengths_) {
        std::vector<ComponentColumn> columns;
        columns.reserve(8);
        if (container_kind.has_value()) {
            columns.push_back(container_kind.value().partitioned(lengths_).value_or_throw());
        }
        if (display_name.has_value()) {
            columns.push_back(display_name.value().partitioned(lengths_).value_or_throw());
        }
        if (contents.has_value()) {
            columns.push_back(contents.value().partitioned(lengths_).value_or_throw());
        }
        if (col_shares.has_value()) {
            columns.push_back(col_shares.value().partitioned(lengths_).value_or_throw());
        }
        if (row_shares.has_value()) {
            columns.push_back(row_shares.value().partitioned(lengths_).value_or_throw());
        }
        if (active_tab.has_value()) {
            columns.push_back(active_tab.value().partitioned(lengths_).value_or_throw());
        }
        if (visible.has_value()) {
            columns.push_back(visible.value().partitioned(lengths_).value_or_throw());
        }
        if (grid_columns.has_value()) {
            columns.push_back(grid_columns.value().partitioned(lengths_).value_or_throw());
        }
        return columns;
    }

    Collection<ComponentColumn> ContainerBlueprint::columns() {
        if (container_kind.has_value()) {
            return columns(std::vector<uint32_t>(container_kind.value().length(), 1));
        }
        if (display_name.has_value()) {
            return columns(std::vector<uint32_t>(display_name.value().length(), 1));
        }
        if (contents.has_value()) {
            return columns(std::vector<uint32_t>(contents.value().length(), 1));
        }
        if (col_shares.has_value()) {
            return columns(std::vector<uint32_t>(col_shares.value().length(), 1));
        }
        if (row_shares.has_value()) {
            return columns(std::vector<uint32_t>(row_shares.value().length(), 1));
        }
        if (active_tab.has_value()) {
            return columns(std::vector<uint32_t>(active_tab.value().length(), 1));
        }
        if (visible.has_value()) {
            return columns(std::vector<uint32_t>(visible.value().length(), 1));
        }
        if (grid_columns.has_value()) {
            return columns(std::vector<uint32_t>(grid_columns.value().length(), 1));
        }
        return Collection<ComponentColumn>();
    }
} // namespace rerun::blueprint::archetypes

namespace rerun {

    Result<Collection<ComponentBatch>>
        AsComponents<blueprint::archetypes::ContainerBlueprint>::as_batches(
            const blueprint::archetypes::ContainerBlueprint& archetype
        ) {
        using namespace blueprint::archetypes;
        std::vector<ComponentBatch> cells;
        cells.reserve(8);

        if (archetype.container_kind.has_value()) {
            cells.push_back(archetype.container_kind.value());
        }
        if (archetype.display_name.has_value()) {
            cells.push_back(archetype.display_name.value());
        }
        if (archetype.contents.has_value()) {
            cells.push_back(archetype.contents.value());
        }
        if (archetype.col_shares.has_value()) {
            cells.push_back(archetype.col_shares.value());
        }
        if (archetype.row_shares.has_value()) {
            cells.push_back(archetype.row_shares.value());
        }
        if (archetype.active_tab.has_value()) {
            cells.push_back(archetype.active_tab.value());
        }
        if (archetype.visible.has_value()) {
            cells.push_back(archetype.visible.value());
        }
        if (archetype.grid_columns.has_value()) {
            cells.push_back(archetype.grid_columns.value());
        }

        return rerun::take_ownership(std::move(cells));
    }
} // namespace rerun
